#include "main.h"

// Objects used to control motors.
Motor propeller(PIN_PROPELLER_A, PIN_PROPELLER_B);
Motor ballast(PIN_BALLAST_A, PIN_BALLAST_B);

// Objects used to control rudders and planes.
Servomotor rudderBottom;
Servomotor rudderTop;
Servomotor planeLeft;
Servomotor planeRight;

// Objects used for infra-red communication.
IRrecv receiverIR(PIN_RECEIVER_IR);
decode_results resultIR;
TimeInterval receiverIntervalIR(RECEIVER_WAITING_TIME);

// Move functions
void stabilize () {
   rudderBottom.middle ();
   rudderTop.middle ();
   planeLeft.middle ();
   planeRight.middle ();
}
void wait () {
   propeller.stop();
   stabilize();
}
void setRudderAngle (int angle) {
   rudderBottom.write(ANGLE_MIDDLE - angle);
   rudderTop.write(ANGLE_MIDDLE + angle);
}
void setPlaneAngle (int angle) {
   planeLeft.write(ANGLE_MIDDLE + angle);
   planeRight.write(ANGLE_MIDDLE - angle);
}
void loopServo () {
   rudderBottom.loop();
   rudderTop.loop();
   planeLeft.loop();
   planeRight.loop();
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
   rudderBottom.attach(PIN_RUDDER_BOTTOM);
   rudderTop.attach(PIN_RUDDER_TOP);
   planeLeft.attach(PIN_PLANE_LEFT);
   planeRight.attach(PIN_PLANE_RIGHT);
   // Main
   Serial.begin(9600);
   wait();
}
void loop() {
   // Motor
   propeller.loop();
   // Servomotors
   loopServo();
   // Comuncations
   receiveCommandIR();
}
