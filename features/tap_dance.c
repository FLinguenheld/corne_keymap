// Tap Dance declarations
enum {
    TD_BSPC_DEL,
    TD_ALT_TREMA, // The standard Mod-Tap doesn't work with "
    TD_EXCLA_QUEST,
    TD_QUOTE_3DOTS,
    TD_PARENTHE,
    TD_BRACKETS,
    TD_CURLY_BTS,


    TD_ESC_CAPS,
    QUOT_LAYR,
    TD_FLO,
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    qk_tap_dance_action_t *action;

    switch (keycode) {
        case TD(TD_BSPC_DEL):  // list all tap dance keycodes with tap-hold configurations
        case TD(TD_FLO):
        case TD(TD_ALT_TREMA):
        case TD(TD_EXCLA_QUEST):
        case TD(TD_QUOTE_3DOTS):
        case TD(TD_PARENTHE):
        case TD(TD_BRACKETS):
        case TD(TD_CURLY_BTS):

        

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


// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_BSPC_DEL] = ACTION_TAP_DANCE_TAP_HOLD(KC_BSPC, KC_DEL),
    [TD_ALT_TREMA] = ACTION_TAP_DANCE_TAP_HOLD(BP_DIAE, KC_LEFT_ALT),
    [TD_EXCLA_QUEST] = ACTION_TAP_DANCE_TAP_HOLD(BP_EXLM, BP_QUES),
    [TD_QUOTE_3DOTS] = ACTION_TAP_DANCE_TAP_HOLD(BP_QUOT, BP_ELLP),

    [TD_PARENTHE] = ACTION_TAP_DANCE_TAP_HOLD(BP_LPRN, BP_RPRN),
    [TD_BRACKETS] = ACTION_TAP_DANCE_TAP_HOLD(BP_LBRC, BP_RBRC),
    [TD_CURLY_BTS] = ACTION_TAP_DANCE_TAP_HOLD(BP_LCBR, BP_RCBR),



    [TD_ESC_CAPS] = ACTION_TAP_DANCE_TAP_HOLD(BP_CCED, BP_EACU),
    [TD_FLO] = ACTION_TAP_DANCE_DOUBLE(BP_EURO, BP_AE),
    

};
