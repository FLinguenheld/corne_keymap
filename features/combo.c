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

    SWITCH_BEPO_USA,

    LAYER_ADJUST,
        US_LAYER_ADJUST,
    LAYER_FN,
        US_LAYER_FN,
    LAYER_FN_OSL,
        US_LAYER_FN_OSL,

    E_DANS_L_A,
    E_DANS_L_O,
    E_ACCENT,
    A_ACCENT,
    U_ACCENT,
    C_CEDILLE,

    // --
    AMPERSAND,
        US_AMPERSAND,
    AT,
        US_AT,
    CIRCUMFLEX,
        US_CIRCUMFLEX,
    HASH,
        US_HASH,
    PIPE,
        US_PIPE,
    TILDE,
        US_TILDE,
    TIRET,              // Sorry Elis but it's better than dash
        US_TIRET,
    UNDERSCORE,
        US_UNDERSCORE,

    DOLLAR,
        US_DOLLAR,
    EURO,
        US_EURO,

    MAIL_SHORT,
        US_MAIL_SHORT,
    MAIL_LONG,
        US_MAIL_LONG,


    COMBO_LENGTH, // Just to replace the define in config.h
};
uint16_t COMBO_LEN = COMBO_LENGTH;


// --------------------------------------------------
// --------------------------------------------------
// Sequences fo keys
const uint16_t PROGMEM switch_bepo_usa[] = {KC_TAB, KC_BSPC, COMBO_END};

const uint16_t PROGMEM combo_adjust[] = {LT(_LOWER, BP_COMM), LT(_RAISE, BP_DOT), COMBO_END};
const uint16_t PROGMEM us_combo_adjust[] = {LT(_US_LOWER, KC_COMMA), LT(_US_RAISE, KC_DOT), COMBO_END};

const uint16_t PROGMEM combo_fn[] = {TD(TDS_ARROWS_SCOLON), TD(TDS_ARROWS_COLON), COMBO_END};
const uint16_t PROGMEM us_combo_fn[] = {LT(_US_ARROWS, KC_SCLN), TD(US_TDS_ARROWS_COLON), COMBO_END};

const uint16_t PROGMEM combo_fn_osl[] = {TD(TDS_ARROWS_COLON), BP_F, COMBO_END};
const uint16_t PROGMEM us_combo_fn_osl[] = {TD(US_TDS_ARROWS_COLON), KC_F, COMBO_END};

// --
const uint16_t PROGMEM combo_e_dans_l_a[] = {BP_EACU, BP_A, COMBO_END};
const uint16_t PROGMEM combo_e_dans_l_o[] = {BP_EACU, BP_O, COMBO_END};

const uint16_t PROGMEM combo_e_accent[] = {BP_EACU, BP_E, COMBO_END};
const uint16_t PROGMEM combo_a_accent[] = {BP_E, BP_A, COMBO_END};
const uint16_t PROGMEM combo_u_accent[] = {BP_E, BP_U, COMBO_END};
const uint16_t PROGMEM combo_c_cedille[] = {BP_E, BP_C, COMBO_END};

// --
const uint16_t PROGMEM combo_ampersand[] = {BP_A, BP_M, COMBO_END};
const uint16_t PROGMEM us_combo_ampersand[] = {KC_A, KC_M, COMBO_END};

const uint16_t PROGMEM combo_at[] = {BP_A, BP_T, COMBO_END};
const uint16_t PROGMEM us_combo_at[] = {KC_A, KC_T, COMBO_END};

const uint16_t PROGMEM combo_circumflex[] = {BP_C, BP_R, COMBO_END};
const uint16_t PROGMEM us_combo_circumflex[] = {KC_C, KC_R, COMBO_END};

const uint16_t PROGMEM combo_hash[] = {BP_H, BP_S, COMBO_END};
const uint16_t PROGMEM us_combo_hash[] = {KC_H, KC_S, COMBO_END};

const uint16_t PROGMEM combo_pipe[] = {BP_P, BP_E, COMBO_END};
const uint16_t PROGMEM us_combo_pipe[] = {KC_P, KC_E, COMBO_END};

const uint16_t PROGMEM combo_tilde[] = {BP_T, BP_D, COMBO_END};
const uint16_t PROGMEM us_combo_tilde[] = {KC_T, KC_D, COMBO_END};

const uint16_t PROGMEM combo_tiret[] = {BP_T, BP_R, COMBO_END};
const uint16_t PROGMEM us_combo_tiret[] = {KC_T, KC_R, COMBO_END};

const uint16_t PROGMEM combo_underscore[] = {BP_S, BP_R, COMBO_END};
const uint16_t PROGMEM us_combo_underscore[] = {KC_S, KC_R, COMBO_END};

// --
const uint16_t PROGMEM combo_dollar[] = {BP_D, BP_L, COMBO_END};
const uint16_t PROGMEM us_combo_dollar[] = {KC_D, KC_L, COMBO_END};

const uint16_t PROGMEM combo_euro[] = {BP_E, BP_U, BP_R, COMBO_END};
// const uint16_t PROGMEM us_combo_euro[] = {KC_E, KC_U, KC_R, COMBO_END};

