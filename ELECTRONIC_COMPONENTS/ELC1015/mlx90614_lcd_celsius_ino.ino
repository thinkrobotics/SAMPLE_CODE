/* This code works with MLX90614 (GY906) and LCD ic screen
 * It measures both ambient and object temperature in Celsius and display it on the screen
 * Please visit www.surtrtech.com for more details
 */

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>

#define I2C_ADDR 0x27 //I2C adress, you should use the code to scan the adress first (0x27) here
#define BACKLIGHT_PIN 3 // Declaring LCD Pins
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  
  mlx.begin();
  lcd.begin (16,2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH); //Lighting backlight
  lcd.home ();

}

void loop() {
 lcd.setCursor(0,0);
 lcd.print("Ambient ");
 lcd.print(mlx.readAmbientTempC());
 lcd.print(" C");
 
 lcd.setCursor(0,1);
 lcd.print("Target  ");
 lcd.print(mlx.readObjectTempC());
 lcd.print(" C");

 delay(1000);

}
