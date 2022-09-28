// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Oled display -----------------------------------------------------------------------------------------------------------------------------------------


// --------------------------------------------------
// --------------------------------------------------
// Return the logo for the right part
oled_rotation_t oled_init_user(oled_rotation_t rotation) {

#ifdef MASTER_RIGHT
    return OLED_ROTATION_180;
#endif

    return rotation;
}

// --------------------------------------------------
// --------------------------------------------------
// Wonderful display !
void oled_display(void) {

    oled_clear(); // prevents the timeout, I used oled_write_ln to fill lines with spaces

        // Logos
        switch (get_highest_layer(layer_state)) {

            case _BASE:
                static const char PROGMEM qmk_logo[] = {
                    0x20, 0x20, 0x20, 0x20, 0x20, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x20, 0x20, 0x20, 0x20, 0x20,
                    0x20, 0x20, 0x20, 0x20, 0x20, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x20, 0x20, 0x20, 0x20, 0x20,
                    0x20, 0x20, 0x20, 0x20, 0x20, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0x20, 0x20, 0x20, 0x20, 0x20,
                    0x20, 0x20, 0x20, 0x20, 0x20, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00
                };

                oled_write_P(qmk_logo, false);
                break;

            case _US_BASE:
                static const char PROGMEM qmk_logo_us[] = {
                    0x20, 0x20, 0x20, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x20, 0x20, 0x20,
                    0x20, 0x20, 0x20, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x20, 0x20, 0x20,
                    0x20, 0x20, 0x20, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0x20, 0x20, 0x20,
                    0x20, 0x20, 0x20, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0x20, 0x20, 0x20, 0x00
                };

                oled_write_P(qmk_logo_us, false);
        }


    if (get_highest_layer(layer_state) != _BASE && get_highest_layer(layer_state) != _US_BASE){

        // US banner
        switch (get_highest_layer(layer_state)) {
            case _US_NUMERIC:
            case _US_MOUSE:
            case _US_ARROWS:
            case _US_ADJUST:
            case _US_FN:

                static const char PROGMEM qmk_logo[] = {
                    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x20, 0x20, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x20, 0x20, 0x08, 0x08, 0x00,
                };

                oled_write_P(qmk_logo, false);
        }

        // Better place
        oled_write_P(PSTR("\n\n"), false);

        // Current layer
        switch (get_highest_layer(layer_state)) {

            case _NUMERIC:
            case _US_NUMERIC:
                static const char PROGMEM qmk_numeric[] = {
                    0x20, 0x20, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x20, 0x20, 0x00,
                };
                oled_write_P(qmk_numeric, false);
                break;

            case _MOUSE:
            case _US_MOUSE:
                static const char PROGMEM qmk_mouse[] = {
                    0x20, 0x20, 0x20, 0x20, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x20, 0x20, 0x20, 0x20, 0x00,
                };
                oled_write_P(qmk_mouse, false);
                break;

            case _ARROWS:
            case _US_ARROWS:
                static const char PROGMEM qmk_arrows[] = {
                    0x20, 0x20, 0x20, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x20, 0x20, 0x00,
                };
                oled_write_P(qmk_arrows, false);
                break;

            case _ADJUST:
            case _US_ADJUST:
                static const char PROGMEM qmk_adjust[] = {
                    0x09, 0x20, 0x20, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x20, 0x20, 0x09, 0x00,
                };
                oled_write_P(qmk_adjust, false);
                break;

            case _FN:
            case _US_FN:
                static const char PROGMEM qmk_fn[] = {
                    0x20, 0x20, 0x20, 0x09, 0x20, 0x09, 0x20, 0x20, 0x4D, 0x4E, 0x20, 0x4F, 0x50, 0x20, 0x20, 0x09, 0x20, 0x09, 0x20, 0x20, 0x20, 0x00,
                };
                oled_write_P(qmk_fn, false);
                break;
        }
    }

    // Modifier keys --
    if (get_mods()){

        oled_set_cursor(0, 0);

        if (get_mods() & MOD_MASK_CTRL) {
            oled_write_char(0x7E, false);
            oled_write_char(0x7F, false);
        }
        if (get_mods() & MOD_BIT(KC_LALT)) {
            oled_write_char(0x9E, false);
            oled_write_char(0x9F, false);
        }
        if (get_mods() & MOD_BIT(KC_RALT)) {
            oled_write_char(0xBE, false);
            oled_write_char(0xBF, false);
        }
        if (get_mods() & MOD_MASK_SHIFT) {
            oled_write_char(0xDE, false);
            oled_write_char(0xDF, false);
        }
        if (get_mods() & MOD_MASK_GUI) {
            oled_write_char(0x7C, false);
            oled_write_char(0x7D, false);
        }

        oled_write_char(0x20, false);
    }
};


// Add the timeout management here.
// Because it doesn't work with the OLED_TIMEOUT (the slave doesn't shutdown on power off).
// This management is only for the master, which will sync the status thanks to the SPLIT_OLED_ENABLE definition.

// The timer is restarted by the process_record_user() function.
// Set the OLED_KEY_TIMEOUT value in the config.h
bool oled_task_user(void) {

    if (is_keyboard_master()) {
        if (is_key_processed && (timer_elapsed(oled_timer) < OLED_KEY_TIMEOUT)) {
            oled_display();
        } else {
            is_key_processed = false;
            oled_off();
        }
    } else {
        oled_display();
    }
    return false;
}

// Shut both oled (witout the slave stays on)
void suspend_power_down_user(void) {
    oled_off();
}
