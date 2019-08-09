#include "motor.h"

/**
 * This is a constructor of motor object.
 * @params: pinA - connected to first wire of motor;
 *          pinB - connected to second wire of motor.
 */
Motor::Motor(byte pinA, byte pinB) {
   pinMode(pinA, OUTPUT);
   pinMode(pinB, OUTPUT);

   this->pinA = pinA;
   this->pinB = pinB;
   this->velocity = MOTOR_IDLE;
}

/**
 * This is a constructor of motor object.
 * @params: pinA - connected to first wire of motor;
 *          pinB - connected to second wire of motor;
 *          velocity - speed of motor. 
 */
Motor::Motor(byte pinA, byte pinB, int velocity) {
   pinMode(pinA, OUTPUT);
   pinMode(pinB, OUTPUT);

   this->pinA = pinA;
   this->pinB = pinB;

   this->write (velocity);
}

/**
 * This is destructor of motor object. This stops the electronic signal
 * to it.
 */
Motor::~Motor() {
   this->stop ();
}

/**
 * This function sends the signal to change speed of motor.
 */
void Motor::write(int velocity) {
   this->velocity = velocity;

   this->loop();
}

/**
 * This function sends signal to mantain speed of motor.
 */
void Motor::loop() {
   if (this->velocity >= MOTOR_IDLE) {
      analogWrite(pinA, MOTOR_IDLE);
      analogWrite(pinB, this->velocity);
   }
   else {
      analogWrite(pinA, -this->velocity);
      analogWrite(pinB, MOTOR_IDLE);      
   }
}

/**
 * This function stops move of motor.
 */
void Motor::stop() {
   this->write (MOTOR_IDLE);
}

/**
 * This function makes the motor to move forward
 * direction with full speed.
 */
void Motor::forward () {
  this->write (MOTOR_FORWARD);
}

/**
 * This function makes the motor to move backward
 * direction with full speed.
 */
void Motor::backward () {
  this->write (MOTOR_BACKWARD);  
}

/**
 * This function increases value of speed.
 */
void Motor::increaseVelocity(int rate) {
   if (MOTOR_FORWARD - rate <= this->velocity) {
      this->velocity = MOTOR_FORWARD;
   }
   else {
      this->velocity += rate;
   }
}

/**
 * This function decreases value of speed.
 */
void Motor::decreaseVelocity(int rate) {
   if (MOTOR_BACKWARD + rate >= this->velocity) {
      this->velocity = MOTOR_BACKWARD;
   }
   else {
      this->velocity -= rate;
   }
}
