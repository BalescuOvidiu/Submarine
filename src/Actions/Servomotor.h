/**
 *  Servomotor.h
 *
 *  Created 1s May 2019
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 13 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef SERVOMOTOR_H_
#define SERVOMOTOR_H_

#include <Arduino.h>
#include <Servo.h>

#include "TimeInterval.h"

/**
 *  @brief: This class allows programmer to control servomotor device
 *  more easy.
 *  First layer is represent by implementation of arduino standard Servo
 *  object. Second layer is represent by methods which allows to rotate
 *  servomotor to special angles and a buffer which is used to send signal
 *  to electronic device at a certain time. 
 */
class Servomotor : public Servo {

public:
    Servomotor ();
    Servomotor (short minAngle, short maxAngle, long dutyCycleTime);
    ~Servomotor ();

    void setup (short minAngle, short maxAngle, long dutyCycleTime);
    void loop ();

    void setMinAngle (short value);
    void setMaxAngle (short value);
    void setDutyCicleTime (unsigned long duration);

    void decreaseAngle (short rate);
    void increaseAngle (short rate);

    void rotateTo (short angle);
    void rotateToMinAngle ();
    void rotateToMidAngle ();
    void rotateToMaxAngle ();

    short getLastAngle ();
    short getError ();

    short getMinAngle ();
    short getMidAngle ();
    short getMaxAngle ();
    unsigned long getDutyCycle ();

private:
    TimeInterval dutyCycleTime;

    /**
     *  @brief: The lastAngle is buffer that contains last 
     *  value received and which will be send to electronic device.
     *  The minAngle is integer value of minimum angle which can 
     *  mechanical device rotate. 
     *  The maxAngle is integer value of maximum angle which can 
     *  mechanical device rotate. 
     */
    short lastAngle;
    short minAngle;
    short maxAngle;
};

#endif