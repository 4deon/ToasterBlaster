#include "HUDIcons.h"

/**
 * Bitmaps used in heads up display.
 */
namespace HUDIcons {
    Bitmap microphone[8] = {
        0b00000000,
        0b00011000,
        0b00001000,
        0b00010000,
        0b01011010,
        0b01000010,
        0b00111100,
        0b00011000,
    };

    Bitmap noBoop[8] = {
        0b00000000,
        0b00001000,
        0b00001000,
        0b00111000,
        0b01111010,
        0b01111110,
        0b01111100,
        0b00111000,
    };

    Bitmap boop[8] = {
        0b11111111,
        0b11110111,
        0b11110111,
        0b11000111,
        0b10000101,
        0b10000001,
        0b10000011,
        0b11000111,
    };

    Bitmap led[8] = {
        0b00000000,
        0b00000000,
        0b00111100,
        0b01110110,
        0b01111010,
        0b01111110,
        0b01111110,
        0b00111100
    };

    Bitmap bluetooth[8] = {
        0b00000000,
        0b00001000,
        0b00011010,
        0b00101100,
        0b00011000,
        0b00101100,
        0b00011010,
        0b00001000
    };

    Bitmap tick[8] = {
        0b00000000,
        0b00000000,
        0b01000000,
        0b00100000,
        0b00010000,
        0b00001010,
        0b00000100,
        0b00000000,
    };

    Bitmap cross[8] = {
        0b00000000,
        0b01000010,
        0b00100100,
        0b00011000,
        0b00011000,
        0b00100100,
        0b01000010,
        0b00000000,
    };

    Bitmap load[8] = {
        0b00000000,
        0b01111110,
        0b01000010,
        0b00100100,
        0b00011000,
        0b00100100,
        0b01000010,
        0b01111110
    };
}