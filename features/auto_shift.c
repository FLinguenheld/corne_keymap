// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Auto shift -------------------------------------------------------------------------------------------------------------------------------------------

// Only for letters and on basis layers
// Exceptions like Tab underneath

bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        case KC_TAB:
        case KC_ENT:

        // --
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

        // Need US international --
        case US_EACU: // É
        case US_AE: // Æ

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
        case KC_EXLM:

        // French
        case CS_EACUTE:
        case CS_AGRAVE:
        case CS_EGRAVE:
        case CS_UGRAVE:
        case CS_CCEDILLE:
        case CS_AE:
        case CS_OE:

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

        case KC_EXLM: // ! ?
            register_code16((!shifted) ? KC_EXLM : KC_QUES);
            break;

        // French
        case CS_EACUTE:
            if (shifted) { send_unicode_string("É"); }
            else         { send_unicode_string("é"); }
            break;
        case CS_AGRAVE:
            if (shifted) { send_unicode_string("À"); }
            else         { send_unicode_string("à"); }
            break;
        case CS_EGRAVE:
            if (shifted) { send_unicode_string("È"); }
            else         { send_unicode_string("è"); }
            break;
        case CS_UGRAVE:
            if (shifted) { send_unicode_string("Ù"); }
            else         { send_unicode_string("ù"); }
            break;
        case CS_CCEDILLE:
            if (shifted) { send_unicode_string("Ç"); }
            else         { send_unicode_string("ç"); }
            break;
        case CS_AE:
            if (shifted) { send_unicode_string("Æ"); }
            else         { send_unicode_string("æ"); }
            break;
        case CS_OE:
            if (shifted) { send_unicode_string("Œ"); }
            else         { send_unicode_string("œ"); }
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
