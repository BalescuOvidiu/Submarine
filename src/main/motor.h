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

// These are values for minimum speed and value for maximum speed send by arduino.
#define MOTOR_FORWARD     255
#define MOTOR_IDLE        0
#define MOTOR_BACKWARD   -255

/**
 * This class allow programmer to control DC motor more easy.
 * This contains pins location of device who send electronic signal to motor.
 * If value of velocity is negative, then the motor will rotate to right, forward.
 * If value of velocity is negative, then the motor will rotate to left, backward.
 */
class Motor {
   public:
      Motor (byte pinA, byte pinB);
      Motor (byte pinA, byte pinB, int velocity);
      
      ~Motor();

      void write (int velocity);
      void stop ();
      
      void loop ();

      void forward ();
      void backward ();

      void increaseVelocity (int rate);
      void decreaseVelocity (int rate);

   private:
      byte pinA;
      byte pinB;
      int velocity;
};

#endif
