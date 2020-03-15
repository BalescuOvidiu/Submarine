/**
 *  Sonar.h
 *
 *  Created 18 February 2020
 *  By Balescu Ovidiu-Gheorghe
<<<<<<< HEAD
 *  Modified 21 February 2020
=======
 *  Modified 24 February 2020
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef SONAR_H_
#define SONAR_H_

#include <Arduino.h>

#include "TimeInterval.h"

/**
<<<<<<< HEAD
 *  @brief: 
=======
 *  @brief: This class control an ultrasonic sensor. This contains
 *  speed of ripple specific of sensor's enviroment, number of samples, 
 *  This can read and filter data, or the read can be stopped when the user
 *  want.
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
 */
class Sonar {

public:
	Sonar (short pinEcho, short pinTrigger, double speedOfRipple);
	~Sonar ();

	void setup (short pinEcho, short pinTrigger, double speedOfRipple);
	void loop ();

<<<<<<< HEAD
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
=======
	void read ();
	void reload ();

	void stop ();
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21

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