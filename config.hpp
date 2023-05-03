#pragma once
#include "button.hpp"

// configuration file for in/out pins of the microcontroller


// potentiometers
#define ws_pot_1            1
#define ws_pot_2            1
#define pitch_pot           1



// algorithm selection buttons
#define btn_pressed_level   ACTIVE_HIGH
#define next_btn_pin        1
#define prev_btn_pin        1



// waveform output
#define wave_out_DDRx       DDRD
#define wave_out_PORTx      PORTD
#define wave_out_PBn        PB3



// led strip (ls)
#define ls_clk              1
#define ls_latch            1
#define ls_data             1

#define ls_common_anode
//#define ls_common_cathode
#if !defined(ls_common_anode) && !defined(ls_common_cathode)
    #error "either ls_common_anode or ls_common_cathode must be defined"
#elif defined(ls_common_anode) && defined(ls_common_cathode)
    #error "ls_common_anode and ls_common_cathode can't be defined at the same time"
#elif defined(ls_common_anode)
    const bool ls_active_low = true;
#else
    const bool ls_active_low = false;
#endif



// seven segment display (ssd)
#define ssd_clk             1
#define ssd_latch           1
#define ssd_data            1

#define ssd_common_anode
//#define ssd_common_cathode
#if !defined(ssd_common_anode) && !defined(ssd_common_cathode)
    #error "either ssd_common_anode or ssd_common_cathode must be defined"
#elif defined(ssd_common_anode) && defined(ssd_common_cathode)
    #error "ssd_common_anode and ssd_common_cathode can't be defined at the same time"
#elif defined(ssd_common_anode)
    const bool ssd_active_low = true;
#else
    const bool ssd_active_low = false;
#endif

