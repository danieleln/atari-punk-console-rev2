#include "button.hpp"
#include "inttypes.h"

Button::Button (const uint8_t pin, const bool level): _pin(pin), _level_when_pressed(level)
{
    pinMode(INPUT, _pin);
    _last_update = millis();
}

void Button::update (unsigned int now)
{
    if (now - DEBOUNCE_DELAY > _last_update)
    {
        _last_update = now;

        // reads if the button is pressed
        bool _is_pressed = digitalRead(_pin) == _level_when_pressed;

        if (!_was_pressed & _is_pressed & (on_press != nullptr))
        {
            on_press();
        }
        else if (_was_pressed & !_is_pressed & (on_release != nullptr))
        {
            on_release();
        }

        _was_pressed = _is_pressed;
}

void Button::update (void)
{
    update(millis());
}
