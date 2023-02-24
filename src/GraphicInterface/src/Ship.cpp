/**
 *  ship.cpp
 * 
 *  Modified 20 February 2023
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 22 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#include <string>
#include <fstream>

#include "Mathematics.h"
#include "Ruller.h"
#include "Writer.h"
#include "Ship.h"

#define INVALID_LENGTH -1

/**
 *  @brief: .
 */
Ship::Ship (std::string directory) {
	this->loadFromFile (directory);
	this->draw ();
}

/**
 *  @brief: .
 */
void Ship::render (sf::RenderWindow *window) {
	this->body.render (window);
	this->shadow.render (window);
}

/**
 *  @brief: .
 */
void Ship::rotate (double angle) {
	this->orientation += angle;
	this->body.rotate (angle);
	this->shadow.rotate (angle);
}

/**
 *  @brief: .
 */
void Ship::update () {
	
}

/**
 *  @brief: .
 */
void Ship::updateComponents () {
	this->body.update ();
	this->shadow.update ();
}

/**
 *  @brief: .
 */
void Ship::move (double x, double y) {
	this->body.move (x, y);
	this->shadow.move (x, y);
}

/**
 *  @brief: .
 */
void Ship::loadFromFile (std::string directory) {
	std::ifstream in (directory);
	/** Read data about ship. */
	if (!in.is_open ()) {
		this->totalLength = INVALID_LENGTH;
		return ;
	}
	in>>this->name;
	in>>this->lengthHull;
	in>>this->radiusHull;

	in>>this->radiusPlane;

	in>>this->radiusBack;

	in>>this->positionBodyNavigation;
	in>>this->radiusXBodyNavigation;
	in>>this->radiusYBodyNavigation;

	in>>this->distanceSensorMin;
	in>>this->distanceSensorMax;

	in>>this->positionInertialDevice;

	in>>this->divisionWidth;
	in>>this->divisionAngle;


	this->totalLength = this->lengthHull + this->radiusHull + this->radiusBack;
	this->orientation = ANGLE_NULL;
	this->speed = PERCENT_NULL;

	in.close ();
}

/**
 *  @brief: .
 */
void Ship::draw () {
	double divisionRadius = this->divisionWidth / 2.0;

	this->lengthHull = Ruller::meterToGrid (this->lengthHull);
	this->radiusHull = Ruller::meterToGrid (this->radiusHull);
	this->radiusPlane = Ruller::meterToGrid (this->radiusPlane);
	this->radiusBack = Ruller::meterToGrid (this->radiusBack);
	this->positionBodyNavigation = Ruller::meterToGrid (this->positionBodyNavigation);
	this->radiusXBodyNavigation = Ruller::meterToGrid (this->radiusXBodyNavigation);
	this->radiusYBodyNavigation = Ruller::meterToGrid (this->radiusYBodyNavigation);
	this->distanceSensorMin = Ruller::meterToGrid (this->distanceSensorMin);
	this->distanceSensorMax = Ruller::meterToGrid (this->distanceSensorMax);
	this->positionInertialDevice = Ruller::meterToGrid (this->positionInertialDevice);

	this->body = Component (
		sf::Lines, 
		Ruller::centerGrid ()
	);
	this->shadow = Component (
		sf::Triangles, 
		Ruller::centerGrid ()
	);

	/** Planes. */	
	this->body.addCircle (
		COLOR_GRID_BIG,
		COLOR_LINE,
		divisionRadius,
		this->radiusPlane,
		this->divisionAngle,
		ANGLE_STRAIGHT,
		ANGLE_FULL,
		true,
		sf::Vector2f (
			-0.5 * this->lengthHull,
			-this->radiusHull
		)
	);
	this->body.addCircle (
		COLOR_GRID_BIG,
		COLOR_LINE,
		divisionRadius,
		this->radiusPlane,
		this->divisionAngle,
		ANGLE_NULL,
		ANGLE_STRAIGHT,
		true,
		sf::Vector2f (
			-0.5 * this->lengthHull,
			this->radiusHull
		)
	);
	this->body.addCircle (
		COLOR_GRID_BIG,
		COLOR_LINE,
		divisionRadius,
		this->radiusPlane,
		this->divisionAngle,
		ANGLE_STRAIGHT,
		ANGLE_FULL,
		true,
		sf::Vector2f (
			0.5 * this->lengthHull + this->radiusHull - this->positionBodyNavigation,
			-this->radiusHull
		)
	);
	this->body.addCircle (
		COLOR_GRID_BIG,
		COLOR_LINE,
		divisionRadius,
		this->radiusPlane,
		this->divisionAngle,
		ANGLE_NULL,
		ANGLE_STRAIGHT,
		true,
		sf::Vector2f (
			0.5 * this->lengthHull + this->radiusHull - this->positionBodyNavigation,
			this->radiusHull
		)
	);

	/** Hull. */
	this->body.addRectangle (
		COLOR_GRID_BIG,
		COLOR_LINE,
		this->lengthHull,
		2.0 * this->radiusHull,
		this->divisionWidth * this->lengthHull / this->radiusHull / 2,
		this->divisionWidth,
		false,
		sf::Vector2f (
			-0.5 * this->lengthHull,
			-this->radiusHull
		)
	);
	this->body.addLine (
		- 0.5 * this->lengthHull,
		this->radiusHull,
		0.5 * this->lengthHull,
		this->radiusHull,
		COLOR_LINE
	);
	this->body.addLine (
		- 0.5 * this->lengthHull,
		- this->radiusHull,
		0.5 * this->lengthHull,
		- this->radiusHull,
		COLOR_LINE
	);
	this->body.addCircle (
		COLOR_GRID_BIG,
		COLOR_LINE,
		divisionRadius,
		this->radiusHull,
		this->divisionAngle,
		ANGLE_NULL, 
		ANGLE_RIGHT,
		true,
		sf::Vector2f (
			0.5 * this->lengthHull,
			0.0
		)
	);
	this->body.addCircle (
		COLOR_GRID_BIG,
		COLOR_LINE,
		divisionRadius,
		this->radiusHull,
		this->divisionAngle,
		ANGLE_FULL - ANGLE_RIGHT,
		ANGLE_FULL,
		true,
		sf::Vector2f (
			0.5 * this->lengthHull,
			0.0
		)
	);
	this->body.addEllipse (
		COLOR_GRID_BIG,
		COLOR_LINE,
		divisionRadius,
		this->radiusBack,
		this->radiusHull,
		this->divisionAngle,
		ANGLE_RIGHT,
		ANGLE_FULL - ANGLE_RIGHT,
		true,
		sf::Vector2f (
			-0.5 * this->lengthHull,
			0.0
		)
	);

	/** Navigation body. */
	this->body.addEllipse (
		COLOR_GRID_BIG,
		COLOR_LINE,
		divisionRadius,
		this->radiusYBodyNavigation,
		this->radiusXBodyNavigation,
		this->divisionAngle,
		ANGLE_NULL,
		ANGLE_FULL,
		true,
		sf::Vector2f (
			0.5 * this->lengthHull + this->radiusHull - this->positionBodyNavigation,
			0.0
		)
	);

	/** Up rudder. */
	this->body.addLine (
		- 0.5 * this->lengthHull - this->radiusPlane,
		0.0,
		- 0.5 * this->lengthHull + this->radiusPlane,
		0.0,
		COLOR_LINE
	);

	/** Position of inertial device */
	this->body.movePoints (
		- 0.5 * this->lengthHull - this->radiusHull + this->positionBodyNavigation,
		0.0
	);

	this->updateComponents ();

	this->lengthHull = Ruller::gridToMeter (this->lengthHull);
	this->radiusHull = Ruller::gridToMeter (this->radiusHull);
	this->radiusPlane = Ruller::gridToMeter (this->radiusPlane);
	this->radiusBack = Ruller::gridToMeter (this->radiusBack);
	this->positionBodyNavigation = Ruller::gridToMeter (this->positionBodyNavigation);
	this->radiusXBodyNavigation = Ruller::gridToMeter (this->radiusXBodyNavigation);
	this->radiusYBodyNavigation = Ruller::gridToMeter (this->radiusYBodyNavigation);
	this->distanceSensorMin = Ruller::gridToMeter (this->distanceSensorMin);
	this->distanceSensorMax = Ruller::gridToMeter (this->distanceSensorMax);
	this->positionInertialDevice = Ruller::gridToMeter (this->positionInertialDevice);
}

