//TRIED AND TESTED BY WWW.THINKROBOTICS.IN
float amplitude_current; //amplitude current
float effective_value; //effective current
void setup()
{
Serial.begin(9600);
pins_init();
}
void loop()
{
int sensor_max;
sensor_max = getMaxValue();
Serial.print("sensor_max = ");
Serial.println(sensor_max);
//the VCC on the Grove interface of the sensor is 5v
amplitude_current=(float)sensor_max/1024*5/200*1000000;
effective_value=amplitude_current/1.414;
//minimum_current=1/1024*5/200*1000000/1.414=24.4(mA)
//Only for sinusoidal alternating current
Serial.println("The amplitude of the current is(in mA)");
Serial.println(amplitude_current,1);//Only one number after the decimal point
Serial.println("The effective value of the current is(in mA)");
Serial.println(effective_value,1);
}
void pins_init()
{
pinMode(ELECTRICITY_SENSOR, INPUT);
}
/*Function: Sample for 1000ms and get the maximum value from the SIG pin*/
int getMaxValue()
{
int sensorValue; //value read from the sensor
int sensorMax = 0;
uint32_t start_time = millis();
while((millis()-start_time) < 1000)//sample for 1000ms
{
sensorValue = analogRead(ELECTRICITY_SENSOR);
if (sensorValue > sensorMax)
{
/*record the maximum sensor value*/
sensorMax = sensorValue;
}
}
return sensorMax;
}