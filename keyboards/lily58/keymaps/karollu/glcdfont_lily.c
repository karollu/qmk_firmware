// This is the 'classic' fixed-space bitmap font for Adafruit_GFX since 1.0.
// See gfxfont.h for newer custom bitmap font info.

// Modified to show the Lily58 logo instead of the qmk logo
#include "progmem.h"

// Standard ASCII 5x7 font
const unsigned char font[] PROGMEM = {
    0x07, 0x08, 0x7F, 0x08, 0x07, 0x00,
    0x3E, 0x5B, 0x4F, 0x5B, 0x3E, 0x00,
    0x3E, 0x6B, 0x4F, 0x6B, 0x3E, 0x00,
    0x1C, 0x3E, 0x7C, 0x3E, 0x1C, 0x00,
    0x18, 0x3C, 0x7E, 0x3C, 0x18, 0x00,
    0x1C, 0x57, 0x7D, 0x57, 0x1C, 0x00,
    0x1C, 0x5E, 0x7F, 0x5E, 0x1C, 0x00,
    0x00, 0x18, 0x3C, 0x18, 0x00, 0x00,
    0xFF, 0xE7, 0xC3, 0xE7, 0xFF, 0x00,
    0x00, 0x18, 0x24, 0x18, 0x00, 0x00,
    0xFF, 0xE7, 0xDB, 0xE7, 0xFF, 0x00,
    0x30, 0x48, 0x3A, 0x06, 0x0E, 0x00,
    0x26, 0x29, 0x79, 0x29, 0x26, 0x00,
    0x40, 0x7F, 0x05, 0x05, 0x07, 0x00,
    0x40, 0x7F, 0x05, 0x25, 0x3F, 0x00,
    0x5A, 0x3C, 0xE7, 0x3C, 0x5A, 0x00,
    0x7F, 0x3E, 0x1C, 0x1C, 0x08, 0x00,
    0x08, 0x1C, 0x1C, 0x3E, 0x7F, 0x00,
    0x14, 0x22, 0x7F, 0x22, 0x14, 0x00,
    0x5F, 0x5F, 0x00, 0x5F, 0x5F, 0x00,
    0x06, 0x09, 0x7F, 0x01, 0x7F, 0x00,
    0x00, 0x66, 0x89, 0x95, 0x6A, 0x00,
    0x60, 0x60, 0x60, 0x60, 0x60, 0x00,
    0x94, 0xA2, 0xFF, 0xA2, 0x94, 0x00,
    0x08, 0x04, 0x7E, 0x04, 0x08, 0x00,
    0x10, 0x20, 0x7E, 0x20, 0x10, 0x00,
    0x08, 0x08, 0x2A, 0x1C, 0x08, 0x00,
    0x08, 0x1C, 0x2A, 0x08, 0x08, 0x00,
    0x1E, 0x10, 0x10, 0x10, 0x10, 0x00,
    0x0C, 0x1E, 0x0C, 0x1E, 0x0C, 0x00,
    0x30, 0x38, 0x3E, 0x38, 0x30, 0x00,
    0x06, 0x0E, 0x3E, 0x0E, 0x06, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x5c, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x06, 0x00, 0x06, 0x00, 0x00, 0x00,
    0x28, 0x7c, 0x28, 0x7c, 0x28, 0x00,
    0x5c, 0x54, 0xfe, 0x54, 0x74, 0x00,
    0x44, 0x20, 0x10, 0x08, 0x44, 0x00,
    0x28, 0x54, 0x54, 0x20, 0x50, 0x00,
    0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x38, 0x44, 0x00, 0x00, 0x00, 0x00,
    0x44, 0x38, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x07, 0x02, 0x00, 0x00, 0x00,
    0x10, 0x10, 0x7c, 0x10, 0x10, 0x00,
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x60, 0x10, 0x0c, 0x00, 0x00, 0x00,
    0x7c, 0x64, 0x54, 0x4c, 0x7c, 0x00,
    0x48, 0x7c, 0x40, 0x00, 0x00, 0x00,
    0x64, 0x54, 0x54, 0x54, 0x48, 0x00,
    0x44, 0x54, 0x54, 0x54, 0x6c, 0x00,
    0x3c, 0x20, 0x70, 0x20, 0x20, 0x00,
    0x5c, 0x54, 0x54, 0x54, 0x24, 0x00,
    0x7c, 0x54, 0x54, 0x54, 0x74, 0x00,
    0x04, 0x04, 0x64, 0x14, 0x0c, 0x00,
    0x7c, 0x54, 0x54, 0x54, 0x7c, 0x00,
    0x5c, 0x54, 0x54, 0x54, 0x7c, 0x00,
    0x44, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xc4, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x10, 0x28, 0x44, 0x00, 0x00, 0x00,
    0x28, 0x28, 0x28, 0x28, 0x28, 0x00,
    0x44, 0x28, 0x10, 0x00, 0x00, 0x00,
    0x08, 0x04, 0x54, 0x08, 0x00, 0x00,
    0x7c, 0x44, 0x54, 0x54, 0x5c, 0x00,
    0x7c, 0x24, 0x24, 0x24, 0x7c, 0x00,
    0x7c, 0x54, 0x54, 0x54, 0x6c, 0x00,
    0x7c, 0x44, 0x44, 0x44, 0x44, 0x00,
    0x7c, 0x44, 0x44, 0x44, 0x38, 0x00,
    0x7c, 0x54, 0x54, 0x54, 0x44, 0x00,
    0x7c, 0x14, 0x14, 0x14, 0x04, 0x00,
    0x7c, 0x44, 0x44, 0x54, 0x74, 0x00,
    0x7c, 0x10, 0x10, 0x10, 0x7c, 0x00,
    0x44, 0x44, 0x7c, 0x44, 0x44, 0x00,
    0x60, 0x40, 0x40, 0x44, 0x7c, 0x00,
    0x7c, 0x10, 0x10, 0x28, 0x44, 0x00,
    0x7c, 0x40, 0x40, 0x40, 0x40, 0x00,
    0x7c, 0x08, 0x10, 0x08, 0x7c, 0x00,
    0x7c, 0x08, 0x10, 0x20, 0x7c, 0x00,
    0x38, 0x44, 0x44, 0x44, 0x38, 0x00,
    0x7c, 0x14, 0x14, 0x14, 0x08, 0x00,
    0x3c, 0x24, 0x64, 0x24, 0x3c, 0x00,
    0x7c, 0x14, 0x14, 0x14, 0x68, 0x00,
    0x5c, 0x54, 0x54, 0x54, 0x74, 0x00,
    0x04, 0x04, 0x7c, 0x04, 0x04, 0x00,
    0x7c, 0x40, 0x40, 0x40, 0x7c, 0x00,
    0x0c, 0x30, 0x40, 0x30, 0x0c, 0x00,
    0x3c, 0x40, 0x30, 0x40, 0x3c, 0x00,
    0x44, 0x28, 0x10, 0x28, 0x44, 0x00,
    0x0c, 0x10, 0x60, 0x10, 0x0c, 0x00,
    0x44, 0x64, 0x54, 0x4c, 0x44, 0x00,
    0x7c, 0x44, 0x00, 0x00, 0x00, 0x00,
    0x0c, 0x10, 0x60, 0x00, 0x00, 0x00,
    0x44, 0x7c, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x00, 0x01, 0x00, 0x00,
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x7c, 0x24, 0x24, 0x24, 0x7c, 0x00,
    0x7c, 0x54, 0x54, 0x54, 0x6c, 0x00,
    0x7c, 0x44, 0x44, 0x44, 0x44, 0x00,
    0x7c, 0x44, 0x44, 0x44, 0x38, 0x00,
    0x7c, 0x54, 0x54, 0x54, 0x44, 0x00,
    0x7c, 0x14, 0x14, 0x14, 0x04, 0x00,
    0x7c, 0x44, 0x44, 0x54, 0x74, 0x00,
    0x7c, 0x10, 0x10, 0x10, 0x7c, 0x00,
    0x44, 0x44, 0x7c, 0x44, 0x44, 0x00,
    0x60, 0x40, 0x40, 0x44, 0x7c, 0x00,
    0x7c, 0x10, 0x10, 0x28, 0x44, 0x00,
    0x7c, 0x40, 0x40, 0x40, 0x40, 0x00,
    0x7c, 0x08, 0x10, 0x08, 0x7c, 0x00,
    0x7c, 0x08, 0x10, 0x20, 0x7c, 0x00,
    0x38, 0x44, 0x44, 0x44, 0x38, 0x00,
    0x7c, 0x14, 0x14, 0x14, 0x08, 0x00,
    0x3c, 0x24, 0x64, 0x24, 0x3c, 0x00,
    0x7c, 0x14, 0x14, 0x14, 0x68, 0x00,
    0x5c, 0x54, 0x54, 0x54, 0x74, 0x00,
    0x04, 0x04, 0x7c, 0x04, 0x04, 0x00,
    0x7c, 0x40, 0x40, 0x40, 0x7c, 0x00,
    0x0c, 0x30, 0x40, 0x30, 0x0c, 0x00,
    0x3c, 0x40, 0x30, 0x40, 0x3c, 0x00,
    0x44, 0x28, 0x10, 0x28, 0x44, 0x00,
    0x0c, 0x10, 0x60, 0x10, 0x0c, 0x00,
    0x44, 0x64, 0x54, 0x4c, 0x44, 0x00,
    0x10, 0x7c, 0x44, 0x00, 0x00, 0x00,
    0x6c, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x44, 0x7c, 0x10, 0x00, 0x00, 0x00,
    0x02, 0x01, 0x02, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xC1, 0xC1, 0xCF, 0x4F, 0x7F,
    0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
    0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF,
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
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xF0,
    0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
    0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF,
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
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC0, 0xC0, 0xF0, 0x70, 0x30, 0x30,
    0x30, 0x30, 0x30, 0x30, 0x30, 0x30,
    0x30, 0x30, 0x30, 0x30, 0x30, 0x70,
    0x70, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
    0x00, 0x00, 0x80, 0xC0, 0xC0, 0xFE,
    0x7E, 0x7E, 0x7F, 0x73, 0xF1, 0xF0,
    0xF0, 0xF0, 0x80, 0x80, 0x00, 0x00,
    0xF0, 0xF0, 0xF0, 0x00, 0x00, 0x00,
    0x70, 0x70, 0x70, 0x71, 0x71, 0x71,
    0x71, 0x71, 0xCE, 0x8E, 0x0F, 0x0F,
    0x0F, 0x7F, 0x70, 0x70, 0xF0, 0xF0,
    0xFF, 0x8F, 0x8F, 0x8F, 0x0F, 0x0F,
    0x00, 0x00, 0x03, 0x73, 0x73, 0x7E,
    0x7E, 0x7E, 0x70, 0x70, 0xF0, 0xF0,
    0xF0, 0xF0, 0x70, 0x70, 0x0F, 0x0F,
    0xF0, 0xF0, 0xF0, 0x0E, 0x0E, 0x0E,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x0F,
    0x0E, 0x0E, 0xFE, 0xFE, 0xFE, 0xF0,
    0xF0, 0x80, 0x80, 0x80, 0x8E, 0x8E,
    0x8F, 0xF3, 0xF3, 0xF1, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x03, 0x03, 0x7E,
    0x7E, 0x7E, 0x80, 0x80, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F,
    0x0F, 0x0F, 0x0F, 0x71, 0x71, 0x71,
    0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F,
};

