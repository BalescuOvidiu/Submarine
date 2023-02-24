/**
 *	Actions.ino
 *
 *	Created 20 July 2019
 *	By Balescu Ovidiu-Gheorghe
 *	Modified 13 February 2020
 *	By Balescu Ovidiu-Gheorghe
 */

#include "Actions.h"

unsigned long baudRate = 115200;

bool silentMode = false;
bool sonarIsOn = false;

MotorDc propulsion (Pins::propulsionA, Pins::propulsionB, -255, 0, 255);

Servomotor planesFront;
Servomotor planesBack;
Servomotor rudders;
Servomotor atennaRaiseSystem;
Servomotor sonarRotationSystem;

/**
 *  @brief: Setup function initializes important objects of software.
 */
void setup () {
    Serial.begin(baudRate);

    planesFront.attach (Pins::servoPlanesFront);
    planesBack.attach (Pins::servoPlanesBack);
    rudders.attach (Pins::servoRudders);
    atennaRaiseSystem.attach (Pins::servoRaiseAntennaSystem);
    sonarRotationSystem.attach (Pins::servoRotationSonarSystem);
}

/**
 *  @brief: This function repeats until the board stop working.
 */
void loop () {

}