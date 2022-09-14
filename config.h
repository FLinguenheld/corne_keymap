/*
This is the c configuration file for the keymap
*/

#pragma once

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT


// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------

// OLED
#define OLED_BRIGHTNESS 90 // Protect my eyesss
#define OLED_TIMEOUT 10000

#ifdef MASTER_LEFT
    #define OLED_FONT_H "keyboards/crkbd/keymaps/corne_keymap/font/glcdfont_left.c"
#else
    #define OLED_FONT_H "keyboards/crkbd/keymaps/corne_keymap/font/glcdfont_right.c"
#endif

#define SPLIT_OLED_ENABLE // Sync both oled (on/off status only)
#define SPLIT_LAYER_STATE_ENABLE

// Auto shift
#define AUTO_SHIFT_TIMEOUT 122

// Unicode
#define UNICODE_SELECTED_MODES UC_LNX

// Tap dance
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 122 // Same as auto shift
#define IGNORE_MOD_TAP_INTERRUPT

// Combo
#define COMBO_COUNT 17
