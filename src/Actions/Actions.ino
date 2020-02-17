#include "servomotor.h"

unsigned long baudRate = 115200;

bool silentMode = false;
bool sonarIsOn = false;

MotorDc propulsion (Pins::propulsionA, Pins::propulsionB);

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
    raiseAntennaSystem.attach (Pins::servoRaiseAntennaSystem);
    rotationSonarSystem.attach (Pins::servoRotationSonarSystem);
}

/**
 *  @brief: This function repeats until the board stop working.
 */
void loop () {

}