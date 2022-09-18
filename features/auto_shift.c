// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Auto shift -------------------------------------------------------------------------------------------------------------------------------------------

// Only for letters and on basis layers
// Exceptions like Tab underneath

bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {

    if (IS_LAYER_ON(_BASE)) {

        switch (keycode) {
            case BP_A:
            case BP_B:
            case BP_C:
            case BP_D:
            case BP_E:
            case BP_F:
            case BP_G:
            case BP_H:
            case BP_I:
            case BP_J:
            case BP_K:
            case BP_L:
            case BP_M:
            case BP_N:
            case BP_O:
            case BP_P:
            case BP_Q:
            case BP_R:
            case BP_S:
            case BP_T:
            case BP_U:
            case BP_V:
            case BP_W:
            case BP_X:
            case BP_Y:
            case BP_Z:

            case BP_EACU: // É
            case BP_EGRV: // È
            case BP_ECIR: // Ê

            case BP_CCED: // Ç
            case BP_AGRV: // À
            case BP_UGRV: // Ù

            case BP_OE: // Œ
            case BP_AE: // Æ

                return true;
        }
    }
    else if (IS_LAYER_ON(_US_BASE)) {
        
        switch (keycode) {
            case KC_A:
            case KC_B:
            case KC_C:
            case KC_D:
            case KC_E:
            case KC_F:
            case KC_G:
            case KC_H:
            case KC_I:
            case KC_J:
            case KC_K:
            case KC_L:
            case KC_M:
            case KC_N:
            case KC_O:
            case KC_P:
            case KC_Q:
            case KC_R:
            case KC_S:
            case KC_T:
            case KC_U:
            case KC_V:
            case KC_W:
            case KC_X:
            case KC_Y:
            case KC_Z:

                return true;
        }
    }

    switch (keycode) {
        case KC_TAB:
        case KC_ENT:
            return true;
    }
    
    return get_custom_auto_shifted_key(keycode, record);
}


// ----------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------
// Custom auto shift
// I use this instead of tap dance because the double tap is horrible
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {

        case KC_BSPC:

        case BP_EXLM:
        case BP_PERC:
        case BP_DLR:

        // US
        case KC_EXLM: // !

            return true;

        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {

        case KC_BSPC:
            register_code16((!shifted) ? KC_BSPC : KC_DEL);
            break;

        case BP_EXLM:
            register_code16((!shifted) ? BP_EXLM : BP_QUES);
            break;
        case BP_PERC:
            register_code16((!shifted) ? BP_PERC : ALGR(BP_PERC));
            break;
        case BP_DLR:
            register_code16((!shifted) ? BP_DLR : BP_EURO);
            break;

        // US
        case KC_EXLM: // ! ?
            register_code16((!shifted) ? KC_EXLM : KC_QUES);
            break;


        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {

        case KC_BSPC:
            unregister_code16((!shifted) ? KC_BSPC : KC_DEL);
            break;

        case BP_EXLM:
            unregister_code16((!shifted) ? BP_EXLM : BP_QUES);
            break;
        case BP_PERC:
            unregister_code16((!shifted) ? BP_PERC : ALGR(BP_PERC));
            break;
        case BP_DLR:
            unregister_code16((!shifted) ? BP_DLR : BP_EURO);
            break;

        // US
        case KC_EXLM:
            unregister_code16((!shifted) ? KC_EXLM : KC_QUES);
            break;


        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}
