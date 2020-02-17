#include "servomotor.h"

/**
 *  This is constructor of class without parameters.
 *  This initialize important parameters with default values.
 */
Servomotor::Servomotor () {
    this->minAngle = 0;
    this->maxAngle = 180;
    this->dutyCycleTime.restart(20);
}

/**
 *  @brief: This is constructor of class. Calls functions 
 *  used to initialize important parameters.
 *  
 *  @param: minAngle - minimum possible rotation angle of servomotor physic part;
 *  @param: maxAngle - maximum possible rotation angle of servomotor physic part;
 *  @param: dutyCycleTime - time between two changes of angle.
 */
Servomotor::Servomotor (short minAngle, short maxAngle, long dutyCycleTime) {
    this->minAngle = minAngle;
    this->maxAngle = maxAngle;

    this->dutyCicleTime.restart (dutyCycleTime);

    this->rotateToMidAngle ();
}

/**
 *  @brief: This is destructor of class.
 */
Servomotor::~Servomotor () {

}

/**
 *  @brief: Initialize importants parameters of servomotor controller.
 *  
 *  @param: minAngle - minimum possible rotation angle of servomotor physic part;
 *  @param: maxAngle - maximum possible rotation angle of servomotor physic part;
 *  @param: dutyCycleTime - time between two changes of angle.
 */
void Servomotor::setup (short minAngle, short maxAngle, long dutyCycleTime) {
    this->setMinAngle (minAngle);
    this->setMaxAngle (maxAngle);

    this->dutyCicleTime.restart (dutyCycleTime);
}

/**
 *  @brief: This function sends signal to mantain angle of electronic
 *  device, respecting the duty cycle time.
 */
void Servomotor::loop () {
    if (this->dutyCycleTime.elapsed ()) {
        this->write (this->lastAngle);
    }
}

/**
 *  @brief: This method set new value of minimum angle.
 *
 *  @param: value - new value of minimum angle.
 */
void Servomotor::setMinAngle (short value) {
    if (this->maxAngle > value) {
        this->minAngle = value;
        
        if (this->minAngle > lastAngle) {
            this->rotateToMinAngle ();
        }
    }

}

/**
 *  @brief: This method set new value of maximum angle.
 *
 *  @param: value - new value of maximum angle.
 */
void Servomotor::setMaxAngle (short value) {
    if (this->minAngle < value) {
        this->maxAngle = value;

        if (this->maxAngle < lastAngle) {
            this->rotateToMaxAngle ();
        }
    }
}

/**
 *  @brief: This method set new value of duty cycle time.
 *
 *  @param: value - new value of duty cycle time.
 */
void Servomotor::setDutyCicleTime (unsigned long duration) {
    if (0 < duration) {
        this->dutyCycleTime.restart (duration);
    }
}

/**
 *  @brief: This function sends a signal to decrease angle of
 *  electronic device with a value or until of his limit.
 * 
 *  @param: rate - value low from angle.
 */
void Servomotor::decreaseAngle (short rate) {
   if  (this->minAngle <= this->lastAngle - rate) {
      this->rotateTo (this->lastAngle - rate);
   }
   else {
      this->rotateTo (this->minAngle);
   }
}

/**
 *  @brief: This function sends a signal to increase angle of
 *  electronic device with a value or until of his limit.
 *  
 *  @param: rate - value added to angle.
 */
void Servomotor::increaseAngle (short rate) {
   if  (this->maxAngle >= this->lastAngle + rate) {
      this->rotateTo (this->lastAngle + rate);
   }
   else {
      this->rotateTo (this->maxAngle);
   }
}

/**
 *  @brief: This method sends signal to rotate mechanical
 *  part to a specific angle.
 *
 *  @param: angle - new value in buffer.
 */
void Servomotor::rotateTo (short angle) {
    this->lastAngle = angle;
}

/**
 *  @brief: This method sends signal to rotate mechanical
 *  part to minimum angle.
 */
void Servomotor::rotateToMinAngle () {
    this->rotateTo (this->minAngle);
}

/**
 *  @brief: This method sends signal to rotate mechanical
 *  part to middle angle.
 */
void Servomotor::rotateToMidAngle () {
    this->rotateTo (this->getMidAngle ());
}

/**
 *  @brief: This method sends signal to rotate mechanical
 *  part to maximum angle.
 */
void Servomotor::rotateToMaxAngle () {
    this->rotateTo (this->maxAngle);
}

/**
 *  This function return last value send to servo.
 * 
 *  @return: last value sends to the electronic device.
 */
short Servomotor::getLastAngle () {
   return this->lastAngle;
}

/**
 *  This function returns error of servo rotation electronic device.
 *  
 *  @return: difference between last angle value send to device and 
 *  current angle of device. If that is zero, then servomotor is precise.
 */
short Servomotor::getError () {
   return  this->lastAngle - this->read ();
}

/**
 *  @brief: This method returns min angle rotation of servomotor.
 *
 *  @return: min angle rotation of servomotor..
 */
short getMinAngle () {
    return this->minAngle;
}

/**
 *  @brief: This method returns middle angle rotation of servomotor.
 *
 *  @return: middle angle rotation of servomotor..
 */
short getMidAngle () {
    return 1 >> (this->minAngle + this->maxAngle);
}

/**
 *  @brief: This method returns max angle rotation of servomotor.
 *
 *  @return: max angle rotation of servomotor.
 */
short getMaxAngle () {
    return this->maxAngle;
}

/**
 *  @brief: This method returns duration of duty cycle time.
 *
 *  @return: duration of duty cycle time.
 */
unsigned long getDutyCycle () {
    return this->dutyCycleTime.getDuration ();
}