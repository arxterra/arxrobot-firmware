/* 

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *motorL = AFMS.getMotor(1);
Adafruit_DCMotor *motorR = AFMS.getMotor(2);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);

// --------------------------------------------------
// Adafruit L293D Motorshield
// --------------------------------------------------

void setup_PCA9685()
{
  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  motorL->run(RELEASE);
  motorR->run(RELEASE);
}

void move_PCA9685(uint8_t * motordata)
{
  
  motorL->setSpeed(motordata[2]);   
  motorR->setSpeed(motordata[4]);
  motorL->run(motordata[1]);
  motorR->run(motordata[3]);
}

void safeRover()
{
  motorL->run(RELEASE);
  motorR->run(RELEASE);
   // Serial.println("Safe Rover");
}

void stopMotors(){
  motorL->run(RELEASE);
  motorR->run(RELEASE);
}


/* motordata[1] and motordata[3]
  FORWARD  1
  BACKWARD 2
  BRAKE    3
  RELEASE  4
*/
