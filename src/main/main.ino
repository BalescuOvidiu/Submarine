#include "main.h"

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
