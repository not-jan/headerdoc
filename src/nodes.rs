use std::fmt::{Display, Formatter};
use std::str::FromStr;
use anyhow::{anyhow, bail};
use tree_sitter::Node;


pub trait FromNode<'tree> {
    type Error;

    fn from_node(node: Node<'tree>, input: &[u8]) -> anyhow::Result<Self, Self::Error>
    where
        Self: Sized;
}

#[derive(Clone, Debug)]
pub struct HeaderDoc {
    pub(crate) content: Vec<Element>,
}

#[derive(Clone, Debug)]
pub enum InlineTagKind {
    MonoSpace,
    Bold,
    Italic,
    Link,
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
pub enum TagKind {
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
    /// `@property`
    /// TODO: Docs
    Property,
    /// `@remark`
    /// TODO: Docs
    Remark,
    /// `@note`
    /// TODO: Docs
    Note,
}

#[derive(Clone, Debug)]
pub struct InlineTag {
    pub kind: InlineTagKind,
    pub data: Box<TextElement>,
}

#[derive(Clone, Debug)]
pub enum TextElement {
    Raw(String),
    Formatted(InlineTag),
}

#[derive(Clone, Debug)]
pub struct Text(pub Vec<TextElement>);

#[derive(Clone, Debug)]
pub struct BlockTag {
    pub kind: TagKind,
    pub content: Text,
}

#[derive(Clone, Debug)]
pub struct FlagTag {
    pub kind: TagKind,
}

#[derive(Clone, Debug)]
pub enum Element {
    BlockTag(BlockTag),
    FlagTag(FlagTag),
    Text(Text),
}

impl<'tree> FromNode<'tree> for HeaderDoc {
    type Error = anyhow::Error;

    fn from_node(node: Node<'tree>, input: &[u8]) -> anyhow::Result<Self, Self::Error>
    where
        Self: Sized,
    {
        let mut cursor = node.walk();
        let content = node.children(&mut cursor).map(|child| match child.kind() {
            "raw_tag_content" => Ok(Element::Text(Text::from_node(child, input)?)),
            "block_tag" => Ok(Element::BlockTag(BlockTag::from_node(child, input)?)),
            "text" => Ok(Element::Text(Text::from_node(child, input)?)),
            "inline_tag" => Ok(Element::Text(Text(vec![TextElement::from_node(child, input)?]))),
            "flag_tag" => Ok(Element::FlagTag(FlagTag::from_node(child, input)?)),
            _ => {
                dbg!(child);
                dbg!(child.utf8_text(input));
                bail!("Invalid HeaderDoc!");
            }
        }).collect::<anyhow::Result<Vec<_>>>()?;
        Ok(HeaderDoc {
            content,
        })
    }
}

impl<'tree> FromNode<'tree> for FlagTag {
    type Error = anyhow::Error;

    fn from_node(node: Node<'tree>, input: &[u8]) -> anyhow::Result<Self, Self::Error>
    where
        Self: Sized,
    {
        let text = node.utf8_text(input)?;
        Ok(FlagTag {
            kind: TagKind::from_str(text)?,
        })
    }
}

impl<'tree> FromNode<'tree> for BlockTag {
    type Error = anyhow::Error;

    fn from_node(node: Node<'tree>, input: &[u8]) -> anyhow::Result<Self, Self::Error>
    where
        Self: Sized,
    {
        let name = node.child_by_field_name("name").ok_or_else(|| anyhow!("Malformed inline tag"))?;
        let kind = TagKind::from_node(name, input)?;

        let value = node.child_by_field_name("value").ok_or_else(|| anyhow!("Malformed inline tag"))?;
        let content = Text::from_node(value, input)?;

        Ok(BlockTag {
            kind,
            content,
        })
    }
}

impl<'tree> FromNode<'tree> for InlineTagKind {
    type Error = anyhow::Error;

    fn from_node(node: Node<'tree>, input: &[u8]) -> anyhow::Result<Self, Self::Error>
    where
        Self: Sized,
    {
        let text = node.utf8_text(input)?;
        InlineTagKind::from_str(text)
    }
}

impl<'tree> FromNode<'tree> for TagKind {
    type Error = anyhow::Error;

    fn from_node(node: Node<'tree>, input: &[u8]) -> anyhow::Result<Self, Self::Error>
    where
        Self: Sized,
    {
        let text = node.utf8_text(input)?;
        TagKind::from_str(text)
    }
}


impl<'tree> FromNode<'tree> for InlineTag {
    type Error = anyhow::Error;

