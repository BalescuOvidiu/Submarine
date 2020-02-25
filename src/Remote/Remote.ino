/**
 *  Remote.ino
 * 
 *  Created 15 May 2019
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 25 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#include "Remote.h"

/**
 *  @brief: Setup function initializes important objects of software.
 */
void setup () {
    Serial.begin (baudRate);

    imu.setup (decimalsNumber, numberOfSamples);
}

/**
 *  @brief: This function repeats until the board stop working.
 */
void loop () {
    loopSonar ();
    loopSerialCommunication ();

    if (silentMode) {

    }
    else {

    }
}