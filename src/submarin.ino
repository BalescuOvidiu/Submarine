// Programmer: Balescu Ovidiu-Gheorghe
// Board:      Arduino Nano
// Processor:  ATmega298P(Old bootloader)
// Programmer: Arduino as ISP

#include <IRremote.h>

#include "motor.h"
#include "servoMotor.h"
#include "timeInterval.h"

// PINS


// Motors
Motor propeller(1, 0, 6, 7);
Motor ballast(1, 0, 8, 9);

// Direction
Servomotor rudderLeft  (2, ANGLE_MID);
Servomotor rudderRight (3, ANGLE_MID);
Servomotor rudderUp    (4, ANGLE_MID);
Servomotor rudderDown  (5, ANGLE_MID);

// Communications
InfraRedReceiver receiver(10);

// Command functions
void wait() {
  propeller.stop();
  rudderLeft.write(ANGLE_MID);
  rudderRight.write(ANGLE_MID);
  rudderUp.write(ANGLE_MID);
  rudderDown.write(ANGLE_MID);
}
void loopServo() {
  rudderLeft.loop();
  rudderRight.loop();
  rudderUp.loop();
  rudderDown.loop();
}

// Main functions
void setup() {
  Serial.begin(9600);
  wait();
}
void loop() {
  // Body
  propeller.loop();
  // Servomotors
  loopServo();
}
