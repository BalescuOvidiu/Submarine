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
    Servomotor(short pin, short angle);
    // Methods
    void write(short angle);
    void loop();
    void attach(short pin);
    void detach();
    void reset();
    // Check
    unsigned long error();
    // Test
    void enableTest(unsigned long duration);
    void disableTest();
    void testIt();
    // Destructor
    ~Servomotor();
};
// Constructors
Servomotor::Servomotor() {
}
Servomotor::Servomotor(short pin, short angle) {
  this->attach(pin);
  this->write(angle);
}
// Methods
void Servomotor::write(short angle) {
  this->angle = angle;
  this->cronometer.restart(HALF_SECOND);
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
// Check
unsigned long Servomotor::error() {
  return (this->angle - this->piece.read()) * cronometer.elapsedTime();
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
  if (cronometer.elapse()) {
    if (this->test) {
      if (angle == ANGLE_MIN || angle == ANGLE_MAX) {
        dir *= -1;
      }
      this->angle += dir;
    }
  }
}
// Destructor
Servomotor::~Servomotor() {
  this->detach();
}

#endif
