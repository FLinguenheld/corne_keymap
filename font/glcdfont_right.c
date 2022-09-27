#include "progmem.h"

// Helidox 8x6 font with QMK Firmware Logo
// Online editor: http://teripom.x0.com/

static const unsigned char PROGMEM font[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3,
    0xC3, 0xFF, 0xFF, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
    0xC0, 0xC0, 0xFF, 0xFF, 0x03, 0x03,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xFF, 0xFF, 0xC3,
    0xC3, 0xFF, 0xFF, 0xC3, 0xC3, 0xC3,
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xFF, 0xFF, 0xC3,
    0xC3, 0xFF, 0xFF, 0xC3, 0xC3, 0xC3,
    0xC3, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFE, 0xFF, 0xC3, 0xC3, 0xFF, 0xFE,
    0xCC, 0xCE, 0xC7, 0xC3, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xFE, 0xFF, 0xC3,
    0xC3, 0xFF, 0xFE, 0xCC, 0xCE, 0xC7,
    0xC3, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x7E, 0xFF, 0xC3, 0xC3, 0xC3, 0xC3,
    0xC3, 0xC3, 0xFF, 0x7E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xC3, 0xC3, 0xC3,
    0xC3, 0xDB, 0xDB, 0xDB, 0xDB, 0xFF,
    0x7E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xC0, 0xC0, 0xFF, 0xFF,
    0x03, 0x03, 0xFF, 0xFF, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x81, 0xC3,
    0xE7, 0xFF, 0xDB, 0xC3, 0xC3, 0xC3,
    0xC3, 0xC3, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x7E, 0xFF, 0xC3, 0xC3, 0xC3,
    0xC3, 0xC3, 0xC3, 0xFF, 0x7E, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xC3, 0xC3,
    0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xFF, 0xFF, 0xC0, 0xC0, 0xFF,
    0xFF, 0x03, 0x03, 0xFF, 0xFF, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
    0xC0, 0xC0, 0xF8, 0xF8, 0xC0, 0xC0,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xE3, 0xE3, 0xF3, 0xF3, 0xDB,
    0xDB, 0xCF, 0xCF, 0xC7, 0xC7, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xC3, 0xC3,
    0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x81, 0xC3, 0xE7, 0xFF, 0xDB,
    0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
    0xC0, 0xC0, 0xF8, 0xF8, 0xC0, 0xC0,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xFE, 0xFF, 0xC3, 0xC3, 0xFF,
    0xFE, 0xCC, 0xCE, 0xC7, 0xC3, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x7F, 0xFF, 0xC0, 0xC0, 0xC0,
    0xC0, 0xC0, 0xC0, 0xFF, 0x7F, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xFF, 0xFF, 0xC0, 0xC0, 0xC0,
    0xF8, 0xF8, 0xC0, 0xC0, 0xC0, 0x00,
    0x00, 0xE3, 0xE3, 0xF3, 0xF3, 0xDB,
    0xDB, 0xCF, 0xCF, 0xC7, 0xC7, 0x00,
    0x00, 0x00, 0x00, 0xFF, 0xFF, 0xC3,
    0xC3, 0xFF, 0xFF, 0xC3, 0xC3, 0xC3,
    0xC3, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFC, 0xFE, 0xC7, 0xC3, 0xC3, 0xC3,
    0xC3, 0xC7, 0xFE, 0xFC, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xFE, 0xFE, 0x30,
    0x30, 0x30, 0x30, 0x30, 0x33, 0x3F,
    0x1E, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3,
    0xC3, 0xC3, 0xFF, 0xFF, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xFF, 0xFF, 0xC0,
    0xC0, 0xFF, 0xFF, 0x03, 0x03, 0xFF,
    0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x00, 0x00,
    0x00, 0xF0, 0x90, 0x20, 0x3C, 0x86,
    0xCC, 0x48, 0x60, 0x20, 0x20, 0x20,
    0x10, 0x10, 0x30, 0x20, 0x20, 0x60,
    0x40, 0x40, 0xC0, 0x80, 0x80, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0x80, 0x80, 0x40, 0x40, 0x40, 0x40,
    0x40, 0x20, 0x20, 0x10, 0x10, 0x18,
    0x08, 0x0C, 0x04, 0xC4, 0x3C, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xE0, 0xE0, 0x62, 0x69,
    0x61, 0x61, 0x09, 0x01, 0x01, 0xFE,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x00, 0xFE, 0x03,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x01, 0x03, 0x02, 0x02, 0x02, 0x06,
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
    0x04, 0x04, 0x04, 0x04, 0x02, 0x02,
    0x02, 0x02, 0x03, 0x01, 0x01, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0xE0, 0x70,
    0x4C, 0x46, 0xC3, 0x00, 0x00, 0x00,
    0x00, 0x18, 0x18, 0x18, 0x98, 0x98,
    0x98, 0xE8, 0x88, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x88, 0x08, 0x08, 0x08, 0x08, 0x48,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x10, 0x10, 0x10,
    0x20, 0x20, 0x21, 0x21, 0xE0, 0xF0,
    0x7F, 0x40, 0x40, 0x40, 0x70, 0x7F,
    0xF0, 0xE0, 0x20, 0x20, 0x20, 0x20,
    0x10, 0x10, 0x10, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x48, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x88, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x88, 0xE8, 0x98,
    0x98, 0x98, 0x18, 0x18, 0x18, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0x06, 0x0C, 0x08, 0x18, 0x11, 0x00,
    0x00, 0xC0, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xC0, 0x60, 0x00, 0x00,
    0x00, 0x00, 0x10, 0x10, 0x30, 0x20,
    0x20, 0x60, 0x40, 0x40, 0x40, 0xC0,
    0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
    0x60, 0x18, 0x0F, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x19, 0x19, 0x06,
    0x04, 0x7C, 0xFC, 0x04, 0x04, 0x0C,
    0x18, 0x10, 0xF0, 0xF0, 0x10, 0x10,
    0x10, 0x10, 0xF0, 0xF0, 0x12, 0x10,
    0x10, 0xE0, 0x80, 0x81, 0x80, 0x80,
    0x80, 0x90, 0x80, 0x80, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0x80, 0x80, 0x88, 0x80,
    0x80, 0x80, 0x80, 0x81, 0xE0, 0x10,
    0x10, 0x10, 0xF4, 0xF0, 0x10, 0x10,
    0x10, 0x10, 0xF0, 0xF0, 0x10, 0x18,
    0x0C, 0x04, 0x04, 0xFC, 0x7C, 0x04,
    0x06, 0x19, 0x19, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x07, 0x1C, 0x30, 0x38,
    0x0E, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x03, 0x02, 0x02, 0x06, 0x04, 0x0C,
    0x08, 0x08, 0x10, 0x10, 0x30, 0x20,
    0x40, 0x40, 0x40, 0x41, 0x61, 0x21,
    0x31, 0x0F, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x03, 0x03, 0x00, 0x00,
    0x00, 0x03, 0x03, 0x00, 0x00, 0x00,
    0x03, 0x03, 0x00, 0xC0, 0x73, 0xDF,
    0x10, 0x18, 0x08, 0x08, 0x18, 0x10,
    0xDF, 0x73, 0xC0, 0x00, 0x03, 0x03,
    0x00, 0x00, 0x00, 0x03, 0x03, 0x00,
    0x00, 0x00, 0x03, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x03, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
