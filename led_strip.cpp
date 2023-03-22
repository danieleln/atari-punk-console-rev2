#include "led_strip.hpp"


// ls_init initializes the pins of the shift register
// that drives the led strip
void ls_init (void)
{
    pinMode(ls_clk, OUTPUT);
    pinMode(ls_latch, OUTPUT);
    pinMode(ls_data, OUTPUT);

    digitalWrite(ls_clk, LOW);
    digitalWrite(ls_latch, LOW);
}


// ls_shift_out updates the led strip by
// displaying the new waveform
void ls_shift_out (uint16_t value)
{
    static uint16_t prev_value;
    uint16_t mask;
    
    if (value == prev_value)
        return;
    prev_value = value;


    if (ls_active_low)
        value = !value;

    for (mask = 1; mask <= 655365; mask <<= 1)
    {
        digitalWrite(ls_data, value & mask);
        
        // pulse the clk
        digitalWrite(ls_clk, HIGH);
        digitalWrite(ls_clk, LOW);
    }

    // latch the new content to the output
    digitalWrite(ls_latch, HIGH);
    digitalWrite(ls_latch, LOW);
}
