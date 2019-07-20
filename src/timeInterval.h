#ifndef TIME_INTERVAL_H
#define TIME_INTERVAL_H

#define HALF_SECOND 500
#define SECOND      1000
#define MINUTE      60000
#define HOUR        3600000
#define DAY         86400000

class TimeInterval {
  private:
    unsigned long start;
    unsigned long duration;
  public:
    // Constructors
    TimeInterval();
    TimeInterval(unsigned long duration);
    TimeInterval(unsigned long start, unsigned long duration);
    // Methods
    unsigned long elapsedTime();
    bool isElapsed();
    bool elapse();
    void restart();
    void restart(unsigned long duration);
    // Destructor
    ~TimeInterval();
};
// Constructors
TimeInterval::TimeInterval() {
  this->start = 0;
  this->duration = 0;
}
TimeInterval::TimeInterval(unsigned long duration) {
  this->start = millis();
  this->duration = duration;
}
TimeInterval::TimeInterval(unsigned long start, unsigned long duration) {
  this->start = start;
  this->duration = duration;
}
// Methods
unsigned long TimeInterval::elapsedTime() {
  return millis() - this->start;
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
// Destructor
TimeInterval::~TimeInterval() {
}

#endif
