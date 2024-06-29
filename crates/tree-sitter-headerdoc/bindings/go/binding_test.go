package tree_sitter_headerdoc_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-headerdoc"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_headerdoc.Language())
	if language == nil {
		t.Errorf("Error loading Headerdoc grammar")
	}
}
