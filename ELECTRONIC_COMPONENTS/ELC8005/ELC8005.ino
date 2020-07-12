/* This code works with SIM800L Evb version, it sets the module on receiving SMS mode
 * And when the user sends SMS it will be shown on the serial monitor
 * The receiving mode is only set at the setup, you can later set the mode you want and check the AT functions you want
 * It's a basic code to test the SIM800L
 * Refer to www.SurtrTech.com for more detaims
 */

#include <SoftwareSerial.h>    //Library required for serial communication

SoftwareSerial sim800l(2, 3); // RX,TX for Arduino and for the module it's TXD RXD, they should be inverted



void setup()
{
   
  sim800l.begin(9600);              //Module baude rate, this is on max, it depends on the version
  Serial.begin(9600);               //Begin the Serial communication with PC
  Serial.println("Starting ...");
  delay(5000);                      //Delay to let the module to connect to network, if turned on before you can remove this
  sim800l.println("AT");            //Send AT command it will says "OK" if everything is fine
  Serialcom();                      //description below
  sim800l.println("AT+CMGF=1");     // Configuring TEXT mode
  Serialcom();
  sim800l.println("AT+CNMI=2,2,0,0,0"); //The way to handle the SMS received, check the module manual, to sum up: store the text or transfert it to serial or other number....
  Serialcom();
  
}



void loop() {
  
Serialcom();                //The only function to run in loop, this function just check if the user has sent something using the Serial monitor and transfers it to the module
                            //and if the module has something to say it will be displayed on the serial monitor, here used to show the feedback of the AT commands sent in the setup
                            //and shows the received SMS

}


void Serialcom()
{
  delay(500);
  while(Serial.available())                                                                      // IDE serial l serial  sim800L
  {
    sim800l.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(sim800l.available())                                                                      //serialsim800L l serial dial IDE
  {
    Serial.write(sim800l.read());//Forward what Software Serial received to Serial Port
  }
}
