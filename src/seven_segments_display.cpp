#include "seven_segment_display.hpp"
#include "config.hpp"

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





// ssd_init initializes the pins of the shift register
// that drives the seven segment display
void ssd_init (void)
{
    pinMode(ssd_clk_pin, OUTPUT);
    pinMode(ssd_latch_pin, OUTPUT);
    pinMode(ssd_data_pin, OUTPUT);

    digitalWrite(ssd_clk_pin, LOW);
    digitalWrite(ssd_latch_pin, LOW);
}



// ssd_display_char displaies a given character 
// expressed in the following way:
//      binary char:            0b 0 0 0 0 0 0 0
//      corresponding segment:  0b A B C D E F G
// It leaves the dot as it is
void ssd_display_char (const uint8_t character)
{
    _ssd.current_char = character;
    _ssd.char_enable = true;
}



// ssd_display_num displaies an hexadecimal number
// (from the hex_num_map). It leaves the dot as it is
void ssd_display_num (const uint8_t number)
{
    if (number < 16)
        _ssd.current_char = hex_num_map[number];
        _ssd.char_enable = true;
    else
        // invalid number!!
        // turns off the seven segments
        _ssd.char_enable = false;
}



// ssd_clear_char turns off all the seven segments, but
// it leaves the dot as it is
void ssd_clear_char (void)
{
    _ssd.char_enable = false;
}



// ssd_clear_all turns off all the segments of the
// display (and also the dot)
void ssd_clear_all (void)
{
    _ssd.char_enable = false;
    _ssd.dot_enable = false;
}



// ssd_dot turns on and off the dot
void ssd_dot (bool status);
{
    _ssd.dot_enable = status;
}



// ssd_shift_out updates the display by shifting
// out the content of _ssd
void ssd_shift_out (bool status);
{
    uint8_t mask;
    uint8_t current_char;

    if (ssd_common_anode)
        current_char = !_ssd.current_char;
    else
        current_char = _ssd.current_char;


    /* data is sent out assuming the following
     * connection:
     *
     *           ┌──────────────────────────┐
     *     clk ──┤                          │
     *    data ──┤                          │
     *   latch ──┤                          │
     *           │ SN74LS595                │
     *           └──┬──┬──┬──┬──┬──┬──┬──┬──┘
     *              │  │  │  │  │  │  │  │
     *              A  B  C  D  E  F  G  .
     */

    // shifting out the dot
    digitalWrite(ssd_data_pin, _ssd.dot_enable);

    // pulse the clk
    digitalWrite(ssd_clk_pin, HIGH);
    digitalWrite(ssd_clk_pin, LOW);




    for (mask = 1; mask <= 63; mask <<= 1)
    {
        digitalWrite(ssd_data_pin, current_char & _ssd.char_enable & mask);
        
        // pulse the clk
        digitalWrite(ssd_clk_pin, HIGH);
        digitalWrite(ssd_clk_pin, LOW);
    }

    // latch the new content to the output
    digitalWrite(ssd_latch_pin, HIGH);
    digitalWrite(ssd_latch_pin, LOW);
}

