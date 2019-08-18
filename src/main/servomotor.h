/**
 * Programmer: Balescu Ovidiu-Gheorghe
 * Date:       20 June 2019
 * Board:      Arduino Nano
 * Processor:  ATmega298P(Old bootloader)
 * Programmer: Arduino as ISP
 * This uses Servo library of Arduino.
 */

#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Arduino.h>
#include <Servo.h>

#include "timeInterval.h"

// These are principal values of servomotor's angle: minimum, middle and maximum.
#define ANGLE_LEFT   0
#define ANGLE_ACUTE  45
#define ANGLE_MIDDLE 90
#define ANGLE_RIGHT  180

/**
 * This class allows programmer to control servomotor device more easy.
 * First layer is represent by implementation of arduino standard Servo
 * object. Second layer is represent by methods which allows to test it
 * or to rotate servomotor to special angle.
 */
class Servomotor : public Servo {
  
   public:
      ~Servomotor();
      
      void loop ();

      void decreaseAngle (int rate);
      void increaseAngle (int rate);

      void left ();
      void middle ();
      void right ();

      int getLastAngle ();
      long getError ();
      
      void enableTest (unsigned long duration);
      void disableTest ();
      void toggleTest (unsigned long duration);

   private:
      int lastAngle;
      int testDirection;
      bool testEnabled;
      TimeInterval testStepTime;
};

#endif
