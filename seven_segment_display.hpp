#pragma once
#include "Arduino.h"
#include "inttypes.h"
#include "config.hpp"

struct {
    uint8_t current_char;
    bool char_enable;
    bool dot_enable;
} _ssd;


void ssd_init         (void);
void ssd_display_char (const uint8_t);
void ssd_display_num  (const uint8_t);
void ssd_clear_char   (void);
void ssd_clear_all    (void);
void ssd_dot          (bool);
void ssd_shift_out    (void);



// map that converts an integer number from 0 to 15
// into the segments of a seven segments display
const uint8_t hex_num_map[16] = {
    /*
     *   ┌───A───┐
     *   │       │
     *   F       B
     *   │       │
     *   ├───G───┤
     *   │       │
     *   E       C
     *   │       │
     *   └───D───┘
     */

    //ABCDEFG
    0b1111110,  // 0
    0b0110000,  // 1
    0b1101101,  // 2
    0b1111001,  // 3
    0b0110011,  // 4
    0b1011011,  // 5
    0b1011111,  // 6
    0b1110000,  // 7
    0b1111111,  // 8
    0b1111011,  // 9
    0b1110111,  // A
    0b0011111,  // b
    0b1001111,  // C
    0b0111101,  // d
    0b1001111,  // E
    0b1000111,  // F
};