/**
 *  @brief: .
 */
void Ship::setPosition (double x, double y) {
	this->setPosition (sf::Vector2f (x, y));
}

/**
 *  @brief: .
 */
void Ship::setPosition (sf::Vector2f position) {
	this->body.setPosition (position);
	this->shadow.setPosition (position);
}

/**
 *  @brief: .
 */
void Ship::setRotation (double angle) {
	this->orientation = angle;
	this->body.setRotation (angle);
	this->shadow.setRotation (angle);
}

/**
 *  @brief: .
 */
bool Ship::isOpen () {
	return this->totalLength != INVALID_LENGTH;
}

/**
 *  @brief: .
 */
bool Ship::mouseOver () {
	return this->body.isInParalelogram (Ruller::mousePosition ());
}

/**
 *  @brief: .
 */
std::string Ship::getName () {
	return this->name;
}

/**
 *  @brief: .
 */
sf::String Ship::getSpeedText () {
	return Writer::toString (this->getSpeed ()) + UNIT_SPEED;
}

/**
 *  @brief: .
 */
sf::String Ship::getRotationText () {
	return Writer::toString (this->getRotation ()) + UNIT_ANGLE;
}

/**
 *  @brief: .
 */
sf::String Ship::getOrientationText () {
	return Writer::toString (this->getOrientation (), 0) + UNIT_ANGLE;
}

/**
 *  @brief: .
 */
sf::String Ship::getLengthText () {
	return Writer::toString (this->getLength ()) + UNIT_DISTANCE;
}

/**
 *  @brief: .
 */
sf::String Ship::getBeamText () {
	return Writer::toString (this->getBeam ()) + UNIT_DISTANCE;
}

/**
 *  @brief: .
 */
sf::String Ship::getGuideText () {
	return this->getName () + "\n" + 
		this->getOrientationText () + "\n" + 
		this->getSpeedText () + "\n" + 
		this->getLengthText () + " length\n" + 
		this->getBeamText () + " beam";
}

/**
 *  @brief: .
 */
sf::Vector2f Ship::getPosition () {
	return this->body.getPosition ();
}

/**
 *  @brief: .
 */
double Ship::getSpeed () {
	return this->speed;
}

/**
 *  @brief: .
 */
double Ship::getRotation () {
	return this->orientation;
}

/**
 *  @brief: .
 */
double Ship::getOrientation () {
	return geographic (this->orientation);
}

/**
 *  @brief: .
 */
double Ship::getLength () {
	return this->totalLength;
}

/**
 *  @brief: .
 */
double Ship::getBeam () {
	return 2 * (radiusHull);
}