    fn from_node(node: Node<'tree>, input: &[u8]) -> anyhow::Result<Self, Self::Error>
    where
        Self: Sized,
    {
        let name = node.child_by_field_name("name").ok_or_else(|| anyhow!("Malformed inline tag"))?;
        let kind = InlineTagKind::from_node(name, input)?;

        let value = node.child_by_field_name("value").ok_or_else(|| anyhow!("Malformed inline tag"))?;
        let content = TextElement::from_node(value, input)?;

        Ok(InlineTag {
            kind,
            data: Box::new(content),
        })
    }
}

impl<'tree> FromNode<'tree> for TextElement {
    type Error = anyhow::Error;

    fn from_node(node: Node<'tree>, input: &[u8]) -> anyhow::Result<Self, Self::Error>
    where
        Self: Sized,
    {
        Ok(match node.kind() {
            "raw_tag_content" => {
                let text = node.utf8_text(input)?.trim();
                TextElement::Raw(text.to_string())
            }
            "inline_tag" => {
                TextElement::Formatted(InlineTag::from_node(node, input)?)
            }
            _ => bail!("Invalid text element: {}!", node.kind())
        })
    }
}

impl<'tree> FromNode<'tree> for Text {
    type Error = anyhow::Error;

    fn from_node(node: Node<'tree>, input: &[u8]) -> anyhow::Result<Self, Self::Error>
    where
        Self: Sized,
    {
        let mut cursor = node.walk();
        let elements = node.children(&mut cursor).map(|child| TextElement::from_node(child, input)).collect::<anyhow::Result<Vec<_>>>()?;

        Ok(Self(elements))
    }
}


impl FromStr for InlineTagKind {
    type Err = anyhow::Error;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        match s {
            "@c" => Ok(InlineTagKind::MonoSpace),
            "@code" => Ok(InlineTagKind::MonoSpace),
            "@link" => Ok(InlineTagKind::Link),
            "@em" => Ok(InlineTagKind::Bold),
            _ => bail!("Unknown inline tag: {}!", s),
        }
    }
}


impl FromStr for TagKind {
    type Err = anyhow::Error;

