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
    LAYER_FN,
    LAYER_FN_2,

    // French
    A_GRAVE,
    E_GRAVE,
    U_GRAVE,

    C_CEDILLA,
    E_A,
    E_O,

    A_CIRCUMFLEX,
    E_CIRCUMFLEX,
    I_CIRCUMFLEX,
    O_CIRCUMFLEX,
    U_CIRCUMFLEX,
    E_DIAERESIS,
    I_DIAERESIS,
    U_DIAERESIS,
    Y_DIAERESIS,

    // --
    ENTER_SHIFTED,
    CONTROL_SHIFT,
    CONTROL_ALT,
    CONTROL_SHIFT_ALT,
    RIGHT_ALT,
    ALT_SHIFT,

    // --
    AMPERSAND,
    BACKSLASH,
    CIRCUMFLEX,
    EQUAL,

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

    DOLLAR,
    EURO,
    POUND,

    PARENTHESIS_LEFT,
    PARENTHESIS_RIGHT,
    BRACKET_LEFT,
    BRACKET_RIGHT,
    CURLY_BRACKET_LEFT,
    CURLY_BRACKET_RIGHT,

    // --
    DEGREE,
    DIAMETER,
    SUPERSCRIPT_1,
    SUPERSCRIPT_2,
    SUPERSCRIPT_3,

    // --
    MAIL_SHORT,
    MAIL_LONG,

    COMBO_LENGTH, // Just to replace the define in config.h
};
uint16_t COMBO_LEN = COMBO_LENGTH;


// --------------------------------------------------
// --------------------------------------------------
// Sequences fo keys

const uint16_t PROGMEM combo_adjust[] =                 {LT(_MOUSE, KC_COMM), LT(_ARROWS, KC_DOT), COMBO_END};
const uint16_t PROGMEM combo_fn[] =                     {LT(_NUMERIC, KC_ENT), KC_F, COMBO_END};
const uint16_t PROGMEM combo_fn_2[] =                   {LT(_NUMERIC, KC_ENT), KC_LCPO, COMBO_END};

// --
const uint16_t PROGMEM combo_enter_shifted[] =          {LT(_NUMERIC, KC_ENT), KC_S, COMBO_END};
const uint16_t PROGMEM combo_control_shift[] =          {KC_LCPO, KC_S, COMBO_END};
const uint16_t PROGMEM combo_control_alt[] =            {KC_LCPO, KC_LALT, COMBO_END};
const uint16_t PROGMEM combo_control_shift_alt[] =      {KC_LCPO, KC_S, KC_A, COMBO_END};
const uint16_t PROGMEM combo_right_alt[] =              {KC_LALT, KC_G, COMBO_END};
const uint16_t PROGMEM combo_alt_shift[] =              {KC_LALT, KC_S, COMBO_END};

// --
const uint16_t PROGMEM combo_a_grave[] =                {KC_LCPO, KC_A, COMBO_END};
const uint16_t PROGMEM combo_e_grave[] =                {KC_LCPO, CS_EACUTE, COMBO_END};
const uint16_t PROGMEM combo_u_grave[] =                {KC_LCPO, KC_U, COMBO_END};

const uint16_t PROGMEM combo_c_cedilla[] =              {CS_EACUTE, KC_I, COMBO_END};
const uint16_t PROGMEM combo_ea[] =                     {CS_EACUTE, KC_A, COMBO_END};
const uint16_t PROGMEM combo_eo[] =                     {CS_EACUTE, KC_O, COMBO_END};

const uint16_t PROGMEM combo_a_circumflex[] =           {LT(_MOUSE, KC_COMM), KC_A, COMBO_END};
const uint16_t PROGMEM combo_e_circumflex[] =           {LT(_MOUSE, KC_COMM), CS_EACUTE, COMBO_END};
const uint16_t PROGMEM combo_i_circumflex[] =           {LT(_MOUSE, KC_COMM), KC_I, COMBO_END};
const uint16_t PROGMEM combo_o_circumflex[] =           {LT(_MOUSE, KC_COMM), KC_O, COMBO_END};
const uint16_t PROGMEM combo_u_circumflex[] =           {LT(_MOUSE, KC_COMM), KC_U, COMBO_END};
const uint16_t PROGMEM combo_e_diaeresis[] =            {KC_SCLN, CS_EACUTE, COMBO_END};
const uint16_t PROGMEM combo_i_diaeresis[] =            {KC_SCLN, KC_I, COMBO_END};
const uint16_t PROGMEM combo_u_diaeresis[] =            {KC_SCLN, KC_U, COMBO_END};
const uint16_t PROGMEM combo_y_diaeresis[] =            {KC_SCLN, KC_Y, COMBO_END};

