//TRIED AND TESTED BY WWW.THINKROBOTICS.IN
void setup()
{
Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}
 
void loop()
{
int val;
val=analogRead(36); //connect sensor to pin marked 36 (A0)
Serial.println(val);//print the value to serial
delay(1000);
}