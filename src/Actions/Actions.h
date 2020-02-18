/**
 *	Actions
 *
 *	This is a module used to control motors and light on the
 *	submarine.
 *
 *  Board:      Arduino Nano V3
 *  Processor:  ATmega298P
 *  Programmer: Arduino as ISP
 *
 *	The circuit:
 *	* list the components attached to each input
 *		-1 x serial communication with communications board
 *	* list the components attached to each output
 *		-1 x RGB led with common cathode
 *		-1 x motor DC HPCB 50:1 6V
 *		-1 x servomotor ES08MA
 *		-4 x servomotors MG996R
 *		-5 x NPN transistors to switch power of servomotors
 *
 *	Created 20 July 2019
 *	By Balescu Ovidiu-Gheorghe
 *	Modified 13 February 2020
 *	By Balescu Ovidiu-Gheorghe
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "MotorDc.h"
#include "Servomotor.h"
#include "TimeInterval.h"

/**
 *  These are logical pins used to control electric components.
 */
enum Pins : short {

	propulsionA = 2,
	propulsionB = 3,

	powerPlanesFront = 4,
	powerPlanesBack = 7,
	powerRudders = 8,
	powerRaiseAntennaSystem = 12,
	powerRotationSonarSystem = 13,

	servoPlanesFront = 5,
	servoPlanesBack = 6,
	servoRudders = 9,
	servoRaiseAntennaSystem = 10,
	servoRotationSonarSystem = 11,

	ledSignalBlue = A0,
	ledSignalGreen = A1,
	ledSignalRed = A2
};

#endif