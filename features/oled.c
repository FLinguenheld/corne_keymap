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

        // Logo
        switch (get_highest_layer(layer_state)) {

            case _BASE:
                static const char PROGMEM qmk_logo[] = {
                    0x20, 0x20, 0x20, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x20, 0x20, 0x20,
                    0x20, 0x20, 0x20, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x20, 0x20, 0x20,
                    0x20, 0x20, 0x20, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0x20, 0x20, 0x20,
                    0x20, 0x20, 0x20, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0x20, 0x20, 0x20, 0x00
                };

                oled_write_P(qmk_logo, false);
                break;
        }

    // Layer name
    if (get_highest_layer(layer_state) != _BASE){

        // Better place
        oled_write_P(PSTR("\n\n"), false);

        // Current layer
        switch (get_highest_layer(layer_state)) {

            case _NUMERIC:
                static const char PROGMEM qmk_numeric[] = {
                    0x20, 0x20, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x20, 0x20, 0x00,
                };
                oled_write_P(qmk_numeric, false);
                break;

            case _MOUSE:
                static const char PROGMEM qmk_mouse[] = {
                    0x20, 0x20, 0x20, 0x20, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x20, 0x20, 0x20, 0x20, 0x00,
                };
                oled_write_P(qmk_mouse, false);
                break;

            case _ARROWS:
                static const char PROGMEM qmk_arrows[] = {
                    0x20, 0x20, 0x20, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x20, 0x20, 0x00,
                };
                oled_write_P(qmk_arrows, false);
                break;

            case _ADJUST:
                static const char PROGMEM qmk_adjust[] = {
                    0x10, 0x20, 0x20, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x20, 0x20, 0x10, 0x00,
                };
                oled_write_P(qmk_adjust, false);
                break;

            case _FN:
                static const char PROGMEM qmk_fn[] = {
                    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x4D, 0x4E, 0x20, 0x4F, 0x50, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00,
                };
                oled_write_P(qmk_fn, false);
                break;
        }
    }

    // Modifier keys --
    if (get_mods()){

        oled_set_cursor(0, 0);

        if (get_mods() & MOD_MASK_CTRL) {
            // oled_write_char(0x20, false);
            oled_write_char(0x01, false);
            oled_write_char(0x02, false);
        }
        if (get_mods() & MOD_BIT(KC_LALT)) {
            // oled_write_char(0x20, false);
            oled_write_char(0x03, false);
            oled_write_char(0x04, false);
        }
        if (get_mods() & MOD_BIT(KC_RALT)) {
            // oled_write_char(0x20, false);
            oled_write_char(0x05, false);
            oled_write_char(0x06, false);
        }
        if (get_mods() & MOD_MASK_SHIFT) {
            // oled_write_char(0x20, false);
            oled_write_char(0x07, false);
            oled_write_char(0x08, false);
        }
        if (get_mods() & MOD_MASK_GUI) {
            // oled_write_char(0x20, false);
            oled_write_char(0x0B, false);
            oled_write_char(0x0C, false);
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
