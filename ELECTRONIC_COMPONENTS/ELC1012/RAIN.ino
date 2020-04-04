//   TRIED AND TESTED BY WWW.THINKROBOTICS.IN
void setup()
{
	Serial.begin(9600);
	pinMode(2, OUTPUT);
}
void loop()
{
	//analog output
	if(analogRead(0)<300) 
		Serial.println("Heavy Rain");
	else if(analogRead(0)<500) 
		Serial.println("Moderate Rain");
	else 
		Serial.println("No Rain");
	// //digital output
	// if(digitalRead(2) == HIGH) Serial.println("No Rain Detected");
	// else Serial.println("Rain Detected");
	delay(250);
}