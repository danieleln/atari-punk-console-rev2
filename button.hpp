#pragma once
#include "Arduino.h"
#include "inttypes.h"

#define DEBOUNCE_DELAY 50 // ms

#define ACTIVE_HIGH HIGH
#define ACTIVE_LOW  LOW


class Button
{
    public:
    Button (const uint8_t, const bool);

    void update (unsigned int);

    void (*on_release) (void) = nullptr;
    void (*on_press)   (void) = nullptr;


    private:
    const uint8_t _pin;
    const bool _level_when_pressed;
    unsigned long _last_update;
    bool _was_pressed;
};
