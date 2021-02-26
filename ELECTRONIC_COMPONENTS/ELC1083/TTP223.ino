/*//==============================================================================//
 * TTP223 interfacing with Arduino
 * Date: - 3-04-2019
 * Author:- Sourav Gupta
 * For:- circuitdigest.com
 *///=============================================================================//
 
#include <Arduino.h>
 
//#define ON 1
//#define OFF 0
 
/*
 * Pin Description
 */
int Touch_Sensor = A5;
int LED = 13;
int Relay = A4;
 
/*
 * Programme flow Description
 */
int condition = 0;
int state = 0; //To hold the switch state.
 
/*
 * Pin mode setup
 */
void setup() {
pinMode(Touch_Sensor, INPUT);
pinMode(LED, OUTPUT);
pinMode(Relay, OUTPUT);
}
 
void loop() {
condition = digitalRead(A5); // Reading digital data from the A5 Pin of the Arduino.
 
if(condition == 1){
delay(250); // de-bounce delay.
if(condition == 1){
state = ~state; // Changing the state of the switch.
digitalWrite(LED, state);
digitalWrite(Relay, state);
}
}
}