#include <AFMotor.h>
AF_DCMotor motor(1, MOTOR12_64KHZ);
motor.setSpeed(200);
void loop() {

motor.run(FORWARD);

delay(1000);

motor.run(BACKWARD);

delay(1000);

motor.run(RELEASE);

delay(1000);

}
