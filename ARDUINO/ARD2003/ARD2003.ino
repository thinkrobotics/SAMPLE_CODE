// Most simplest program to use a DS1307

#include <DS1307.h>

DS1307  Horloge(false); // declare a DS1307 object in stop mode

void setup()
{
  Serial.begin(9600); // to communicate with console
  Horloge.begin(); // initialise auu communication between arduino and DS1307
  Horloge.run(); // start count at predetermine values (01/01/2000 at 00:00:00)
}

boolean premier = true;
void loop()
{ 
  Serial.print("Time : ");
  Serial.println(Horloge.getTimeString());
  delay(100);
}
