#ifndef IR_DEVICE_H
#define IR_DEVICE_H

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
    void initialize (unsigned long value);
    void setInputLoopTime (unsigned long value);
    void addValue (unsigned long newValue);

    unsigned long check ();
    
  private:    
    decode_results result;
    
    TimeInterval inputLoopTime;
    
    unsigned numberValues;
    unsigned long* standardValue;
};

#endif
