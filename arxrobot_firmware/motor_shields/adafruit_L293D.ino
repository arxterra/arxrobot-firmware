// --------------------------------------------------
// Adafruit L293D Motorshield
// --------------------------------------------------
#include <AFMotor.h> 

AF_DCMotor motorL(1, MOTOR12_64KHZ);  // instantiate motors
AF_DCMotor motorR(2, MOTOR12_64KHZ);

void move_L293D(uint8_t * motordata)
{
  motorL.setSpeed(motordata[2]);   
  motorR.setSpeed(motordata[4]);
  motorL.run(motordata[1]);
  motorR.run(motordata[3]);
}

void safeRover()
{
   motorL.run(RELEASE);
   motorR.run(RELEASE);
   // Serial.println("Safe Rover");
}

void stopMotors(){
}


/* motordata[1] and motordata[3]
  FORWARD  1
  BACKWARD 2
  BRAKE    3
  RELEASE  4
*/
