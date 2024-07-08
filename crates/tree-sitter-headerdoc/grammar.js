/*

Note: Once you have specified a non-inline tag such as @abstract, that tag is active until the next non-inline tag.
This means that general discussion paragraphs can only occur in one of four places:

- At the beginning of the comment.
- Immediately following an introductory top-level tag such as @class.
- Immediately following a discussion tag (@discussion).
- After an empty line in an @brief tag (which is identical to @abstract except that it stops at the first blank line).

 */


module.exports = grammar({
    name: 'headerdoc',
    extras: $ => [
        $._new_line,
        /\s+/,
        token("///"),

    ],

    externals: $ => [
        $._tag_content,
        $._simple_line,
        $._multiline_begin,
        $._simple_multiline_begin,
        $._new_line,
    ],
    rules: {
        document: $ => repeat1(choice(
            $._multiline,
            $._singleline,
            $._simple_singleline,
            $._simple_multiline
        )),
        _singleline_begin: _ => token(seq('///')),
        _simple_singleline_begin: _ => token(seq('//')),
        _multiline_end: $ => token.immediate('*/'),
        _multiline: $ => seq(
            $._multiline_begin,

            optional($._text),
            repeat(choice(
                    $.flag_tag,
                    $.block_tag
                )
            ),

            $._multiline_end,
        ),
        _simple_singleline: $ => seq(
            $._simple_singleline_begin,
            alias(token(/[^\n]*/), $.text),
        ),
        _simple_multiline: $ => seq(
            $._simple_multiline_begin,
            alias(prec.left(repeat($.raw_tag_content)), $.text),
            $._multiline_end,
        ),
        _singleline: $ => seq(
            $._singleline_begin,
            optional($._text),
            repeat($.block_tag),
        ),

        block_tag: $ => seq(
            field("name", $.tag_name),
            field("value", $.tag_content)
        ),
        _text: $ => prec.left(repeat1(
            choice(
                $.raw_tag_content,
                $.inline_tag,
            )
        )),
        raw_tag_content: $ => $._tag_content,
        flag_tag: $ => $.tag_name,
        tag_name: $ => token.immediate(
            seq(
                "@",
                choice(
                    "abstract",
                    "discussion",
                    "return",
                    "see",
                    "property",
                    "brief",
                    "remark",
                    "note",
                    "result"
                )
            )
        ),
        tag_content: $ => repeat1($._text),
        inline_tag_name: $ => token.immediate(seq(
            "@",
            choice(
                "c",
                "a",
                "em",
                "b",
                "link"
            ),
        )),
        inline_tag: $ => seq(
            field("name", $.inline_tag_name),
            /\s/,
            field("value", alias($.inline_tag_value, $.raw_tag_content))
        ),
        inline_tag_value: $ => token.immediate(/\S+/),

        _word: $ => token.immediate(/([^@\s]|[^@]\S+)/),
        _whitespace: $ => prec(-1, token(/\s+/)),
    }
});