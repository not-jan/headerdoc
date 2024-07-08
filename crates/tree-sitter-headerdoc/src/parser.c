#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 46
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 32
#define ALIAS_COUNT 0
#define TOKEN_COUNT 15
#define EXTERNAL_TOKEN_COUNT 5
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 4

enum ts_symbol_identifiers {
  sym__singleline_begin = 1,
  sym__simple_singleline_begin = 2,
  sym__multiline_end = 3,
  aux_sym__simple_singleline_token1 = 4,
  sym_tag_name = 5,
  sym_inline_tag_name = 6,
  aux_sym_inline_tag_token1 = 7,
  sym_inline_tag_value = 8,
  aux_sym__whitespace_token1 = 9,
  sym__tag_content = 10,
  sym__simple_line = 11,
  sym__multiline_begin = 12,
  sym__simple_multiline_begin = 13,
  sym__new_line = 14,
  sym_document = 15,
  sym__multiline = 16,
  sym__simple_singleline = 17,
  sym__simple_multiline = 18,
  sym__singleline = 19,
  sym_block_tag = 20,
  sym__text = 21,
  sym_raw_tag_content = 22,
  sym_flag_tag = 23,
  sym_tag_content = 24,
  sym_inline_tag = 25,
  aux_sym_document_repeat1 = 26,
  aux_sym__multiline_repeat1 = 27,
  aux_sym__simple_multiline_repeat1 = 28,
  aux_sym__singleline_repeat1 = 29,
  aux_sym__text_repeat1 = 30,
  aux_sym_tag_content_repeat1 = 31,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__singleline_begin] = "_singleline_begin",
  [sym__simple_singleline_begin] = "_simple_singleline_begin",
  [sym__multiline_end] = "_multiline_end",
  [aux_sym__simple_singleline_token1] = "text",
  [sym_tag_name] = "tag_name",
  [sym_inline_tag_name] = "inline_tag_name",
  [aux_sym_inline_tag_token1] = "inline_tag_token1",
  [sym_inline_tag_value] = "raw_tag_content",
  [aux_sym__whitespace_token1] = "_whitespace_token1",
  [sym__tag_content] = "_tag_content",
  [sym__simple_line] = "_simple_line",
  [sym__multiline_begin] = "_multiline_begin",
  [sym__simple_multiline_begin] = "_simple_multiline_begin",
  [sym__new_line] = "_new_line",
  [sym_document] = "document",
  [sym__multiline] = "_multiline",
  [sym__simple_singleline] = "_simple_singleline",
  [sym__simple_multiline] = "_simple_multiline",
  [sym__singleline] = "_singleline",
  [sym_block_tag] = "block_tag",
  [sym__text] = "_text",
  [sym_raw_tag_content] = "raw_tag_content",
  [sym_flag_tag] = "flag_tag",
  [sym_tag_content] = "tag_content",
  [sym_inline_tag] = "inline_tag",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym__multiline_repeat1] = "_multiline_repeat1",
  [aux_sym__simple_multiline_repeat1] = "_simple_multiline_repeat1",
  [aux_sym__singleline_repeat1] = "_singleline_repeat1",
  [aux_sym__text_repeat1] = "_text_repeat1",
  [aux_sym_tag_content_repeat1] = "tag_content_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__singleline_begin] = sym__singleline_begin,
  [sym__simple_singleline_begin] = sym__simple_singleline_begin,
  [sym__multiline_end] = sym__multiline_end,
  [aux_sym__simple_singleline_token1] = aux_sym__simple_singleline_token1,
  [sym_tag_name] = sym_tag_name,
  [sym_inline_tag_name] = sym_inline_tag_name,
  [aux_sym_inline_tag_token1] = aux_sym_inline_tag_token1,
  [sym_inline_tag_value] = sym_raw_tag_content,
  [aux_sym__whitespace_token1] = aux_sym__whitespace_token1,
  [sym__tag_content] = sym__tag_content,
  [sym__simple_line] = sym__simple_line,
  [sym__multiline_begin] = sym__multiline_begin,
  [sym__simple_multiline_begin] = sym__simple_multiline_begin,
  [sym__new_line] = sym__new_line,
  [sym_document] = sym_document,
  [sym__multiline] = sym__multiline,
  [sym__simple_singleline] = sym__simple_singleline,
  [sym__simple_multiline] = sym__simple_multiline,
  [sym__singleline] = sym__singleline,
  [sym_block_tag] = sym_block_tag,
  [sym__text] = sym__text,
  [sym_raw_tag_content] = sym_raw_tag_content,
  [sym_flag_tag] = sym_flag_tag,
  [sym_tag_content] = sym_tag_content,
  [sym_inline_tag] = sym_inline_tag,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym__multiline_repeat1] = aux_sym__multiline_repeat1,
  [aux_sym__simple_multiline_repeat1] = aux_sym__simple_multiline_repeat1,
  [aux_sym__singleline_repeat1] = aux_sym__singleline_repeat1,
  [aux_sym__text_repeat1] = aux_sym__text_repeat1,
  [aux_sym_tag_content_repeat1] = aux_sym_tag_content_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__singleline_begin] = {
    .visible = false,
    .named = true,
  },
  [sym__simple_singleline_begin] = {
    .visible = false,
    .named = true,
  },
  [sym__multiline_end] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__simple_singleline_token1] = {
    .visible = true,
    .named = true,
  },
  [sym_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym_inline_tag_name] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_inline_tag_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_inline_tag_value] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__whitespace_token1] = {
    .visible = false,
    .named = false,
  },
  [sym__tag_content] = {
    .visible = false,
    .named = true,
  },
  [sym__simple_line] = {
    .visible = false,
    .named = true,
  },
  [sym__multiline_begin] = {
    .visible = false,
    .named = true,
  },
  [sym__simple_multiline_begin] = {
    .visible = false,
    .named = true,
  },
  [sym__new_line] = {
    .visible = false,
    .named = true,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym__multiline] = {
    .visible = false,
    .named = true,
  },
  [sym__simple_singleline] = {
    .visible = false,
    .named = true,
  },
  [sym__simple_multiline] = {
    .visible = false,
    .named = true,
  },
  [sym__singleline] = {
    .visible = false,
    .named = true,
  },
  [sym_block_tag] = {
    .visible = true,
    .named = true,
  },
  [sym__text] = {
    .visible = false,
    .named = true,
  },
  [sym_raw_tag_content] = {
    .visible = true,
    .named = true,
  },
  [sym_flag_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_tag_content] = {
    .visible = true,
    .named = true,
  },
  [sym_inline_tag] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__multiline_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__simple_multiline_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__singleline_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__text_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_tag_content_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_name = 1,
  field_value = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_name] = "name",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [3] = {.index = 2, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 0},
    {field_value, 1},
  [2] =
    {field_name, 0},
    {field_value, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [2] = {
    [1] = aux_sym__simple_singleline_token1,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  aux_sym__simple_multiline_repeat1, 2,
    aux_sym__simple_multiline_repeat1,
    aux_sym__simple_singleline_token1,
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 3,
  [12] = 4,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 6,
  [21] = 7,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 14,
  [35] = 35,
  [36] = 36,
  [37] = 15,
  [38] = 22,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 41,
  [45] = 40,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(55);
      if (lookahead == '*') ADVANCE(1);
      if (lookahead == '/') SKIP(51);
      if (lookahead == '@') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(68);
      END_STATE();
    case 1:
      if (lookahead == '/') ADVANCE(58);
      END_STATE();
    case 2:
      if (lookahead == '/') ADVANCE(57);
      END_STATE();
    case 3:
      if (lookahead == '/') ADVANCE(69);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(71);
      if (lookahead != 0) ADVANCE(70);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        'a', 66,
        'b', 67,
        'c', 65,
        'd', 16,
        'e', 22,
        'l', 15,
        'n', 26,
        'p', 30,
        'r', 9,
        's', 12,
      );
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(7);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(32);
      END_STATE();
    case 7:
      if (lookahead == 'c') ADVANCE(39);
      END_STATE();
    case 8:
      if (lookahead == 'c') ADVANCE(44);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(23);
      END_STATE();
    case 10:
      if (lookahead == 'e') ADVANCE(64);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(14);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(10);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(34);
      END_STATE();
    case 14:
      if (lookahead == 'f') ADVANCE(64);
      END_STATE();
    case 15:
      if (lookahead == 'i') ADVANCE(24);
      END_STATE();
    case 16:
      if (lookahead == 'i') ADVANCE(35);
      END_STATE();
    case 17:
      if (lookahead == 'i') ADVANCE(28);
      END_STATE();
    case 18:
      if (lookahead == 'i') ADVANCE(11);
      END_STATE();
    case 19:
      if (lookahead == 'k') ADVANCE(65);
      END_STATE();
    case 20:
      if (lookahead == 'k') ADVANCE(64);
      END_STATE();
    case 21:
      if (lookahead == 'l') ADVANCE(39);
      END_STATE();
    case 22:
      if (lookahead == 'm') ADVANCE(65);
      END_STATE();
    case 23:
      if (lookahead == 'm') ADVANCE(6);
      if (lookahead == 's') ADVANCE(43);
      if (lookahead == 't') ADVANCE(45);
      END_STATE();
    case 24:
      if (lookahead == 'n') ADVANCE(19);
      END_STATE();
    case 25:
      if (lookahead == 'n') ADVANCE(64);
      END_STATE();
    case 26:
      if (lookahead == 'o') ADVANCE(42);
      END_STATE();
    case 27:
      if (lookahead == 'o') ADVANCE(29);
      END_STATE();
    case 28:
      if (lookahead == 'o') ADVANCE(25);
      END_STATE();
    case 29:
      if (lookahead == 'p') ADVANCE(13);
      END_STATE();
    case 30:
      if (lookahead == 'r') ADVANCE(27);
      END_STATE();
    case 31:
      if (lookahead == 'r') ADVANCE(25);
      END_STATE();
    case 32:
      if (lookahead == 'r') ADVANCE(20);
      END_STATE();
    case 33:
      if (lookahead == 'r') ADVANCE(5);
      END_STATE();
    case 34:
      if (lookahead == 'r') ADVANCE(40);
      END_STATE();
    case 35:
      if (lookahead == 's') ADVANCE(8);
      END_STATE();
    case 36:
      if (lookahead == 's') ADVANCE(41);
      END_STATE();
    case 37:
      if (lookahead == 's') ADVANCE(17);
      END_STATE();
    case 38:
      if (lookahead == 's') ADVANCE(37);
      END_STATE();
    case 39:
      if (lookahead == 't') ADVANCE(64);
      END_STATE();
    case 40:
      if (lookahead == 't') ADVANCE(46);
      END_STATE();
    case 41:
      if (lookahead == 't') ADVANCE(33);
      END_STATE();
    case 42:
      if (lookahead == 't') ADVANCE(10);
      END_STATE();
    case 43:
      if (lookahead == 'u') ADVANCE(21);
      END_STATE();
    case 44:
      if (lookahead == 'u') ADVANCE(38);
      END_STATE();
    case 45:
      if (lookahead == 'u') ADVANCE(31);
      END_STATE();
    case 46:
      if (lookahead == 'y') ADVANCE(64);
      END_STATE();
    case 47:
      if (eof) ADVANCE(55);
      if (lookahead == '*') ADVANCE(1);
      if (lookahead == '/') SKIP(53);
      if (lookahead == '@') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(71);
      END_STATE();
    case 48:
      if (eof) ADVANCE(55);
      if (lookahead == '/') SKIP(51);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(68);
      END_STATE();
    case 49:
      if (eof) ADVANCE(55);
      if (lookahead == '/') SKIP(48);
      END_STATE();
    case 50:
      if (eof) ADVANCE(55);
      if (lookahead == '/') ADVANCE(2);
      if (lookahead == '@') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(71);
      END_STATE();
    case 51:
      if (eof) ADVANCE(55);
      if (lookahead == '/') SKIP(49);
      END_STATE();
    case 52:
      if (eof) ADVANCE(55);
      if (lookahead == '/') SKIP(54);
      END_STATE();
    case 53:
      if (eof) ADVANCE(55);
      if (lookahead == '/') SKIP(52);
      END_STATE();
    case 54:
      if (eof) ADVANCE(55);
      if (lookahead == '/') SKIP(53);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(71);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym__singleline_begin);
      if (lookahead == '/') ADVANCE(2);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym__simple_singleline_begin);
      if (lookahead == '/') ADVANCE(56);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym__multiline_end);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym__simple_singleline_token1);
      if (lookahead == '\n') ADVANCE(71);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(59);
      if (lookahead != 0) ADVANCE(63);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym__simple_singleline_token1);
      if (lookahead == '/') ADVANCE(61);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(63);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym__simple_singleline_token1);
      if (lookahead == '/') ADVANCE(62);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(59);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(63);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym__simple_singleline_token1);
      if (lookahead == '/') ADVANCE(60);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(63);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym__simple_singleline_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(63);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_tag_name);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_inline_tag_name);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_inline_tag_name);
      if (lookahead == 'b') ADVANCE(36);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_inline_tag_name);
      if (lookahead == 'r') ADVANCE(18);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_inline_tag_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(71);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_inline_tag_value);
      if (lookahead == '/') ADVANCE(69);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(70);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_inline_tag_value);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(70);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(aux_sym__whitespace_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(71);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 50, .external_lex_state = 2},
  [2] = {.lex_state = 50, .external_lex_state = 3},
  [3] = {.lex_state = 50, .external_lex_state = 3},
  [4] = {.lex_state = 50, .external_lex_state = 3},
  [5] = {.lex_state = 47, .external_lex_state = 4},
  [6] = {.lex_state = 50, .external_lex_state = 3},
  [7] = {.lex_state = 50, .external_lex_state = 3},
  [8] = {.lex_state = 50, .external_lex_state = 2},
  [9] = {.lex_state = 50, .external_lex_state = 2},
  [10] = {.lex_state = 47, .external_lex_state = 4},
  [11] = {.lex_state = 47, .external_lex_state = 4},
  [12] = {.lex_state = 47, .external_lex_state = 4},
  [13] = {.lex_state = 50, .external_lex_state = 2},
  [14] = {.lex_state = 50, .external_lex_state = 3},
  [15] = {.lex_state = 50, .external_lex_state = 3},
  [16] = {.lex_state = 47, .external_lex_state = 4},
  [17] = {.lex_state = 50, .external_lex_state = 2},
  [18] = {.lex_state = 50, .external_lex_state = 2},
  [19] = {.lex_state = 50, .external_lex_state = 2},
  [20] = {.lex_state = 47, .external_lex_state = 4},
  [21] = {.lex_state = 47, .external_lex_state = 4},
  [22] = {.lex_state = 50, .external_lex_state = 2},
  [23] = {.lex_state = 50, .external_lex_state = 2},
  [24] = {.lex_state = 47, .external_lex_state = 5},
  [25] = {.lex_state = 50, .external_lex_state = 2},
  [26] = {.lex_state = 50, .external_lex_state = 2},
  [27] = {.lex_state = 50, .external_lex_state = 2},
  [28] = {.lex_state = 47, .external_lex_state = 5},
  [29] = {.lex_state = 47, .external_lex_state = 5},
  [30] = {.lex_state = 47, .external_lex_state = 5},
  [31] = {.lex_state = 50, .external_lex_state = 2},
  [32] = {.lex_state = 50, .external_lex_state = 2},
  [33] = {.lex_state = 47, .external_lex_state = 4},
  [34] = {.lex_state = 47, .external_lex_state = 4},
  [35] = {.lex_state = 47, .external_lex_state = 4},
  [36] = {.lex_state = 47, .external_lex_state = 4},
  [37] = {.lex_state = 47, .external_lex_state = 4},
  [38] = {.lex_state = 47, .external_lex_state = 5},
  [39] = {.lex_state = 47, .external_lex_state = 4},
  [40] = {.lex_state = 0, .external_lex_state = 5},
  [41] = {.lex_state = 3, .external_lex_state = 5},
  [42] = {.lex_state = 47, .external_lex_state = 5},
  [43] = {.lex_state = 61, .external_lex_state = 5},
  [44] = {.lex_state = 3, .external_lex_state = 5},
  [45] = {.lex_state = 0, .external_lex_state = 5},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__multiline_end] = ACTIONS(1),
    [sym_tag_name] = ACTIONS(1),
    [sym_inline_tag_name] = ACTIONS(1),
    [aux_sym_inline_tag_token1] = ACTIONS(1),
    [aux_sym__whitespace_token1] = ACTIONS(3),
    [sym__tag_content] = ACTIONS(1),
    [sym__simple_line] = ACTIONS(1),
    [sym__multiline_begin] = ACTIONS(1),
    [sym__simple_multiline_begin] = ACTIONS(1),
    [sym__new_line] = ACTIONS(5),
  },
  [1] = {
    [sym_document] = STATE(42),
    [sym__multiline] = STATE(9),
    [sym__simple_singleline] = STATE(9),
    [sym__simple_multiline] = STATE(9),
    [sym__singleline] = STATE(9),
    [aux_sym_document_repeat1] = STATE(9),
    [sym__singleline_begin] = ACTIONS(7),
    [sym__simple_singleline_begin] = ACTIONS(9),
    [aux_sym__whitespace_token1] = ACTIONS(3),
    [sym__multiline_begin] = ACTIONS(11),
    [sym__simple_multiline_begin] = ACTIONS(13),
    [sym__new_line] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 10,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(19), 1,
      sym_tag_name,
    ACTIONS(21), 1,
      sym_inline_tag_name,
    ACTIONS(23), 1,
      sym__tag_content,
    STATE(17), 1,
      sym__text,
    ACTIONS(17), 2,
      sym__singleline_begin,
      sym__simple_singleline_begin,
    STATE(18), 2,
      sym_block_tag,
      aux_sym__singleline_repeat1,
    ACTIONS(15), 3,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
    STATE(7), 3,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym__text_repeat1,
  [37] = 7,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(29), 1,
      sym_inline_tag_name,
    ACTIONS(32), 1,
      sym__tag_content,
    ACTIONS(27), 2,
      sym__singleline_begin,
      sym__simple_singleline_begin,
    ACTIONS(25), 4,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym_tag_name,
    STATE(3), 5,
      sym__text,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym__text_repeat1,
      aux_sym_tag_content_repeat1,
  [67] = 7,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(21), 1,
      sym_inline_tag_name,
    ACTIONS(23), 1,
      sym__tag_content,
    ACTIONS(37), 2,
      sym__singleline_begin,
      sym__simple_singleline_begin,
    ACTIONS(35), 4,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym_tag_name,
    STATE(3), 5,
      sym__text,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym__text_repeat1,
      aux_sym_tag_content_repeat1,
  [97] = 8,
    ACTIONS(39), 1,
      sym__multiline_end,
    ACTIONS(41), 1,
      sym_tag_name,
    ACTIONS(43), 1,
      sym_inline_tag_name,
    ACTIONS(45), 1,
      sym__tag_content,
    STATE(24), 1,
      sym__text,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(21), 3,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym__text_repeat1,
    STATE(30), 3,
      sym_block_tag,
      sym_flag_tag,
      aux_sym__multiline_repeat1,
  [127] = 7,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(51), 1,
      sym_inline_tag_name,
    ACTIONS(54), 1,
      sym__tag_content,
    ACTIONS(49), 2,
      sym__singleline_begin,
      sym__simple_singleline_begin,
    STATE(6), 3,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym__text_repeat1,
    ACTIONS(47), 4,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym_tag_name,
  [155] = 7,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(21), 1,
      sym_inline_tag_name,
    ACTIONS(23), 1,
      sym__tag_content,
    ACTIONS(59), 2,
      sym__singleline_begin,
      sym__simple_singleline_begin,
    STATE(6), 3,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym__text_repeat1,
    ACTIONS(57), 4,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym_tag_name,
  [183] = 8,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(61), 1,
      ts_builtin_sym_end,
    ACTIONS(63), 1,
      sym__singleline_begin,
    ACTIONS(66), 1,
      sym__simple_singleline_begin,
    ACTIONS(69), 1,
      sym__multiline_begin,
    ACTIONS(72), 1,
      sym__simple_multiline_begin,
    STATE(8), 5,
      sym__multiline,
      sym__simple_singleline,
      sym__simple_multiline,
      sym__singleline,
      aux_sym_document_repeat1,
  [212] = 8,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(7), 1,
      sym__singleline_begin,
    ACTIONS(9), 1,
      sym__simple_singleline_begin,
    ACTIONS(11), 1,
      sym__multiline_begin,
    ACTIONS(13), 1,
      sym__simple_multiline_begin,
    ACTIONS(75), 1,
      ts_builtin_sym_end,
    STATE(8), 5,
      sym__multiline,
      sym__simple_singleline,
      sym__simple_multiline,
      sym__singleline,
      aux_sym_document_repeat1,
  [241] = 6,
    ACTIONS(43), 1,
      sym_inline_tag_name,
    ACTIONS(45), 1,
      sym__tag_content,
    STATE(38), 1,
      sym_tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(77), 2,
      sym__multiline_end,
      sym_tag_name,
    STATE(12), 5,
      sym__text,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym__text_repeat1,
      aux_sym_tag_content_repeat1,
  [266] = 5,
    ACTIONS(79), 1,
      sym_inline_tag_name,
    ACTIONS(82), 1,
      sym__tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(25), 2,
      sym__multiline_end,
      sym_tag_name,
    STATE(11), 5,
      sym__text,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym__text_repeat1,
      aux_sym_tag_content_repeat1,
  [288] = 5,
    ACTIONS(43), 1,
      sym_inline_tag_name,
    ACTIONS(45), 1,
      sym__tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(35), 2,
      sym__multiline_end,
      sym_tag_name,
    STATE(11), 5,
      sym__text,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym__text_repeat1,
      aux_sym_tag_content_repeat1,
  [310] = 6,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(89), 1,
      sym_tag_name,
    ACTIONS(87), 2,
      sym__singleline_begin,
      sym__simple_singleline_begin,
    STATE(13), 2,
      sym_block_tag,
      aux_sym__singleline_repeat1,
    ACTIONS(85), 3,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
  [333] = 4,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(94), 3,
      sym__singleline_begin,
      sym__simple_singleline_begin,
      sym_inline_tag_name,
    ACTIONS(92), 5,
      sym__tag_content,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym_tag_name,
  [352] = 4,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(98), 3,
      sym__singleline_begin,
      sym__simple_singleline_begin,
      sym_inline_tag_name,
    ACTIONS(96), 5,
      sym__tag_content,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym_tag_name,
  [371] = 5,
    ACTIONS(23), 1,
      sym__tag_content,
    ACTIONS(100), 1,
      sym_inline_tag_name,
    STATE(22), 1,
      sym_tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(4), 5,
      sym__text,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym__text_repeat1,
      aux_sym_tag_content_repeat1,
  [392] = 6,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(19), 1,
      sym_tag_name,
    ACTIONS(104), 2,
      sym__singleline_begin,
      sym__simple_singleline_begin,
    STATE(19), 2,
      sym_block_tag,
      aux_sym__singleline_repeat1,
    ACTIONS(102), 3,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
  [415] = 6,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(19), 1,
      sym_tag_name,
    ACTIONS(104), 2,
      sym__singleline_begin,
      sym__simple_singleline_begin,
    STATE(13), 2,
      sym_block_tag,
      aux_sym__singleline_repeat1,
    ACTIONS(102), 3,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
  [438] = 6,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(19), 1,
      sym_tag_name,
    ACTIONS(108), 2,
      sym__singleline_begin,
      sym__simple_singleline_begin,
    STATE(13), 2,
      sym_block_tag,
      aux_sym__singleline_repeat1,
    ACTIONS(106), 3,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
  [461] = 5,
    ACTIONS(110), 1,
      sym_inline_tag_name,
    ACTIONS(113), 1,
      sym__tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(47), 2,
      sym__multiline_end,
      sym_tag_name,
    STATE(20), 3,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym__text_repeat1,
  [481] = 5,
    ACTIONS(43), 1,
      sym_inline_tag_name,
    ACTIONS(45), 1,
      sym__tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(57), 2,
      sym__multiline_end,
      sym_tag_name,
    STATE(20), 3,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym__text_repeat1,
  [501] = 4,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(118), 2,
      sym__singleline_begin,
      sym__simple_singleline_begin,
    ACTIONS(116), 4,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym_tag_name,
  [518] = 4,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(122), 2,
      sym__singleline_begin,
      sym__simple_singleline_begin,
    ACTIONS(120), 3,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
  [534] = 4,
    ACTIONS(41), 1,
      sym_tag_name,
    ACTIONS(124), 1,
      sym__multiline_end,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(28), 3,
      sym_block_tag,
      sym_flag_tag,
      aux_sym__multiline_repeat1,
  [550] = 4,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(128), 2,
      sym__singleline_begin,
      sym__simple_singleline_begin,
    ACTIONS(126), 3,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
  [566] = 4,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(132), 2,
      sym__singleline_begin,
      sym__simple_singleline_begin,
    ACTIONS(130), 3,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
  [582] = 4,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(136), 2,
      sym__singleline_begin,
      sym__simple_singleline_begin,
    ACTIONS(134), 3,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
  [598] = 4,
    ACTIONS(41), 1,
      sym_tag_name,
    ACTIONS(138), 1,
      sym__multiline_end,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(29), 3,
      sym_block_tag,
      sym_flag_tag,
      aux_sym__multiline_repeat1,
  [614] = 4,
    ACTIONS(140), 1,
      sym__multiline_end,
    ACTIONS(142), 1,
      sym_tag_name,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(29), 3,
      sym_block_tag,
      sym_flag_tag,
      aux_sym__multiline_repeat1,
  [630] = 4,
    ACTIONS(41), 1,
      sym_tag_name,
    ACTIONS(124), 1,
      sym__multiline_end,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(29), 3,
      sym_block_tag,
      sym_flag_tag,
      aux_sym__multiline_repeat1,
  [646] = 4,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(147), 2,
      sym__singleline_begin,
      sym__simple_singleline_begin,
    ACTIONS(145), 3,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
  [662] = 4,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(151), 2,
      sym__singleline_begin,
      sym__simple_singleline_begin,
    ACTIONS(149), 3,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
  [678] = 5,
    ACTIONS(45), 1,
      sym__tag_content,
    ACTIONS(153), 1,
      sym__multiline_end,
    STATE(36), 1,
      aux_sym__simple_multiline_repeat1,
    STATE(39), 1,
      sym_raw_tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
  [695] = 3,
    ACTIONS(94), 1,
      sym_inline_tag_name,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(92), 3,
      sym__tag_content,
      sym__multiline_end,
      sym_tag_name,
  [708] = 5,
    ACTIONS(45), 1,
      sym__tag_content,
    ACTIONS(155), 1,
      sym__multiline_end,
    STATE(33), 1,
      aux_sym__simple_multiline_repeat1,
    STATE(39), 1,
      sym_raw_tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
  [725] = 5,
    ACTIONS(157), 1,
      sym__multiline_end,
    ACTIONS(159), 1,
      sym__tag_content,
    STATE(36), 1,
      aux_sym__simple_multiline_repeat1,
    STATE(39), 1,
      sym_raw_tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
  [742] = 3,
    ACTIONS(98), 1,
      sym_inline_tag_name,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(96), 3,
      sym__tag_content,
      sym__multiline_end,
      sym_tag_name,
  [755] = 2,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(116), 2,
      sym__multiline_end,
      sym_tag_name,
  [764] = 2,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(162), 2,
      sym__tag_content,
      sym__multiline_end,
  [773] = 3,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(164), 1,
      aux_sym_inline_tag_token1,
  [783] = 3,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(166), 1,
      sym_inline_tag_value,
  [793] = 2,
    ACTIONS(168), 1,
      ts_builtin_sym_end,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
  [801] = 3,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(170), 1,
      aux_sym__simple_singleline_token1,
  [811] = 3,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(172), 1,
      sym_inline_tag_value,
  [821] = 3,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(174), 1,
      aux_sym_inline_tag_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 37,
  [SMALL_STATE(4)] = 67,
  [SMALL_STATE(5)] = 97,
  [SMALL_STATE(6)] = 127,
  [SMALL_STATE(7)] = 155,
  [SMALL_STATE(8)] = 183,
  [SMALL_STATE(9)] = 212,
  [SMALL_STATE(10)] = 241,
  [SMALL_STATE(11)] = 266,
  [SMALL_STATE(12)] = 288,
  [SMALL_STATE(13)] = 310,
  [SMALL_STATE(14)] = 333,
  [SMALL_STATE(15)] = 352,
  [SMALL_STATE(16)] = 371,
  [SMALL_STATE(17)] = 392,
  [SMALL_STATE(18)] = 415,
  [SMALL_STATE(19)] = 438,
  [SMALL_STATE(20)] = 461,
  [SMALL_STATE(21)] = 481,
  [SMALL_STATE(22)] = 501,
  [SMALL_STATE(23)] = 518,
  [SMALL_STATE(24)] = 534,
  [SMALL_STATE(25)] = 550,
  [SMALL_STATE(26)] = 566,
  [SMALL_STATE(27)] = 582,
  [SMALL_STATE(28)] = 598,
  [SMALL_STATE(29)] = 614,
  [SMALL_STATE(30)] = 630,
  [SMALL_STATE(31)] = 646,
  [SMALL_STATE(32)] = 662,
  [SMALL_STATE(33)] = 678,
  [SMALL_STATE(34)] = 695,
  [SMALL_STATE(35)] = 708,
  [SMALL_STATE(36)] = 725,
  [SMALL_STATE(37)] = 742,
  [SMALL_STATE(38)] = 755,
  [SMALL_STATE(39)] = 764,
  [SMALL_STATE(40)] = 773,
  [SMALL_STATE(41)] = 783,
  [SMALL_STATE(42)] = 793,
  [SMALL_STATE(43)] = 801,
  [SMALL_STATE(44)] = 811,
  [SMALL_STATE(45)] = 821,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__singleline, 1, 0, 0),
  [17] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__singleline, 1, 0, 0),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tag_content_repeat1, 2, 0, 0),
  [27] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_tag_content_repeat1, 2, 0, 0),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_tag_content_repeat1, 2, 0, 0), SHIFT_REPEAT(45),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_tag_content_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag_content, 1, 0, 0),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag_content, 1, 0, 0),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__text_repeat1, 2, 0, 0),
  [49] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__text_repeat1, 2, 0, 0),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__text_repeat1, 2, 0, 0), SHIFT_REPEAT(45),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__text_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__text, 1, 0, 0),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__text, 1, 0, 0),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(43),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(35),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag_tag, 1, 0, 0),
  [79] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_tag_content_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [82] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_tag_content_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__singleline_repeat1, 2, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__singleline_repeat1, 2, 0, 0),
  [89] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__singleline_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_tag, 3, 0, 3),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_tag, 3, 0, 3),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_raw_tag_content, 1, 0, 0),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_raw_tag_content, 1, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__singleline, 2, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__singleline, 2, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__singleline, 3, 0, 0),
  [108] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__singleline, 3, 0, 0),
  [110] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__text_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [113] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__text_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_tag, 2, 0, 1),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_tag, 2, 0, 1),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__simple_multiline, 3, 0, 2),
  [122] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__simple_multiline, 3, 0, 2),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__multiline, 2, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__multiline, 2, 0, 0),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__simple_singleline, 2, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__simple_singleline, 2, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__multiline, 3, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__multiline, 3, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__multiline_repeat1, 2, 0, 0),
  [142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__multiline_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__multiline, 4, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__multiline, 4, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__simple_multiline, 2, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__simple_multiline, 2, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__simple_multiline_repeat1, 2, 0, 0),
  [159] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__simple_multiline_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__simple_multiline_repeat1, 1, 0, 0),
  [164] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [168] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [170] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [174] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__tag_content = 0,
  ts_external_token__simple_line = 1,
  ts_external_token__multiline_begin = 2,
  ts_external_token__simple_multiline_begin = 3,
  ts_external_token__new_line = 4,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__tag_content] = sym__tag_content,
  [ts_external_token__simple_line] = sym__simple_line,
  [ts_external_token__multiline_begin] = sym__multiline_begin,
  [ts_external_token__simple_multiline_begin] = sym__simple_multiline_begin,
  [ts_external_token__new_line] = sym__new_line,
};

