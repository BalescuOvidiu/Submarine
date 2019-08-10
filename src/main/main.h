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

// Pins of sensors
#define PIN_SENSOR_HUMIDITY A1

// Pin of infra-red communication
#define PIN_IR_RECEIVER A0

// Codes used for propeller speed.
#define C_FASTER 0
#define C_SLOWER 1
#define C_STOP   2
#define C_WAIT   3

// Codes used for direction.
#define C_LEFT      4
#define C_RIGHT     5
#define C_DOWN      6
#define C_UP        7
#define C_STABILIZE 8

// Codes used for for test.
#define C_TEST_RUDDER_BOTTOM 9
#define C_TEST_RUDDER_TOP    10
#define C_TEST_PLANE_LEFT    11
#define C_TEST_PLANE_RIGHT   12

#endif
