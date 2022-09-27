/*
QMK keymap for the crkbd keyboard 3x6
Flo 2022

https://github.com/foostan/crkbd
https://docs.qmk.fm/#/
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <keymap_bepo.h>
// https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_bepo.h


// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Layers -----------------------------------------------------------------------------------------------------------------------------------------------
enum layers { 
    _BASE, 
    _NUMERIC, 
    _ARROWS,
    _MOUSE,
    _ADJUST,
    _FN,

    // US --
    _US_BASE,
    _US_NUMERIC,
    _US_ARROWS,
    _US_MOUSE,
    _US_ADJUST,
    _US_FN,
};

// Current language ?
int is_currently_in_us(void) {

    switch (get_highest_layer(layer_state)) {

        case _US_BASE:
        case _US_NUMERIC:
        case _US_ARROWS:
        case _US_MOUSE:
        case _US_ADJUST:
        case _US_FN:
            return true;

        default:
            return false;
    }
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Timer ------------------------------------------------------------------------------------------------------------------------------------------------
// To shutdown oled screens
static uint16_t oled_timer = 0;
static bool     is_key_processed = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // Restart the timer on all pressed key
    // The timer value is read by the oled_task_user() function
    if (record->event.pressed) {
        oled_timer = timer_read();
        is_key_processed = true;
    }

    return true;
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Features ---------------------------------------------------------------------------------------------------------------------------------------------

// #include "features/tap_dance.c"
#include "features/auto_shift.c"
#include "features/combo.c"
#include "features/oled.c"

// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Layouts ----------------------------------------------------------------------------------------------------------------------------------------------

  /* [1] = LAYOUT_split_3x6_3(

  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                  XXXXXXX     ,       XXXXXXX     ,         XXXXXXX       ,          XXXXXXX          ,     XXXXXXX       ,      XXXXXXX
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ), */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_split_3x6_3(
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
      KC_TAB                ,     BP_Z       ,    BP_EACU     ,     BP_P       ,     BP_O       ,        BP_J           ,                 BP_K          ,      BP_V      ,      BP_D      ,      BP_L      ,      BP_M      ,       KC_BSPC         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
      GUI_T(KC_ESC)         ,     BP_A       ,     BP_U       ,     BP_I       ,     BP_E       ,       BP_EXLM         ,                 BP_C          ,      BP_T      ,      BP_S      ,      BP_R      ,      BP_N      ,     RCS_T(BP_QUOT)    ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
      KC_LAPO               ,     BP_B       ,     BP_Y       ,     BP_X       ,     BP_W       ,       BP_LABK         ,                BP_RABK        ,      BP_Q      ,      BP_G      ,      BP_H      ,      BP_F      ,       KC_RSPC         ,
  //|---/* ALT ¨ */---------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+------/* SFT ^ */------|
  //                                                |----------------------+----------------------+-----------------------|   |-----------------------+----------------------+----------------------|
                                                            BP_SCLN        , LT(_MOUSE, BP_COMM) ,        KC_LCPO        ,       LT(_NUMERIC, KC_ENT) , LT(_ARROWS, BP_DOT)  ,     BP_COLN
  //                                                |----------------------+----------------------+----/* Space ctl */----|   |-----------------------+----------------------+----------------------|
  ),

  [_NUMERIC] = LAYOUT_split_3x6_3(
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     BP_RCBR    ,     BP_RBRC    ,    BP_RPRN     ,        XXXXXXX        ,                BP_COMM        ,      BP_7      ,      BP_8      ,      BP_9      ,     BP_PLUS    ,       BP_MINS         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     BP_LCBR    ,     BP_LBRC    ,    BP_LPRN     ,        XXXXXXX        ,                 BP_EQL        ,      BP_4      ,      BP_5      ,      BP_6      ,     BP_ASTR    ,       BP_SLSH         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,                 BP_DOT        ,      BP_1      ,      BP_2      ,      BP_3      ,     BP_CIRC    ,       BP_PERC         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                  XXXXXXX     ,       XXXXXXX     ,         XXXXXXX       ,          XXXXXXX          ,     XXXXXXX       ,      BP_0
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,  KC_MS_WH_LEFT ,   KC_MS_WH_UP  ,  KC_MS_WH_DOWN , KC_MS_WH_RIGHT ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,     XXXXXXX    ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,   KC_MS_LEFT   ,    KC_MS_UP    ,   KC_MS_DOWN   ,   KC_MS_RIGHT  ,        XXXXXXX        ,               XXXXXXX         ,  KC_MS_ACCEL0  ,  KC_MS_ACCEL1  ,  KC_MS_ACCEL2  ,    XXXXXXX     ,       KC_RCTL         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,   KC_MS_BTN1   ,     XXXXXXX    ,   KC_MS_BTN3   ,   KC_MS_BTN2   ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,     XXXXXXX    ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                 XXXXXXX      ,     XXXXXXX       ,        _______        ,          KC_MS_BTN1       ,     KC_MS_BTN3    ,     KC_MS_BTN2
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [_ARROWS] = LAYOUT_split_3x6_3(
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,        XXXXXXX        ,               XXXXXXX         ,    KC_HOME     ,  KC_PAGE_DOWN  ,   KC_PAGE_UP   ,     KC_END     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,        XXXXXXX        ,               XXXXXXX         ,    KC_LEFT     ,    KC_DOWN     ,     KC_UP      ,    KC_RIGHT    ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    C(BP_D)     ,    C(BP_U)     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                 XXXXXXX      ,     XXXXXXX       ,        _______        ,          XXXXXXX          ,     XXXXXXX       ,      XXXXXXX
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     , KC_AUDIO_MUTE  , KC_AUDIO_VOL_UP,   KC_AUDIO_VOL_DOWN   ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                 XXXXXXX      ,       XXXXXXX     ,         XXXXXXX       ,          XXXXXXX          ,     XXXXXXX       ,      XXXXXXX
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [_FN] = LAYOUT_split_3x6_3(
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,      KC_F7     ,      KC_F8     ,      KC_F9     ,     KC_F10     ,    KC_PRINT_SCREEN    ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,      KC_F4     ,      KC_F5     ,      KC_F6     ,     KC_F11     ,   S(KC_PRINT_SCREEN)  ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,      KC_F1     ,      KC_F2     ,      KC_F3     ,     KC_F12     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                  XXXXXXX     ,       XXXXXXX     ,         XXXXXXX       ,          XXXXXXX          ,     XXXXXXX       ,      XXXXXXX
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),


// ------------------------------------------------------------------------------------------------------------------------------------------------------
// USA --------------------------------------------------------------------------------------------------------------------------------------------------

  [_US_BASE] = LAYOUT_split_3x6_3(
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
       KC_TAB               ,     KC_Z       ,    XXXXXXX     ,     KC_P       ,     KC_O       ,        KC_J           ,                 KC_K          ,      KC_V      ,      KC_D      ,      KC_L      ,      KC_M      ,     KC_BSPC           ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
      LGUI_T(KC_ESC)        ,     KC_A       ,     KC_U       ,     KC_I       ,     KC_E       ,       KC_EXLM         ,                 KC_C          ,      KC_T      ,      KC_S      ,      KC_R      ,      KC_N      ,    RCS_T(KC_QUOTE)    ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
       KC_LALT              ,     KC_B       ,     KC_Y       ,     KC_X       ,     KC_W       ,       KC_LABK         ,                KC_RABK        ,      KC_Q      ,      KC_G      ,      KC_H      ,      KC_F      ,     KC_RSFT           ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                            |------------------------+------------------------+-----------------------|   |-----------------------+------------------------+------------------------|
                                                       KC_SEMICOLON      , LT(_US_MOUSE, KC_COMMA),        KC_LCPO        ,    LT(_US_NUMERIC, KC_ENT), LT(_US_ARROWS, KC_DOT) ,      KC_COLON
  //                                            |------------------------+------------------------+----/* Space ctl */----|   |-----------------------+------------------------+------------------------|
  ),

  [_US_NUMERIC] = LAYOUT_split_3x6_3(
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     KC_RCBR    ,     KC_RBRC    ,    KC_RPRN     ,        XXXXXXX        ,               KC_COMMA        ,      KC_7      ,      KC_8      ,      KC_9      ,     KC_PLUS    ,       KC_MINUS        ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     KC_LCBR    ,     KC_LBRC    ,    KC_LPRN     ,        XXXXXXX        ,                KC_EQL         ,      KC_4      ,      KC_5      ,      KC_6      ,   KC_ASTERISK  ,       KC_SLASH        ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,                KC_DOT         ,      KC_1      ,      KC_2      ,      KC_3      ,     KC_CIRC    ,      KC_PERCENT       ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                  XXXXXXX     ,       XXXXXXX     ,         XXXXXXX       ,          XXXXXXX          ,     XXXXXXX       ,      KC_0
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [_US_MOUSE] = LAYOUT_split_3x6_3(
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,  KC_MS_WH_LEFT ,   KC_MS_WH_UP  ,  KC_MS_WH_DOWN , KC_MS_WH_RIGHT ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,     XXXXXXX    ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,   KC_MS_LEFT   ,    KC_MS_UP    ,   KC_MS_DOWN   ,   KC_MS_RIGHT  ,        XXXXXXX        ,               XXXXXXX         ,  KC_MS_ACCEL0  ,  KC_MS_ACCEL1  ,  KC_MS_ACCEL2  ,    XXXXXXX     ,       KC_RCTL         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,   KC_MS_BTN1   ,     XXXXXXX    ,   KC_MS_BTN3   ,   KC_MS_BTN2   ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,     XXXXXXX    ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                 XXXXXXX      ,     XXXXXXX       ,        _______        ,          KC_MS_BTN1       ,     KC_MS_BTN3    ,     KC_MS_BTN2
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [_US_ARROWS] = LAYOUT_split_3x6_3(
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,        XXXXXXX        ,               XXXXXXX         ,    KC_HOME     ,  KC_PAGE_DOWN  ,   KC_PAGE_UP   ,     KC_END     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,        XXXXXXX        ,               XXXXXXX         ,    KC_LEFT     ,    KC_DOWN     ,     KC_UP      ,    KC_RIGHT    ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    C(KC_D)     ,    C(KC_U)     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                 XXXXXXX      ,     XXXXXXX       ,        _______        ,          XXXXXXX          ,     XXXXXXX       ,      XXXXXXX
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [_US_ADJUST] = LAYOUT_split_3x6_3(
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     , KC_AUDIO_MUTE  , KC_AUDIO_VOL_UP,   KC_AUDIO_VOL_DOWN   ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,    XXXXXXX     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                  XXXXXXX     ,       XXXXXXX     ,         XXXXXXX       ,          XXXXXXX          ,     XXXXXXX       ,      XXXXXXX
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),

  [_US_FN] = LAYOUT_split_3x6_3(
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,      KC_F7     ,      KC_F8     ,      KC_F9     ,     KC_F10     ,    KC_PRINT_SCREEN    ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,      KC_F4     ,      KC_F5     ,      KC_F6     ,     KC_F11     ,   S(KC_PRINT_SCREEN)  ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
            _______         ,     XXXXXXX    ,     XXXXXXX    ,     XXXXXXX    ,    XXXXXXX     ,        XXXXXXX        ,               XXXXXXX         ,      KC_F1     ,      KC_F2     ,      KC_F3     ,     KC_F12     ,       _______         ,
  //|-----------------------+----------------+----------------+----------------+----------------+-----------------------|       |-----------------------+----------------+----------------+----------------+----------------+-----------------------|
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
                                                                  XXXXXXX     ,       XXXXXXX     ,         _______       ,          XXXXXXX          ,     XXXXXXX       ,      XXXXXXX
  //                                                      |-------------------+-------------------+-----------------------|   |-----------------------+-------------------+-------------------|
  ),
};
