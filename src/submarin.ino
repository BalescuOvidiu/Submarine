// Programmer: Balescu Ovidiu-Gheorghe
// Board:      Arduino Nano
// Processor:  ATmega298P(Old bootloader)
// Programmer: Arduino as ISP

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

// Motors
Motor propeller(PIN_PROPELLER_A, PIN_PROPELLER_B);
Motor ballast(PIN_BALLAST_A, PIN_BALLAST_B);

// Servomotors
Servomotor planeLeft;
Servomotor planeRight;
Servomotor rudderUp;
Servomotor rudderDown;

// Communications
IRrecv receiverIR(PIN_RECEIVER_IR);
decode_results resultIR;
TimeInterval receiverIntervalIR(RECEIVER_WAITING_TIME);

// Move functions
void stabilize() {
  planeLeft.write(ANGLE_MID);
  planeRight.write(ANGLE_MID);
  rudderUp.write(ANGLE_MID);
  rudderDown.write(ANGLE_MID);
}
void wait() {
  propeller.stop();
  stabilize();
}
void setRudderAngle(short angle) {
  rudderUp.write(ANGLE_MID + angle);
  rudderDown.write(ANGLE_MID - angle);
}
void setPlaneAngle(short angle) {
  planeLeft.write(ANGLE_MID + angle);
  planeRight.write(ANGLE_MID - angle);
}
void loopServo() {
  planeLeft.loop();
  planeRight.loop();
  rudderUp.loop();
  rudderDown.loop();
}

// Sensors functions
byte getHumidity() {
  return analogRead(PIN_SENSOR_HUMIDITY);
}

// Command functions
void receiveCommandIR() {
  if (receiverIntervalIR.isElapsed()) {
    if (receiverIR.decode(&resultIR)) {
      // Setup
      Serial.println(resultIR.value, HEX);
      receiverIR.resume();
      receiverIntervalIR.restart();
      // Send command
      
    }
  }
}

// Main functions
void setup() {
  // Servomotors
  planeLeft.attach(PIN_PLANE_LEFT);
  planeRight.attach(PIN_PLANE_RIGHT);
  rudderUp.attach(PIN_RUDDER_UP);
  rudderDown.attach(PIN_RUDDER_DOWN);
  // Main
  Serial.begin(9600);
  wait();
}
void loop() {
  // Motor
  propeller.loop();
  // Servomotors
  loopServo();
  // Sensors
  if (getHumidity() > HUMIDITY_LIMIT) {
    Serial.println("Water in submarine!");
  }
  // Comuncations
  receiveCommandIR();
}
