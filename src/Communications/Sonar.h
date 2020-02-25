/**
 *  Sonar.h
 *
 *  Created 18 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 24 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef SONAR_H_
#define SONAR_H_

#include <Arduino.h>

#include "TimeInterval.h"

/**
 *  @brief: This class control an ultrasonic sensor. This contains
 *  speed of ripple specific of sensor's enviroment, number of samples, 
 *  This can read and filter data, or the read can be stopped when the user
 *  want.
 */
class Sonar {

public:
	Sonar (short pinEcho, short pinTrigger, double speedOfRipple);
	~Sonar ();

	void setup (short pinEcho, short pinTrigger, double speedOfRipple);
	void loop ();

	void read ();
	void reload ();

	void stop ();

	void setClockTime (unsigned long newClockTime);
	void setNumberOfSamples (byte newNumberOfSamples);
	void setSpeedOfRipple (double newSpeedOfRipple);

	double getData ();
	double getDistanceInCm ();
	double getDistanceInMeters ();
	double getDistanceInInches ();
	double getDistanceInFeet ();

	bool dataWasChanged ();

private:
	byte pinEcho;
	byte pinTrigger;
	byte numberOfSamples;
	byte theSample;

	double speedOfRipple;
	double lastDataRead;
	double rawData;

	bool dataChanged;

	TimeInterval clock;
};

#endif