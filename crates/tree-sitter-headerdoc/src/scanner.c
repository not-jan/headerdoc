#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"
#include <wctype.h>
#include <stdio.h>

enum TokenType {
  TAG_CONTENT,
  SIMPLE_LINE,
  MULTILINE_BEGIN,
  SIMPLE_MULTILINE_BEGIN,
  NEW_LINE
};

struct Scanner {

};


static bool scan_tag_content(TSLexer* lexer) {
  bool did_capture = false;

  // EOF is our absolute bound, that should probably never be reached anyway!
  while(!lexer->eof(lexer)) {

    // We might be encountering one of those dreadful new line constructs
    if(lexer->lookahead == '\n') {
      if (did_capture) {
        lexer->mark_end(lexer);
        lexer->result_symbol = TAG_CONTENT;
        return true;
      } else {
        return false;
      }
    }

    if(lexer->lookahead == '*') {
        lexer->mark_end(lexer);
        lexer->advance(lexer, false);

        if(lexer->lookahead == '/') {
           if(did_capture) {
             lexer->result_symbol = TAG_CONTENT;
             return true;
           } else {
             return false;
           }
        }
    }

    if(lexer->lookahead == '@') {
      lexer->mark_end(lexer);
      lexer->advance(lexer, false);

      if (lexer->lookahead == '@') {
        // We got an escape sequence
        lexer->advance(lexer, false);
      } else {
        if(did_capture) {
            lexer->result_symbol = TAG_CONTENT;
            return true;
        } else {
          return false;
        }

      }
    }
    if(!iswspace(lexer->lookahead)) {
      did_capture = true;
    }

    lexer->advance(lexer, false);
  }
  return false;
}


void *tree_sitter_headerdoc_external_scanner_create(void) {
  return NULL;
}

void tree_sitter_headerdoc_external_scanner_destroy(void *payload) {
  (payload);
}

unsigned tree_sitter_headerdoc_external_scanner_serialize(
  void *payload,
  char *buffer
) {
  return 0;
}

void tree_sitter_headerdoc_external_scanner_deserialize(
  void *payload,
  const char *buffer,
  unsigned length
) {
  // ...
}

static bool scan_multiline(TSLexer *lexer) {
  if(lexer->eof(lexer) || lexer->lookahead != '/') {
    return false;
  }

  lexer->advance(lexer, false);

  if(lexer->eof(lexer) || lexer->lookahead != '*') {
    return false;
  }

  lexer->advance(lexer, false);

  if(lexer->eof(lexer)) {
    return false;
  }

  if (lexer->lookahead == '*') {
    lexer->mark_end(lexer);
    lexer->advance(lexer, false);

    if(lexer->eof(lexer)) {
      return false;
    }

    if(lexer->lookahead == '/') {
      lexer->result_symbol = SIMPLE_MULTILINE_BEGIN;
    } else {
      lexer->mark_end(lexer);
      lexer->result_symbol = MULTILINE_BEGIN;
    }

    return true;
  } else if (lexer->lookahead == '!') {
    lexer->advance(lexer, false);
    lexer->result_symbol = MULTILINE_BEGIN;
    return true;
  } else {
    lexer->result_symbol = SIMPLE_MULTILINE_BEGIN;
    return true;
  }
  return false;
}

static bool scan_simple_line(TSLexer *lexer) {
    bool did_capture = false;

    while(!lexer->eof(lexer) && lexer->lookahead != '*') {
        did_capture = true;
        lexer->advance(lexer, false);
    }

    if(lexer->lookahead == '*') {
        lexer->mark_end(lexer);
        lexer->advance(lexer, false);
        if(lexer->lookahead == '/') {
            lexer->result_symbol = SIMPLE_LINE;
            return did_capture;
        }
    }

    return false;

}

static bool scan_new_line(TSLexer *lexer) {
    if(lexer->lookahead != '\n') {
      return false;
    }

    lexer->mark_end(lexer);
    lexer->advance(lexer, false);

    while(!lexer->eof(lexer) && (lexer->lookahead == ' ' || lexer->lookahead == '\t')) {
      lexer->advance(lexer, false);
    }

    if(lexer->eof(lexer)) {
      return false;
    }

    lexer->mark_end(lexer);

    if(lexer->lookahead == '*') {
      lexer->advance(lexer, false);

      if(lexer->lookahead == '/') {
        lexer->result_symbol = NEW_LINE;
        return true;
      }

      while(!lexer->eof(lexer) && (lexer->lookahead == ' ' || lexer->lookahead == '\t')) {
        lexer->advance(lexer, false);
      }

      lexer->mark_end(lexer);
      lexer->result_symbol = NEW_LINE;
      return true;
    }

    lexer->result_symbol = NEW_LINE;
    return true;
}

static bool my_tree_sitter_headerdoc_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  if (lexer->eof(lexer)) {
    return false;
  }

  if(lexer->lookahead == '/' && (valid_symbols[MULTILINE_BEGIN] || valid_symbols[SIMPLE_MULTILINE_BEGIN])) {
    return scan_multiline(lexer);
  } else if (lexer->lookahead == '\n' && valid_symbols[NEW_LINE]) {
    return scan_new_line(lexer);
  } else if (valid_symbols[TAG_CONTENT]) {
    return scan_tag_content(lexer);
  } else if (valid_symbols[SIMPLE_LINE]) {
    return scan_simple_line(lexer);
  }

  return false;
}

static const char* token_to_str(enum TokenType itoken) {
    const char* token = 0;

    switch(itoken) {
      case TAG_CONTENT: {
        token = "TAG_CONTENT";
        break;
      }
      case MULTILINE_BEGIN: {
        token = "MULTILINE_BEGIN";
        break;
      }
      case SIMPLE_MULTILINE_BEGIN: {
        token = "SIMPLE_MULTILINE_BEGIN";
        break;
      }
      case SIMPLE_LINE: {
        token = "SIMPLE_LINE";
        break;
      }
      case NEW_LINE: {
        token = "NEW_LINE";
        break;
      }
      default: {
        token = "UNKNOWN";
        break;
      }
    }
    return token;
}

bool tree_sitter_headerdoc_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  puts("Expected tokens:");
  for(int i = TAG_CONTENT; i <= NEW_LINE; i++) {
    if(valid_symbols[i]) {
      printf("- %s\n", token_to_str(i));
    }
  }
  bool result = my_tree_sitter_headerdoc_external_scanner_scan(payload, lexer, valid_symbols);

  if (result) {
    const char* token = token_to_str(lexer->result_symbol);
    printf("Recognized token: %s\n", token);
  }
  return result;
}