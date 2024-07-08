use std::fmt::{Debug, Display, Formatter};
use crate::nodes::{HeaderDoc, Element as HeaderElement, BlockTag, Text as HeaderText, TextElement, InlineTag, InlineTagKind, TagKind};
use anyhow::Result;


#[derive(Debug, Clone)]
pub struct Section {
    title: String,
    content: Text,
}

#[derive(Debug, Clone)]
struct Text(String);

impl Text {
    fn as_wrapped(&self, soft: usize) -> String {
        let mut acc: Vec<Vec<&str>> = Vec::new();

        for word in self.0.split_whitespace() {
            match acc.last_mut() {
                Some(last) => {
                    let length = last.iter().fold(0, |acc, word| {
                        word.len() + acc
                    }) + last.len() - 1;
                    let new_length = length + word.len();

                    if new_length > soft {
                        acc.push([word].to_vec());
                    } else {
                        last.push(word);
                    }
                }
                None => {
                    acc.push([word].to_vec());
                }
            }
        }

        acc.iter().map(|line| line.join(" ")).collect::<Vec<_>>().join("\n")
    }
}

impl Display for Text {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        <String as Display>::fmt(&self.0, f)
    }
}

#[derive(Debug, Clone)]
pub struct Flag {
    kind: TagKind,
}

#[derive(Debug, Clone)]
pub enum Element {
    Text(Text),
    Section(Section),
    Flag(Flag),
}


trait Markdown {
    fn as_markdown(&self) -> Result<String>;
}

impl Markdown for TagKind {
    fn as_markdown(&self) -> Result<String> {
        match self {
            TagKind::Abstract => Ok("Abstract".to_string()),
            TagKind::Apiuid => Ok("API UID".to_string()),
            TagKind::Attribute => Ok("Attribute".to_string()),
            TagKind::Attributelist => Ok("Attribute List".to_string()),
            TagKind::Attributeblock => Ok("Attribute Block".to_string()),
            TagKind::Availability => Ok("Availability".to_string()),
            TagKind::Brief => Ok("Brief".to_string()),
            TagKind::Discussion => Ok("Discussion".to_string()),
            TagKind::Indexgroup => Ok("Index Group".to_string()),
            TagKind::Internal => Ok("Internal".to_string()),
            TagKind::Link => Ok("Link".to_string()),
            TagKind::Namespace => Ok("Namespace".to_string()),
            TagKind::See => Ok("See".to_string()),
            TagKind::Seealso => Ok("See Also".to_string()),
            TagKind::Textblock => Ok("Text Block".to_string()),
            TagKind::Updated => Ok("Updated".to_string()),
            TagKind::Frameworkcopyright => Ok("Framework Copyright".to_string()),
            TagKind::Frameworkpath => Ok("Framework Path".to_string()),
            TagKind::Frameworkuid => Ok("Framework UID".to_string()),
            TagKind::Headerpath => Ok("Header Path".to_string()),
            TagKind::Author => Ok("Author".to_string()),
            TagKind::Charset => Ok("Charset".to_string()),
            TagKind::Compilerflag => Ok("Compiler Flag".to_string()),
            TagKind::Copyright => Ok("Copyright".to_string()),
            TagKind::CFBundleIdentifier => Ok("CFBundleIdentifier".to_string()),
            TagKind::Encoding => Ok("Encoding".to_string()),
            TagKind::Flag => Ok("Flag".to_string()),
            TagKind::Ignore => Ok("Ignore".to_string()),
            TagKind::Ignorefuncmacro => Ok("Ignore Func Macro".to_string()),
            TagKind::Language => Ok("Language".to_string()),
            TagKind::Meta => Ok("Meta".to_string()),
            TagKind::Preprocinfo => Ok("Preproc Info".to_string()),
            TagKind::Related => Ok("Related".to_string()),
            TagKind::Unsorted => Ok("Unsorted".to_string()),
            TagKind::Version => Ok("Version".to_string()),
            TagKind::Whyinclude => Ok("Why Include".to_string()),
            TagKind::Classdesign => Ok("Class Design".to_string()),
            TagKind::Coclass => Ok("Coclass".to_string()),
            TagKind::Dependency => Ok("Dependency".to_string()),
            TagKind::Deprecated => Ok("Deprecated".to_string()),
            TagKind::Helper => Ok("Helper".to_string()),
            TagKind::HelperClass => Ok("Helper Class".to_string()),
            TagKind::Helps => Ok("Helps".to_string()),
            TagKind::Instancesize => Ok("Instance Size".to_string()),
            TagKind::Ownership => Ok("Ownership".to_string()),
            TagKind::Performance => Ok("Performance".to_string()),
            TagKind::Security => Ok("Security".to_string()),
            TagKind::Superclass => Ok("Superclass".to_string()),
            TagKind::Templatefield => Ok("Template Field".to_string()),
            TagKind::Var => Ok("Var".to_string()),
            TagKind::Param => Ok("Param".to_string()),
            TagKind::Result => Ok("Result".to_string()),
            TagKind::Return => Ok("Returns".to_string()),
            TagKind::Throws => Ok("Throws".to_string()),
            TagKind::Callback => Ok("Callback".to_string()),
            TagKind::Field => Ok("Field".to_string()),
            TagKind::Constant => Ok("Constant".to_string()),
            TagKind::Const => Ok("Const".to_string()),
            TagKind::Define => Ok("Define".to_string()),
            TagKind::Defined => Ok("Defined".to_string()),
            TagKind::NoParse => Ok("No Parse".to_string()),
            TagKind::ParseOnly => Ok("Parse Only".to_string()),
            TagKind::Property => Ok("Property".to_string()),
            TagKind::Remark => Ok("Remark".to_string()),
            TagKind::Note => Ok("Note".to_string())
        }
    }
}

