#include <Servo.h>
#include <RobotIRremote.h>
#include <RobotIRremoteInt.h>
#include <RobotIRremoteTools.h>

// Time
#define SECOND 1000
#define MINUTE 60000
#define HOUR   3600000
#define DAY    86400000
// Color
#define BLUE     0,   0, 255
#define GREEN    0, 255,   0
#define RED    255,   0,   0
#define YELLOW 255, 255,   0
#define WHITE  255, 255, 255
// Angle
#define ANGLE_MIN       0
#define ANGLE_MID      90
#define ANGLE_MAX     180
// Numbers
#define MIN             0
#define MAX           255
// RGB LED
#define PIN_RED         2
#define PIN_GREEN       3
#define PIN_BLUE        4
// Servomotors
#define PIN_STERN_LEFT  5
#define PIN_STERN_RIGHT 6
#define PIN_RUDDER      7
#define MID             90
// Propeller
#define PIN_PROPELLER_A 8
#define PIN_PROPELLER_B 9
// Receiver
#define PIN_RECEIVER    10

// Time interval
class TimeInterval {
  private:
    unsigned long start;
    unsigned long duration;
  public:
    TimeInterval(unsigned long start, unsigned long duration);
    bool isElapsed();
    bool elapse();
    void restart();
    void restart(unsigned long duration);
    ~TimeInterval();
};
TimeInterval::TimeInterval(unsigned long start, unsigned long duration) {
  this->start = start;
  this->duration = duration;
}
bool TimeInterval::isElapsed() {
  return this->start + this->duration <= millis();
}
bool TimeInterval::elapse() {
  if (this->isElapsed()) {
    this->restart();
    return 1;
  }
  return 0;
}
void TimeInterval::restart() {
  this->start = millis();
}
void TimeInterval::restart(unsigned long duration) {
  this->start = millis();
  this->duration = duration;
}
TimeInterval::~TimeInterval() {
}

// RGB
class Color {
  public:
    short red;
    short green;
    short blue;
    Color();
    Color(short red, short green, short blue);
    ~Color();
};
Color::Color() {
  this->red = 0;
  this->green = 0;
  this->blue = 0;
}
Color::Color(short red, short green, short blue) {
  this->red = red;
  this->green = green;
  this->blue = blue;
}
Color::~Color() {
}

// RGB LED
class Led {
  private:
    Color color;
    Color pin;
    bool commonAnode;
  public:
    Led(Color color, bool commonAnode);
    Led(short red, short green, short blue, bool commonAnode);
    void loop();
    void write(short red, short green, short blue);
    void write(Color color);
    void error();
    ~Led();
};
Led::Led(Color color, bool commonAnode) {
  pinMode(color.red, OUTPUT);
  pinMode(color.green, OUTPUT);
  pinMode(color.blue, OUTPUT);
  this->pin = color;
  this->color = Color();
  this->commonAnode = commonAnode;
  this->loop();
}
Led::Led(short red, short green, short blue, bool commonAnode) {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  this->pin = Color(red, green, blue);
  this->color = Color();
  this->commonAnode = commonAnode;
  this->loop();
}
void Led::loop() {
  if (this->commonAnode) {
    analogWrite(this->pin.red, this->color.red);
    analogWrite(this->pin.green, this->color.green);
    analogWrite(this->pin.blue, this->color.blue);
  }
  else {
    analogWrite(this->pin.red, MAX - this->color.red);
    analogWrite(this->pin.green, MAX - this->color.green);
    analogWrite(this->pin.blue, MAX - this->color.blue);
  }
}
void Led::write(short red, short green, short blue) {
  this->color = Color(red, green, blue);
}
void Led::write(Color color) {
  this->color = color;
}
void Led::error() {
  this->write(RED);
}
Led::~Led() {
}

