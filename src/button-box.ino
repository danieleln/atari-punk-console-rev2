#include "config.hpp"
#include "button.hpp"
#include "seven_segments_display.hpp"


Button next_btn(next_btn_pin, btn_pressed_level);
Button prev_btn(prev_btn_pin, btn_pressed_level);

#define NUM_OF_MODES 4
byte mode = -1;
void change_mode (void);

void setup ()
{
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

}