impl Markdown for InlineTag {
    fn as_markdown(&self) -> Result<String> {
        let content = self.data.as_markdown()?;

        Ok(match self.kind {
            InlineTagKind::MonoSpace => format!("`{}`", content),
            InlineTagKind::Bold => format!("**{}**", content),
            InlineTagKind::Italic => format!("*{}*", content),
            // TODO: Don't really know what to do here...
            InlineTagKind::Link => content,
        })
    }
}

impl Markdown for TextElement {
    fn as_markdown(&self) -> Result<String> {
        match self {
            TextElement::Raw(text) => Ok(text.clone()),
            TextElement::Formatted(content) => content.as_markdown()
        }
    }
}

impl Markdown for HeaderText {
    fn as_markdown(&self) -> Result<String> {
        let elements = self.0.iter().map(|element| {
            element.as_markdown()
        }).collect::<Result<Vec<_>>>()?;

        Ok(elements.join(" "))
    }
}

impl Markdown for BlockTag {
    fn as_markdown(&self) -> Result<String> {
        Ok(format!(" # {}\n\n{}", self.kind.to_string(), self.content.as_markdown()?))
    }
}

#[derive(Debug, Clone)]
pub struct RustDoc {
    content: Vec<Element>,
    line_width: usize,
}

impl Default for RustDoc {
    fn default() -> Self {
        Self {
            content: vec![],
            line_width: 80,
        }
    }
}

impl TryFrom<HeaderDoc> for RustDoc {
    type Error = anyhow::Error;

    fn try_from(value: HeaderDoc) -> Result<Self, Self::Error> {
        let content = value.content.into_iter().map(|element| match element {
            HeaderElement::BlockTag(BlockTag { kind, content }) => {
                Ok(Element::Section(Section {
                    title: kind.as_markdown()?,
                    content: Text(content.as_markdown()?),
                }))
            }
            HeaderElement::Text(content) => Ok(Element::Text(Text(content.as_markdown()?))),
            HeaderElement::FlagTag(flag) => {
                // TODO: Do we even need to emit those?
                Ok(Element::Flag(Flag {
                    kind: flag.kind
                }))
            }
        }).collect::<Result<Vec<_>>>()?;

        Ok(Self { content, ..Default::default() })
    }
}

impl Display for RustDoc {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        for element in &self.content {
            match element {
                Element::Text(text) => writeln!(f, "{}", text.as_wrapped(self.line_width))?,
                Element::Section(Section { title, content }) => writeln!(f, "# {}\n\n{}\n", title, content.as_wrapped(self.line_width))?,
                Element::Flag(_) => {}
            }
        }
        Ok(())
    }
}

