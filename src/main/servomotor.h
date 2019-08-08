/**
 * Programmer: Balescu Ovidiu-Gheorghe
 * Data:       20 June 2019
 * Board:      Arduino Nano
 * Processor:  ATmega298P(Old bootloader)
 * Programmer: Arduino as ISP
 */

#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Arduino.h>
#include <Servo.h>

#include "timeInterval.h"

// These are principal values of servomotor's angle: minimum, middle and maximum.
#define ANGLE_MIN 0
#define ANGLE_MID 90
#define ANGLE_MAX 180

class Servomotor : public Servo {
  
   public:
      void loop ();

      void decreaseAngle (int a);
      void increaseAngle (int a);

      int getLastAngle ();
      long getError ();

      void enableTest (unsigned long duration);
      void disableTest ();

   private:
      int lastAngle;
      int testDirection;
      bool testEnabled;
      TimeInterval testStepTime;
};

#endif
