#include "irDevice.h"

static decode_results result;

/**
 * This is constructor.
 */
IrDevice::IrDevice (byte pin) : IRrecv (pin) {
  
}

/**
 * This set the time.
 * @params: value - of time in miliseconds of input loop.
 */
void IrDevice::setInputLoopTime (unsigned long value) {
  this->inputLoopTime.restart (value);
}

/**
 * This function set list of standard value of your project.
 * @params: newValue - new value added in list.
 */
void IrDevice::setStandardValue (const unsigned long values[]) {
  this->standardValue = NULL;
  this->numberValues = sizeof (*values) / sizeof (values[0]);
  this->standardValue = (unsigned long*)malloc (sizeof (unsigned long) * numberValues);

  for (unsigned i = 0; i < numberValues; i++) {
    this->standardValue[i] = values[i];
  }
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
    if (this->decode(&result)) {
      Serial.println(result.value, HEX);
      this->resume();
      this->inputLoopTime.restart();
      
      if (this->standardValue == NULL) {
        return result.value;
      }

      minDifference = abs (this->standardValue[minIndex] - result.value);
      for (unsigned index = 1; index < numberValues; index++) {
        if (abs (this->standardValue[index] - result.value) < minDifference) {
          minIndex = index;
          minDifference = abs (this->standardValue[minIndex] - result.value);
        }
      }
      
      return this->standardValue[minIndex];
    }
  }
  
  return 0;
}
