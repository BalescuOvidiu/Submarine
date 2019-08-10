#include "servomotor.h"

/**
 * 
 */
Servomotor::~Servomotor() {
  this->write (ANGLE_LEFT);
}

/**
 * This function sends signal to mantain angle of electronic device.
 * If test is enabled, then this function send signal for a round-trip
 * move to test his speed , response time and functionality.
 */
void Servomotor::loop () {
   if  (this->testEnabled) {
      if  (testStepTime.elapse ()) {
         this->lastAngle += this->testDirection;
         if  (this->lastAngle <= ANGLE_LEFT || this->lastAngle >= ANGLE_RIGHT) {
            testDirection *= -1;
         }
      }
   }
   
   this->write (this->lastAngle);
}

/**
 * This function sends a signal to decrease angle of electronic device with a 
 * value or until of his limit.
 * 
 * @params: rate - value low from angle.
 */
void Servomotor::decreaseAngle (int rate) {
   if  (this->lastAngle - rate >= ANGLE_LEFT) {
      this->write (this->lastAngle - rate);
   }
   else {
      this->write (ANGLE_LEFT);
   }
}

/**
 * This function sends a signal to increase angle of electronic device with a 
 * value or until of his limit.
 * 
 * @params: rate - value added to angle.
 */
void Servomotor::increaseAngle (int rate) {
   if  (this->lastAngle + rate <= ANGLE_RIGHT) {
      this->write (this->lastAngle + rate);
   }
   else {
      this->write (ANGLE_RIGHT);
   }
}

/**
 * This function sends signal to set angle of device to left, minimum.
 */
void Servomotor::left () {
  this->write (ANGLE_LEFT);
}

/**
 * This function sends signal to set angle of device to middle, center.
 */
void Servomotor::middle () {
  this->write (ANGLE_MIDDLE);
}

/**
 * This function sends signal to set angle of device to right, maximum.
 */
void Servomotor::right () {
  this->write (ANGLE_RIGHT);  
}

/**
 * This function return last value send to servo.
 * 
 * @return: - last value sends to the electronic device.
 */
int Servomotor::getLastAngle () {
   return this->lastAngle;
}

/**
 * This function returns error of servo rotation electronic device.
 * 
 * @return: - difference between last angle value send to device and
 *            current angle of device. If that is zero, then servomotor
 *            is precise.
 */
long Servomotor::getError () {
   return  this->lastAngle - this->read ();
}

/**
 * This function sends signal to enable test move.
 * 
 * @params: duration - between two moves of servomotor.
 */
void Servomotor::enableTest (unsigned long duration) {
   this->testEnabled = true;
   this->testStepTime = TimeInterval (duration);
}

/**
 * This function sends signal to disable test move.
 */
void Servomotor::disableTest () {
   this->testEnabled = false;
   this->testDirection = 1;
}

/**
 * This function sends change signal to enable or disable test move.
 * 
 * @params: duration - between two moves of servomotor.
 */
void Servomotor::toggleTest (unsigned long duration) {
  if (this->testEnabled) {
    this-> disableTest ();
  }
  else {
    this->enableTest (duration);
  }
}
