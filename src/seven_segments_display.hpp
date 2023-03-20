#pragma once
#include "config.hpp"

const byte hex_num_map[16];

struct {
    byte current_char;
    bool char_enable;
    bool dot_enable;
    volatile bool queue_shift_out;
} _ssd;

void ssd_display_char (const byte);
void ssd_display_num  (const byte);
void ssd_clear_char   (void);
void ssd_clear_all    (void);
void ssd_dot          (bool);