static const bool ts_external_scanner_states[6][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__tag_content] = true,
    [ts_external_token__simple_line] = true,
    [ts_external_token__multiline_begin] = true,
    [ts_external_token__simple_multiline_begin] = true,
    [ts_external_token__new_line] = true,
  },
  [2] = {
    [ts_external_token__multiline_begin] = true,
    [ts_external_token__simple_multiline_begin] = true,
    [ts_external_token__new_line] = true,
  },
  [3] = {
    [ts_external_token__tag_content] = true,
    [ts_external_token__multiline_begin] = true,
    [ts_external_token__simple_multiline_begin] = true,
    [ts_external_token__new_line] = true,
  },
  [4] = {
    [ts_external_token__tag_content] = true,
    [ts_external_token__new_line] = true,
  },
  [5] = {
    [ts_external_token__new_line] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_headerdoc_external_scanner_create(void);
void tree_sitter_headerdoc_external_scanner_destroy(void *);
bool tree_sitter_headerdoc_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_headerdoc_external_scanner_serialize(void *, char *);
void tree_sitter_headerdoc_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_headerdoc(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_headerdoc_external_scanner_create,
      tree_sitter_headerdoc_external_scanner_destroy,
      tree_sitter_headerdoc_external_scanner_scan,
      tree_sitter_headerdoc_external_scanner_serialize,
      tree_sitter_headerdoc_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
