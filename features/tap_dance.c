// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Tap dance

// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Advanced tap-hold to replace the LT(c) function

// Unfortunatelly, the LT(layer, kc) function is limited to basics keycodes
// According to the doc, we have to use a tap dance
// https://docs.qmk.fm/#/feature_layers
// Moreover I can`t use two layout (one for arrows and another for mouse), That created a bug when I clicked on both TD simultaneously ;(
// So I have grouped them in one layer : _ARROWS

// How to :
//      - Add an entry in the enum
//      - Declare and create a function :
//                  *_finished()
//      - I have regrouped all *_reset(), so add the unregister key and the layer off inside tds_reset()
//      - Add it in the "qk_tap_dance_action_t" function with these new functions (end of this file)
//      - Add in keymap.c : TD(name)


// enum tap_dances {

    // TDS_ARROWS_COLON,
    // TDS_ARROWS_SCOLON,

    // US_TDS_ARROWS_COLON,
// };


// // ------------------------------------------------------------
// // ------------------------------------------------------------
// // Tap dance limited to tap and hold (double tap is horrible ^^)
// typedef enum {
    // TD_NONE,
    // TD_UNKNOWN,
    // TD_SINGLE_TAP,
    // TD_SINGLE_HOLD,
// } td_state_t;

// typedef struct {
    // bool is_press_action;
    // td_state_t state;
// } td_tap_t;

// // Determine the current tap dance state
// td_state_t cur_dance(qk_tap_dance_state_t *state) {
    // if (state->count == 1) {
        // if (!state->pressed) return TD_SINGLE_TAP;
        // else return TD_SINGLE_HOLD;
    // }
    // else return TD_UNKNOWN;
// }

// // Initialize tap structure associated with example tap dance key
// static td_tap_t ql_tap_state = {
    // .is_press_action = true,
    // .state = TD_NONE
// };


// // ------------------------------------------------------------
// // Layout _ARROWS and colon
// void lt_arrows_colon_finished(qk_tap_dance_state_t *state, void *user_data) {
    // ql_tap_state.state = cur_dance(state);
    // switch (ql_tap_state.state) {
        // case TD_SINGLE_TAP:
            // // Add here the key (and unregister it in the reset function)
            // register_code16(BP_COLN);
            // break;
        // case TD_SINGLE_HOLD:
            // layer_on(_ARROWS);
            // break;
        // default:
            // break;
    // }
// }

// // ------------------------------------------------------------
// // Layout _ARROWS and semi colon
// void lt_arrows_semicolon_finished(qk_tap_dance_state_t *state, void *user_data) {
    // ql_tap_state.state = cur_dance(state);
    // switch (ql_tap_state.state) {
        // case TD_SINGLE_TAP:
            // // Add here the key (and unregister it in the reset function)
            // register_code16(BP_SCLN);
            // break;
        // case TD_SINGLE_HOLD:
            // layer_on(_ARROWS);
            // break;
        // default:
            // break;
    // }
// }

// // ------------------------------------------------------------
// // Layout _US_ARROWS and colon
// void us_lt_arrows_colon_finished(qk_tap_dance_state_t *state, void *user_data) {
    // ql_tap_state.state = cur_dance(state);
    // switch (ql_tap_state.state) {
        // case TD_SINGLE_TAP:
            // // Add here the key (and unregister it in the reset function)
            // register_code16(KC_COLON);
            // break;
        // case TD_SINGLE_HOLD:
            // layer_on(_US_ARROWS);
            // break;
        // default:
            // break;
    // }
// }

// // ------------------------------------------------------------
// // Common reset, add here all layers off and unregister keys
// void tds_reset(qk_tap_dance_state_t *state, void *user_data) {
    // // If the key was held down and now is released then switch off the layer
    // if (ql_tap_state.state == TD_SINGLE_HOLD) {
        // layer_off(_US_ARROWS);
        // layer_off(_ARROWS);
    // }
    // else {
        // // unregister the tapped key here
        // unregister_code16(KC_COLON);
        // unregister_code16(BP_SCLN);
        // unregister_code16(BP_COLN);
    // }

    // ql_tap_state.state = TD_NONE;
// }


// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Link here enum and keys (simple or advanced)
// qk_tap_dance_action_t tap_dance_actions[] = {

    // // [TDS_ARROWS_COLON] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lt_arrows_colon_finished, tds_reset),
    // // [TDS_ARROWS_SCOLON] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lt_arrows_semicolon_finished, tds_reset),

    // // [US_TDS_ARROWS_COLON] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, us_lt_arrows_colon_finished, tds_reset),
// };