// With macros !
const uint16_t PROGMEM combo_mail_short[] = {BP_M, BP_S, COMBO_END};
const uint16_t PROGMEM combo_mail_long[] = {BP_M, BP_L, COMBO_END};

const uint16_t PROGMEM us_combo_mail_short[] = {KC_M, KC_S, COMBO_END};
const uint16_t PROGMEM us_combo_mail_long[] = {KC_M, KC_L, COMBO_END};


// --------------------------------------------------
// --------------------------------------------------
// Sequences fo keys
combo_t key_combos[] = {

    [SWITCH_BEPO_USA] = COMBO(switch_bepo_usa, TG(_US_BASE)),

    [LAYER_ADJUST] = COMBO(combo_adjust, MO(_ADJUST)),
    [US_LAYER_ADJUST] = COMBO(us_combo_adjust, MO(_US_ADJUST)),

    [LAYER_FN] = COMBO(combo_fn, MO(_FN)),
    [US_LAYER_FN] = COMBO(us_combo_fn, MO(_US_FN)),

    [LAYER_FN_OSL] = COMBO(combo_fn_osl, OSL(_FN)),
    [US_LAYER_FN_OSL] = COMBO(us_combo_fn_osl, OSL(_US_FN)),

    // --
    [E_DANS_L_A] = COMBO(combo_e_dans_l_a, BP_AE),
    [E_DANS_L_O] = COMBO(combo_e_dans_l_o, BP_OE),

    [C_CEDILLE] = COMBO(combo_c_cedille, BP_CCED),
    [E_ACCENT] = COMBO(combo_e_accent, BP_EGRV),
    [A_ACCENT] = COMBO(combo_a_accent, BP_AGRV),
    [U_ACCENT] = COMBO(combo_u_accent, BP_UGRV),

    // --
    [AMPERSAND] = COMBO(combo_ampersand, BP_AMPR),
    [US_AMPERSAND] = COMBO(us_combo_ampersand, KC_AMPERSAND),

    [AT] = COMBO(combo_at, BP_AT),
    [US_AT] = COMBO(us_combo_at, KC_AT),

    [CIRCUMFLEX] = COMBO(combo_circumflex, BP_CIRC),
    [US_CIRCUMFLEX] = COMBO(us_combo_circumflex, KC_CIRCUMFLEX),

    [HASH] = COMBO(combo_hash, BP_HASH),
    [US_HASH] = COMBO(us_combo_hash, KC_HASH),

    [PIPE] = COMBO(combo_pipe, BP_PIPE),
    [US_PIPE] = COMBO(us_combo_pipe, KC_PIPE),

    [TILDE] = COMBO(combo_tilde, BP_TILD),
    [US_TILDE] = COMBO(us_combo_tilde, KC_TILDE),

    [TIRET] = COMBO(combo_tiret, KC_MINS),
    [US_TIRET] = COMBO(us_combo_tiret, KC_MINUS),

    [UNDERSCORE] = COMBO(combo_underscore, BP_UNDS),
    [US_UNDERSCORE] = COMBO(us_combo_underscore, KC_UNDERSCORE),

    // --
    [DOLLAR] = COMBO(combo_dollar, BP_DLR),
    [US_DOLLAR] = COMBO(us_combo_dollar, KC_DOLLAR),

    [EURO] = COMBO(combo_euro, BP_EURO),
    // [US_EURO] = COMBO(us_combo_at, KC_AT),

    // --
    [MAIL_SHORT] = COMBO_ACTION(combo_mail_short),
    [MAIL_LONG] = COMBO_ACTION(combo_mail_long),

    [US_MAIL_SHORT] = COMBO_ACTION(us_combo_mail_short),
    [US_MAIL_LONG] = COMBO_ACTION(us_combo_mail_long),
};


// --------------------------------------------------
// --------------------------------------------------
// Macros !
// Impossible to use the 'sendstring_bepo.h' because of the conversion to us.
// So bepo versions have to be converted from us (see the keymap_bepo.h file to match characters)
void process_combo_event(uint16_t combo_index, bool pressed) {

  switch(combo_index) {
        // Apparently, it works with us and bepo :o
    case MAIL_SHORT:
      if (pressed) {
        SEND_STRING("/6od;,sf;.foiv/l");
      }
      break;

    case US_MAIL_SHORT:
      if (pressed) {
        SEND_STRING("f@linguenheld.fr");
      }
      break;

    case MAIL_LONG:
      if (pressed) {
        SEND_STRING("/orlf;j6od;,sf;.foiv/l");
      }
      break;

    case US_MAIL_LONG:
      if (pressed) {
        SEND_STRING("florent@linguenheld.fr");
      }
      break;

    // case VIM_COLON:
      // if (pressed) {
        // SEND_STRING(SS_TAP(X_ESC) SS_LSFT("a") ":" SS_TAP(X_ESC));
      // }
      // break;

    // case BSPC_LSFT_CLEAR:
      // if (pressed) {
        // tap_code16(KC_END);
        // tap_code16(S(KC_HOME));
        // tap_code16(KC_BSPC);
      // }
      // break;

  }
}
