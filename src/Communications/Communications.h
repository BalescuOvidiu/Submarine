/**
 *  Communications
 *
 *  This is a module used to control motors and light on the
 *  submarine.
 *
 *  Board:      Arduino Nano V3
 *  Processor:  ATmega298P
 *  Programmer: Arduino as ISP
 *
 *  The circuit:
 *  * list the components attached to each input
 *	  -1 x IMU MPU9250
 *    -1 x NRF24L01 to send data to controller
 *    -3 x ultrasonic sensors echo pins
 *    -3 x humidity sensors with regulator
 *  * list the components attached to each output
 *    -1 x serial communication with communications board
 *    -1 x NRF24L01 to send data to controller
 *    -3 x ultrasonic sensors triggers pins
 *
 *  Created 22 February 2019
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 13 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef COMUNICATIONS_H_
#define COMUNICATIONS_H_

#include "Imu.h"
#include "Sonar.h"
#include "TimeInterval.h"

/**
 *  These are logical pins used to control electric components.
 */
enum Pins : short {

	sonarTrigger = ,
	sonarTrigger = ,
	sonarTrigger = ,
	sonarEcho = ,
	sonarEcho = ,
	sonarEcho = ,

	sensorHumidity = ,
	sensorHumidity = ,
	sensorHumidity = ,

	antennaCe = ,
	AntennaCs = ,

	imuAddressInitial = 0x68
	imuAddressError = 0x00
};

#endif