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

    CB_SWITCH_BEPO_USA,

    CB_LAYER_ADJUST,
    CB_LAYER_FN,

    CB_E_DANS_L_A,
    CB_E_DANS_L_O,
    CB_E_ACCENT,
    CB_A_ACCENT,
    CB_U_ACCENT,
    CB_C_CEDILLE,

    CB_MAIL_SHORT,
    CB_MAIL_LONG,


    // US
    US_CB_LAYER_ADJUST,
    US_CB_LAYER_FN,

    US_CB_MAIL_SHORT,
    US_CB_MAIL_LONG,


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

const uint16_t PROGMEM combo_e_dans_l_a[] = {BP_EACU, BP_A, COMBO_END};
const uint16_t PROGMEM combo_e_dans_l_o[] = {BP_EACU, BP_O, COMBO_END};

const uint16_t PROGMEM combo_e_accent[] = {BP_EACU, BP_E, COMBO_END};
const uint16_t PROGMEM combo_a_accent[] = {BP_E, BP_A, COMBO_END};
const uint16_t PROGMEM combo_u_accent[] = {BP_E, BP_U, COMBO_END};
const uint16_t PROGMEM combo_c_cedille[] = {BP_E, BP_C, COMBO_END};


// With macros !
const uint16_t PROGMEM combo_mail_short[] = {BP_M, BP_S, COMBO_END};
const uint16_t PROGMEM combo_mail_long[] = {BP_M, BP_L, COMBO_END};

const uint16_t PROGMEM us_combo_mail_short[] = {KC_M, KC_S, COMBO_END};
const uint16_t PROGMEM us_combo_mail_long[] = {KC_M, KC_L, COMBO_END};


// --------------------------------------------------
// --------------------------------------------------
// Sequences fo keys
combo_t key_combos[] = {

    [CB_SWITCH_BEPO_USA] = COMBO(switch_bepo_usa, TG(_US_BASE)),

    [CB_LAYER_ADJUST] = COMBO(combo_adjust, MO(_ADJUST)),
    [US_CB_LAYER_ADJUST] = COMBO(us_combo_adjust, MO(_US_ADJUST)),

    [CB_LAYER_FN] = COMBO(combo_fn, MO(_FN)),
    [US_CB_LAYER_FN] = COMBO(us_combo_fn, MO(_US_FN)),

    [CB_E_DANS_L_A] = COMBO(combo_e_dans_l_a, BP_AE),
    [CB_E_DANS_L_O] = COMBO(combo_e_dans_l_o, BP_OE),

    [CB_C_CEDILLE] = COMBO(combo_c_cedille, BP_CCED),
    [CB_E_ACCENT] = COMBO(combo_e_accent, BP_EGRV),
    [CB_A_ACCENT] = COMBO(combo_a_accent, BP_AGRV),
    [CB_U_ACCENT] = COMBO(combo_u_accent, BP_UGRV),


    [CB_MAIL_SHORT] = COMBO_ACTION(combo_mail_short),
    [CB_MAIL_LONG] = COMBO_ACTION(combo_mail_long),

    [US_CB_MAIL_SHORT] = COMBO_ACTION(us_combo_mail_short),
    [US_CB_MAIL_LONG] = COMBO_ACTION(us_combo_mail_long),
};


// --------------------------------------------------
// --------------------------------------------------
// Macros !
// Impossible to use the 'sendstring_bepo.h' because of the conversion to us.
// So bepo versions have to be converted from us (see the keymap_bepo.h file to match characters)
void process_combo_event(uint16_t combo_index, bool pressed) {

  switch(combo_index) {
        // Apparently, it works with us and bepo :o
    case CB_MAIL_SHORT:
      if (pressed) {
        SEND_STRING("/6od;.sf;,foiv/l");
      }
      break;

    case US_CB_MAIL_SHORT:
      if (pressed) {
        SEND_STRING("f@linguenheld.fr");
      }
      break;

    case CB_MAIL_LONG:
      if (pressed) {
        SEND_STRING("/orlf;j6od;,sf;.foiv/l");
      }
      break;

    case US_CB_MAIL_LONG:
      if (pressed) {
        SEND_STRING("florent@linguenheld.fr");
      }
      break;

    // case CB_VIM_COLON:
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
