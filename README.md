# Button Box
Just a fancy button box (with not so much buttons actually, some potentiometers, a seven segment display and a ton of LEDs)


## User Interface
- on/off switch + tiny led
- 16 LEDs strip
- Seven segment display
- big flashing LED
- 3 potentiometers
- 2 mode selection buttons (next/prev)


## Modes
- off: only the dot of the seven segment display is turned on (plus some random slow flashes of the flashing LED)
- mode 0 (tracker):
- mode 1 (filler):
- mode 2 (kitt car):
- mode 3 (binary counter):


## Microcontroller in/out pins
- 3 analog input ports:
    - potentiometers (pot_1, pot_2, pot_3)
- 2 digital input ports:
    - mode selection buttons (next_btn, prev_btn)
- 7 digital output ports:
    - flashing LED (flashing_led)
    - led strip display shift register (ls_clk, ls_latch, ls_data)
    - seven segment display shift register (ssd_clk, ssd_latch, ssd_data)

