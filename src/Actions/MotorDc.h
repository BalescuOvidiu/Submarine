/**
 *  MotorDc
 *
 *  Created 1s May 2019
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 13 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef MOTOR_DC_H_
#define MOTOR_DC_H_

#include <Arduino.h>

/**
 *  @brief: This class allow programmer to control DC motor more easy.
 *  This contains pins location of device who send electronic signal to motor.
 *  If value of speed is negative, then the motor will rotate to right, forward.
 *  If value of speed is negative, then the motor will rotate to left, backward.
 */
class MotorDc {

public:
    MotorDc (const Motor& source);
    MotorDc (
        byte pinA,
        byte pinB, 
        short speedSignalBackward,
        short speedSignalIdle,
        short speedSignalForward
    );
    MotorDc (
        byte pinA,
        byte pinB, 
        short speedSignalBackward,
        short speedSignalIdle,
        short speedSignalForward,
        short speed
    );

    ~MotorDc ();

    /**
     *  This is assignment operator.
     *  
     *  @params: source - is a motor object.
     */
    Motor& operator = (const Motor& source){
        this->pinA = source.pinA;
        this->pinB = source.pinB;
        this->write (this->speedSignalIdle);
        return *this;
    }

    void setup (
        short speedSignalBackward,
        short speedSignalIdle,
        short speedSignalForward
    );
    void loop ();

    void setSpeed (short value);

    void backward ();
    void stop ();
    void forward ();

    void increaseSpeed (short rate);
    void decreaseSpeed (short rate);

    void setSpeedSignalBackward (short value);
    void setSpeedSignalIdle (short value);
    void setSpeedSignalForward (short value);

    short get

private:
    byte pinA;
    byte pinB;

    short speed;

    short speedSignalBackward;
    short speedSignalIdle;
    short speedSignalForward;
};

#endif