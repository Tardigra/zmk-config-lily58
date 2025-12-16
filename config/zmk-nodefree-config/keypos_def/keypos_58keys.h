// Lily58: 6x4+4 (58 keys total)
/* 58 KEY MATRIX / LAYOUT MAPPING

   ╭──────────────────────────────┬──────────────────────────────╮
   │  0   1   2   3   4   5       │       6   7   8   9  10  11  │  number row
   │ 12  13  14  15  16  17       │      18  19  20  21  22  23  │  top row (QWERTY)
   │ 24  25  26  27  28  29       │      30  31  32  33  34  35  │  home row (ASDF)
   │ 36  37  38  39  40  41  42   │   43 44  45  46  47  48  49  │  bottom row (ZXCV) + encoder keys
   ╰───────────╮ 50  51  52  53   │   54 55  56  57 ╭────────────╯  thumb cluster
               ╰──────────────────┴──────────────────╯

   SEMANTIC LABELS (matching totem convention):
   ╭──────────────────────────────┬──────────────────────────────╮
   │ LN5 LN4 LN3 LN2 LN1 LN0      │      RN0 RN1 RN2 RN3 RN4 RN5 │  number row
   │ LE5 LT4 LT3 LT2 LT1 LT0      │      RT0 RT1 RT2 RT3 RT4 RE5 │  top row
   │ LE4 LM4 LM3 LM2 LM1 LM0      │      RM0 RM1 RM2 RM3 RM4 RE4 │  middle/home row
   │ LE3 LB4 LB3 LB2 LB1 LB0 LE2  │  RE2 RB0 RB1 RB2 RB3 RB4 RE3 │  bottom row
   ╰───────────╮ LH3 LH2 LH1 LH0  │  RH0 RH1 RH2 RH3 ╭────────────╯  thumbs
               ╰──────────────────┴──────────────────╯                       */

#pragma once

// Number row (extras on lily58)
#define LN5  0  // ESC
#define LN4  1  // 1
#define LN3  2  // 2
#define LN2  3  // 3
#define LN1  4  // 4
#define LN0  5  // 5

#define RN0  6  // 6
#define RN1  7  // 7
#define RN2  8  // 8
#define RN3  9  // 9
#define RN4 10  // 0
#define RN5 11  // GRAVE

// Top row (alphas) - QWERTY
#define LE5 12  // TAB (left extra)
#define LT4 13  // Q
#define LT3 14  // W
#define LT2 15  // E
#define LT1 16  // R
#define LT0 17  // T

#define RT0 18  // Y
#define RT1 19  // U
#define RT2 20  // I
#define RT3 21  // O
#define RT4 22  // P
#define RE5 23  // MINUS (right extra)

// Middle/Home row - ASDFGH
#define LE4 24  // LCTRL (left extra)
#define LM4 25  // A
#define LM3 26  // S
#define LM2 27  // D
#define LM1 28  // F
#define LM0 29  // G

#define RM0 30  // H
#define RM1 31  // J
#define RM2 32  // K
#define RM3 33  // L
#define RM4 34  // SEMI
#define RE4 35  // SQT (right extra)

// Bottom row - ZXCVBN
#define LE3 36  // LSHFT (left extra)
#define LB4 37  // Z
#define LB3 38  // X
#define LB2 39  // C
#define LB1 40  // V
#define LB0 41  // B
#define LE2 42  // LBKT (left encoder/extra)

#define RE2 43  // RBKT (right encoder/extra)
#define RB0 44  // N
#define RB1 45  // M
#define RB2 46  // COMMA
#define RB3 47  // DOT
#define RB4 48  // FSLH
#define RE3 49  // RSHFT (right extra)

// Thumb cluster (4 keys per side on lily58)
#define LH3 50  // LALT (outermost left thumb)
#define LH2 51  // LGUI
#define LH1 52  // LOWER (mo 1)
#define LH0 53  // SPACE (innermost left thumb)

#define RH0 54  // ENTER (innermost right thumb)
#define RH1 55  // RAISE (mo 2)
#define RH2 56  // BSPC
#define RH3 57  // RCTRL (outermost right thumb)

// Key groups for HRM (only alphas, excluding extra keys and number row)
#define KEYS_L LT0 LT1 LT2 LT3 LT4 LM0 LM1 LM2 LM3 LM4 LB0 LB1 LB2 LB3 LB4
#define KEYS_R RT0 RT1 RT2 RT3 RT4 RM0 RM1 RM2 RM3 RM4 RB0 RB1 RB2 RB3 RB4
#define THUMBS LH0 LH1 LH2 LH3 RH0 RH1 RH2 RH3