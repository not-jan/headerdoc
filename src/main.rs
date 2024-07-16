use crate::nodes::{FromNode, HeaderDoc};
use anyhow::Result;
use log::{error, info, warn};
use std::io::ErrorKind;
use std::path::PathBuf;
use tree_sitter::Parser;

mod nodes;
mod rustdoc;

fn main() -> Result<()> {
    env_logger::init();
    let mut parser = Parser::new();
    parser
        .set_language(&tree_sitter_headerdoc::language())
        .expect("Error loading HeaderDoc grammar");

    parser.set_logger(Some(Box::new(move |ty, msg| {
        info!("[{ty:?}] {msg}");
    })));

    let count = std::fs::read_dir("./crates/tree-sitter-headerdoc/assets")?.count();

    for i in 0..count {
        parser.reset();
        parser.set_timeout_micros(1000);

        let path = PathBuf::from(format!("./crates/tree-sitter-headerdoc/assets/{i}.comment"));

        let data = match std::fs::read(&path) {
            Ok(data) => data,
            Err(err) if err.kind() == ErrorKind::NotFound => {
                warn!("could not find path {path:?}");
                continue;
            }
            Err(err) => Err(err)?,
        };

        match parser.parse(&data, None) {
            None => {
                error!("Failed to parse: {path:?}!");
            }
            Some(tree) => {
                let root = tree.root_node();
                match HeaderDoc::from_node(root, &data) {
                    Ok(_) => {}
                    Err(e) => {
                        error!("Failed to convert syntax tree to HeaderDoc in {path:?}: {e}");
                        break;
                    }
                }
                print!("\r{i}/{count}");
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
        parser
            .set_language(&tree_sitter_headerdoc::language())
            .expect("Error loading HeaderDoc grammar");
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
