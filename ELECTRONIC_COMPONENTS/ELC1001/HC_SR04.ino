/*
Tested with HY-SRF05, HC-SR04
Assuming a room temp of 20 degrees centigrade
The circuit:
* VVC connection of the sensor attached to +5V
* GND connection of the sensor attached to ground
* TRIG connection of the sensor attached to digital pin 12
* ECHO connection of the sensor attached to digital pin 13

TRIED AND TESTED BY WWW.THINKROBOTICS.IN
*/
const int TRIG_PIN = 12;
const int ECHO_PIN = 13;
void setup() 
{
	 // initialize serial communication:
	 
	 Serial.begin(9600);
	 pinMode(TRIG_PIN,OUTPUT);
	 pinMode(ECHO_PIN,INPUT);
}
void loop()
{
	 long duration, distanceCm, distanceIn;
	 
	 // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
	 
	 digitalWrite(TRIG_PIN, LOW);
	 delayMicroseconds(2);
	 digitalWrite(TRIG_PIN, HIGH);
	 delayMicroseconds(10);
	 digitalWrite(TRIG_PIN, LOW);
	 duration = pulseIn(ECHO_PIN,HIGH);
	 
	 // convert the time into a distance
	 
	 distanceCm = duration / 29.1 / 2 ;
	 distanceIn = duration / 74 / 2;
	 if (distanceCm <= 0)
	 {
		Serial.println("Out of range");
	 }
	 else 
	 {
		 Serial.print(distanceIn);
		 Serial.print("in, ");
		 Serial.print(distanceCm);
		 Serial.print("cm");
		 Serial.println();
	 }
	 delay(1000);
}
