//TRIED AND TESTED BY WWW.THINKROBOTICS.IN
#include "Timer.h"
#include <LiquidCrystal.h>

//Variable decleared
float Volts; //voltage read by arduino
float tempC; //final temperature in degree celsius after calibration
float tempF; //final temperature in degree fahrenhiet after calibration
float temp1; //temperatuere before calibration
float calibration; //calibration 
float Rx; //Resistance of PT100

// variables that required to convert voltage into resistance
float C = 106.852; //Constant of straight line (Y = mx + C)
float slope = 48.31; // Slope of straight line (Y = mx + C)


// variables that required to convert resistance into temperatures
float R0 = 100.0; //Resistance of minimum temperature to be measured (at 0 degree)
float alpha = 0.00385; // value of alpha from datasheet

//pin assign ment for sensor
int Vin = A0;

//pin assignment for LCD
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Timer t; // Define Timer object

//Setup function
void setup() {
  Serial.begin(9600); // Set Baudrate at 9600
  lcd.begin(16, 2); //Start LCD
  pinMode(Vin,INPUT); // Make Vin (A0) pin as input
  
  t.every(100,takeReading); // Take reading of sensor in every 100ms
 analogReference(INTERNAL); // Taking internal reference 1.1V ADC of arduino
}

//loop function
void loop() {
  t.update(); // Update Timer
}

void takeReading(){
  // Bits to Voltage
  Volts = (analogRead(Vin)/1023.0)*1.1; //converting bits of voltage into voltage
  lcd.setCursor(0, 0);
  lcd.print("V:");
  lcd.setCursor(4,0);
  lcd.print(Volts);
  // Converting voltage to resistance
  Rx = Volts*slope+C; //y=mx+c
  lcd.setCursor(9,0);
  lcd.print("R:");
  lcd.setCursor(11,0);
  lcd.print(Rx);
  
  // Converting resistnace to temperature
  temp1= (Rx/R0-1.0)/alpha; // from Rx = R0(1+alpha*X)
  calibration=0.3+(0.005*temp1); //tolerance for class B PT100
  tempC=temp1-calibration; // Final temperature in celsius
  
  // conversion of celsius to fehrenheit
   tempF = tempC*1.8+32; //Final temperature in fehrenheit 
 //Serial.println(Volts);
 // Serial.println(Rx);
 lcd.setCursor(0,1);
 lcd.print(tempC);
 lcd.setCursor(5,1);
 lcd.print((char)223);
 lcd.setCursor(6,1);
 lcd.print("C");
 lcd.setCursor(7,1);
 lcd.print(tempF);
 lcd.setCursor(13,1);
 lcd.print((char)223);
 lcd.setCursor(14,1);
 lcd.print("F");
 Serial.println(tempC);
 delay(1000);
}