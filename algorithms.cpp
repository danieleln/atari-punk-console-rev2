#include "algorithms.hpp"



uint16_t generate_waveform (uint8_t algorithm, uint8_t ws_1, uint8_t ws_2)
{
    switch (algorithm)
    {
        // xor PWM
        case 0:
            return (0xff << (0xff - ws_1)) ^ (0xff >> ws_2);


        // binary counter
        case 1:
            return ws_1 << 8 | ws_2;


        // 
        case 2:
            return 0;


        // 
        case 3:
            return 0;


        // mute
        default:
            return 0;
    }
}