// Servomotor
class Servomotor {
  private:
    Servo s;
    short angle;
    int dir;
    short pin;
    bool test;
  public:
    Servomotor();
    Servomotor(short pin, short angle);
    void write(short angle);
    void loop();
    void attach(short pin);
    void detach();
    void reset();
    void enableTest();
    void disableTest();
    void testIt();
    ~Servomotor();
};
Servomotor::Servomotor() {
  this->detach();
}
Servomotor::Servomotor(short pin, short angle) {
  this->attach(pin);
  this->write(angle);
}
void Servomotor::loop() {
  this->s.write(this->angle);
  this->testIt();
}
void Servomotor::write(short angle) {
  this->angle = angle;
}
void Servomotor::attach(short pin) {
  this->pin = pin;
  this->s.attach(pin);
  this->reset();
}
void Servomotor::detach() {
  this->s.detach();
}
void Servomotor::reset() {
  this->dir = 1;
  this->test = false;
}
void Servomotor::enableTest() {
  this->test = true;
}
void Servomotor::disableTest() {
  this->reset();
}
void Servomotor::testIt() {
  if (this->test) {
    if (angle == ANGLE_MIN || angle == ANGLE_MAX) {
      dir *= -1;
    }
    this->angle += dir;
  }
}
Servomotor::~Servomotor() {
  this->detach();
}

// Motor
class Motor {
  private:
    short a;
    short b;
    short pinA;
    short pinB;
  public:
    Motor(short a, short b, short pinA, short pinB);
    void loop();
    void write(short a, short b);
    void stop();
    void forward(short speed);
    void backward(short speed);
    ~Motor();
};
Motor::Motor(short a, short b, short pinA, short pinB) {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  this->a = a;
  this->b = b;
  this->pinA = pinA;
  this->pinB = pinB;
}
void Motor::loop() {
  analogWrite(pinA, a);
  analogWrite(pinB, b);
}
void Motor::write(short a, short b) {
  this->a = a;
  this->b = b;
  loop();
}
void Motor::stop() {
  this->write(0, 0);
}
void Motor::forward(short speed) {
  this->write(speed, 0);
}
void Motor::backward(short speed) {
  this->write(0, speed);
}
Motor::~Motor() {
}

// Variable
bool shore = true;
unsigned long idServo = 0;

// Time interval
TimeInterval timeCommand(0, 0);
TimeInterval timeServo(0, 800);

// Objects
Led output(PIN_RED, PIN_GREEN, PIN_BLUE, false);
Motor propeller(0, 0, PIN_PROPELLER_A, PIN_PROPELLER_B);
Servomotor sternLeft(PIN_STERN_LEFT, ANGLE_MID);
Servomotor sternRight(PIN_STERN_RIGHT, ANGLE_MID);
Servomotor rudder(PIN_RUDDER, ANGLE_MID);;
Servo a;
double angle = 0, dir = 1;

// Receiver
IRrecv receiver(PIN_RECEIVER);
decode_results receiverResult;

// Other functions
void loopServo() {
  if (timeServo.elapse()) {
    idServo = (idServo + 1) % 3;
  }
  else {
    switch (idServo) {
      //case 0: sternLeft.loop(); break;
      case 1: sternRight.loop(); break;
      //case 2: rudder.loop(); break;
      default: break;
    }
  }
}
void wait() {
  shore = true;
  propeller.stop();
  output.write(WHITE);
  rudder.write(ANGLE_MID);
}
void go(unsigned long duration, short speed, int dir) {
  output.write(BLUE);
  shore = false;
  rudder.write(ANGLE_MID + dir);
  propeller.forward(speed);
  timeCommand.restart(duration);
}
void receiveCommand() {
  if (shore) {
    if (receiver.decode(&receiverResult)) {
      //Serial.println(receiverResult.value, HEX);
      go(25 * SECOND, 255, 0);
      receiver.resume();
    }
  }
  else {
    if (timeCommand.isElapsed()) {
      wait();
    }
  }
}

// Main functions
void setup() {
  Serial.begin(9600);
  wait();
  // Servomotors
  rudder.enableTest();
  // Receiver
  receiver.enableIRIn();
}
void loop() {
  propeller.loop();
  // Communication
  output.loop();
  receiveCommand();
  // Servomotors
  loopServo();
}
