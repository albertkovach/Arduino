// Credit:
// Midi to Arduino Converter
//     - Andy Tran (extramaster), 2015
// https://www.extramaster.net/tools/midiToArduino/
//
// Process:
// Midi -> Midi tracks -> Note mappings -> Frequency
//
// CC0

// Set this to be the pin that your buzzer resides in. (Note that you can only have one buzzer actively using the PWM signal at a time).
int tonePin = 11;
void setup() {
  
}

void midi() {

    tone(tonePin, 2093, 26.1627906977);
    delay(29.0697674419);
    delay(29.0697674419);
    tone(tonePin, 1975, 8.72093023256);
    delay(9.68992248062);
    delay(38.7596899225);
    tone(tonePin, 3135, 17.4418604651);
    delay(19.3798449612);
    delay(38.7596899225);
    tone(tonePin, 2959, 26.1627906977);
    delay(29.0697674419);
    delay(29.0697674419);
    tone(tonePin, 3135, 26.1627906977);
    delay(29.0697674419);
    delay(9.68992248062);
    tone(tonePin, 1975, 26.1627906977);
    delay(29.0697674419);

}


void loop() {
  midi();
  delay(5000);
  midi();
  midi();
  midi();
  midi();
  midi();
  delay(5000);
}

