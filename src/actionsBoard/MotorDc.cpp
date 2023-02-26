/**
 *  MotorDc.cpp
 *
 *  Created 1s May 2019
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 13 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#include "MotorDc.h"

/**
 *  @brief: This is copy constructor.
 *  
 *  @param source is MotorDc object.
 */
MotorDc::MotorDc (const MotorDc &source) {
   this->pinA = source.pinA;
   this->pinB = source.pinB;
   
   this->setSpeed (this->speedSignalIdle);
}

/**
 *  @brief: This is a constructor of MotorDc object.
 *
 *  @param: pinA - connected to first wire of MotorDc;
 *  @param: pinB - connected to second wire of MotorDc;
 *  @param: speedSignalBackward - signal of full backward speed;
 *  @param: speedSignalIdle - signal of stop;
 *  @param: speedSignalForward - signal of full forward speed.
 */
MotorDc::MotorDc (
    byte pinA,
    byte pinB,
    short speedSignalBackward,
    short speedSignalIdle,
    short speedSignalForward
) {
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);

    this->pinA = pinA;
    this->pinB = pinB;

    this->setup (
        speedSignalBackward,
        speedSignalIdle,
        speedSignalForward
    );
    this->stop ();
}

/**
 *  @brief: This is a constructor of MotorDc object.
 *
 *  @param: pinA - connected to first wire of MotorDc;
 *  @param: pinB - connected to second wire of MotorDc;
 *  @param: speedSignalBackward - signal of full backward speed;
 *  @param: speedSignalIdle - signal of stop;
 *  @param: speedSignalForward - signal of full forward speed;
 *  @param: speed - speed of MotorDc. 
 */
MotorDc::MotorDc (
    byte pinA,
    byte pinB, 
    short speedSignalBackward,
    short speedSignalIdle,
    short speedSignalForward,
    short speed
) {
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);

    this->pinA = pinA;
    this->pinB = pinB;

    this->setup (
        speedSignalBackward,
        speedSignalIdle,
        speedSignalForward
    );
    this->setSpeed (speed);
}

/**
 *  @brief: This is destructor of MotorDc object. 
 *  This stops the electronic signal to it.
 */
MotorDc::~MotorDc () {
   this->stop ();
}

/**
 *  @brief: .
 * 
 *  @param: speedSignalBackward - signal of full backward speed;
 *  @param: speedSignalIdle - signal of stop;
 *  @param: speedSignalForward - signal of full forward speed.
 */
void MotorDc::setup (
    short speedSignalBackward,
    short speedSignalIdle,
    short speedSignalForward
) {
    this->speedSignalBackward = speedSignalBackward;
    this->speedSignalIdle = speedSignalIdle;
    this->speedSignalForward = speedSignalForward;
}

/**
 *  @brief: This function sends signal to mantain speed of MotorDc.
 */
void MotorDc::loop () {
    if (this->speed >= this->speedSignalIdle) {
        analogWrite (pinA, this->speedSignalIdle);
        analogWrite (pinB, this->speed);
    }
    else {
        analogWrite (pinA, -this->speed);
        analogWrite (pinB, this->speedSignalIdle);      
    }
}

/**
 *  @brief: This function sends the signal to change speed of MotorDc.
 */
void MotorDc::setSpeed (short value) {
    this->speed = value;
}

/**
 *  @brief: This function stops move of MotorDc.
 */
void MotorDc::stop () {
    this->setSpeed (this->speedSignalIdle);
}

/**
 *  @brief: This function makes the MotorDc to move backward
 *  direction with full speed.
 */
void MotorDc::backward () {
    this->setSpeed (this->speedSignalBackward);  
}

/**
 *  @brief: This function makes the MotorDc to move forward
 *  direction with full speed.
 */
void MotorDc::forward () {
    this->setSpeed (this->speedSignalForward);
}

/**
 *  @brief: This function increases value of speed.
 */
void MotorDc::increaseSpeed (short rate) {
    if (this->speedSignalForward - rate <= this->speed) {
        this->setSpeed (this->speedSignalForward);
    }
    else {
        this->setSpeed (this->speed + rate);
    }
}

/**
 *  @brief: This function decreases value of speed.
 */
void MotorDc::decreaseSpeed (short rate) {
    if (this->speedSignalBackward + rate >= this->speed) {
        this->setSpeed (this->speedSignalBackward);
    }
    else {
        this->setSpeed (this->speed - rate);
    }
}

/**
 *  @brief: This change value of speed signal backward.
 *  
 *  @param: value - new value of speed signal backward.
 */
void MotorDc::setSpeedSignalBackward (short value) {
    if (this->speedSignalIdle > value) {
        this->speedSignalBackward = value;

        if (this->speedSignalBackward < this->speed) {
            this->backward ();
        }
    }
}

/**
 *  @brief: This change value of speed signal idle.
 *  
 *  @param: value - new value of speed signal idle.
 */
void MotorDc::setSpeedSignalIdle (short value) {
    if (this->speedSignalForward > value) {

        if(this->speedSignalBackward < value) {

            if (this->speedSignalIdle == this->speed) {
                this->setSpeed (value);
            }

            this->speedSignalIdle = value;
        }
    }
}

/**
 *  @brief: This change value of speed signal forward.
 *  
 *  @param: value - new value of speed signal forward.
 */
void MotorDc::setSpeedSignalForward (short value) {
    if (this->speedSignalIdle < value) {
        this->speedSignalForward = value;

        if (this->speedSignalForward < this->speed) {
            this->forward ();
        }
    }
}