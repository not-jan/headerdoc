use std::cell::OnceCell;
use std::error::Error;
use std::fmt::{Display, Formatter};
use std::str::FromStr;
use tree_sitter::{Parser, Node, TreeCursor,TextProvider, Query, QueryCursor};
use anyhow::{anyhow, Result};
use regex::{Regex, RegexSet, RegexSetBuilder};
use lazy_static::lazy_static;

use tree_sitter_traversal::{traverse, traverse_tree, Order};

struct HeaderDoc {

}

trait FromNode {
    type Error: Error;

    fn from_node(node: Node, input: &[u8]) -> Result<Self, Self::Error>
    where
        Self: Sized;
}

enum InlineTagKind {
    MonoSpace,
    Bold,
    Italic,
}

struct InlineTag {
    kind: InlineTagKind,
    data: String,
}

enum Text {
    Raw(String),
    Formatted(InlineTag)
}

struct BlockTag {
    kind: Tag,
    content: Vec<Text>
}





/// Apple defines a number of tags in their headerdoc documentation:
///
/// Duplicates:
/// - @brief / @abstract
/// - @charset / @encoding
/// - @compilerflag / @flag
/// - @helperclass / @helper
/// - @return / @result
/// - @const / @constant
///
///
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
enum Tag {
    /// `@abstract`
    /// A short string that briefly describes a function, data type, and so on. This should not contain multiple lines (because it will look odd in the mini-TOCs). Save the detailed descriptions for the discussion tag.
    Abstract,
    /// `@apiuid`
    /// Overrides the API UID (`apple_ref`) associated with this comment.
    ///
    /// Note: that very little checking is performed on this string. Thus, this tag has the potential to seriously break your output if used incorrectly. It is primarily provided for resolving symbol collisions that are otherwise unavoidable, and is generally discouraged.
    Apiuid,
    /// `@attribute`
    /// Adds arbitrary attributes.
    Attribute,
    /// `@attributelist`
    /// Adds arbitrary attributes.
    Attributelist,
    /// `@attributeblock`
    /// Adds arbitrary attributes.
    Attributeblock,
    /// `@availability`
    /// A string that describes the availability of a function, class, and so on.
    Availability,
    /// `@brief`
    /// Equivalent to @abstract. Provided for better Doxygen compatibility.
    Brief,
    /// `@discussion`
    /// A block of text that describes a function, class, header, or data type in detail. This may contain multiple paragraphs. `@discussion` may be omitted, as described above.
    ///
    /// `@discussion` must be present if you have a multiword name for a data type, function, class, or header.
    ///
    /// An `@discussion` block ends only when another block begins, such as an @param tag.
    Discussion,
    /// `@indexgroup`
    /// Provides grouping information within the master TOC (landing page).
    ///
    /// In the absence of an `@indexgroup` tag, the index group is inherited from the enclosing class or header.
    Indexgroup,
    /// `@internal`
    /// Marks the declaration as internal documentation. Such documentation is emitted only if the `--document-internal` flag is specified on the command line.
    ///
    /// Note: The declaration may still modify other declarations in the case of #define macros with C preprocessing enabled.
    Internal,
    /// `@link`
    /// Allows you to insert a link request for an API ref. See Creating Links Between Symbols for more information.
    Link,
    /// `@namespace`
    /// String describing the namespace in which the function, data type, etc. exists.
    Namespace,
    /// `@see`
    /// Adds a “See:” entry to the attributes. Arguments are the same as `@link`. Note that this tag is ignored if the API reference marker already appears in the see or see also list.
    See,
    /// `@seealso`
    /// Adds a “See Also:” entry to the attributes. Arguments are the same as `@link`. Note that this tag is ignored if the API reference marker already appears in the see or see also list.
    Seealso,
    /// `@textblock`
    /// Treat everything until the trailing `@/textblock` as raw text, preserving initial spaces and line breaks, and converting “<” and “>” to “&lt;” and “&gt;”.
    ///
    /// Note: This tag does not automatically insert `<pre>` or `<tt>`. You may wrap it with whatever formatting you choose.
    Textblock,
    /// `@updated`
    /// The date at which the header was last updated.
    Updated,
    /// `@frameworkcopyright`
    /// The copyright info for the header.
    Frameworkcopyright,
    /// `@frameworkpath`
    /// The path to the framework.
    Frameworkpath,
    /// `@frameworkuid`
    /// Specifies a unique ID that `gatherHeaderDoc` inserts as part of a special anchor when building the main TOC.
    /// (This is not particularly useful externally, but is included for completeness.)
    Frameworkuid,
    /// `@headerpath`
    /// Provides the path to the Headers folder inside the framework.
    Headerpath,
    /// `@author`
    /// The author of the header.
    Author,
    /// `@charset`
    /// Sets the character encoding for generated HTML files (same as `@encoding`).
    Charset,
    /// `@compilerflag`
    /// Compiler flag that should be set when using functions and types in this header.
    Compilerflag,
    /// `@copyright`
    /// Copyright info to be added to each page. This overrides the config file value and may not span multiple lines.
    Copyright,
    /// `@CFBundleIdentifier`
    /// Which kernel subcomponent, loadable extension, or application bundle contains this header
    CFBundleIdentifier,
    /// `@encoding`
    /// Sets the character encoding for generated HTML files (same as `@charset`).
    Encoding,
    /// `@flag`
    /// Same as `@compilerflag`.
    Flag,
    /// `@ignore`
    /// Tells HeaderDoc to delete the specified token.
    Ignore,
    /// `@ignorefuncmacro`
    /// Tells HeaderDoc to unwrap occurrences of the specified function-like macro.
    Ignorefuncmacro,
    /// `@language`
    /// **Deprecated**. Sets the current programming language.
    Language,
    /// `@meta`
    /// Meta tag info to be added to each page. This can be either in the form `@meta <name> <content>` or `@meta <complete tag contents>`, and may not span multiple lines.
    Meta,
    /// `@preprocinfo`
    /// Description of behavior when preprocessor macros are set (`-DDEBUG`, for example).
    Preprocinfo,
    /// `@related`
    /// Indicates another header that is related to this one. You may use multiple `@related` tags.
    ///
    /// Similar to the `@seealso` tag.
    Related,
    /// `@unsorted`
    /// Indicates that you do not want HeaderDoc to alphabetize the contents of this header.
    Unsorted,
    /// `@version`
    /// The version number to which this documentation applies.
    Version,
    /// `@whyinclude`
    /// Indicates why you should include the header.
    Whyinclude,
    /// `@classdesign`
    /// Description of any common design considerations that apply to this class, such as consistent ways of handling locking or threading.
    Classdesign,
    /// `@coclass`
    /// Class with which this class was designed to work.
    Coclass,
    /// `@dependency`
    /// External resource that this class depends on (such as a class or file).
    Dependency,
    /// `@deprecated`
    /// String telling when the function, data type, etc. was deprecated.
    Deprecated,
    /// `@helper`
    /// A helper class used by this class.
    Helper,
    /// `@helperclass`
    /// A helper class used by this class.
    HelperClass,
    /// `@helps`
    /// If this is a helper class, a short description of classes that this class was designed to help.
    Helps,
    /// `@instancesize`
    /// The typical size of each instance of the class.
    Instancesize,
    /// `@ownership`
    /// Describes the ownership model to which this class conforms.
    Ownership,
    /// `@performance`
    /// Describes special performance characteristics for this class.
    Performance,
    /// `@security`
    /// Describes security considerations associated with the use of this class
    Security,
    /// `@superclass`
    /// Overrides superclass name—see note below.
    Superclass,
    /// `@templatefield`
    /// Each of the function’s template fields (C++).
    Templatefield,
    /// `@var`
    /// Documents a local variable in a function or method.
    ///
    /// You can suppress local variables in the output by passing the `-L` flag to headerdoc2html.
    ///
    /// Note: Because this tag has the same name as a top-level tag, it cannot be the first tag in the HeaderDoc comment for a function or method
    Var,
    /// `@param`
    /// The name and description of a parameter to a function or callback.
    Param,
    /// `@result`
    /// Describes the return values expected from this function.
    ///
    /// Don't include if the return value is `void` or `OSERR`.
    Result,
    /// `@return`
    /// Same as `@result`.
    Return,
    /// `@throws`
    /// Include one @throws tag for each exception thrown by this function (in languages that support exceptions).
    Throws,
    /// `@callback`
    /// Specifies the name and description of a callback field in a structure.
    Callback,
    /// `@field`
    /// A field in a structure declaration.
    Field,
    /// `@constant`
    /// A constant within an enumeration
    Constant,
    /// `@const`
    /// A constant within an enumeration
    Const,
    /// `@define`
    /// Legacy top-level tag that provides the macro name.
    Define,
    /// `@defined`
    /// Legacy top-level tag that provides the macro name.
    Defined,
    /// `@noParse`
    /// Disables C preprocessor parsing of a macro. The macro will still be included as a `#define` entry in the resulting documentation.
    NoParse,
    /// `@parseOnly`
    /// Marks macro as “hidden”. The macro will be parsed and used by the C preprocessor, but will not be included as a separate `#define` entry in the resulting documentation.
    ParseOnly,
}

