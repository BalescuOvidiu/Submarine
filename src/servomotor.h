#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H

#include <Servo.h>

#include "timeInterval.h"

#define ANGLE_MIN 0
#define ANGLE_MID 90
#define ANGLE_MAX 180

class Servomotor {
  private:
    // Object
    Servo piece;
    short angle;
    // Test
    int dir;
    bool test;
    TimeInterval cronometer;
  public:
    // Constructors
    Servomotor();
    Servomotor(short angle);
    // Methods
    void write(short angle);
    void loop();
    void attach(short pin);
    void detach();
    void reset();
    // Move
    void decreaseAngle(short a);
    void increaseAngle(short a);
    // Check
    short getAngle();
    long error();
    // Test
    void enableTest(unsigned long duration);
    void disableTest();
    void testIt();
    // Destructor
    ~Servomotor();
};
// Constructors
Servomotor::Servomotor() {
  this->write(ANGLE_MID);
}
Servomotor::Servomotor(short angle) {
  this->write(angle);
}
// Methods
void Servomotor::write(short angle) {
  this->angle = angle;
}
void Servomotor::loop() {
  this->piece.write(this->angle);
  this->testIt();
}
void Servomotor::attach(short pin) {
  this->piece.attach(pin);
  this->reset();
}
void Servomotor::detach() {
  this->piece.detach();
}
void Servomotor::reset() {
  this->dir = 1;
  this->test = false;
  this->cronometer.restart(HALF_SECOND);
}
// Move
void Servomotor::decreaseAngle(short a){
  if(this->angle-a>=ANGLE_MIN){
    this->write(this->angle-a);
  }
  else{
    this->write(ANGLE_MIN);
  }
}
void Servomotor::increaseAngle(short a){
  if(this->angle+a<=ANGLE_MAX){
    this->write(this->angle+a);
  }
  else{
    this->write(ANGLE_MIN);
  }
}
// Check
short Servomotor::getAngle(){
  return this->angle;
}
long Servomotor::error() {
  return (this->angle - this->piece.read());
}
// Test
void Servomotor::enableTest(unsigned long duration) {
  this->test = true;
  this->cronometer = TimeInterval(duration);
}
void Servomotor::disableTest() {
  this->reset();
}
void Servomotor::testIt() {
  if (this->test) {
    if (cronometer.elapse()) {
      this->angle += dir;
      if (this->angle <= ANGLE_MIN || this->angle >= ANGLE_MAX) {
        dir *= -1;
      }
    }
  }
}
// Destructor
Servomotor::~Servomotor() {
  this->detach();
}

#endif
