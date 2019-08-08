#include "servomotor.h"

/**
 * 
 */
void Servomotor::loop () {
   if  (this->testEnabled) {
      if  (testStepTime.elapse ()) {
         this->lastAngle += this->testDirection;
         if  (this->lastAngle <= ANGLE_MIN || this->lastAngle >= ANGLE_MAX) {
            testDirection *= -1;
         }
      }
   }
   
   this->write (this->lastAngle);
}

/**
 * 
 */
void Servomotor::decreaseAngle (int a) {
   if  (this->lastAngle - a >= ANGLE_MIN) {
      this->write (this->lastAngle - a);
   }
   else {
      this->write (ANGLE_MIN);
   }
}

/**
 * 
 */
void Servomotor::increaseAngle (int a) {
   if  (this->lastAngle + a <= ANGLE_MAX) {
      this->write (this->lastAngle + a);
   }
   else {
      this->write (ANGLE_MIN);
   }
}

/**
 * 
 */
int Servomotor::getLastAngle () {
   return this->lastAngle;
}

/**
 * 
 */
long Servomotor::getError () {
   return  this->lastAngle - this->read ();
}

/**
 * 
 */
void Servomotor::enableTest (unsigned long duration) {
   this->testEnabled = true;
   this->testStepTime = TimeInterval (duration);
}

/**
 * 
 */
void Servomotor::disableTest () {
   this->testEnabled = false;
   this->testDirection = 1;
}
