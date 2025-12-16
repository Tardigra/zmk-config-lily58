# Lily58 Keymap Features Documentation

This document explains the advanced features integrated into this Lily58 keymap, adapted from the totem BSAG configuration.

## Table of Contents
- [Layers Overview](#layers-overview)
- [Home Row Mods (HRM)](#home-row-mods-hrm)
- [Mod-Morphs](#mod-morphs)
- [Combos](#combos)
- [Special Modifiers](#special-modifiers)
- [SYM Layer](#sym-layer)
- [Configuration](#configuration)

---

## Layers Overview

This keymap uses multiple layers to maximize functionality without leaving home position:

### Layer 0: BASE
- QWERTY layout with Home Row Mods
- Number row (1-0) always accessible
- Layer-tap thumbs: TAB (hold=NAV), ESC (hold=NUM), BSPC (hold=SYM)

### Layer 1: NAV (Hold TAB)
- Vim-style navigation: hjkl = arrow keys
- Page Up/Down, Home/End
- Left hand modifiers for Ctrl+arrows, etc.
- Essential for IDE navigation

### Layer 2: NUM (Hold ESC)
- F1-F10 for IDE debugging
- Numbers 1-0 in QWERTY order
- Shifted symbols (! @ # $ % etc.)
- F11/F12 on extra keys

### Layer 3: SYM (Hold BSPC)
- Programming symbols optimized for TS/JS/PHP
- Most frequent symbols on home row
- Inward rolls for common patterns (=>, ?., ->)
- All bracket types easily accessible

### Layer 4: EXTRA
- Mouse emulation (reserved for future use)

---

## Home Row Mods (HRM)

### What Are Home Row Mods?

Home Row Mods (HRM) turn your home row keys into **dual-purpose keys**:
- **Quick tap** = regular letter (A, S, D, F, J, K, L, ;)
- **Hold** = modifier key (Ctrl, Alt, Gui/Cmd, Shift)

This allows you to access modifier keys without leaving the home position, making typing more ergonomic and efficient.

### HRM Behaviors Defined

We have three HRM behaviors:

#### 1. `hml` (Home Row Mod Left)
Used on the **left hand** home row keys.

**Configuration:**
- **Tap**: Types the letter normally
- **Hold**: Activates the specified modifier
- **Hold trigger**: Only activates as modifier when pressing keys on the **right hand** or thumbs

**Example usage:**
```c
&hml LCTRL A    // Tap = 'A', Hold = Ctrl
&hml LALT S     // Tap = 'S', Hold = Alt
&hml LGUI D     // Tap = 'D', Hold = Gui/Cmd
&hml LSHFT F    // Tap = 'F', Hold = Shift
```

#### 2. `hmr` (Home Row Mod Right)
Used on the **right hand** home row keys.

**Configuration:**
- **Tap**: Types the letter normally
- **Hold**: Activates the specified modifier
- **Hold trigger**: Only activates as modifier when pressing keys on the **left hand** or thumbs

**Example usage:**
```c
&hmr RSHFT J      // Tap = 'J', Hold = Shift
&hmr RGUI K       // Tap = 'K', Hold = Gui/Cmd
&hmr LALT L       // Tap = 'L', Hold = Alt
&hmr RCTRL SEMI   // Tap = ';', Hold = Ctrl
```

#### 3. `hmr_meh` (Special HRM for MEH)
Special variant that combines HRM with a mod-morph for the MEH modifier.

**Configuration:**
- **Tap**: Uses `comma_morph` behavior (comma normally, semicolon when shifted)
- **Hold**: Activates MEH modifier (Shift+Ctrl+Alt)

### How HRM Works

#### Timing Parameters:
- **Tapping term**: 280ms
  - Press and release quickly (< 280ms) = letter
  - Press and hold (> 280ms) = modifier
- **Quick tap**: 175ms
  - Allows quick repeated taps without triggering hold
- **Prior idle**: 150ms
  - Must pause 150ms before a hold can activate
  - Prevents accidental modifiers during fast typing

#### Smart Triggering:
The **hold-trigger-key-positions** feature is crucial for preventing accidental modifiers:
- `hml` (left hand) only activates as modifier when you press a key on the **right hand** (`KEYS_R`) or **thumbs** (`THUMBS`)
- `hmr` (right hand) only activates as modifier when you press a key on the **left hand** (`KEYS_L`) or **thumbs** (`THUMBS`)

This means if you're typing quickly with one hand, the keys won't accidentally trigger as modifiers.

### Practical Examples

#### Example 1: Ctrl+C (Copy)
1. **Hold** the `A` key (activates Ctrl via `hml LCTRL A`)
2. **Tap** `C` with your right hand
3. Release `A`

#### Example 2: Shift+T (Capital T)
1. **Hold** the `J` key (activates Shift via `hmr RSHFT J`)
2. **Tap** `T` with your left hand
3. Release `J`

#### Example 3: Gui+Space (Spotlight/Alfred)
1. **Hold** the `D` key (activates Gui via `hml LGUI D`)
2. **Tap** `Space` with your thumb
3. Release `D`

### Benefits of HRM

✅ **Ergonomic**: No need to move fingers to reach Ctrl/Alt/Shift keys
✅ **Efficient**: Faster access to modifiers, fingers stay on home row
✅ **Powerful**: Can combine multiple modifiers easily
✅ **Space-saving**: Especially useful on smaller keyboards like the Lily58

### Learning Curve

HRM takes time to learn:
- **Week 1**: Feels awkward, you'll trigger accidental modifiers
- **Week 2**: Starting to feel more natural
- **Week 3-4**: Muscle memory develops
- **Month 2+**: Second nature, significantly faster than traditional modifiers

**Tip**: Start by using just one or two home row mods (e.g., Shift on F and J) before adding all of them.

---

## Mod-Morphs

Mod-morphs change the behavior of a key when a modifier (typically Shift) is held.

### Defined Mod-Morphs:

#### 1. `qexcl` (Question/Exclamation)
- **Normal tap**: `?` (question mark)
- **With Shift**: `!` (exclamation mark)

#### 2. `comma_morph` (Comma/Semicolon)
- **Normal tap**: `,` (comma)
- **With Shift**: `;` (semicolon)

**Usage**: Used on the right hand in combination with `hmr_meh`

#### 3. `dot_morph` (Dot/Colon)
- **Normal tap**: `.` (period/dot)
- **With Shift**: `:` (colon)

**Usage**: Replaces the standard period key on the base layer

### Why Mod-Morphs?

Mod-morphs reduce the number of keys needed for punctuation by intelligently combining related symbols. Instead of having separate keys for comma and semicolon, one key does both jobs.

---

## Combos

Combos allow you to press two (or more) keys simultaneously to trigger a different action. The combo system is defined in `config/combos.dtsi`.

### Combo Categories:

#### Left Hand Vertical Combos
**Between top and home row:**
- `W + S` → `@`
- `E + D` → `#`
- `R + F` → `$`
- `T + G` → `%`

**Between home and bottom row:**
- `S + X` → `` ` `` (backtick/grave)
- `D + C` → `\` (backslash)
- `F + V` → `=` (equal)
- `G + B` → `~` (tilde)

#### Right Hand Vertical Combos
**Between top and home row:**
- `Y + H` → `^` (caret)
- `U + J` → `+` (plus)
- `I + K` → `*` (asterisk)
- `O + L` → `&` (ampersand)

**Between home and bottom row:**
- `H + N` → `_` (underscore)
- `J + M` → `-` (minus)
- `K + ,` → `/` (forward slash)
- `L + .` → `|` (pipe)

#### Left Hand Horizontal Combos
- `X + V` → `Cmd+X` (cut)
- `X + C` → `Cmd+C` (copy)
- `C + V` → `Cmd+V` (paste)

#### Right Hand Horizontal Combos
**Brackets:**
- `U + I` → `[` (left bracket)
- `I + O` → `]` (right bracket)
- `J + K` → `(` (left parenthesis)
- `K + L` → `)` (right parenthesis)
- `M + ,` → `{` (left brace)
- `, + .` → `}` (right brace)

**Angle brackets:**
- `H + J` → `<` (less than)
- `L + ;` → `>` (greater than)

#### Special Combos
- `F + J` (both index fingers) → `caps_word`

### Combo Timing:
- **COMBO_TERM_FAST**: 18ms - for horizontal combos (tight timing)
- **COMBO_TERM_SLOW**: 30ms - for vertical combos (more forgiving)
- **Prior idle**: 150ms - prevents accidental combos during fast typing

---

## Special Modifiers

### HYP (Hyper)
- **Definition**: `Shift + Ctrl + Alt + Gui` (all modifiers)
- **Usage**: Assigned to `V` (left) and `M` (right) as hold-tap
- **Purpose**: Creates unique keybindings that won't conflict with existing shortcuts

### MEH (Meh)
- **Definition**: `Shift + Ctrl + Alt`
- **Usage**: Assigned to `C` (left) and comma (right) as hold-tap
- **Purpose**: Similar to Hyper but without Gui, useful for additional unique shortcuts

---

## SYM Layer

The SYM layer is a dedicated programming symbol layer optimized for TypeScript, JavaScript, and PHP development.

### Activation
**Hold the Backspace key** (right middle thumb). Tap for Backspace, hold for SYM layer access.

### Layout Philosophy
The SYM layer is designed with these priorities:
1. **Most frequent symbols on home row** - minimal finger movement
2. **Inward rolls for common patterns** - faster typing of `=>`, `?.`, `->`
3. **All bracket types together** - easy access to `()`, `[]`, `{}`, `<>`
4. **Programming-oriented** - symbols used in TS/JS/PHP

### Right Hand - Most Frequent Symbols (Home Row)

**On HJKL; positions:**
- **H**: `)` - Closing parenthesis
- **J**: `=` - Assignment, equality (most used!)
- **K**: `.` - Property access, method chaining (very frequent!)
- **L**: `-` - Subtraction, arrow functions
- **;**: `>` - Arrow functions, comparisons

**Common Patterns (Inward Rolls):**
- **Arrow function** `=>`: Type J→; (index to pinky) - smooth roll!
- **Optional chaining** `?.`: Type ; (from base home row) then K
- **PHP arrow** `->`: Type L→; (ring to pinky)

### Left Hand - All Bracket Types (Home Row)

**On ASDFG positions:**
- **A**: `{` - Opening brace
- **S**: `}` - Closing brace
- **D**: `[` - Opening bracket
- **F**: `]` - Closing bracket
- **G**: `(` - Opening parenthesis

**Bracket Pairs:**
- `{}`: Type A→S (index to middle)
- `[]`: Type D→F (middle to ring)
- `()`: Type left G + right H (alternating hands = very fast!)

### Top Row - Less Frequent Symbols

**Left side (QWERTY positions):**
- `!` `@` `#` `$` `%` - Common programming symbols

**Right side (YUIOP positions):**
- `^` `&` `*` `=` `+` - Math and logical operators

### Third Row - Quotes and Special Characters

**Left side:**
- `` ` `` (backtick) - Template literals
- `~` (tilde) - Bitwise NOT
- `|` (pipe) - Bitwise OR, union types
- `\` (backslash) - Escape character
- `:` (colon) - Object properties, type annotations

**Right side:**
- `;` (semicolon) - Statement terminator
- `'` (single quote) - Strings
- `"` (double quote) - Strings
- `_` (underscore) - Private vars, snake_case
- `?` (question mark) - Ternary operator, optional chaining

### Bottom Row - Additional Patterns

**Right side for fast access:**
- `;` `=` `>` `.` - Duplicates of home row for sequences

### Usage Examples

#### Arrow Function
```typescript
const add = (a, b) => a + b;
```
1. Type `()` using left G + right H
2. Roll `=>` using J→; (index to pinky)

#### Optional Chaining
```typescript
user?.profile?.name
```
1. Type `?` from home row ; position
2. Type `.` from home row K position

#### PHP Object Access
```php
$user->getName()
```
1. Roll `->` using L→; (ring to pinky)
2. Type `()` using left G + right H

#### TypeScript Type Annotation
```typescript
const name: string = "value";
```
1. Type `:` from third row H position
2. Type `=` from home row J position
3. Type `"` from third row K position

### Benefits

✅ **Optimized for Programming**: All common programming symbols easily accessible
✅ **Reduced Hand Movement**: Most frequent symbols on home row
✅ **Fast Patterns**: Inward rolls for `=>`, `?.`, `->`
✅ **Ergonomic**: Index and middle fingers handle most common symbols
✅ **Language Agnostic**: Works well for TS, JS, PHP, and other C-style languages

---

## Configuration

### Key Position Definitions

The keymap uses semantic labels defined in `config/zmk-nodefree-config/keypos_def/keypos_58keys.h`:

#### Alpha Keys:
- **Left Top**: LT4, LT3, LT2, LT1, LT0 (Q, W, E, R, T)
- **Left Middle**: LM4, LM3, LM2, LM1, LM0 (A, S, D, F, G)
- **Left Bottom**: LB4, LB3, LB2, LB1, LB0 (Z, X, C, V, B)
- **Right Top**: RT0, RT1, RT2, RT3, RT4 (Y, U, I, O, P)
- **Right Middle**: RM0, RM1, RM2, RM3, RM4 (H, J, K, L, ;)
- **Right Bottom**: RB0, RB1, RB2, RB3, RB4 (N, M, ,, ., /)

#### Thumb Keys:
- **Left**: LH3, LH2, LH1, LH0 (4 thumb keys)
- **Right**: RH0, RH1, RH2, RH3 (4 thumb keys)

#### Extra Keys (Lily58 specific):
- **Number Row**: LN5-LN0 (left), RN0-RN5 (right)
- **Extra Positions**: LE5, LE4, LE3, LE2 (left), RE5, RE4, RE3, RE2 (right)

### Key Groups for HRM:
```c
#define KEYS_L LT0 LT1 LT2 LT3 LT4 LM0 LM1 LM2 LM3 LM4 LB0 LB1 LB2 LB3 LB4
#define KEYS_R RT0 RT1 RT2 RT3 RT4 RM0 RM1 RM2 RM3 RM4 RB0 RB1 RB2 RB3 RB4
#define THUMBS LH0 LH1 LH2 LH3 RH0 RH1 RH2 RH3
```

### Standard Behavior Configurations:

#### Caps Word:
```c
&caps_word {
    /delete-property/ ignore-numbers;
    continue-list = <BACKSPACE ENTER DELETE UNDERSCORE MINUS>;
};
```
- Activates all-caps mode that automatically deactivates after word boundaries
- Continues with underscore and minus (useful for CONSTANT_NAMES)

#### Key Repeat:
```c
&key_repeat {
    usage-pages = <HID_USAGE_KEY HID_USAGE_CONSUMER>;
};
```
- Repeats all types of keys, including media keys

#### Sticky Keys (One-shot mods):
```c
&sk {
    release-after-ms = <2000>;
    quick-release;
};
```
- Auto-releases after 2 seconds if not used

#### Layer Tap:
```c
&lt {
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <QUICK_TAP_MS>;
};
```
- Balanced behavior between tap and hold
- Uses the QUICK_TAP_MS constant (175ms)

---

## Tips and Tricks

### Getting Started with HRM:
1. Start with just Shift on F and J
2. Add Gui/Cmd on D and K next
3. Finally add Alt and Ctrl once comfortable
4. Practice common shortcuts: Ctrl+C, Ctrl+V, Gui+Tab

### Common Mistakes:
- **Resting fingers**: Don't rest on home row keys - hover slightly above
- **Too slow**: If you're triggering modifiers when typing, you're pausing too long
- **Wrong hand**: Remember to use opposite hand for modifier combinations

### Customization:
All timing values can be adjusted in the keymap:
- `QUICK_TAP_MS`: Currently 175ms
- HRM `tapping-term-ms`: Currently 280ms
- HRM `require-prior-idle-ms`: Currently 150ms

Increase these values if you're getting accidental modifiers, decrease if you want faster activation.

---

## References

- **Source configuration**: `/home/pinscher/keyboards/zmk-layouts/totem/zmk-bsag/zmk-config-bsag/`
- **ZMK Documentation**: https://zmk.dev/
- **Helper library**: `zmk-nodefree-config` by urob