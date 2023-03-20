#pragma once
#include "button.hpp"

// potentiometers
#define pot_1_pin           1
#define pot_2_pin           1
#define pot_3_pin           1



// mode selection buttons
#define btn_pressed_level   ACTIVE_HIGH
#define next_btn_pin        1
#define prev_btn_pin        1



// flashing LED
#define flashing_led_pin    1



// led strip (ls)
#define ls_clk_pin          1
#define ls_latch_pin        1
#define ls_data_pin         1

#define ls_common_anode
//#define ls_common_cathode
#if !defined(ls_common_anode) && !defined(ls_common_cathode)
    #error "either ls_common_anode or ls_common_cathode must be defined"
#elif defined(ls_common_anode) && defined(ls_common_cathode)
    #error "ls_common_anode and ls_common_cathode can't be defined at the same time"
#elif defined(ls_common_anode)
    #define _ls_off         1
    #define _ls_on          0
#else
    #define _ls_off         0
    #define _ls_on          1
#endif



// seven segment display (ssd)
#define ssd_clk_pin         1
#define ssd_latch_pin       1
#define ssd_data_pin        1

#define ssd_common_anode
//#define ssd_common_cathode
#if !defined(ssd_common_anode) && !defined(ssd_common_cathode)
    #error "either ssd_common_anode or ssd_common_cathode must be defined"
#elif defined(ssd_common_anode) && defined(ssd_common_cathode)
    #error "ssd_common_anode and ssd_common_cathode can't be defined at the same time"
#elif defined(ssd_common_anode)
    #define _ssd_off        1
    #define _ssd_on         0
#else
    #define _ssd_off        0
    #define _ssd_on         1
#endif