impl std::str::FromStr for Tag {
    type Err = anyhow::Error;

    fn from_str(s: &str) -> Result<Tag, Self::Err> {
        match s {
            "@abstract" => Ok(Tag::Abstract),
            "@apiuid" => Ok(Tag::Apiuid),
            "@attribute" => Ok(Tag::Attribute),
            "@attributelist" => Ok(Tag::Attributelist),
            "@attributeblock" => Ok(Tag::Attributeblock),
            "@availability" => Ok(Tag::Availability),
            "@brief" => Ok(Tag::Brief),
            "@discussion" => Ok(Tag::Discussion),
            "@indexgroup" => Ok(Tag::Indexgroup),
            "@internal" => Ok(Tag::Internal),
            "@link" => Ok(Tag::Link),
            "@namespace" => Ok(Tag::Namespace),
            "@see" => Ok(Tag::See),
            "@seealso" => Ok(Tag::Seealso),
            "@textblock" => Ok(Tag::Textblock),
            "@updated" => Ok(Tag::Updated),
            "@frameworkcopyright" => Ok(Tag::Frameworkcopyright),
            "@frameworkpath" => Ok(Tag::Frameworkpath),
            "@frameworkuid" => Ok(Tag::Frameworkuid),
            "@headerpath" => Ok(Tag::Headerpath),
            "@author" => Ok(Tag::Author),
            "@charset" => Ok(Tag::Charset),
            "@compilerflag" => Ok(Tag::Compilerflag),
            "@copyright" => Ok(Tag::Copyright),
            "@CFBundleIdentifier" => Ok(Tag::CFBundleIdentifier),
            "@encoding" => Ok(Tag::Encoding),
            "@flag" => Ok(Tag::Flag),
            "@ignore" => Ok(Tag::Ignore),
            "@ignorefuncmacro" => Ok(Tag::Ignorefuncmacro),
            "@language" => Ok(Tag::Language),
            "@meta" => Ok(Tag::Meta),
            "@preprocinfo" => Ok(Tag::Preprocinfo),
            "@related" => Ok(Tag::Related),
            "@unsorted" => Ok(Tag::Unsorted),
            "@version" => Ok(Tag::Version),
            "@whyinclude" => Ok(Tag::Whyinclude),
            "@classdesign" => Ok(Tag::Classdesign),
            "@coclass" => Ok(Tag::Coclass),
            "@dependency" => Ok(Tag::Dependency),
            "@deprecated" => Ok(Tag::Deprecated),
            "@helper" => Ok(Tag::Helper),
            "@helperclass" => Ok(Tag::Helper),
            "@helps" => Ok(Tag::Helps),
            "@instancesize" => Ok(Tag::Instancesize),
            "@ownership" => Ok(Tag::Ownership),
            "@performance" => Ok(Tag::Performance),
            "@security" => Ok(Tag::Security),
            "@superclass" => Ok(Tag::Superclass),
            "@templatefield" => Ok(Tag::Templatefield),
            "@var" => Ok(Tag::Var),
            "@param" => Ok(Tag::Param),
            "@result" => Ok(Tag::Result),
            "@return" => Ok(Tag::Return),
            "@throws" => Ok(Tag::Throws),
            "@callback" => Ok(Tag::Callback),
            "@field" => Ok(Tag::Field),
            "@constant" => Ok(Tag::Constant),
            "@const" => Ok(Tag::Const),
            "@define" => Ok(Tag::Define),
            "@defined" => Ok(Tag::Defined),
            "@noParse" => Ok(Tag::NoParse),
            "@parseOnly" => Ok(Tag::ParseOnly),
            // Add further matches
            _ => Err(anyhow!("Unknown tag!")),
        }
    }
}

