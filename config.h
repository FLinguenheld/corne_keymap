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
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 40
#define MOUSEKEY_MAX_SPEED 10
#define MOUSEKEY_WHEEL_DELAY 0
