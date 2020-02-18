/**
 * Programmer: Balescu Ovidiu-Gheorghe
 * Date:       20 June 2019
 * Board:      Arduino Nano
 * Processor:  ATmega298P(Old bootloader)
 * Programmer: Arduino as ISP
 * This uses IRremote library of Arduino.
 */

#ifndef IR_DEVICE_H_
#define IR_DEVICE_H_

#include <Arduino.h>
#include <IRremote.h>

#include "timeInterval.h"

// These are values standard input cicle time in miliseconds.
#define INPUT_CICLE_SHORT  200
#define INPUT_CICLE_MEDIUM 400
#define INPUT_CICLE_LONG   600

/**
 * This class is a new layer on driver of infra-red receiver and 
 * allows to get a more precise inputs from  * infra-red 
 * receiver which receives data from a remote.
 */
class IrDevice : public IRrecv {

  public:
    IrDevice (byte pin);
    
    void setInputLoopTime (unsigned long value);
    void setStandardValue (const unsigned long values[], unsigned numberValues);

    unsigned long check ();
    
  private:
    
    TimeInterval inputLoopTime;
    
    unsigned numberValues;
    unsigned long* standardValue;
};

#endif
