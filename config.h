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
#ifdef MASTER_LEFT
    #define OLED_FONT_H "keyboards/crkbd/keymaps/corne_keymap/font/glcdfont_left.c"
#else
    #define OLED_FONT_H "keyboards/crkbd/keymaps/corne_keymap/font/glcdfont_right.c"
#endif

#define OLED_BRIGHTNESS 60 // Protect my eyesss
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_OLED_ENABLE

// Used in the oled_task_user() function, because the OLED_TIMEOUT doesn't work correctly
#undef  OLED_TIMEOUT
#define OLED_KEY_TIMEOUT 25000

// Auto shift
#define AUTO_SHIFT_TIMEOUT 115


// Redefine ALT + ¨  -  SHITF + ^  -  CTRL + space
// The equivalent TD(ALT, TREMA) doesn't work
// See space cadet shift
#define LAPO_KEYS KC_LALT, KC_RALT, KC_D
#define RSPC_KEYS KC_RSFT, KC_TRNS, KC_Y
#define LCPO_KEYS KC_LCTL, KC_TRNS, KC_SPC

// Unicode
// #define UNICODE_SELECTED_MODES UC_LNX

// Mouse
#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
// #define MK_COMBINED

#define MK_C_OFFSET_0 1
#define MK_C_INTERVAL_0 12

#define MK_C_OFFSET_1 4
#define MK_C_INTERVAL_1 18

#define MK_C_OFFSET_UNMOD 12
#define MK_C_INTERVAL_UNMOD 17

#define MK_C_OFFSET_2 27
#define MK_C_INTERVAL_2 15

#define MK_W_OFFSET_UNMOD 3
#define MK_W_INTERVAL_UNMOD 80

#define MK_W_OFFSET_0 1
#define MK_W_INTERVAL_0 300

#define MK_W_OFFSET_1 4
#define MK_W_INTERVAL_1 200

#define MK_W_OFFSET_2 5
#define MK_W_INTERVAL_2 30

