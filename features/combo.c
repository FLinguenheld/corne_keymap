// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Combos

// How to :
//      - Add an entry in the enum
//      - Create a new sequence of keys
//      - Link the enum to this sequence in the key_combos table

// For macros :
//      - Same steps
//      - And add the macro in the process_combo_event() function

enum combos {

    LAYER_ADJUST,
    LAYER_FN_OSL,

    // French
    A_ACCENT,
    E_ACCENT,
    U_ACCENT,
    C_CEDILLE,

    E_DANS_L_A,
    E_DANS_L_O,

    // --
    ENTER_SHIFTED,
    CONTROL_SHIFT,
    CONTROL_ALT,
    CONTROL_SHIFT_ALT,
    RIGHT_ALT,

    // --
    AMPERSAND,
    AT,
    BACKSLASH,
    CIRCUMFLEX,
    DOLLAR,
    DOUBLE_QUOTE,
    EQUAL,
    EURO,

    GRAVE,
    HASH,
    PIPE,
    PERCENT,
    PLUS,
    SLASH,
    STAR,
    TILDE,
    TIRET,              // Sorry Elis but it's better than dash
    UNDERSCORE,

    // --
    // MAIL_SHORT,
        // KC_MAIL_SHORT,
    // MAIL_LONG,
        // KC_MAIL_LONG,

    COMBO_LENGTH, // Just to replace the define in config.h
};
uint16_t COMBO_LEN = COMBO_LENGTH;


// --------------------------------------------------
// --------------------------------------------------
// Sequences fo keys

const uint16_t PROGMEM combo_adjust[] = {LT(_MOUSE, KC_COMM), LT(_ARROWS, KC_DOT), COMBO_END};
const uint16_t PROGMEM combo_fn_osl[] = {LT(_ARROWS, KC_DOT), KC_F, COMBO_END};

// --
const uint16_t PROGMEM combo_enter_shifted[] = {LT(_NUMERIC, KC_ENT), KC_S, COMBO_END};
const uint16_t PROGMEM combo_control_shift[] = {KC_LCPO, KC_S, COMBO_END};
const uint16_t PROGMEM combo_control_alt[] = {KC_LCPO, KC_A, COMBO_END};
const uint16_t PROGMEM combo_control_shift_alt[] = {KC_LCPO, KC_S, KC_A, COMBO_END};
const uint16_t PROGMEM combo_right_alt[] = {KC_LAPO, KC_G, COMBO_END};

