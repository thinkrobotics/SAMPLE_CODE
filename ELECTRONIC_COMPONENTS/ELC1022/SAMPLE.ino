//TRIED AND TESTED BY WWW.THINKROBOTICS.IN
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
#include <Wire.h>
#include <MPU6050.h>

#define period 10000

MPU6050 mpu;

int count=0;
char okFlag=0;

byte degree[8] = {
  0b00000,
  0b00110,
  0b01111,
  0b00110,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

void setup() 
{
  lcd.begin(16,2);
  lcd.createChar(0, degree);
  Serial.begin(9600);
  Serial.println("Initialize MPU6050");
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    lcd.clear();
    lcd.print("Device not Found");
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
  count=0;

  mpu.calibrateGyro();
  mpu.setThreshold(3);
  
  lcd.clear();
  lcd.print("MPU6050 Interface");
  lcd.setCursor(0,1);
  lcd.print(" Circuit Digest");
  delay(2000);
  lcd.clear();
}

void loop()
{
    lcd.clear();
    lcd.print("Temperature");
    long st=millis();
    Serial.println("Temperature");
    while(millis()<st+period)
    {
      lcd.setCursor(0,1);
      tempShow();
    }
    
    lcd.clear();
    lcd.print("Gyro");
    delay(2000);
    st=millis();
    Serial.println("Gyro");
    while(millis()<st+period)
    {
      lcd.setCursor(0,1);
      gyroShow();
    }

    lcd.clear();
    lcd.print("Accelerometer");
    delay(2000);
    st=millis();
    Serial.println("Accelerometer");
    while(millis()<st+period)
    {
      lcd.setCursor(0,1);
      accelShow();
    }
}

void tempShow()
{
    float temp = mpu.readTemperature();
    Serial.print(" Temp = ");
    Serial.print(temp);
    Serial.println(" *C");
    lcd.clear();
    lcd.print("Temperature");
    lcd.setCursor(0,1);
    lcd.print(temp);
    lcd.write((byte)0);
    lcd.print("C");
    delay(400);
}

void gyroShow()
{
  //lcd.setCursor(0,0);
  lcd.clear();
  lcd.print(" X     Y     Z");
  Vector rawGyro = mpu.readRawGyro();
  Vector normGyro = mpu.readNormalizeGyro();
  lcd.setCursor(0,1);
  lcd.print(normGyro.XAxis,1);
  lcd.setCursor(6,1);
  lcd.print(normGyro.YAxis,1);
  lcd.setCursor(12,1);
  lcd.print(normGyro.ZAxis,1);
  Serial.print(" Xnorm = ");
  Serial.print(normGyro.XAxis);
  Serial.print(" Ynorm = ");
  Serial.print(normGyro.YAxis);
  Serial.print(" Znorm = ");
  Serial.println(normGyro.ZAxis);
  delay(200);
}

void accelShow()
{
 // lcd.setCursor(0,0);
  lcd.clear();
  lcd.print(" X     Y     Z");
  Vector rawAccel = mpu.readRawAccel();
  Vector normAccel = mpu.readNormalizeAccel();
  lcd.setCursor(0,1);
  lcd.print(normAccel.XAxis,1);
  lcd.setCursor(6,1);
  lcd.print(normAccel.YAxis,1);
  lcd.setCursor(12,1);
  lcd.print(normAccel.ZAxis,1);
  Serial.print(" Xnorm = ");
  Serial.print(normAccel.XAxis);
  Serial.print(" Ynorm = ");
  Serial.print(normAccel.YAxis);
  Serial.print(" Znorm = ");
  Serial.println(normAccel.ZAxis);
  delay(200);
}