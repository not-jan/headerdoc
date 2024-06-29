#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 40
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 31
#define ALIAS_COUNT 0
#define TOKEN_COUNT 15
#define EXTERNAL_TOKEN_COUNT 5
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 4

enum ts_symbol_identifiers {
  sym__singleline_begin = 1,
  sym__simple_singleline_begin = 2,
  anon_sym_STAR_SLASH = 3,
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
  sym__multiline_end = 16,
  sym__multiline = 17,
  sym__simple_singleline = 18,
  sym__simple_multiline = 19,
  sym__singleline = 20,
  sym_block_tag = 21,
  sym_text = 22,
  sym_raw_tag_content = 23,
  sym_tag_content = 24,
  sym_inline_tag = 25,
  aux_sym_document_repeat1 = 26,
  aux_sym__multiline_repeat1 = 27,
  aux_sym__simple_multiline_repeat1 = 28,
  aux_sym_text_repeat1 = 29,
  aux_sym_tag_content_repeat1 = 30,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__singleline_begin] = "_singleline_begin",
  [sym__simple_singleline_begin] = "_simple_singleline_begin",
  [anon_sym_STAR_SLASH] = "*/",
  [aux_sym__simple_singleline_token1] = "text",
  [sym_tag_name] = "tag_name",
  [sym_inline_tag_name] = "inline_tag_name",
  [aux_sym_inline_tag_token1] = "inline_tag_token1",
  [sym_inline_tag_value] = "inline_tag_value",
  [aux_sym__whitespace_token1] = "_whitespace_token1",
  [sym__tag_content] = "_tag_content",
  [sym__simple_line] = "_simple_line",
  [sym__multiline_begin] = "_multiline_begin",
  [sym__simple_multiline_begin] = "_simple_multiline_begin",
  [sym__new_line] = "_new_line",
  [sym_document] = "document",
  [sym__multiline_end] = "_multiline_end",
  [sym__multiline] = "_multiline",
  [sym__simple_singleline] = "_simple_singleline",
  [sym__simple_multiline] = "_simple_multiline",
  [sym__singleline] = "_singleline",
  [sym_block_tag] = "block_tag",
  [sym_text] = "text",
  [sym_raw_tag_content] = "raw_tag_content",
  [sym_tag_content] = "tag_content",
  [sym_inline_tag] = "inline_tag",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym__multiline_repeat1] = "_multiline_repeat1",
  [aux_sym__simple_multiline_repeat1] = "_simple_multiline_repeat1",
  [aux_sym_text_repeat1] = "text_repeat1",
  [aux_sym_tag_content_repeat1] = "tag_content_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__singleline_begin] = sym__singleline_begin,
  [sym__simple_singleline_begin] = sym__simple_singleline_begin,
  [anon_sym_STAR_SLASH] = anon_sym_STAR_SLASH,
  [aux_sym__simple_singleline_token1] = sym_text,
  [sym_tag_name] = sym_tag_name,
  [sym_inline_tag_name] = sym_inline_tag_name,
  [aux_sym_inline_tag_token1] = aux_sym_inline_tag_token1,
  [sym_inline_tag_value] = sym_inline_tag_value,
  [aux_sym__whitespace_token1] = aux_sym__whitespace_token1,
  [sym__tag_content] = sym__tag_content,
  [sym__simple_line] = sym__simple_line,
  [sym__multiline_begin] = sym__multiline_begin,
  [sym__simple_multiline_begin] = sym__simple_multiline_begin,
  [sym__new_line] = sym__new_line,
  [sym_document] = sym_document,
  [sym__multiline_end] = sym__multiline_end,
  [sym__multiline] = sym__multiline,
  [sym__simple_singleline] = sym__simple_singleline,
  [sym__simple_multiline] = sym__simple_multiline,
  [sym__singleline] = sym__singleline,
  [sym_block_tag] = sym_block_tag,
  [sym_text] = sym_text,
  [sym_raw_tag_content] = sym_raw_tag_content,
  [sym_tag_content] = sym_tag_content,
  [sym_inline_tag] = sym_inline_tag,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym__multiline_repeat1] = aux_sym__multiline_repeat1,
  [aux_sym__simple_multiline_repeat1] = aux_sym__simple_multiline_repeat1,
  [aux_sym_text_repeat1] = aux_sym_text_repeat1,
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
  [anon_sym_STAR_SLASH] = {
    .visible = true,
    .named = false,
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
  [sym__multiline_end] = {
    .visible = false,
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
  [sym_text] = {
    .visible = true,
    .named = true,
  },
  [sym_raw_tag_content] = {
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
  [aux_sym_text_repeat1] = {
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
    [1] = sym_text,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  aux_sym__simple_multiline_repeat1, 2,
    aux_sym__simple_multiline_repeat1,
    sym_text,
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
  [10] = 5,
  [11] = 11,
  [12] = 12,
  [13] = 5,
  [14] = 4,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 11,
  [31] = 12,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 37,
  [39] = 36,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(28);
      if (lookahead == '*') ADVANCE(1);
      if (lookahead == '/') ADVANCE(2);
      if (lookahead == '@') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(37);
      END_STATE();
    case 1:
      if (lookahead == '/') ADVANCE(31);
      END_STATE();
    case 2:
      if (lookahead == '/') ADVANCE(30);
      END_STATE();
    case 3:
      if (lookahead == 'a') ADVANCE(36);
      if (lookahead == 'd') ADVANCE(11);
      if (lookahead == 'e') ADVANCE(12);
      if (lookahead == 'r') ADVANCE(7);
      if (lookahead == 's') ADVANCE(9);
      if (lookahead == 'b' ||
          lookahead == 'c') ADVANCE(35);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(6);
      END_STATE();
    case 5:
      if (lookahead == 'c') ADVANCE(25);
      END_STATE();
    case 6:
      if (lookahead == 'c') ADVANCE(22);
      END_STATE();
    case 7:
      if (lookahead == 'e') ADVANCE(21);
      END_STATE();
    case 8:
      if (lookahead == 'e') ADVANCE(34);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(8);
      END_STATE();
    case 10:
      if (lookahead == 'i') ADVANCE(14);
      END_STATE();
    case 11:
      if (lookahead == 'i') ADVANCE(17);
      END_STATE();
    case 12:
      if (lookahead == 'm') ADVANCE(35);
      END_STATE();
    case 13:
      if (lookahead == 'n') ADVANCE(34);
      END_STATE();
    case 14:
      if (lookahead == 'o') ADVANCE(13);
      END_STATE();
    case 15:
      if (lookahead == 'r') ADVANCE(4);
      END_STATE();
    case 16:
      if (lookahead == 'r') ADVANCE(13);
      END_STATE();
    case 17:
      if (lookahead == 's') ADVANCE(5);
      END_STATE();
    case 18:
      if (lookahead == 's') ADVANCE(10);
      END_STATE();
    case 19:
      if (lookahead == 's') ADVANCE(23);
      END_STATE();
    case 20:
      if (lookahead == 's') ADVANCE(18);
      END_STATE();
    case 21:
      if (lookahead == 't') ADVANCE(24);
      END_STATE();
    case 22:
      if (lookahead == 't') ADVANCE(34);
      END_STATE();
    case 23:
      if (lookahead == 't') ADVANCE(15);
      END_STATE();
    case 24:
      if (lookahead == 'u') ADVANCE(16);
      END_STATE();
    case 25:
      if (lookahead == 'u') ADVANCE(20);
      END_STATE();
    case 26:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(39);
      if (lookahead != 0) ADVANCE(38);
      END_STATE();
    case 27:
      if (eof) ADVANCE(28);
      if (lookahead == '*') ADVANCE(1);
      if (lookahead == '/') ADVANCE(2);
      if (lookahead == '@') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(39);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym__singleline_begin);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym__simple_singleline_begin);
      if (lookahead == '/') ADVANCE(29);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym__simple_singleline_token1);
      if (lookahead == '\n') ADVANCE(39);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(32);
      if (lookahead != 0) ADVANCE(33);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym__simple_singleline_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(33);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_tag_name);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_inline_tag_name);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_inline_tag_name);
      if (lookahead == 'b') ADVANCE(19);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(aux_sym_inline_tag_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(39);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_inline_tag_value);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(38);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym__whitespace_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(39);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 27, .external_lex_state = 2},
  [2] = {.lex_state = 27, .external_lex_state = 3},
  [3] = {.lex_state = 27, .external_lex_state = 2},
  [4] = {.lex_state = 27, .external_lex_state = 4},
  [5] = {.lex_state = 27, .external_lex_state = 4},
  [6] = {.lex_state = 27, .external_lex_state = 2},
  [7] = {.lex_state = 27, .external_lex_state = 3},
  [8] = {.lex_state = 27, .external_lex_state = 3},
  [9] = {.lex_state = 27, .external_lex_state = 3},
  [10] = {.lex_state = 27, .external_lex_state = 3},
  [11] = {.lex_state = 27, .external_lex_state = 4},
  [12] = {.lex_state = 27, .external_lex_state = 4},
  [13] = {.lex_state = 27, .external_lex_state = 3},
  [14] = {.lex_state = 27, .external_lex_state = 3},
  [15] = {.lex_state = 27, .external_lex_state = 3},
  [16] = {.lex_state = 27, .external_lex_state = 2},
  [17] = {.lex_state = 27, .external_lex_state = 2},
  [18] = {.lex_state = 27, .external_lex_state = 3},
  [19] = {.lex_state = 27, .external_lex_state = 2},
  [20] = {.lex_state = 27, .external_lex_state = 2},
  [21] = {.lex_state = 27, .external_lex_state = 3},
  [22] = {.lex_state = 27, .external_lex_state = 2},
  [23] = {.lex_state = 27, .external_lex_state = 5},
  [24] = {.lex_state = 27, .external_lex_state = 2},
  [25] = {.lex_state = 27, .external_lex_state = 5},
  [26] = {.lex_state = 27, .external_lex_state = 5},
  [27] = {.lex_state = 27, .external_lex_state = 2},
  [28] = {.lex_state = 27, .external_lex_state = 5},
  [29] = {.lex_state = 27, .external_lex_state = 3},
  [30] = {.lex_state = 27, .external_lex_state = 3},
  [31] = {.lex_state = 27, .external_lex_state = 3},
  [32] = {.lex_state = 27, .external_lex_state = 5},
  [33] = {.lex_state = 27, .external_lex_state = 3},
  [34] = {.lex_state = 27, .external_lex_state = 5},
  [35] = {.lex_state = 32, .external_lex_state = 5},
  [36] = {.lex_state = 0, .external_lex_state = 5},
  [37] = {.lex_state = 26, .external_lex_state = 5},
  [38] = {.lex_state = 26, .external_lex_state = 5},
  [39] = {.lex_state = 0, .external_lex_state = 5},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__singleline_begin] = ACTIONS(1),
    [sym__simple_singleline_begin] = ACTIONS(1),
    [anon_sym_STAR_SLASH] = ACTIONS(1),
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
    [sym_document] = STATE(34),
    [sym__multiline] = STATE(3),
    [sym__simple_singleline] = STATE(3),
    [sym__simple_multiline] = STATE(3),
    [sym__singleline] = STATE(3),
    [aux_sym_document_repeat1] = STATE(3),
    [sym__singleline_begin] = ACTIONS(7),
    [sym__simple_singleline_begin] = ACTIONS(9),
    [aux_sym__whitespace_token1] = ACTIONS(5),
    [sym__multiline_begin] = ACTIONS(11),
    [sym__simple_multiline_begin] = ACTIONS(13),
    [sym__new_line] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(15), 1,
      anon_sym_STAR_SLASH,
    ACTIONS(17), 1,
      sym_tag_name,
    ACTIONS(19), 1,
      sym_inline_tag_name,
    ACTIONS(21), 1,
      sym__tag_content,
    STATE(22), 1,
      sym__multiline_end,
    STATE(23), 1,
      sym_text,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(26), 2,
      sym_block_tag,
      aux_sym__multiline_repeat1,
    STATE(13), 3,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym_text_repeat1,
  [32] = 7,
    ACTIONS(7), 1,
      sym__singleline_begin,
    ACTIONS(9), 1,
      sym__simple_singleline_begin,
    ACTIONS(11), 1,
      sym__multiline_begin,
    ACTIONS(13), 1,
      sym__simple_multiline_begin,
    ACTIONS(23), 1,
      ts_builtin_sym_end,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(6), 5,
      sym__multiline,
      sym__simple_singleline,
      sym__simple_multiline,
      sym__singleline,
      aux_sym_document_repeat1,
  [59] = 6,
    ACTIONS(27), 1,
      sym__simple_singleline_begin,
    ACTIONS(29), 1,
      sym_inline_tag_name,
    ACTIONS(32), 1,
      sym__tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(4), 3,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym_text_repeat1,
    ACTIONS(25), 4,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym__singleline_begin,
  [84] = 6,
    ACTIONS(37), 1,
      sym__simple_singleline_begin,
    ACTIONS(39), 1,
      sym_inline_tag_name,
    ACTIONS(41), 1,
      sym__tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(4), 3,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym_text_repeat1,
    ACTIONS(35), 4,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym__singleline_begin,
  [109] = 7,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
    ACTIONS(45), 1,
      sym__singleline_begin,
    ACTIONS(48), 1,
      sym__simple_singleline_begin,
    ACTIONS(51), 1,
      sym__multiline_begin,
    ACTIONS(54), 1,
      sym__simple_multiline_begin,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(6), 5,
      sym__multiline,
      sym__simple_singleline,
      sym__simple_multiline,
      sym__singleline,
      aux_sym_document_repeat1,
  [136] = 6,
    ACTIONS(59), 1,
      sym_inline_tag_name,
    ACTIONS(62), 1,
      sym__tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(57), 2,
      anon_sym_STAR_SLASH,
      sym_tag_name,
    STATE(7), 2,
      sym_text,
      aux_sym_tag_content_repeat1,
    STATE(10), 3,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym_text_repeat1,
  [160] = 6,
    ACTIONS(19), 1,
      sym_inline_tag_name,
    ACTIONS(21), 1,
      sym__tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(65), 2,
      anon_sym_STAR_SLASH,
      sym_tag_name,
    STATE(7), 2,
      sym_text,
      aux_sym_tag_content_repeat1,
    STATE(10), 3,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym_text_repeat1,
  [184] = 6,
    ACTIONS(21), 1,
      sym__tag_content,
    ACTIONS(67), 1,
      sym_inline_tag_name,
    STATE(32), 1,
      sym_tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(8), 2,
      sym_text,
      aux_sym_tag_content_repeat1,
    STATE(10), 3,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym_text_repeat1,
  [207] = 4,
    ACTIONS(37), 1,
      sym_inline_tag_name,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(35), 3,
      sym__tag_content,
      anon_sym_STAR_SLASH,
      sym_tag_name,
    STATE(14), 3,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym_text_repeat1,
  [225] = 3,
    ACTIONS(71), 1,
      sym__simple_singleline_begin,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(69), 6,
      sym__tag_content,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym__singleline_begin,
      sym_inline_tag_name,
  [241] = 3,
    ACTIONS(75), 1,
      sym__simple_singleline_begin,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(73), 6,
      sym__tag_content,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym__singleline_begin,
      sym_inline_tag_name,
  [257] = 5,
    ACTIONS(19), 1,
      sym_inline_tag_name,
    ACTIONS(21), 1,
      sym__tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(35), 2,
      anon_sym_STAR_SLASH,
      sym_tag_name,
    STATE(14), 3,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym_text_repeat1,
  [277] = 5,
    ACTIONS(77), 1,
      sym_inline_tag_name,
    ACTIONS(80), 1,
      sym__tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(25), 2,
      anon_sym_STAR_SLASH,
      sym_tag_name,
    STATE(14), 3,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym_text_repeat1,
  [297] = 5,
    ACTIONS(39), 1,
      sym_inline_tag_name,
    ACTIONS(41), 1,
      sym__tag_content,
    STATE(19), 1,
      sym_text,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(5), 3,
      sym_raw_tag_content,
      sym_inline_tag,
      aux_sym_text_repeat1,
  [316] = 3,
    ACTIONS(85), 1,
      sym__simple_singleline_begin,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(83), 4,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym__singleline_begin,
  [330] = 3,
    ACTIONS(89), 1,
      sym__simple_singleline_begin,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(87), 4,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym__singleline_begin,
  [344] = 6,
    ACTIONS(21), 1,
      sym__tag_content,
    ACTIONS(91), 1,
      anon_sym_STAR_SLASH,
    STATE(27), 1,
      sym__multiline_end,
    STATE(29), 1,
      aux_sym__simple_multiline_repeat1,
    STATE(33), 1,
      sym_raw_tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
  [364] = 3,
    ACTIONS(95), 1,
      sym__simple_singleline_begin,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(93), 4,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym__singleline_begin,
  [378] = 3,
    ACTIONS(99), 1,
      sym__simple_singleline_begin,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(97), 4,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym__singleline_begin,
  [392] = 6,
    ACTIONS(21), 1,
      sym__tag_content,
    ACTIONS(101), 1,
      anon_sym_STAR_SLASH,
    STATE(17), 1,
      sym__multiline_end,
    STATE(18), 1,
      aux_sym__simple_multiline_repeat1,
    STATE(33), 1,
      sym_raw_tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
  [412] = 3,
    ACTIONS(105), 1,
      sym__simple_singleline_begin,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(103), 4,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym__singleline_begin,
  [426] = 5,
    ACTIONS(17), 1,
      sym_tag_name,
    ACTIONS(107), 1,
      anon_sym_STAR_SLASH,
    STATE(24), 1,
      sym__multiline_end,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(25), 2,
      sym_block_tag,
      aux_sym__multiline_repeat1,
  [444] = 3,
    ACTIONS(111), 1,
      sym__simple_singleline_begin,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(109), 4,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym__singleline_begin,
  [458] = 5,
    ACTIONS(17), 1,
      sym_tag_name,
    ACTIONS(113), 1,
      anon_sym_STAR_SLASH,
    STATE(16), 1,
      sym__multiline_end,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(28), 2,
      sym_block_tag,
      aux_sym__multiline_repeat1,
  [476] = 5,
    ACTIONS(17), 1,
      sym_tag_name,
    ACTIONS(107), 1,
      anon_sym_STAR_SLASH,
    STATE(24), 1,
      sym__multiline_end,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(28), 2,
      sym_block_tag,
      aux_sym__multiline_repeat1,
  [494] = 3,
    ACTIONS(117), 1,
      sym__simple_singleline_begin,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(115), 4,
      sym__multiline_begin,
      sym__simple_multiline_begin,
      ts_builtin_sym_end,
      sym__singleline_begin,
  [508] = 4,
    ACTIONS(119), 1,
      anon_sym_STAR_SLASH,
    ACTIONS(121), 1,
      sym_tag_name,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    STATE(28), 2,
      sym_block_tag,
      aux_sym__multiline_repeat1,
  [523] = 5,
    ACTIONS(124), 1,
      anon_sym_STAR_SLASH,
    ACTIONS(126), 1,
      sym__tag_content,
    STATE(29), 1,
      aux_sym__simple_multiline_repeat1,
    STATE(33), 1,
      sym_raw_tag_content,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
  [540] = 3,
    ACTIONS(71), 1,
      sym_inline_tag_name,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(69), 3,
      sym__tag_content,
      anon_sym_STAR_SLASH,
      sym_tag_name,
  [553] = 3,
    ACTIONS(75), 1,
      sym_inline_tag_name,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(73), 3,
      sym__tag_content,
      anon_sym_STAR_SLASH,
      sym_tag_name,
  [566] = 2,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(129), 2,
      anon_sym_STAR_SLASH,
      sym_tag_name,
  [575] = 2,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
    ACTIONS(131), 2,
      sym__tag_content,
      anon_sym_STAR_SLASH,
  [584] = 2,
    ACTIONS(133), 1,
      ts_builtin_sym_end,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
  [592] = 3,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(135), 1,
      aux_sym__simple_singleline_token1,
  [602] = 3,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(137), 1,
      aux_sym_inline_tag_token1,
  [612] = 2,
    ACTIONS(139), 1,
      sym_inline_tag_value,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
  [620] = 2,
    ACTIONS(141), 1,
      sym_inline_tag_value,
    ACTIONS(5), 2,
      sym__new_line,
      aux_sym__whitespace_token1,
  [628] = 3,
    ACTIONS(3), 1,
      aux_sym__whitespace_token1,
    ACTIONS(5), 1,
      sym__new_line,
    ACTIONS(143), 1,
      aux_sym_inline_tag_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 32,
  [SMALL_STATE(4)] = 59,
  [SMALL_STATE(5)] = 84,
  [SMALL_STATE(6)] = 109,
  [SMALL_STATE(7)] = 136,
  [SMALL_STATE(8)] = 160,
  [SMALL_STATE(9)] = 184,
  [SMALL_STATE(10)] = 207,
  [SMALL_STATE(11)] = 225,
  [SMALL_STATE(12)] = 241,
  [SMALL_STATE(13)] = 257,
  [SMALL_STATE(14)] = 277,
  [SMALL_STATE(15)] = 297,
  [SMALL_STATE(16)] = 316,
  [SMALL_STATE(17)] = 330,
  [SMALL_STATE(18)] = 344,
  [SMALL_STATE(19)] = 364,
  [SMALL_STATE(20)] = 378,
  [SMALL_STATE(21)] = 392,
  [SMALL_STATE(22)] = 412,
  [SMALL_STATE(23)] = 426,
  [SMALL_STATE(24)] = 444,
  [SMALL_STATE(25)] = 458,
  [SMALL_STATE(26)] = 476,
  [SMALL_STATE(27)] = 494,
  [SMALL_STATE(28)] = 508,
  [SMALL_STATE(29)] = 523,
  [SMALL_STATE(30)] = 540,
  [SMALL_STATE(31)] = 553,
  [SMALL_STATE(32)] = 566,
  [SMALL_STATE(33)] = 575,
  [SMALL_STATE(34)] = 584,
  [SMALL_STATE(35)] = 592,
  [SMALL_STATE(36)] = 602,
  [SMALL_STATE(37)] = 612,
  [SMALL_STATE(38)] = 620,
  [SMALL_STATE(39)] = 628,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_text_repeat1, 2, 0, 0),
  [27] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_text_repeat1, 2, 0, 0),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_text_repeat1, 2, 0, 0), SHIFT_REPEAT(39),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_text_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_text, 1, 0, 0),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_text, 1, 0, 0),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(35),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tag_content_repeat1, 2, 0, 0),
  [59] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_tag_content_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_tag_content_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag_content, 1, 0, 0),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_tag, 3, 0, 3),
  [71] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_tag, 3, 0, 3),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_raw_tag_content, 1, 0, 0),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_raw_tag_content, 1, 0, 0),
  [77] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_text_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_text_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__multiline, 4, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__multiline, 4, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__simple_multiline, 2, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__simple_multiline, 2, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__singleline, 2, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__singleline, 2, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__simple_singleline, 2, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__simple_singleline, 2, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__multiline, 2, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__multiline, 2, 0, 0),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__multiline, 3, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__multiline, 3, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__simple_multiline, 3, 0, 2),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__simple_multiline, 3, 0, 2),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__multiline_repeat1, 2, 0, 0),
  [121] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__multiline_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__simple_multiline_repeat1, 2, 0, 0),
  [126] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__simple_multiline_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_tag, 2, 0, 1),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__simple_multiline_repeat1, 1, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [135] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [143] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
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
    [ts_external_token__new_line] = true,
  },
  [4] = {
    [ts_external_token__tag_content] = true,
    [ts_external_token__multiline_begin] = true,
    [ts_external_token__simple_multiline_begin] = true,
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
