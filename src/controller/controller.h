/**
 * Programmer: Balescu Ovidiu-Gheorghe
 * Date:       22 February 2019
 * Board:      Arduino Nano
 * Processor:  ATmega298P(Old bootloader)
 * Programmer: Arduino as ISP
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "motor.h"
#include "servomotor.h"
#include "irDevice.h"
#include "timeInterval.h"

// Pins of servomotors
#define PIN_RUDDER_BOTTOM   2
#define PIN_RUDDER_TOP      3
#define PIN_PLANE_LEFT      4
#define PIN_PLANE_RIGHT     5
#define PIN_PLANE_FRONT     6

// Pins of motors
#define PIN_PROPELLER_A     7
#define PIN_PROPELLER_B     8
#define PIN_BALLAST_A       9
#define PIN_BALLAST_B       10

// Pins of sensors
#define PIN_SENSOR_HUMIDITY A1

// Pin of infra-red communication
#define PIN_IR_RECEIVER 11

// Codes used for propeller speed.
#define C_FASTER 0xE0E0A25D
#define C_SLOWER 0xE0E012ED
#define C_STOP   0xE0E052AD
#define C_WAIT   0xE0E0629D

// Codes used for direction.
#define C_LEFT      0xE0E0A659
#define C_RIGHT     0xE0E046B9
#define C_DOWN      0xE0E08679
#define C_UP        0xE0E006F9
#define C_STABILIZE 0xE0E016E9

// Codes used for for test.
#define C_TEST_RUDDER_BOTTOM 0xE0E036C9
#define C_TEST_RUDDER_TOP    0xE0E028D7
#define C_TEST_PLANE_LEFT    0xE0E0A857
#define C_TEST_PLANE_RIGHT   0xE0E06897

#endif
