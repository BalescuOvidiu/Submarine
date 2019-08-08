/**
 * Programmer: Balescu Ovidiu-Gheorghe
 * Data:       20 June 2019
 * Board:      Arduino Nano
 * Processor:  ATmega298P(Old bootloader)
 * Programmer: Arduino as ISP
 */

#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

// Value for minimum speed and value for maximum speed send by arduino
#define MIN_SPEED 0
#define MAX_SPEED 255

class Motor {
   public:
      Motor(byte pinA, byte pinB);
      Motor(bool a, bool b, byte pinA, byte pinB);
      Motor(bool a, bool b, byte pinA, byte pinB, byte speed);
      
      ~Motor();

      void write(bool a, bool b);
      void stop();
      byte read();
      
      void loop();
      
      void increaseSpeed(byte rate);
      void decreaseSpeed(byte rate);

   private:
      bool a;
      bool b;
      byte pinA;
      byte pinB;
      byte speed;
};

#endif
