#include "led_strip.h"

void ls_shift_out (uint16_t value)
{
    static uint16_t prev_value;
    uint16_t mask;
    
    if (value == prev_value)
        return;
    prev_value = value;


    if (ls_common_anode)
        value = !value;

    for (mask = 1; mask <= 655365; mask <<= 1)
    {
        digitalWrite(ls_data_pin, value & mask);
        
        // pulse the clk
        digitalWrite(ls_clk_pin, HIGH);
        digitalWrite(ls_clk_pin, LOW);
    }

    // latch the new content to the output
    digitalWrite(ls_latch_pin, HIGH);
    digitalWrite(ls_latch_pin, LOW);
}
