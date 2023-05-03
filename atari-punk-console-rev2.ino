#include "inttypes.h"
#include "config.hpp"
#include "button.hpp"
#include "seven_segment_display.hpp"
#include "led_strip.hpp"
#include "algorithms.hpp"

// potentiometers value
uint8_t ws_1, ws_2;

// algorithm selection buttons ("button.hpp")
Button next_btn(next_btn_pin, btn_pressed_level);
Button prev_btn(prev_btn_pin, btn_pressed_level);

void select_next_algorithm (void);
void select_prev_algorithm (void);

unsigned long update_time;




// selected algorithm
uint8_t algorithm = -1;

// seven segment display
void update_ssd (void);

// output waveform
uint16_t waveform = 0;



void setup ()
{
    // set the wave_out pin as output
    wave_out_DDRx |= 1<<wave_out_PBn;

    // initializes pins for the led strip
    ls_init();

    // initializes pins for the seven segment display
    ssd_init();

    // changes algorithm when pressing the button
    next_btn.on_press = select_next_algorithm;
    prev_btn.on_press = select_prev_algorithm;



    // disables Compare Output Mode
    TCCR1A &= ~(1<<COM1A1 | 1<<COM1A0 | 1<<COM1B1 | 1<<COM1B0);
    // selects the Waveform Generation Mode to CTC (Clear Timer on Compare)
    TCCR1A &= ~(1<<WGM11 | 1<<WGM10);
    TCCR1B |=  1<<WGM12;
    TCCR1B &= ~1<<WGM13;
    // enables the Output Compare Interrupt for the register A
    TIMSK1 |= 1<<OCIE1A;
    // sets the Output Compare Register A
    OCR1A |= 7687;


    // enables interrupts
    sei();
}



void loop ()
{
    // analogRead( ... ) outputs an integer value ∈ [0, 1023]
    // The value of wave shaping potentiometers is mapped to
    // the range [0, 255]. One way to make this conversion is:
    //
    //      map(analogRead( ... ), 0, 1023, 0, 255)
    //
    // but that's slow to run. Instead, it's possible to exploit
    // the fact that the conversion is between powers of 2:
    // from [0, 2^10-1] to [0, 2^8-1]. In fact, the same effect
    // can be obtained simply by shifting the value of 2 binary
    // places (from 2^10 to 2^8)
    ws_1 = analogRead(ws_pot_1) >> 2;


    ws_2 = analogRead(ws_pot_2) >> 2;

    
    // generate the waveform ("algorithm.hpp")
    waveform = generate_waveform(algorithm, ws_1, ws_2);


    // update the led strip
    ls_shift_out(waveform);

    
    // update buttons
    update_time = millis();
    next_btn.update(update_time);
    prev_btn.update(update_time);
}



void select_next_algorithm (void)
{
    if (algorithm == NUM_OF_ALGORITHMS - 1)
        algorithm = -1;
    // else if (algorithm == -1)
    //     algorithm = 0;
    else
        algorithm++;

    update_ssd();
}


void select_prev_algorithm (void)
{
    if (algorithm == -1)
        algorithm = NUM_OF_ALGORITHMS - 1;
    // else if (algorithm == 0)
    //     algorithm = -1;
    else
        algorithm--;

    update_ssd();
}


// updates the seven segment display every time that
// either next_btn or prev_btn is pressed
void update_ssd (void)
{
    // functions defined in "seven_segments_display.hpp"


    // displaies the algorithm number
    // NB: when the algorithm is -1 (a.k.a 255),
    // the function automatically clears 
    // the display since it doesn't recognise
    // it as a valid hexadecimal number
    ssd_display_num(algorithm);

    // turns on the dot only when the algorithm is -1
    ssd_dot(algorithm == -1);

    // updates the display
    ssd_shift_out();
}


volatile uint16_t mask = 0;

ISR(TIMER1_COMPA_vect)
{
    mask <<= 1;
    if (mask == 0) mask = 1;


    if (waveform & mask)
        wave_out_PORTx |= 1<<wave_out_PBn;
    else
        wave_out_PORTx &= ~1<<wave_out_PBn;
}