// --
const uint16_t PROGMEM combo_a_accent[] = {KC_E, KC_A, COMBO_END};
const uint16_t PROGMEM combo_e_accent[] = {CS_EACUTE, KC_E, COMBO_END};
const uint16_t PROGMEM combo_u_accent[] = {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM combo_c_cedille[] = {KC_E, KC_C, COMBO_END};

const uint16_t PROGMEM combo_e_dans_l_a[] = {CS_EACUTE, KC_A, COMBO_END};
const uint16_t PROGMEM combo_e_dans_l_o[] = {CS_EACUTE, KC_O, COMBO_END};

// --
const uint16_t PROGMEM combo_ampersand[] = {KC_A, KC_P, COMBO_END};
const uint16_t PROGMEM combo_at[] = {KC_A, KC_T, COMBO_END};
const uint16_t PROGMEM combo_backslash[] = {KC_D, KC_R, COMBO_END};
const uint16_t PROGMEM combo_circumflex[] = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM combo_dollar[] = {KC_D, KC_L, COMBO_END};
const uint16_t PROGMEM combo_double_quote[] = {KC_D, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_equal[] = {KC_E, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_euro[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_grave[] = {KC_G, KC_R, COMBO_END};
const uint16_t PROGMEM combo_hash[] = {KC_H, KC_S, COMBO_END};
const uint16_t PROGMEM combo_percent[] = {KC_P, KC_C, COMBO_END};
const uint16_t PROGMEM combo_pipe[] = {KC_P, KC_E, COMBO_END};
const uint16_t PROGMEM combo_plus[] = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM combo_slash[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM combo_star[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo_tilde[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM combo_tiret[] = {KC_T, KC_R, COMBO_END};
const uint16_t PROGMEM combo_underscore[] = {KC_S, KC_R, COMBO_END};


// With macros !
// const uint16_t PROGMEM combo_mail_short[] = {KC_M, KC_S, COMBO_END};
// const uint16_t PROGMEM us_combo_mail_short[] = {KC_M, KC_S, COMBO_END};

// const uint16_t PROGMEM combo_mail_long[] = {KC_M, KC_L, COMBO_END};
// const uint16_t PROGMEM us_combo_mail_long[] = {KC_M, KC_L, COMBO_END};


// --------------------------------------------------
// --------------------------------------------------
// Sequences fo keys
combo_t key_combos[] = {

    [LAYER_ADJUST] = COMBO(combo_adjust, MO(_ADJUST)),
    [LAYER_FN_OSL] = COMBO(combo_fn_osl, OSL(_FN)),

    // --
    [ENTER_SHIFTED] = COMBO(combo_enter_shifted, S(KC_ENT)),
    [CONTROL_SHIFT] = COMBO(combo_control_shift, C(S(XXXXXXX))),
    [CONTROL_ALT] = COMBO(combo_control_alt, C(A(XXXXXXX))),
    [CONTROL_SHIFT_ALT] = COMBO(combo_control_shift_alt, C(S(A(XXXXXXX)))),
    [RIGHT_ALT] = COMBO(combo_right_alt, KC_RALT),

    // French
    [A_ACCENT] = COMBO(combo_a_accent, CS_AGRAVE),
    [E_ACCENT] = COMBO(combo_e_accent, CS_EGRAVE),
    [U_ACCENT] = COMBO(combo_u_accent, CS_UGRAVE),
    [C_CEDILLE] = COMBO(combo_c_cedille, CS_CCEDILLE),

    [E_DANS_L_A] = COMBO(combo_e_dans_l_a, CS_AE),
    [E_DANS_L_O] = COMBO(combo_e_dans_l_o, CS_OE),

    // --
    [AMPERSAND] = COMBO(combo_ampersand, KC_AMPR),

    [AT] = COMBO(combo_at, KC_AT),
    [BACKSLASH] = COMBO(combo_backslash, KC_BSLS),
    [DOUBLE_QUOTE] = COMBO(combo_double_quote, KC_DQUO),
    [EQUAL] = COMBO(combo_equal, KC_EQL),
    [GRAVE] = COMBO(combo_grave, KC_GRV),
    [HASH] = COMBO(combo_hash, KC_HASH),
    [PERCENT] = COMBO(combo_percent, KC_PERC),
    [PIPE] = COMBO(combo_pipe, KC_PIPE),
    [PLUS] = COMBO(combo_plus, KC_PLUS),
    [SLASH] = COMBO(combo_slash, KC_SLSH),
    [STAR] = COMBO(combo_star, KC_ASTR),
    [TILDE] = COMBO(combo_tilde, KC_TILD),
    [TIRET] = COMBO(combo_tiret, KC_MINS),
    [UNDERSCORE] = COMBO(combo_underscore, KC_UNDS),
    // --
    [DOLLAR] = COMBO(combo_dollar, KC_DLR),
    [EURO] = COMBO(combo_euro, US_EURO),

    // --
    // [MAIL_SHORT] = COMBO_ACTION(combo_mail_short),
    // [MAIL_LONG] = COMBO_ACTION(combo_mail_long),

    // [KC_MAIL_SHORT] = COMBO_ACTION(us_combo_mail_short),
    // [KC_MAIL_LONG] = COMBO_ACTION(us_combo_mail_long),
};


// --------------------------------------------------
// --------------------------------------------------
// Macros !
// Impossible to use the 'sendstring_bepo.h' because of the conversion to us.
// So bepo versions have to be converted from us (see the keymap_bepo.h file to match characters)
// void process_combo_event(uint16_t combo_index, bool pressed) {

  // switch(combo_index) {


  // // switch(combo_index) {
        // // // Apparently, it works with us and bepo :o
    // // case MAIL_SHORT:
      // // if (pressed) {
        // // SEND_STRING("/6od;,sf;.foiv/l");
      // // }
      // // break;

    // // case KC_MAIL_SHORT:
      // // if (pressed) {
        // // SEND_STRING("f@linguenheld.fr");
      // // }
      // // break;

    // // case MAIL_LONG:
      // // if (pressed) {
        // // SEND_STRING("/orlf;j6od;,sf;.foiv/l");
      // // }
      // // break;

    // // case KC_MAIL_LONG:
      // // if (pressed) {
        // // SEND_STRING("florent@linguenheld.fr");
      // // }
      // // break;

    // // // case VIM_COLON:
      // // // if (pressed) {
        // // // SEND_STRING(SS_TAP(X_ESC) SS_LSFT("a") ":" SS_TAP(X_ESC));
      // // // }
      // // // break;

    // // // case VIM_NOH:
      // // // if (pressed) {
        // // // tap_code16(KC_ESC);
        // // // tap_code16(KC_COLN);
        // // // tap_code16(KC_N);
        // // // tap_code16(KC_O);
        // // // tap_code16(KC_H);
        // // // tap_code16(KC_ENTER);
      // // // }
      // // // break;
  // // }
// }
