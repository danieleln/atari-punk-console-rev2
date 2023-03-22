#include "inttypes.h"
#include "config.hpp"
#include "button.hpp"
#include "seven_segments_display.hpp"

// potentiometers
#define ws_pot_1 ws_pot_1_pin
#define ws_pot_2 ws_pot_2_pin
#define pitch_pot pitch_pot_pin

// mode selection buttons
Button next_btn(next_btn_pin, btn_pressed_level);
Button prev_btn(prev_btn_pin, btn_pressed_level);

// waveform output
#define wave_out wave_out_pin

#define NUM_OF_MODES 4
uint8_t mode = -1;
void change_mode (void);

void setup ()
{
    pinMode(wave_out, OUTPUT);

    ssd_init();

    // next_btn.on_press = prev_btn.on_press = change_mode;
}


void loop ()
{
}



void change_mode (void)
{
    // displaies the mode number
    // NB: when the mode is -1 (a.k.a 255),
    // the function automatically clears 
    // the display since it doesn't recognise
    // it as a valid hexadecimal number
    ssd_display_num(mode);

    // turns on the dot only when the mode is -1
    ssd_dot(mode == -1);

    // updates the display
    ssd_shift_out();
}
