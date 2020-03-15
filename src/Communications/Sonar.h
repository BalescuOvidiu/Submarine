/**
 *  Sonar
 *
 *  Created 18 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 21 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef SONAR_H_
#define SONAR_H_

#include <Arduino.h>

#include "TimeInterval.h"

/**
 *  @brief: 
 */
class Sonar {

public:
	Sonar (short pinEcho, short pinTrigger, double speedOfRipple);
	~Sonar ();

	void setup (short pinEcho, short pinTrigger, double speedOfRipple);
	void loop ();

	void setSpeedOfRipple (double value);

	double getData ();
	double readDistanceInCm ();
	double readDistanceInMeters ();
	double readDistanceInInches ();
	double readDistanceInFeet ();

private:
	byte pinEcho;
	byte pinTrigger;
	byte numberOfSamples;
	byte theSample;

	double speedOfRipple;
	double lastDataRead;
	double unfiltredData;

	TimeInterval clock;
};


#endif