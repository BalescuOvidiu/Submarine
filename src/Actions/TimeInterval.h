/**
 *  TimeInterval.h
 *
 *  Created 20 July 2019
 *	By Balescu Ovidiu-Gheorghe
 *	Modified 13 February 2020
 *	By Balescu Ovidiu-Gheorghe
 */

#ifndef TIME_INTERVAL_H_
#define TIME_INTERVAL_H_

#include <Arduino.h>

#include "TimeUnits.h"

/**
 *  @brief: This class is a representation of a time interval.
 *  Variable start is moment of begin of interval.Duration of 
 *  interval is represent by variable duration.End of interval is 
 *  calculated automatic by sum of start moment and duration for 
 *  other processes. All variable are represented in miliseconds.
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
	
	unsigned long getStart ();
	unsigned long getDuration ();
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