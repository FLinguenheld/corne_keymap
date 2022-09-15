// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Oled display -----------------------------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------
// --------------------------------------------------
// Logos (and fonts) are in the glcdfont_.c files
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x80, 0x80, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x80, 0x80, 0x80, 0x80,
        0xA0, 0xA0, 0xA0, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xA0, 0xA0, 0xA0, 0xA0,
        0xC0, 0xC0, 0xC0, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xC0, 0xC0, 0xC0, 0xC0, 0x00
    };

    oled_write_P(qmk_logo, false);
}
static void render_logo_us(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x80, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
        0xA0, 0xA0, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
        0xC0, 0xC0, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0x00
    };

    oled_write_P(qmk_logo, false);
}


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
bool oled_task_user(void) {

#ifdef MASTER_LEFT
    oled_write_P(PSTR("\n"), false);
#endif

    // oled_clear() prevents the timeout, I used oled_write_ln to fill lines with spaces
    bool us = false;

        switch (get_highest_layer(layer_state)) {
            case _US_LOWER:
            case _US_RAISE:
            case _US_ARROWS:
            case _US_ADJUST:
            case _US_FN:
                us = true;
                oled_write_ln_P(PSTR("    $$$$$ USA $$$$$"), false);
        }


        switch (get_highest_layer(layer_state)) {
            case _BASE:
                render_logo();
                break;

            case _US_BASE:
                render_logo_us();
                break;

            case _LOWER:
            case _US_LOWER:
                oled_write_ln_P(PSTR("\n      -- LOWER --"), false);
                break;

            case _RAISE:
            case _US_RAISE:
                oled_write_ln_P(PSTR("\n      -- RAISE --"), false);
                break;

            case _ARROWS:
            case _US_ARROWS:
                oled_write_ln_P(PSTR("\n    --- ARROWS ---"), false);
                break;

            case _ADJUST:
            case _US_ADJUST:
                oled_write_ln_P(PSTR("\n   ~~~~ ADJUST ~~~~"), false);
                break;

            case _FN:
            case _US_FN:
                oled_write_ln_P(PSTR("\n    ~~~~~ FN ~~~~~"), false);
                break;
        }

    // Add an empty line to clear the screen
    if (!us){
        oled_write_ln_P(PSTR(""), false);
    }

    // oled_invert(true);
    return false;
}

// --------------------------------------------------
// --------------------------------------------------
// Used to shutdown the oled slave
void suspend_power_down_user(void) {
    oled_off();
}
