// define global variables for analog pins.

// X values will be read from pin 0 and Y from pin 1

#define PIN_ANALOG_X 0

#define PIN_ANALOG_Y 1

 

void setup() {

 // Start serial because we will observe values at serial monitor

 Serial.begin(9600);

}

 

void loop() {

 // Print x axis values

 Serial.print("x: ");

 Serial.println(analogRead(PIN_ANALOG_X));

 // Print y axis values

 Serial.print("y: ");

 Serial.println(analogRead(PIN_ANALOG_Y));

 

 // Some delay to clearly observe your values on serial monitor.

 delay(500);

}
