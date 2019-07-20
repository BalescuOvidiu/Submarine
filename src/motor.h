#ifndef MOTOR_H
#define MOTOR_H

#define MIN_SPEED 0
#define MAX_SPEED 255

class Motor {
  private:
    bool a;
    bool b;
    byte pinA;
    byte pinB;
    byte speed;
  public:
    // Constructors
    Motor(byte pinA, byte pinB);
    Motor(bool a, bool b, byte pinA, byte pinB);
    Motor(bool a, bool b, byte pinA, byte pinB, byte speed);
    // Methods
    void write(bool a, bool b);
    void loop();
    void stop();
    // Control of speed
    byte read();
    void increaseSpeed(byte rate);
    void decreaseSpeed(byte rate);
    // Destructor
    ~Motor();
};
// Constructors
Motor::Motor(byte pinA, byte pinB) {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  this->a = 0;
  this->b = 1;
  this->pinA = pinA;
  this->pinB = pinB;
  this->speed = 0;
}
Motor::Motor(bool a, bool b, byte pinA, byte pinB) {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  this->a = a;
  this->b = b;
  this->pinA = pinA;
  this->pinB = pinB;
  this->speed = 0;
}
Motor::Motor(bool a, bool b, byte pinA, byte pinB, byte speed) {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  this->a = a;
  this->b = b;
  this->pinA = pinA;
  this->pinB = pinB;
  this->speed = speed;
}
// Methods
void Motor::write(bool a, bool b) {
  this->a = a;
  this->b = b;
  loop();
}
void Motor::loop() {
  analogWrite(pinA, a * this->speed);
  analogWrite(pinB, b * this->speed);
}
void Motor::stop() {
  this->speed = 0;
}
// Control of speed
byte Motor::read() {
  return this->speed;
}
void Motor::increaseSpeed(byte rate) {
  if (MAX_SPEED - rate <= this->speed) {
    this->speed = MAX_SPEED;
  }
  else {
    this->speed += rate;
  }
}
void Motor::decreaseSpeed(byte rate) {
  if (MIN_SPEED + rate >= this->speed) {
    this->speed = MIN_SPEED;
  }
  else {
    this->speed -= rate;
  }
}
// Destructor
Motor::~Motor() {
}

#endif
