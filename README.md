# Atari Punk Console revision 2
Revision of the famous Atari Punk Console, built around an atmega328p.
This version features a led strip to visualize the output waveform, two potentiometers to shape the waveform and one potentiometer that controls the pitch of the waveform.
There are different waveshaping algorithms (up to 16) that can be selected by means of two buttons. The number of the algorithm is visualized on a seven segment display.


## User Interface
- on/off switch + tiny led
- 16 LEDs strip
- Seven segment display
- Volume potentiometer
- Pitch potentiometer
- 2 waveform shaping potentiometers
- 2 mode selection buttons (next/prev)


## Modes
- off: only the dot of the seven segment display is turned on (plus some random slow flashes of the flashing LED)
- mode 0 (tracker):
- mode 1 (filler):
- mode 2 (kitt car):
- mode 3 (binary counter):


## Microcontroller in/out pins
- 3 analog input ports:
    - pitch potentiometer (pitch_pot)
    - 2 waveform shaping potentiometers (ws_pot_1, ws_pot_2)
- 2 digital input ports:
    - mode selection buttons (next_btn, prev_btn)
- 7 digital output ports:
    - waveform output (wave_out)
    - led strip display shift register (ls_clk, ls_latch, ls_data)
    - seven segment display shift register (ssd_clk, ssd_latch, ssd_data)

