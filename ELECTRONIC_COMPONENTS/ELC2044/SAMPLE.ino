//TRIED AND TESTED BY WWW.THINKROBOTICS.IN
#include <TM1637Display.h>

// CONSTANTS
const uint8_t OFF[] = {0, 0, 0, 0};
// In this library, the byte order is .GFEDCBA
const uint8_t PLAY[] = {B01110011, B00111000, B01011111, B01101110};
const uint8_t DONE[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
};


// Create a display object, specifying parameters (Clock pin, Data pin)
TM1637Display display(2, 3);

void setup(){
  // Set brightness of the LED
  display.setBrightness(4);
  // Clear the display
  display.setSegments(OFF);
}

void countdown() {
  for(int i=1500; i>0; i--) {
    // showNumberDec is a function for displaying numeric values,
    display.showNumberDec(i, true, 4, 0);
    delay(80);
  }
}
void displayPlay() {
  display.setSegments(PLAY);
  delay(2000);
}
void displayDone() {
  display.setSegments(DONE);
  delay(2000);
}
void loop(){
  displayPlay();
  countdown();
  displayDone();
}