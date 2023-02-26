<<<<<<< HEAD
#include "Sonar.h"

/**
 *  @brief:
=======
/**
 *  Sonar.cpp
 *
 *  Created 18 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 24 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#include "Sonar.h"

#define FIRST_SAMPLE 0

/**
 *  @brief: This constructor allocates memory for sensor and set reading
 *  configuration.
 *
 *  @param: pinEcho - pin connected to the receiver of sensor, called echo,
 *  @param: pinTrigger - pin connected to the transmiter of sensor, called trigger,
 *  @param: speedOfRipple - speed of sound in enviroment of sensor. 
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
 */
Sonar::Sonar (short pinEcho, short pinTrigger, double speedOfRipple) {
	this->setup (pinEcho, pinTrigger, speedOfRipple);
}

/**
<<<<<<< HEAD
 *  @brief:
 */
Sonnar::setup (short pinEcho, short pinTrigger, double speedOfRipple) {
=======
 *  @brief: This is destructor of class.
 */
Sonar::~Sonar () {

}

/**
 *  @brief: This method initializes communication with sensor.
 *
 *  @param: pinEcho - pin connected to the receiver of sensor, called echo,
 *  @param: pinTrigger - pin connected to the transmiter of sensor, called trigger,
 *  @param: speedOfRipple - speed of sound in enviroment of sensor. 
 */
void Sonar::setup (short pinEcho, short pinTrigger, double speedOfRipple) {
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
	this->pinEcho = pinEcho;
	this->pinTrigger = pinTrigger;
	this->speedOfRipple = speedOfRipple;

<<<<<<< HEAD
	pinMode (pinEcho, INPUT);
	pinMode (pinTrigger, OUTNPUT);
}

/**
 *  @brief:
 */
void Sonar::loop () {

}

/**
 *  @brief:
 */
void Sonar::setSpeedOfRipple (double value) {
	this->speedOfRipple = value;
}

/**
 *  @brief:
=======
	this->rawData = FIRST_SAMPLE;

	pinMode (pinEcho, INPUT);
	pinMode (pinTrigger, OUTPUT);

	this->stop ();
}

/**
 *  @brief: This method runs reading and update functions of sensor.
 *  It's executed in loop function of program.
 */
void Sonar::loop () {
	if (this->numberOfSamples > this->theSample) {
		if (this->clock.elapse ()) {
			this->read ();

			this->theSample ++;

			digitalWrite (this->pinEcho, HIGH);
		}

		if (this->numberOfSamples == this->theSample) {
			if (this->lastDataRead != this->rawData) {
				this->dataChanged = true;
			}

			this->lastDataRead = this->rawData;
		}
	}
}

/**
 *  @brief: This function reads data received from electronic device.
 */
void Sonar::read () {
	digitalWrite (this->pinEcho, LOW);
	this->rawData = (this->rawData / this->theSample + analogRead (this->pinTrigger)) / (1 + this->theSample);
}

/**
 *  @brief: This function begins a new read process.
 */
void Sonar::reload () {
	this->theSample = FIRST_SAMPLE;
	this->clock.restart ();
}

/**
 *  @brief: This function stops the reading process of sensor.
 */
void Sonar::stop () {
	this->theSample = this->numberOfSamples;
	this->dataChanged = false;
}

/**
 *  @brief: This method set new value of time reading of a sample.
 *  
 *  @param: newClockTime - new value of time reading of a sample.
 */
void Sonar::setClockTime (unsigned long newClockTime) {
	this->clock.restart (newClockTime);
	this->reload ();
}

/**
 *  @brief: This method set new value of number of samples read.
 *  
 *  @param: newNumberOfSamples - new value of number of samples read.
 */
void Sonar::setNumberOfSamples (byte newNumberOfSamples) {
	this->speedOfRipple = newNumberOfSamples;
	this->reload ();
}

/**
 *  @brief: This method set new value of speed of sound.
 *  
 *  @param: newSpeedOfRipple - new value of speed of sound.
 */
void Sonar::setSpeedOfRipple (double newSpeedOfRipple) {
	this->speedOfRipple = newSpeedOfRipple;
	this->reload ();
}

/**
 *  @brief: This function returns readed information by sensor, 
 *  in unit.
 *
 *  @return: raw filtered data.
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
 */
double Sonar::getData () {
	return this->lastDataRead;
}

/**
<<<<<<< HEAD
 *  @brief:
 */
double Sonar::readDistanceInCm () {
	return this->getData () *;
}

/**
 *  @brief:
 */
double Sonar::readDistanceInMeters () {
	return this->getData () *;
}

/**
 *  @brief:
 */
double Sonar::readDistanceInInches () {
	return this->getData () *;
}

/**
 *  @brief:
 */
double Sonar::readDistanceInFeet () {
	return this->getData () *;
}
=======
 *  @brief: This function returns readed distance by sensor, 
 *  in centimeters unit.
 *
 *  @return: distance in centimeters.
 */
double Sonar::getDistanceInCm () {
	return this->getData () * this->speedOfRipple;
}

/**
 *  @brief: This function returns readed distance by sensor, 
 *  in meter unit.
 *
 *  @return: distance in meters.
 */
double Sonar::getDistanceInMeters () {
	return getDistanceInCm () / 100.0;
}

/**
 *  @brief: This function returns readed distance by sensor, 
 *  in inches unit.
 *
 *  @return: distance in inches.
 */
double Sonar::getDistanceInInches () {
	return this->getDistanceInCm () / 2.54;
}

/**
 *  @brief: This function returns readed distance by sensor, 
 *  in feet unit.
 *
 *  @return: distance in feet.
 */
double Sonar::getDistanceInFeet () {
	return this->getDistanceInCm () / 30.48;
}

/**
 *  @brief: This method returns if data wast changed after last
 *  last return of function.
 *
 *  @return: if data is different after last read.
 */
bool Sonar::dataWasChanged () {
	if (this->dataChanged) {
		this->dataChanged = false;

		return true;
	}

	return false;
}
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
