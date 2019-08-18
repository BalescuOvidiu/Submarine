/**
 * Programmer: Balescu Ovidiu-Gheorghe
 * Date:       20 June 2019
 * Board:      Arduino Nano
 * Processor:  ATmega298P(Old bootloader)
 * Programmer: Arduino as ISP
 */

#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

// These are standard values for rate of decrease and increase rate.

#define RATE_SMALL  5
#define RATE_MEDIUM 51
#define RATE_BIG    100

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
      Motor (const Motor& source);
      Motor (byte pinA, byte pinB);
      Motor (byte pinA, byte pinB, int velocity);
      
      ~Motor();

      /**
       * This is assignment operator.
       * 
       * @params: source - is a motor object.
       */
      Motor& operator = (const Motor& source){
        this->pinA = source.pinA;
        this->pinB = source.pinB;
        this->write (MOTOR_IDLE);
        return *this;
      }

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
