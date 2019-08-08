/**
 * Programmer: Balescu Ovidiu-Gheorghe
 * Data:       22 February 2019
 * Board:      Arduino Nano
 * Processor:  ATmega298P(Old bootloader)
 * Programmer: Arduino as ISP
 */

#ifndef MAIN_H
#define MAIN_H

#include <IRremote.h>

#include "motor.h"
#include "servomotor.h"
#include "timeInterval.h"

// Pins of servomotors
#define PIN_PLANE_LEFT      2
#define PIN_PLANE_RIGHT     3
#define PIN_RUDDER_UP       4
#define PIN_RUDDER_DOWN     5
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
#define C_FAST
#define C_SLOW
#define C_STOP

// Codes direction
#define C_LEFT
#define C_RIGHT
#define C_DOWN
#define C_UP
#define C_RESET

#endif
