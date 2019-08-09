#include "irDevice.h"

/**
 * This initialize fields of second layer of infra-red receiver.
 * @params: value - of time in miliseconds of input loop.
 */
void IrDevice::initialize (unsigned long value) {
  this->numberValues = 0;
  this->standardValue = NULL;
  this->setInputLoopTime (value);
}

/**
 * This set the time.
 * @params: value - of time in miliseconds of input loop.
 */
void IrDevice::setInputLoopTime (unsigned long value) {
  this->inputLoopTime.restart (value);
}

/**
 * This add value on list of standard value of your project.
 * @params: newValue - new value added in list.
 */
void IrDevice::addValue (unsigned long newValue) {
  if (this->standardValue == NULL) {
    this->standardValue = (unsigned long*)malloc (sizeof (unsigned long)*2);
    this->standardValue[0] = newValue;
  }
  else {
      
  }
  
  this->numberValues++;
}

/**
 * This function checks and returns received value by
 * infra-red receiver.
 * @return: - value received by infra-red receiver;
 *          - 0 if not one of these values is received.
 */
unsigned long IrDevice::check () {
  unsigned long minIndex = 0;
  unsigned long minDifference;
  if (this->inputLoopTime.isElapsed()) {
    if (this->decode(&this->result)) {
      this->resume();
      this->inputLoopTime.restart();
      
      if (this->standardValue == NULL) {
        return this->result.value;
      }

      minDifference = abs (this->standardValue[minIndex] - this->result.value);
      for (unsigned index = 1; index < numberValues; index++) {
        if (abs (this->standardValue[index] - this->result.value) < minDifference) {
          minIndex = index;
          minDifference = abs (this->standardValue[minIndex] - this->result.value);
        }
      }
    }
  }
  
  return this->standardValue[minIndex];
}
