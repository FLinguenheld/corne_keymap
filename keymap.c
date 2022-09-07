/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of

GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <keymap_bepo.h>
#include "features/french.h"


#include "features/tap_dance.c"


        // SEND_STRING("aurnisetaurie");
        // send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");






const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(

  //|-----------------------+---------------+---------------+---------------+---------------+-----------------------|       |-----------------------+---------------+---------------+---------------+---------------+-----------------------|
       KC_TAB               ,     BP_Z      ,    BP_EACU    ,     BP_P      ,     BP_O      ,        BP_ECIR        ,                BP_AGRV        ,      BP_V     ,      BP_D     ,      BP_L     ,      BP_J     ,     TD(TD_BSPC_DEL)   ,
  //|-----------------------+---------------+---------------+---------------+---------------+-----------------------|       |-----------------------+---------------+---------------+---------------+---------------+-----------------------|
      GUI_T(KC_ESC)         ,     BP_A      ,     BP_U      ,     BP_I      ,     BP_E      ,   TD(TD_EXCLA_QUEST)  ,                 BP_C          ,      BP_T     ,      BP_S     ,      BP_R     ,      BP_N     ,     BP_M              ,
  //|-----------------------+---------------+---------------+---------------+---------------+-----------------------|       |-----------------------+---------------+---------------+---------------+---------------+-----------------------|
      TD(TD_ALT_TREMA)      ,     BP_B      ,     BP_Y      ,     BP_X      ,     BP_W      ,   TD(TD_QUOTE_3DOTS)  ,                 BP_K          ,      BP_Q     ,      BP_G     ,      BP_H     ,      BP_F     ,  MT(MOD_RSFT, BP_DCIR),
  //|-----------------------+---------------+---------------+---------------+---------------+-----------------------|       |-----------------------+---------------+---------------+---------------+---------------+-----------------------|
  //                                                  |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                MO(4)     ,   LT(1, BP_SCLN)  ,    LCTL_T(KC_SPC)     ,        KC_ENT             ,   LT(2, BP_COLN)  ,       MO(5)
  //                                                  |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [1] = LAYOUT_split_3x6_3(

  //|-----------------------+---------------+---------------+---------------+---------------+-----------------------|       |-----------------------+---------------+---------------+---------------+---------------+-----------------------|
            _______         ,    XXXXXXX    ,    BP_GRV     ,   BP_QUOTE    ,   BP_DQUO     ,        XXXXXXX        ,               XXXXXXX         ,   BP_HASH  ,    BP_D    ,    BP_L    ,    BP_J    ,     TD(TD_BSPC_DEL)   ,
  //|-----------------------+---------------+---------------+---------------+---------------+-----------------------|       |-----------------------+---------------+---------------+---------------+---------------+-----------------------|
            _______         ,    XXXXXXX    , TD(CURLY_BTS) , TD(BRACKETS)  , TD(PARENTHE)  ,        XXXXXXX        ,               XXXXXXX         ,    BP_T    ,    BP_S    ,    BP_R    ,    BP_N    ,     BP_M              ,
  //|-----------------------+---------------+---------------+---------------+---------------+-----------------------|       |-----------------------+---------------+---------------+---------------+---------------+-----------------------|
            _______         ,    XXXXXXX    ,    BP_Y       ,     BP_X      ,    BP_W       ,        XXXXXXX        ,               XXXXXXX         ,    BP_Q    ,    BP_G    ,    BP_H    ,    BP_F    ,  MT(MOD_RSFT, BP_DCIR),
  //|-----------------------+---------------+---------------+---------------+---------------+-----------------------|       |-----------------------+---------------+---------------+---------------+---------------+-----------------------|
  //                                                  |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                MO(4)     ,   LT(1, BP_SCLN)  ,    LCTL_T(KC_SPC)     ,        KC_ENT             ,   LT(2, BP_COLN)  ,       MO(5)
  //                                                  |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};




// Auto shift
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_TAB:
            return true;
        default:
            return false;
    }
}




