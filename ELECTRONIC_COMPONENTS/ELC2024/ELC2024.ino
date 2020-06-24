#include <Esplora.h>

void setup()
{
Serial.begin(9600);
}

void loop()
{
int value = Esplora.readJoystickX();
Serial.println(value);

delay(1000);
}