// --
const uint16_t PROGMEM combo_ampersand[] =              {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM combo_backslash[] =              {KC_D, KC_R, COMBO_END};
const uint16_t PROGMEM combo_circumflex[] =             {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM combo_equal[] =                  {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM combo_grave[] =                  {KC_G, KC_R, COMBO_END};
const uint16_t PROGMEM combo_hash[] =                   {KC_H, KC_S, COMBO_END};
const uint16_t PROGMEM combo_percent[] =                {KC_P, KC_E, COMBO_END};
const uint16_t PROGMEM combo_pipe[] =                   {KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM combo_plus[] =                   {KC_P, KC_U, COMBO_END};
const uint16_t PROGMEM combo_slash[] =                  {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM combo_star[] =                   {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo_tilde[] =                  {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM combo_tiret[] =                  {KC_T, KC_R, COMBO_END};
const uint16_t PROGMEM combo_underscore[] =             {KC_S, KC_R, COMBO_END};

// --
const uint16_t PROGMEM combo_dollar[] =                 {KC_D, KC_L, COMBO_END};
const uint16_t PROGMEM combo_euro[] =                   {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_pound[] =                  {KC_P, KC_D, COMBO_END};

// --
const uint16_t PROGMEM combo_parenthesis_left[] =       {KC_Y, KC_E, COMBO_END};
const uint16_t PROGMEM combo_parenthesis_right[] =      {KC_U, KC_W, COMBO_END};
const uint16_t PROGMEM combo_bracket_left[] =           {KC_X, KC_E, COMBO_END};
const uint16_t PROGMEM combo_bracket_right[] =          {KC_I, KC_W, COMBO_END};
const uint16_t PROGMEM combo_curly_bracket_left[] =     {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM combo_curly_bracket_right[] =    {KC_U, KC_X, COMBO_END};

// --
const uint16_t PROGMEM combo_degree[] =                 {KC_D, KC_G, KC_R, COMBO_END};
const uint16_t PROGMEM combo_diameter[] =               {KC_D, KC_I, KC_A, COMBO_END};
const uint16_t PROGMEM combo_superscript_1[] =          {KC_CIRC, KC_1, COMBO_END};
const uint16_t PROGMEM combo_superscript_2[] =          {KC_CIRC, KC_2, COMBO_END};
const uint16_t PROGMEM combo_superscript_3[] =          {KC_CIRC, KC_3, COMBO_END};

// With macros !
const uint16_t PROGMEM combo_mail_short[] =             {KC_M, KC_S, COMBO_END};
const uint16_t PROGMEM combo_mail_long[] =              {KC_M, KC_L, COMBO_END};


// --------------------------------------------------
// --------------------------------------------------
// Sequences fo keys
combo_t key_combos[] = {

    [LAYER_ADJUST] = COMBO(combo_adjust,                    OSL(_ADJUST)),
    [LAYER_FN] = COMBO(combo_fn,                            OSL(_FN)),
    [LAYER_FN_2] = COMBO(combo_fn_2,                        OSL(_FN)),

    // --
    [ENTER_SHIFTED] = COMBO(combo_enter_shifted,            S(KC_ENT)),
    [CONTROL_SHIFT] = COMBO(combo_control_shift,            C(S(XXXXXXX))),
    [CONTROL_ALT] = COMBO(combo_control_alt,                C(A(XXXXXXX))),
    [CONTROL_SHIFT_ALT] = COMBO(combo_control_shift_alt,    C(S(A(XXXXXXX)))),
    [RIGHT_ALT] = COMBO(combo_right_alt,                    KC_RALT),
    [ALT_SHIFT] = COMBO(combo_alt_shift,                    A(S(XXXXXXX))),

    // French
    [A_GRAVE] = COMBO(combo_a_grave,                        CS_AGRAVE),
    [E_GRAVE] = COMBO(combo_e_grave,                        CS_EGRAVE),
    [U_GRAVE] = COMBO(combo_u_grave,                        CS_UGRAVE),

    [C_CEDILLA] = COMBO(combo_c_cedilla,                    CS_CCEDILLA),
    [E_A] = COMBO(combo_ea,                                 CS_AE),
    [E_O] = COMBO(combo_eo,                                 CS_OE),

    [A_CIRCUMFLEX] = COMBO(combo_a_circumflex,              CS_ACIRCUMFLEX),
    [E_CIRCUMFLEX] = COMBO(combo_e_circumflex,              CS_ECIRCUMFLEX),
    [I_CIRCUMFLEX] = COMBO(combo_i_circumflex,              CS_ICIRCUMFLEX),
    [O_CIRCUMFLEX] = COMBO(combo_o_circumflex,              CS_OCIRCUMFLEX),
    [U_CIRCUMFLEX] = COMBO(combo_u_circumflex,              CS_UCIRCUMFLEX),

    [E_DIAERESIS] = COMBO(combo_e_diaeresis,                CS_EDIAERESIS),
    [I_DIAERESIS] = COMBO(combo_i_diaeresis,                CS_IDIAERESIS),
    [U_DIAERESIS] = COMBO(combo_u_diaeresis,                CS_UDIAERESIS),
    [Y_DIAERESIS] = COMBO(combo_y_diaeresis,                CS_YDIAERESIS),

    // --
    [AMPERSAND] = COMBO(combo_ampersand,                    KC_AMPR),

    [BACKSLASH] = COMBO(combo_backslash,                    KC_BSLS),
    [CIRCUMFLEX] = COMBO(combo_circumflex,                  KC_CIRC),
    [EQUAL] = COMBO(combo_equal,                            KC_EQL),
    [GRAVE] = COMBO(combo_grave,                            KC_GRV),
    [HASH] = COMBO(combo_hash,                              KC_HASH),
    [PERCENT] = COMBO(combo_percent,                        KC_PERC),
    [PIPE] = COMBO(combo_pipe,                              KC_PIPE),
    [PLUS] = COMBO(combo_plus,                              KC_PLUS),
    [SLASH] = COMBO(combo_slash,                            KC_SLSH),
    [STAR] = COMBO(combo_star,                              KC_ASTR),
    [TILDE] = COMBO(combo_tilde,                            KC_TILD),
    [TIRET] = COMBO(combo_tiret,                            KC_MINS),
    [UNDERSCORE] = COMBO(combo_underscore,                  KC_UNDS),

    // --
    [DOLLAR] = COMBO(combo_dollar,                          KC_DLR),
    [EURO] = COMBO(combo_euro,                              CS_EURO),
    [POUND] = COMBO(combo_pound,                            CS_POUND),

    // --
    [PARENTHESIS_LEFT] = COMBO(combo_parenthesis_left,          KC_LEFT_PAREN),
    [PARENTHESIS_RIGHT] COMBO(combo_parenthesis_right,          KC_RIGHT_PAREN),
    [BRACKET_LEFT] = COMBO(combo_bracket_left,                  KC_LEFT_BRACKET),
    [BRACKET_RIGHT] = COMBO(combo_bracket_right,                KC_RIGHT_BRACKET),
    [CURLY_BRACKET_LEFT] = COMBO(combo_curly_bracket_left,      KC_LEFT_CURLY_BRACE),
    [CURLY_BRACKET_RIGHT] = COMBO(combo_curly_bracket_right,    KC_RIGHT_CURLY_BRACE),

    // --
    [DEGREE] = COMBO(combo_degree,                          CS_DEGREE),
    [DIAMETER] = COMBO(combo_diameter,                      CS_DIAMETER),
    [SUPERSCRIPT_1] = COMBO(combo_superscript_1,            CS_SUPERSCRIPT_1),
    [SUPERSCRIPT_2] = COMBO(combo_superscript_2,            CS_SUPERSCRIPT_2),
    [SUPERSCRIPT_3] = COMBO(combo_superscript_3,            CS_SUPERSCRIPT_3),

    // --
    [MAIL_SHORT] = COMBO_ACTION(combo_mail_short),
    [MAIL_LONG] = COMBO_ACTION(combo_mail_long),
};


// --------------------------------------------------
// --------------------------------------------------
// Macros !
void process_combo_event(uint16_t combo_index, bool pressed) {

    switch(combo_index) {

        case MAIL_SHORT:
            if (pressed) {
                SEND_STRING("f@linguenheld.fr");
            }
            break;

        case MAIL_LONG:
            if (pressed) {
                SEND_STRING("florent@linguenheld.fr");
            }
            break;

    // // case VIM_COLON:
      // // if (pressed) {
        // // SEND_STRING(SS_TAP(X_ESC) SS_LSFT("a") ":" SS_TAP(X_ESC));
      // // }
      // // break;

    // // case VIM_NOH:
      // // if (pressed) {
        // // tap_code16(KC_ESC);
        // // tap_code16(KC_COLN);
        // // tap_code16(KC_N);
        // // tap_code16(KC_O);
        // // tap_code16(KC_H);
        // // tap_code16(KC_ENTER);
      // // }
      // // break;
    }
}
