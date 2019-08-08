#include "timeInterval.h"

/**
 * This is constructor with no parameters.
 */
TimeInterval::TimeInterval () {
   this->start = 0;
   this->duration = 0;
}

/**
 * This is copy constructor.
 * 
 * @params: source - is a time interval object.
 */
TimeInterval::TimeInterval (const TimeInterval& source) {
  this->start = source.start;
  this->duration = source.duration;
}

/**
 * Constructor with given duration in miliseconds and
 * set start moment with current moment.
 * 
 * @params: duration - of interval.
 */
TimeInterval::TimeInterval (unsigned long duration) {
   this->start = millis();
   this->duration = duration;
}

/**
 * Constructor with given duration and start in miliseconds.
 * 
 * @params: start - moment of interval,
 *          duration - of interval.
 */
TimeInterval::TimeInterval (unsigned long start, unsigned long duration) {
   this->start = start;
   this->duration = duration;
}

/** 
 * Destructor with no parameters.
 */
TimeInterval::~TimeInterval () {

}

/**
 * This function return elapsed time 
 * from the start moment of interval.
 * 
 * @return: time elapsed from start moment of interval.
 */
unsigned long TimeInterval::elapsedTimeFromStart () {
   return millis() - this->start;
}

/** 
 * This function return elapsed time from the 
 * end moment of interval.
 * 
 * @return: time elapsed from end moment of interval.
 */
unsigned long TimeInterval::elapsedTimeFromEnd () {
   return millis() - this->start - this->duration;
}

/**
 * The function check if the interval has started.
 * 
 * @return: true if current moment is over the start moment 
 *          of interval or false if interval has not started.
 */
bool TimeInterval::isStarted () {
   return this->start <= millis();
}

/**
 * The function check if the interval is elapsed.
 * 
 * @return: true if interval is elapsed or false if
 *          present moment is before end moment of interval.
 */
bool TimeInterval::isElapsed () {
   return this->start + this->duration <= millis();
}

/** 
 * Check if the interval is elapsed 
 * and restart it with current moment.
 * 
 * @return: true if interval is elapsed and false in if end moment 
 *          of interval is over present moment.
 */
bool TimeInterval::elapse () {
   if (this->isElapsed()) {
      this->restart();
      return 1;
   }
   return 0;
}

/**
 * Set the start moment of interval with current moment.
 */
void TimeInterval::restart () {
   this->start = millis();
}

/** 
 * Set the start moment of interval with 
 * current moment with given duration.
 * 
 * @params: duration - new duration of interval after restart.
 */
void TimeInterval::restart(unsigned long duration) {
   this->start = millis();
   this->duration = duration;
}