    fn from_str(s: &str) -> anyhow::Result<TagKind, Self::Err> {
        match s {
            "@abstract" => Ok(TagKind::Abstract),
            "@apiuid" => Ok(TagKind::Apiuid),
            "@attribute" => Ok(TagKind::Attribute),
            "@attributelist" => Ok(TagKind::Attributelist),
            "@attributeblock" => Ok(TagKind::Attributeblock),
            "@availability" => Ok(TagKind::Availability),
            "@brief" => Ok(TagKind::Brief),
            "@discussion" => Ok(TagKind::Discussion),
            "@indexgroup" => Ok(TagKind::Indexgroup),
            "@internal" => Ok(TagKind::Internal),
            "@link" => Ok(TagKind::Link),
            "@namespace" => Ok(TagKind::Namespace),
            "@see" => Ok(TagKind::See),
            "@seealso" => Ok(TagKind::Seealso),
            "@textblock" => Ok(TagKind::Textblock),
            "@updated" => Ok(TagKind::Updated),
            "@frameworkcopyright" => Ok(TagKind::Frameworkcopyright),
            "@frameworkpath" => Ok(TagKind::Frameworkpath),
            "@frameworkuid" => Ok(TagKind::Frameworkuid),
            "@headerpath" => Ok(TagKind::Headerpath),
            "@author" => Ok(TagKind::Author),
            "@charset" => Ok(TagKind::Charset),
            "@compilerflag" => Ok(TagKind::Compilerflag),
            "@copyright" => Ok(TagKind::Copyright),
            "@CFBundleIdentifier" => Ok(TagKind::CFBundleIdentifier),
            "@encoding" => Ok(TagKind::Encoding),
            "@flag" => Ok(TagKind::Flag),
            "@ignore" => Ok(TagKind::Ignore),
            "@ignorefuncmacro" => Ok(TagKind::Ignorefuncmacro),
            "@language" => Ok(TagKind::Language),
            "@meta" => Ok(TagKind::Meta),
            "@preprocinfo" => Ok(TagKind::Preprocinfo),
            "@related" => Ok(TagKind::Related),
            "@unsorted" => Ok(TagKind::Unsorted),
            "@version" => Ok(TagKind::Version),
            "@whyinclude" => Ok(TagKind::Whyinclude),
            "@classdesign" => Ok(TagKind::Classdesign),
            "@coclass" => Ok(TagKind::Coclass),
            "@dependency" => Ok(TagKind::Dependency),
            "@deprecated" => Ok(TagKind::Deprecated),
            "@helper" => Ok(TagKind::Helper),
            "@helperclass" => Ok(TagKind::Helper),
            "@helps" => Ok(TagKind::Helps),
            "@instancesize" => Ok(TagKind::Instancesize),
            "@ownership" => Ok(TagKind::Ownership),
            "@performance" => Ok(TagKind::Performance),
            "@security" => Ok(TagKind::Security),
            "@superclass" => Ok(TagKind::Superclass),
            "@templatefield" => Ok(TagKind::Templatefield),
            "@var" => Ok(TagKind::Var),
            "@param" => Ok(TagKind::Param),
            "@result" => Ok(TagKind::Result),
            "@return" => Ok(TagKind::Return),
            "@throws" => Ok(TagKind::Throws),
            "@callback" => Ok(TagKind::Callback),
            "@field" => Ok(TagKind::Field),
            "@constant" => Ok(TagKind::Constant),
            "@const" => Ok(TagKind::Const),
            "@define" => Ok(TagKind::Define),
            "@defined" => Ok(TagKind::Defined),
            "@noParse" => Ok(TagKind::NoParse),
            "@parseOnly" => Ok(TagKind::ParseOnly),
            "@property" => Ok(TagKind::Property),
            "@remark" => Ok(TagKind::Remark),
            "@note" => Ok(TagKind::Note),
            // Add further matches
            _ => Err(anyhow!("Unknown tag: {s}!", )),
        }
    }
}

impl Display for TagKind {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        let raw_tag = match self {
            TagKind::Abstract => "@abstract",
            TagKind::Apiuid => "@apiuid",
            TagKind::Attribute => "@attribute",
            TagKind::Attributelist => "@attributelist",
            TagKind::Attributeblock => "@attributeblock",
            TagKind::Availability => "@availability",
            TagKind::Brief => "@brief",
            TagKind::Discussion => "@discussion",
            TagKind::Indexgroup => "@indexgroup",
            TagKind::Internal => "@internal",
            TagKind::Link => "@link",
            TagKind::Namespace => "@namespace",
            TagKind::See => "@see",
            TagKind::Seealso => "@seealso",
            TagKind::Textblock => "@textblock",
            TagKind::Updated => "@updated",
            TagKind::Frameworkcopyright => "@frameworkcopyright",
            TagKind::Frameworkpath => "@frameworkpath",
            TagKind::Frameworkuid => "@frameworkuid",
            TagKind::Headerpath => "@headerpath",
            TagKind::Author => "@author",
            TagKind::Charset => "@charset",
            TagKind::Compilerflag => "@compilerflag",
            TagKind::Copyright => "@copyright",
            TagKind::CFBundleIdentifier => "@CFBundleIdentifier",
            TagKind::Encoding => "@encoding",
            TagKind::Flag => "@flag",
            TagKind::Ignore => "@ignore",
            TagKind::Ignorefuncmacro => "@ignorefuncmacro",
            TagKind::Language => "@language",
            TagKind::Meta => "@meta",
            TagKind::Preprocinfo => "@preprocinfo",
            TagKind::Related => "@related",
            TagKind::Unsorted => "@unsorted",
            TagKind::Version => "@version",
            TagKind::Whyinclude => "@whyinclude",
            TagKind::Classdesign => "@classdesign",
            TagKind::Coclass => "@coclass",
            TagKind::Dependency => "@dependency",
            TagKind::Deprecated => "@deprecated",
            TagKind::Helper => "@helper",
            TagKind::Helps => "@helps",
            TagKind::Instancesize => "@instancesize",
            TagKind::Ownership => "@ownership",
            TagKind::Performance => "@performance",
            TagKind::Security => "@security",
            TagKind::Superclass => "@superclass",
            TagKind::Templatefield => "@templatefield",
            TagKind::Var => "@var",
            TagKind::Param => "@param",
            TagKind::Result => "@result",
            TagKind::Return => "@return",
            TagKind::Throws => "@throws",
            TagKind::Callback => "@callback",
            TagKind::Field => "@field",
            TagKind::Constant => "@constant",
            TagKind::Const => "@const",
            TagKind::Define => "@define",
            TagKind::Defined => "@defined",
            TagKind::NoParse => "@noParse",
            TagKind::ParseOnly => "@parseOnly",
            TagKind::HelperClass => "@helperclass",
            TagKind::Property => "@property",
            TagKind::Remark => "@remark",
            TagKind::Note => "@note",
        };

        write!(f, "{raw_tag}")
    }
}