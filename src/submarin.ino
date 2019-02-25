#include <Servo.h>
#include <RobotIRremote.h>
#include <RobotIRremoteInt.h>
#include <RobotIRremoteTools.h>

// RGB LED
#define PIN_RED         2
#define PIN_GREEN       3
#define PIN_BLUE        4
// Servomotors
#define PIN_STERN_LEFT  5
#define PIN_RUDDER      6
#define PIN_STERN_RIGHT 7
#define MID             90
// Propeller
#define PIN_PROPELLER_A 8
#define PIN_PROPELLER_B 9
// Receiver
#define PIN_RECEIVER    10

// RGB LED
unsigned ledRed = 0;
unsigned ledGreen = 0;
unsigned ledBlue = 0;
// Servomotors
Servo sternLeft;
Servo sternRight;
Servo rudder;
int sternLeftAngle = 0;
int sternRightAngle = 0;
int rudderAngle = 0;
int sternLeftDir = 1;
int sternRightDir = 1;
int rudderDir = 1;
int sternLeftTest=0;
int sternRightTest=0;
int rudderTest=0;
// Propeller
int propellerA = LOW;
int propellerB = LOW;
// Receiver
IRrecv receiver(PIN_RECEIVER);
decode_results receiverResult;
// Commands
unsigned long duration = 0;
unsigned long start = 0;
unsigned long route = 0;
int shore = 1;

// RGB LED
void setColor(unsigned red, unsigned green, unsigned blue) {
  ledRed = 255 - red;
  ledGreen = 255 - green;
  ledBlue = 255 - blue;
}
void printLed() {
  analogWrite(PIN_RED, ledRed);
  analogWrite(PIN_GREEN, ledGreen);
  analogWrite(PIN_BLUE, ledBlue);
}
void error() {
  setColor(255, 0, 0);
}
void up() {
  setColor(0, 0, 255);
}
void down() {
  setColor(255, 64, 0);
}
void getColor() {
  if (sternLeftAngle < 0 && sternRightAngle < 0) {
    down();
  }
  else if (sternLeftAngle > 0 && sternRightAngle > 0) {
    up();
  }
}
// Servomotors
void setRudder(int angle) {
  rudder.write(MID + angle);
  rudderAngle = angle;
}
void setSternLeft(int angle) {
  sternLeft.write(MID + angle);
  sternLeftAngle = angle;
}
void setSternRight(int angle) {
  sternRight.write(MID + angle);
  sternRightAngle = angle;
}
void setSterns(int angle) {
  setSternLeft(angle);
  setSternRight(angle);
  getColor();
}
// Propeller
void propeller() {
  if (propellerA || propellerB) {
    digitalWrite(PIN_PROPELLER_A, propellerA);
    digitalWrite(PIN_PROPELLER_B, propellerB);
  }
}
void forward() {
  propellerA = HIGH;
  propellerB = LOW;
  setColor(0, 0, 255);
}
void wait() {
  propellerA = 0;
  propellerB = 0;
  digitalWrite(PIN_PROPELLER_A, propellerA);
  digitalWrite(PIN_PROPELLER_B, propellerB);
  setColor(255, 255, 255);
  setSterns(30);
  setRudder(0);
}
// Commands
void go(unsigned long seconds) {
  setSterns(0);
  duration = seconds * 1000;
  shore = 0;
  forward();
  start = millis();
}
void testLeftStern() {
  if(sternLeftTest){
    setSternLeft((sternLeftAngle + sternLeftDir));
    if (sternLeftAngle == 0 || sternLeftAngle == 90) {
      sternLeftDir *= -1;
    }
    delay(20);
  }
}
void testRightStern() {
  if(sternRightTest){
    setSternRight((sternRightAngle + sternRightDir));
    if (sternRightAngle == 0 || sternRightAngle == 90) {
      sternRightDir *= -1;
    }
    delay(20);
  }
}
void testSterns() {
  testLeftStern();
  testRightStern();
  delay(20);
}
void testRudder() {
  if(rudderTest){
    setRudder((rudderAngle + rudderDir));
    if (rudderAngle == 0 || rudderAngle == 90) {
      rudderDir *= -1;
    }
    delay(20);
  }
}
// Receiver
void receiveCommand() {
  if (shore) {
    if (receiver.decode(&receiverResult)) {
      Serial.println(receiverResult.value, HEX);
      go(15);
      receiver.resume();
    }

  }
  else {
    if (start + duration <= millis()) {
      wait();
      shore = 1;
    }
  }
}
// Main functions
void setup() {
  Serial.begin(9600);
  // RGB LED
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  // Servomotors
  sternLeft.attach(PIN_STERN_LEFT);
  sternRight.attach(PIN_STERN_RIGHT);
  rudder.attach(PIN_RUDDER);
  // Propeller
  pinMode(PIN_PROPELLER_A, OUTPUT);
  pinMode(PIN_PROPELLER_B, OUTPUT);
  wait();
  // Receiver
  receiver.enableIRIn();
}
int angle = 0;
int dir = 1;
void loop() {
  testLeftStern();
  testRightStern();
  testRudder();
  printLed();
  propeller();
  receiveCommand();
}
