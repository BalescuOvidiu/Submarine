/**
 * Programmer: Balescu Ovidiu-Gheorghe
 * Date:       20 June 2019
 * Board:      Arduino Nano
 * Processor:  ATmega298P(Old bootloader)
 * Programmer: Arduino as ISP
 */

#ifndef TIME_INTERVAL_H_
#define TIME_INTERVAL_H_

#include <Arduino.h>

// These are time units in miliseconds.
#define HALF_SECOND 500
#define SECOND      1000
#define MINUTE      60000
#define HOUR        3600000
#define DAY         86400000

/**
 * This class is a representation of a time interval. Variable 
 * start is moment of begin of interval.Duration of interval 
 * is represent by variable duration.End of interval is 
 * calculated automatic by sum of start moment and duration for 
 * other processes. All variable are represented in miliseconds.
 */
class TimeInterval {
  
   public:
      TimeInterval ();
      TimeInterval (const TimeInterval& source);
      TimeInterval (unsigned long duration);
      TimeInterval (unsigned long start, unsigned long duration);
      
      ~TimeInterval ();

      /**
       * This is assignment operator.
       * 
       * @params: source - is a time interval object.
       */
      TimeInterval& operator = (const TimeInterval& source){
        this->start = source.start;
        this->duration = source.duration;
        return *this;
      }
      
      unsigned long elapsedTimeFromStart ();
      unsigned long elapsedTimeFromEnd ();
      
      bool isStarted ();
      bool isElapsed ();
      
      bool elapse ();
      
      void restart ();
      void restart (unsigned long duration);

   private:
      unsigned long start;
      unsigned long duration;
};

#endif
