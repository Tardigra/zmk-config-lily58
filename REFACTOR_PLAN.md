# Lily58 Totem Integration Plan

## Overview
Integrate totem BSAG configuration (HRM, combos, mod-morphs) into lily58 while keeping QWERTY and utilizing extra keys.

## Workflow Rules (AGREED)
1. **Incremental**: Small steps, each must compile
2. **User commits**: After each step, user commits and triggers GitHub workflow
3. **Verification gates**: Must confirm build success before next step
4. **No auto-commits**: Claude never commits
5. **Stop on errors**: Fix or ask for help, never proceed with broken code

## Implementation Steps

### Step 0: Preparation ✅
**Do**: Copy plan to `/home/pinscher/keyboards/zmk-layouts/zmk-config-lily58/REFACTOR_PLAN.md`
**Safe**: Docs only
**Commit**: `docs: add refactor plan`
**Status**: COMPLETED

---

### Step 1: Copy Helper Library ✅
**Do**: Copy `zmk-nodefree-config/` from totem to lily58 config dir
**Safe**: Not yet included
**Commit**: `feat: add zmk-nodefree-config library`
**Status**: COMPLETED

---

### Step 2: Create keypos_58keys.h ✅
**Do**: Create `config/zmk-nodefree-config/keypos_def/keypos_58keys.h` with lily58 position defines
**Safe**: Not yet included
**Commit**: `feat: add lily58 key position definitions`
**Status**: COMPLETED - Ready to commit

<details>
<summary>Key positions to define</summary>

```c
// Alphas (30 keys) - map to totem semantic labels
#define LT4 13  // Q    #define RT4 22  // P
#define LT3 14  // W    #define RT3 21  // O
#define LT2 15  // E    #define RT2 20  // I
#define LT1 16  // R    #define RT1 19  // U
#define LT0 17  // T    #define RT0 18  // Y

#define LM4 25  // A    #define RM4 34  // ;
#define LM3 26  // S    #define RM3 33  // L
#define LM2 27  // D    #define RM2 32  // K
#define LM1 28  // F    #define RM1 31  // J
#define LM0 29  // G    #define RM0 30  // H

#define LB4 37  // Z    #define RB4 48  // /
#define LB3 38  // X    #define RB3 47  // .
#define LB2 39  // C    #define RB2 46  // ,
#define LB1 40  // V    #define RB1 45  // M
#define LB0 41  // B    #define RB0 44  // N

// Thumbs (verify exact positions from current lily58.keymap)
#define LH2 53  #define RH2 56
#define LH1 54  #define RH1 55
#define LH0 55  #define RH0 54

// Key groups for HRM
#define KEYS_L LT0 LT1 LT2 LT3 LT4 LM0 LM1 LM2 LM3 LM4 LB0 LB1 LB2 LB3 LB4
#define KEYS_R RT0 RT1 RT2 RT3 RT4 RM0 RM1 RM2 RM3 RM4 RB0 RB1 RB2 RB3 RB4
#define THUMBS LH0 LH1 LH2 RH0 RH1 RH2
```
</details>

---

### Step 3: Copy Combos ✅
**Do**: Copy `combos.dtsi` from totem to lily58 config
**Safe**: Not yet included
**Commit**: `feat: add combo definitions`
**Status**: COMPLETED - Ready to commit

---

### Step 4: Add Includes & Defines ✅
**Do**: Add to top of `lily58.keymap`:
```c
#include "zmk-nodefree-config/helper.h"
#include "zmk-nodefree-config/keypos_def/keypos_58keys.h"
```
Add after layer defines:
```c
#define XXX &none
#define ___ &trans
#define QUICK_TAP_MS 175
#define HYP LS(LC(LA(LGUI)))
#define MEH LS(LC(LALT))
```
**Don't**: Include combos yet, don't change bindings
**Safe**: Just includes/defines
**Commit**: `feat: add helper includes and common defines`
**Status**: COMPLETED - Ready to commit

---

### Step 5: Configure Standard Behaviors ✅
**Do**: Add before `/ {`:
```c
&caps_word {
    /delete-property/ ignore-numbers;
    continue-list = <BACKSPACE ENTER DELETE UNDERSCORE MINUS>;
};

&key_repeat {
    usage-pages = <HID_USAGE_KEY HID_USAGE_CONSUMER>;
};

&sk {
    release-after-ms = <2000>;
    quick-release;
};

&lt {
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <QUICK_TAP_MS>;
};
```
**Don't**: Change bindings
**Safe**: Configuring existing behaviors
**Commit**: `feat: configure caps_word, key_repeat, sk, lt`
**Status**: COMPLETED - Ready to commit

---

### Step 6: Add Mod-Morphs ✅
**Do**: Add inside `/ {`, before keymap:
```c
ZMK_BEHAVIOR(qexcl, mod_morph,
    bindings = <&kp QMARK>, <&kp EXCL>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
)

ZMK_BEHAVIOR(comma_morph, mod_morph,
    bindings = <&kp COMMA>, <&kp SEMICOLON>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
)

ZMK_BEHAVIOR(dot_morph, mod_morph,
    bindings = <&kp DOT>, <&kp COLON>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
)
```
**Don't**: Use in bindings yet
**Safe**: Just defining
**Commit**: `feat: add mod-morph behaviors`
**Status**: COMPLETED - Ready to commit