impl Display for Tag {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        let raw_tag = match self {
            Tag::Abstract => "@abstract",
            Tag::Apiuid => "@apiuid",
            Tag::Attribute => "@attribute",
            Tag::Attributelist => "@attributelist",
            Tag::Attributeblock => "@attributeblock",
            Tag::Availability => "@availability",
            Tag::Brief => "@brief",
            Tag::Discussion => "@discussion",
            Tag::Indexgroup => "@indexgroup",
            Tag::Internal => "@internal",
            Tag::Link => "@link",
            Tag::Namespace => "@namespace",
            Tag::See => "@see",
            Tag::Seealso => "@seealso",
            Tag::Textblock => "@textblock",
            Tag::Updated => "@updated",
            Tag::Frameworkcopyright => "@frameworkcopyright",
            Tag::Frameworkpath => "@frameworkpath",
            Tag::Frameworkuid => "@frameworkuid",
            Tag::Headerpath => "@headerpath",
            Tag::Author => "@author",
            Tag::Charset => "@charset",
            Tag::Compilerflag => "@compilerflag",
            Tag::Copyright => "@copyright",
            Tag::CFBundleIdentifier => "@CFBundleIdentifier",
            Tag::Encoding => "@encoding",
            Tag::Flag => "@flag",
            Tag::Ignore => "@ignore",
            Tag::Ignorefuncmacro => "@ignorefuncmacro",
            Tag::Language => "@language",
            Tag::Meta => "@meta",
            Tag::Preprocinfo => "@preprocinfo",
            Tag::Related => "@related",
            Tag::Unsorted => "@unsorted",
            Tag::Version => "@version",
            Tag::Whyinclude => "@whyinclude",
            Tag::Classdesign => "@classdesign",
            Tag::Coclass => "@coclass",
            Tag::Dependency => "@dependency",
            Tag::Deprecated => "@deprecated",
            Tag::Helper => "@helper",
            Tag::Helps => "@helps",
            Tag::Instancesize => "@instancesize",
            Tag::Ownership => "@ownership",
            Tag::Performance => "@performance",
            Tag::Security => "@security",
            Tag::Superclass => "@superclass",
            Tag::Templatefield => "@templatefield",
            Tag::Var => "@var",
            Tag::Param => "@param",
            Tag::Result => "@result",
            Tag::Return => "@return",
            Tag::Throws => "@throws",
            Tag::Callback => "@callback",
            Tag::Field => "@field",
            Tag::Constant => "@constant",
            Tag::Const => "@const",
            Tag::Define => "@define",
            Tag::Defined => "@defined",
            Tag::NoParse => "@noParse",
            Tag::ParseOnly => "@parseOnly",
            Tag::HelperClass => "@helperclass"
        };

