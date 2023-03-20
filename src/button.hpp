#pragma once
#define DEBOUNCE_DELAY 50

#define ACTIVE_HIGH HIGH
#define ACTIVE_LOW  LOW


class Button
{
    public:
    Button (const byte, const bool);

    void update (unsigned int);
    void update (void);

    void *on_release (void) = nullptr;
    void *on_press   (void) = nullptr;


    private:
    const byte _pin;
    const bool _level_when_pressed;
    unsigned long _last_update;
    bool _was_pressed;
};
