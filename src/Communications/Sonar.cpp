#include "Sonar.h"

/**
 *  @brief:
 */
Sonar::Sonar (short pinEcho, short pinTrigger, double speedOfRipple) {
	this->setup (pinEcho, pinTrigger, speedOfRipple);
}

/**
 *  @brief:
 */
Sonnar::setup (short pinEcho, short pinTrigger, double speedOfRipple) {
	this->pinEcho = pinEcho;
	this->pinTrigger = pinTrigger;
	this->speedOfRipple = speedOfRipple;

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
 */
double Sonar::getData () {
	return this->lastDataRead;
}

/**
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
