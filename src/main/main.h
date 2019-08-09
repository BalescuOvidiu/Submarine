/**
 * Programmer: Balescu Ovidiu-Gheorghe
 * Data:       22 February 2019
 * Board:      Arduino Nano
 * Processor:  ATmega298P(Old bootloader)
 * Programmer: Arduino as ISP
 */

#ifndef MAIN_H
#define MAIN_H

#include "motor.h"
#include "servomotor.h"
#include "irDevice.h"
#include "timeInterval.h"

// Pins of servomotors
#define PIN_RUDDER_BOTTOM   2
#define PIN_RUDDER_TOP      3
#define PIN_PLANE_LEFT      4
#define PIN_PLANE_RIGHT     5

// Pins of motors
#define PIN_PROPELLER_A     6
#define PIN_PROPELLER_B     7
#define PIN_BALLAST_A       8
#define PIN_BALLAST_B       9

// Sensors
#define PIN_SENSOR_HUMIDITY A1
#define HUMIDITY_LIMIT      100

// Infra-red communications
#define PIN_RECEIVER_IR       A0
#define RECEIVER_WAITING_TIME 200

// Codes speed
#define C_FASTER
#define C_SLOWER
#define C_STOP

// Codes direction
#define C_LEFT
#define C_RIGHT
#define C_DOWN
#define C_UP
#define C_STABILIZE

// Codes for test
#define C_TEST_RUDDER_TOP
#define C_TEST_RUDDER_BOTTOM
#define C_TEST_PLANE_LEFT 
#define C_TEST_PLANE_RIGHT

#endif