---

### Step 7: Add HRM Behaviors ✅
**Do**: Add before `/ {`:
```c
#define KEYS_L LT0 LT1 LT2 LT3 LT4 LM0 LM1 LM2 LM3 LM4 LB0 LB1 LB2 LB3 LB4
#define KEYS_R RT0 RT1 RT2 RT3 RT4 RM0 RM1 RM2 RM3 RM4 RB0 RB1 RB2 RB3 RB4
#define THUMBS LH0 LH1 LH2 RH0 RH1 RH2

#define MAKE_HRM(NAME, HOLD, TAP, TRIGGER_POS) \
    ZMK_BEHAVIOR(NAME, hold_tap, \
        flavor = "balanced"; \
        tapping-term-ms = <280>; \
        quick-tap-ms = <QUICK_TAP_MS>; \
        require-prior-idle-ms = <150>; \
        bindings = <HOLD>, <TAP>; \
        hold-trigger-key-positions = <TRIGGER_POS>; \
        hold-trigger-on-release; \
    )

MAKE_HRM(hml, &kp, &kp, KEYS_R THUMBS)
MAKE_HRM(hmr, &kp, &kp, KEYS_L THUMBS)
MAKE_HRM(hmr_meh, &kp, &comma_morph, KEYS_L THUMBS)
```
**Don't**: Use in bindings yet
**Safe**: Just defining
**Commit**: `feat: add HRM behaviors`
**Status**: COMPLETED - Ready to commit

---

### Step 8: Enable Combos ✅
**Do**: Add `#include "combos.dtsi"` after layer defines in lily58.keymap
**Safe**: Combos work with current layout
**Commit**: `feat: enable combo system`
**Status**: COMPLETED - Ready to commit

---

### Step 9: Update Base Layer - Home Row Mods
**Do**: Change home row in default_layer bindings from:
```c
&kp LCTRL &kp A  &kp S  &kp D    &kp F    &kp G      &kp H  &kp J    &kp K     &kp L   &kp SEMI &kp SQT
```
To:
```c
&kp LCTRL &hml LCTRL A  &hml LALT S  &hml LGUI D  &hml LSHFT F  &kp G      &kp H  &hmr RSHFT J  &hmr RGUI K  &hmr LALT L  &hmr RCTRL SEMI  &kp SQT
```
**Safe**: One row change, testable
**Commit**: `feat: add home row modifiers to base layer`

---

### Step 10: Update Base Layer - Bottom Row Special Keys
**Do**: Change bottom row C, V, M, comma in default_layer from:
```c
&kp LSHFT &kp Z  &kp X  &kp C    &kp V    &kp B ...  &kp N  &kp M    &kp COMMA &kp DOT &kp FSLH &kp RSHFT
```
To:
```c
&kp LSHFT &kp Z  &kp X  &hml MEH C  &hml HYP V  &kp B ...  &kp N  &hmr HYP M  &hmr_meh MEH 0  &dot_morph  &kp FSLH &kp RSHFT
```
And change period to `&dot_morph`
**Safe**: Small change, builds on previous
**Commit**: `feat: add MEH/HYP modifiers and mod-morphs to base layer`

---

### Step 11: Update Base Layer - Thumb Cluster Layer-Taps
**Do**: Update thumb cluster to use layer-tap (verify positions first):
- Left thumbs: keep some traditional (ALT, GUI), add layer-taps
- Right thumbs: similar approach
**Details**: Will determine exact mapping when we reach this step
**Safe**: One change at a time
**Commit**: `feat: add layer-tap thumb keys`

---

### Step 12-15: Update Other Layers
Will detail when we reach them:
- Step 12: NAV layer
- Step 13: NUM layer
- Step 14: FUN layer
- Step 15: UTIL layer

Each as separate compilable step.

---

## Reference Files

**Source (totem)**:
- `/home/pinscher/keyboards/zmk-layouts/totem/zmk-bsag/zmk-config-bsag/config/totem.keymap`
- `/home/pinscher/keyboards/zmk-layouts/totem/zmk-bsag/zmk-config-bsag/config/combos.dtsi`
- `/home/pinscher/keyboards/zmk-layouts/totem/zmk-bsag/zmk-config-bsag/zmk-nodefree-config/`

**Target (lily58)**:
- `/home/pinscher/keyboards/zmk-layouts/zmk-config-lily58/config/lily58.keymap`
- `/home/pinscher/keyboards/zmk-layouts/zmk-config-lily58/config/lily58.conf`

## Notes
- Keep ZMK Studio enabled (`CONFIG_ZMK_STUDIO=y`)
- Keep number row on base layer (lily58 extra keys)
- Each step must compile before proceeding
- User controls all commits