        write!(f, "{raw_tag}")
    }
}




fn main() -> Result<()> {
    let mut parser = Parser::new();
    parser.set_language(&tree_sitter_headerdoc::language()).expect("Error loading HeaderDoc grammar");
    let input = b"// This is a test!";
    let input2 = b"
    /*!
    *  dsaiodsaiodsadas
    *
    *  @abstract Link to the Contacts database.
    *
    *  @discussion Identities discovered via @c CKDiscoverAllUserIdentitiesOperation correspond to entries in the local Contacts database.  These identities will have @c contactIdentifiers filled out, which your app may use to get additional information about the contacts that were discovered.  Multiple @c contactIdentifiers may exist for a single discovered user, as multiple contacts may contain the same email addresses or phone numbers.
    *
    *  @return individual, non-unified contacts.
    *
    *  @discussion To transform these identifiers into an array of unified contact identifiers, pass a @c CNContact.predicateForContacts(withIdentifiers:) predicate into @c CNContactStore.unifiedContacts(matching:keysToFetch:)
    *
    *  @return Contacts.framework and CNContact.identifier
     */";

    let tree = parser.parse(input2, None).unwrap();

    let root = tree.root_node();
    let mut cursor = root.walk();

    let block_tag_id = tree_sitter_headerdoc::language().id_for_node_kind("block_tag", true);
    let text_id = tree_sitter_headerdoc::language().id_for_node_kind("text", true);

    dbg!(&root);

    for child in root.children(&mut cursor) {

        dbg!(&child);
        let kind_id = child.kind_id();

        if kind_id == block_tag_id {
            let tag_name_node = child.child_by_field_name("name").ok_or_else(|| anyhow!("Invalid block tag!"))?;
            let tag_name = tag_name_node.utf8_text(input2)?;
            let tag_kind = Tag::from_str(tag_name)?;
            dbg!(tag_kind);

            let tag_value_node = child.child_by_field_name("value").ok_or_else(|| anyhow!("Invalid block tag!"))?;


            let mut inner_cursor = tag_value_node.walk();

            for inner_child in tag_value_node.children(&mut inner_cursor) {
                if inner_child.is_extra() {
                    continue;
                }
                let tag_value = inner_child.utf8_text(input2)?;
                let trimmed_tag_value = tag_value.trim();
                if trimmed_tag_value.is_empty() {
                    continue;
                }

                dbg!(trimmed_tag_value);
            }


        } else if kind_id == text_id {

            let mut inner_cursor = child.walk();

            for inner_child in child.children(&mut inner_cursor) {
                if inner_child.is_extra() {
                    continue;
                }
                let tag_value = inner_child.utf8_text(input2)?;

                let trimmed_tag_value = tag_value.trim();
                if trimmed_tag_value.is_empty() {
                    continue;
                }

                dbg!(trimmed_tag_value);
            }

        }

    }



    Ok(())
}

#[cfg(test)]
mod test {
    use tree_sitter::Parser;

    fn make_parser() -> Parser {
        let mut parser = Parser::new();
        parser.set_language(&tree_sitter_headerdoc::language()).expect("Error loading HeaderDoc grammar");
        parser
    }

    #[test]
    fn test_empty_multi() {
        let mut parser = make_parser();


        parser.parse("/**/", None).unwrap();
    }

    #[test]
    fn test_single_line_multi() {
        let mut parser = make_parser();
        parser.set_logger(Some(Box::new(|ty, data| {
            println!("[{:?}] {}", ty, data);
        })));
        const INPUT: &[u8] = b"/* This is a test */";
        let tree = parser.parse(INPUT, None).unwrap();

        let node = tree.root_node().child(0).unwrap();
        dbg!(node);
        dbg!(tree.root_node());
        let root_node = tree.root_node();
        let mut cursor = root_node.walk();
        for (i, child) in root_node.children(&mut cursor).enumerate() {
            dbg!(&child);
            dbg!(child.field_name_for_child(i as u32));
            dbg!(child.utf8_text(INPUT));



        }
    }
}
