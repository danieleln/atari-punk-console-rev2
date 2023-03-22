#pragma once
#include "inttypes.h"
#include "config.hpp"

const uint8_t hex_num_map[16];

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
