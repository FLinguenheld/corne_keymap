// General enum for all tap dance
enum {
    TD_BSPC_DEL,
    TD_TREMA_ALT, // The standard Mod-Tap doesn't work with "
    TD_EXCLA_QUEST,

    TD_CURRENCY,
    TD_PERCENT,

    // Specific tap dances to replace LT(layer, kc)
    TDS_ARROWS_COLON,
    TDS_ARROWS_SCOLON,

    // US --
    US_TD_EXCLA_QUEST,

    US_TDS_ARROWS_COLON,
    US_TDS_ARROWS_SCOLON,
};


// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Simple tap-hold

// How to :
//      - Add an entry in the general enum
//      - Add a case with it in the "process_record_user" function
//      - Add it in the "qk_tap_dance_action_t" function with the two keys
//      - Add in the layout TD(name)


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    qk_tap_dance_action_t *action;

    switch (keycode) {
        case TD(TD_BSPC_DEL):  // list here all tap dance keycodes with tap-hold configurations
        case TD(TD_TREMA_ALT):
        case TD(TD_EXCLA_QUEST):
        case TD(TD_CURRENCY):
        case TD(TD_PERCENT):

        // US
        case TD(US_TD_EXCLA_QUEST):


            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}

void tap_dance_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

// Simple tap-hold
// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------



// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Advanced tap-hold to replace the LT(c) function

// Unfortunatelly, the LT(layer, kc) function is limited to basics keycodes
// According to the doc, we have to use a tap dance
// https://docs.qmk.fm/#/feature_layers
// Moreover I can`t use two layout (one for arrows and another for mouse), That created a bug when I clicked on both TD simultaneously ;(
// So I have grouped them in one layer : _ARROWS

// How to :
//      - Add an entry in the general enum
//      - Declare and create two functions :
//                  *_finished()
//                  *_reset()
//      - Add it in the "qk_tap_dance_action_t" function with these new functions
//      - Add in the layout TD(name)


// ------------------------------------------------------------
// ------------------------------------------------------------
// Tap dance limited to tap and hold (double tap is horrible ^^)
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Determine the current tap dance state
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};


// ------------------------------------------------------------
// Layout _ARROWS and colon - Specific functions

void lt_arrows_colon_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            // Add here the key (and unregister it in the reset function)
            register_code16(BP_COLN);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_ARROWS);
            break;
        default:
            break;
    }
}

void lt_arrows_colon_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_ARROWS);
    }
    else {
        // unregister the tapped key here
        unregister_code16(BP_COLN);
    }

    ql_tap_state.state = TD_NONE;
}

// Layout _ARROWS and colon
// ------------------------------------------------------------

// ------------------------------------------------------------
// Layout _ARROWS and semi colon - Specific functions

void lt_arrows_semicolon_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            // Add here the key (and unregister it in the reset function)
            register_code16(BP_SCLN);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_ARROWS);
            break;
        default:
            break;
    }
}

void lt_arrows_semicolon_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_ARROWS);
    }
    else {
        // unregister the tapped key here
        unregister_code16(BP_SCLN);
    }

    ql_tap_state.state = TD_NONE;
}

// Layout _ARROWS and semi colon
// ------------------------------------------------------------



// ------------------------------------------------------------
// USA --
// Layout _US_ARROWS and colon - Specific functions

void us_lt_arrows_colon_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            // Add here the key (and unregister it in the reset function)
            register_code16(S(KC_SEMICOLON));
            break;
        case TD_SINGLE_HOLD:
            layer_on(_US_ARROWS);
            break;
        default:
            break;
    }
}

void us_lt_arrows_colon_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_US_ARROWS);
    }
    else {
        // unregister the tapped key here
        unregister_code16(S(KC_SEMICOLON));
    }

    ql_tap_state.state = TD_NONE;
}

// USA --
// Layout _US_ARROWS and colon
// ------------------------------------------------------------

// ------------------------------------------------------------
// USA --
// Layout _US_ARROWS and semi colon - Specific functions

void us_lt_arrows_semicolon_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            // Add here the key (and unregister it in the reset function)
            register_code16(KC_SEMICOLON);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_US_ARROWS);
            break;
        default:
            break;
    }
}

void us_lt_arrows_semicolon_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_US_ARROWS);
    }
    else {
        // unregister the tapped key here
        unregister_code16(KC_SEMICOLON);
    }

    ql_tap_state.state = TD_NONE;
}

// USA --
// Layout _US_ARROWS and semi colon
// ------------------------------------------------------------



// Set a long-ish tapping term for tap-dance keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        default:
            return TAPPING_TERM;
    }
}
