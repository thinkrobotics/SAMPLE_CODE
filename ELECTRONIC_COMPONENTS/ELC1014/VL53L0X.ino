

/* This example shows how to use continuous mode to take
range measurements with the VL53L0X. It is based on
vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.

The range readings are in units of mm. 

Original source: https://github.com/pololu/vl53l0x-arduino
TRIED AND TESTED BY WWW.THINKROBOTICS.IN
Date mortified: Sep 26, 2017
*/


#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  sensor.init();
  sensor.setTimeout(500);

  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  sensor.startContinuous();
}

void loop()
{
  int distance =sensor.readRangeContinuousMillimeters();
 distance = distance -55;// -55 is to compensate for error. Change or set it to zero to make it work for your sensor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("mm");
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }

  Serial.println();
}
 
  
Source code for VL53L0X Distance measurement using two sensor module for Arduino
This code is to measure distance using two VL53L0X modules. Each module's distance value is displayed separately.


 

/* This example shows how to use continuous mode to take
range measurements with two VL53L0X. It is based on
vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.

The range readings are in units of mm. 

Original source: https://github.com/pololu/vl53l0x-arduino
Modified by Ahmad Shamshiri for RoboJax.com
Date mortified: June 06, 2018
Deniss from YouTube requested this code on June 06, 2018
*/


#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor1;// define object for sensor 1
VL53L0X sensor2;// define object for sensor 2

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  sensor1.init();// initialize sensor 1
  sensor1.setTimeout(500);// set time out for sensor 1
  
  sensor2.init();// initialize sensor 2
  sensor2.setTimeout(500);// set time out for sensor 2
  

  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  sensor1.startContinuous();// measure continuously for sensor 1
  sensor2.startContinuous();// measure continuously for sensor 2  
}

void loop()
{
  int distance1 =sensor1.readRangeContinuousMillimeters();// get distance for sensor 1
  int distance2 =sensor2.readRangeContinuousMillimeters();// get distance for sensor 2
  
 distance1 = distance1 -55;// -55 is to compensate for error. Change or set it to zero to make it work for your sensor
 distance2 = distance2 -34;// -35 is to compensate for error. Change or set it to zero to make it work for your sensor
 
  Serial.print("Distance 1: ");
  Serial.print(distance1);// print distance from sensor 1
  Serial.print("mm Distance 2: ");  
  Serial.print(distance2);// print distance from sensor 2 
  Serial.print("mm");
  if (sensor1.timeoutOccurred()) { Serial.print(" TIMEOUT 1"); }
  if (sensor2.timeoutOccurred()) { Serial.print(" TIMEOUT 2"); }  

  Serial.println();
}
 