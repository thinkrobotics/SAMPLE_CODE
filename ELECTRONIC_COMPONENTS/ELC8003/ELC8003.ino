void setup() {
  // initialize LED_BUILTIN as an output pin.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off
  delay(1000);
}
