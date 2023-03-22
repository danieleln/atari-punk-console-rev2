#include "inttypes.h"
#include "config.hpp"
#include "button.hpp"
#include "seven_segments_display.hpp"
#include "led_strip.hpp"

// potentiometers value
uint8_t ws_1, ws_2;

// mode selection buttons
Button next_btn(next_btn_pin, btn_pressed_level);
Button prev_btn(prev_btn_pin, btn_pressed_level);


#define NUM_OF_MODES 4
uint8_t mode = -1;
void change_mode (void);

// output waveform
uint16_t waveform = 0;



void setup ()
{
    pinMode(wave_out_pin, OUTPUT);

    ssd_init();

    // next_btn.on_press = prev_btn.on_press = change_mode;
}


void loop ()
{
    // analogRead( ... ) outputs an integer value ∈ [0, 1023]
    // The value of wave shaping potentiometers is mapped to
    // the range [0, 15] (one step per each LED of the strip).
    // One way to make this conversion is:
    //
    //      map(analogRead( ... ), 0, 1023, 0, 15)
    //
    // but that's slow to run. Instead, it's possible to exploit
    // the fact that the conversion is between powers of 2:
    // from [0, 2^10-1] to [0, 2^4-1]. In fact, the same effect
    // can be obtained simply by shifting the value of 6 binary
    // places (from 2^10 to 2^4)
    ws_1 = analogRead(ws_pot_1_pin) >> 6;
    ws_2 = analogRead(ws_pot_2_pin) >> 6;

    
    switch (mode)
    {
        case 1:
            waveform = (0xff << (0xff - ws_1)) ^ (0xff >> ws_2);
        case 2:
            waveform = ws_1 << 7 | ws_2;
    }

    ls_shift_out(waveform);
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
