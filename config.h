/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */
// #define MASTER_LEFT
#define MASTER_RIGHT


// OLED
#define SPLIT_OLED_ENABLE // Sync both oled (on/off status only)
#define OLED_BRIGHTNESS 100 // Protect my eyesss
// #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define OLED_FONT_H "keyboards/crkbd/keymaps/corne_keymap/font/glcdfont_flo.c"

// Auto shift
#define AUTO_SHIFT_TIMEOUT 122

// #define NO_AUTO_SHIFT_SPECIAL // Problems with bépo
// #define NO_AUTO_SHIFT_NUMERIC

#define UNICODE_SELECTED_MODES UC_LNX

// Tap dance
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 122 // Same as auto shift
#define IGNORE_MOD_TAP_INTERRUPT

// Combo
#define COMBO_COUNT 3
