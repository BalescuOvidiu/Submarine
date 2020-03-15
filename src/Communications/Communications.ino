/**
 *  Communications.ino
 *
 *  Created 22 February 2019
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 13 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#include "Communications.h"

unsigned long baudRate = 115200;

byte decimalsNumber = 2;
byte numberOfSamples = 5;

bool silentMode = false;
bool sonarIsOn = false;

<<<<<<< HEAD
=======
Imu imu (Wire, imuAddress);

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

/**
 *  @brief: This function is executing sonar functions
 *  until the board stop working.
 */
void loopSonar () {
    if (sonarIsOn && !silentMode) {

    }
}

>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
/**
 *  @brief: This function is executing serial communication with other
 *  Arduino board functions until the board stop working.
 */
void loopSerialCommunication () {

}

/**
 *  @brief: This function reads message from outside using wireless
 *  communication module NRF24L01 with antena.
 */
<<<<<<< HEAD
void loop() {

=======
void readMessageFromWirelessCommunication () {

}

/**
 *  @brief: This function reads message from outside using wireless
 *  communication module NRF24L01 with antena.
 */
void sendMessageWithWirelessCommunication (short code) {
    switch (code) {
        
        default: {

        }
    }
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
}