void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);

}

void loop() {
  if (digitalRead(2) == HIGH);
  Serial.println("Sensor is touched");
  delay(500);

}
