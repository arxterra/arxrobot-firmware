 
// --------------------------------------------------
// Pololu VNH5019 Motorshield
// --------------------------------------------------
#include <DualVNH5019MotorShield.h>

// Translation Array. Unique to Pathfinder and Pololu VNH5019 Motor Shield (need to verify shield) 
int dirArray[5] = {0, 1,-1,0,0};  // FORWARD = index 1, BACKWARD = index 2, BRAKE = index 3, RELEASE = index 4

DualVNH5019MotorShield motor;  // instantiate motors
       
void move_VNH5019(uint8_t * motordata)
{
  int m1Speed = dirArray[motordata[1]] * motordata[2]; // left motor
  int m2Speed = dirArray[motordata[3]] * motordata[4]; // right motor
  motor.setSpeeds(m1Speed, m2Speed);
}
 
