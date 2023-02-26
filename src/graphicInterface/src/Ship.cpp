/**
 *  ship.cpp
 * 
 *  Modified 20 February 2023
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 24 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#include <string>

#include "Mathematics.h"
#include "Ruller.h"
#include "Ship.h"
#include "Writer.h"

/**
 *  @brief: .
 */
Ship::Ship (std::string directory) {
	this->totalLength = 0.0;
	this->speed = 0.0;
	this->clock = sf::Clock ();

	this->body = FilledComponent (
		Ruller::centerGrid ()
	);
	this->navigationBody = FilledComponent (
		Ruller::centerGrid ()
	);
	this->upperRudder = FilledComponent (
		Ruller::centerGrid ()
	);

	this->propulsion = FilledComponent (
		Ruller::centerGrid ()
	);

	this->loadFromFile (directory);
}

/**
 *  @brief: .
 */
void Ship::render (sf::RenderWindow *window) {
	this->body.render (window);
	this->navigationBody.render (window);
	this->upperRudder.render (window);
	this->propulsion.render (window);
}

/**
 *  @brief: .
 */
void Ship::rotate (double angle) {
	this->body.rotate (angle);
	this->navigationBody.rotate (angle);
	this->upperRudder.rotate (angle);
	this->propulsion.rotate (angle);
}

/**
 *  @brief: .
 */
void Ship::update () {
	double distance = Ruller::meterToGrid (this->speed) * this->clock.getElapsedTime().asSeconds ();
	this->move (
		distance * cos (this->getRotation () * radians),
		distance * sin (this->getRotation () * radians)
	);
	this->clock.restart ();
}

/**
 *  @brief: .
 */
void Ship::updateComponents () {
	this->body.update ();
	this->navigationBody.update ();
	this->upperRudder.update ();
	this->propulsion.update ();
}

/**
 *  @brief: .
 */
void Ship::move (double x, double y) {
	this->body.move (x, y);
	this->navigationBody.move (x, y);
	this->upperRudder.move (x, y);
	this->propulsion.move (x, y);
}

/**
 *  @brief: .
 */
void Ship::move (sf::Vector2f point) {
	this->move (point.x, point.y);
}

/**
 *  @brief: .
 */
void Ship::setSpeed (double value) {
	this->speed = value;
}

/**
 *  @brief: .
 */
void Ship::setPosition (double x, double y) {
	this->body.setPosition (x, y);
	this->navigationBody.setPosition (x, y);
	this->upperRudder.setPosition (x, y);
	this->propulsion.setPosition (x, y);
}

/**
 *  @brief: .
 */
void Ship::setPosition (sf::Vector2f position) {
	this->setPosition (position.x, position.y);
}

/**
 *  @brief: .
 */
void Ship::setRotation (double angle) {
	this->body.setRotation (angle);
	this->navigationBody.setRotation (angle);
	this->upperRudder.setRotation (angle);
	this->propulsion.setRotation (angle);
}

/**
 *  @brief: .
 */
void Ship::loadFromFile (std::string directory) {
	std::string extension = directory.substr (directory.rfind ("."));

	json data = getJsonFromFile (directory);
	json dataVersion = getJsonFromFile (data["versionFile"]);

	this->identificator = getFileName (directory);
	this->name = data["name"];
	this->version = getFileName (std::string(data["versionFile"]));

	this->draw (dataVersion);
}

/**
 *  @brief: .
 */
void Ship::draw (json dataVersion) {
	double hullWidth = Ruller::meterToGrid ((double)dataVersion["hull"]["width"]);
	double hullBreadth = Ruller::meterToGrid ((double)dataVersion["hull"]["breadth"]);
	double hullBreadthDivision = dataVersion["hull"]["breadthDivision"];
	double hullRadiusFront = Ruller::meterToGrid ((double)dataVersion["hull"]["radiusFront"]);
	double hullRadiusBack = Ruller::meterToGrid ((double)dataVersion["hull"]["radiusBack"]);
	double hullAngleDivision = (double)dataVersion["hull"]["angleDivision"];

	double navigationBodyPosition = Ruller::meterToGrid ((double)dataVersion["navigationBody"]["position"]);
	double navigationBodyWidth = Ruller::meterToGrid ((double)dataVersion["navigationBody"]["width"]);
	double navigationBodyBreadth = Ruller::meterToGrid ((double)dataVersion["navigationBody"]["breadth"]);
	
	double planesFrontPosition = Ruller::meterToGrid ((double)dataVersion["planesFront"]["position"]);
	double planesFrontWidth = Ruller::meterToGrid ((double)dataVersion["planesFront"]["width"]);
	double planesFrontBreadth = Ruller::meterToGrid ((double)dataVersion["planesFront"]["breadth"]);
	
	double planesBackPosition = Ruller::meterToGrid ((double)dataVersion["planesBack"]["position"]);
	double planesBackWidth = Ruller::meterToGrid ((double)dataVersion["planesBack"]["width"]);
	double planesBackBreadth = Ruller::meterToGrid ((double)dataVersion["planesBack"]["breadth"]);
	
	double ruddersPosition = Ruller::meterToGrid ((double)dataVersion["rudders"]["position"]);
	double ruddersBreadth = Ruller::meterToGrid ((double)dataVersion["rudders"]["breadth"]);
	double ruddersThickness = Ruller::meterToGrid ((double)dataVersion["rudders"]["thickness"]);
	
	double propulsionWidth = Ruller::meterToGrid ((double)dataVersion["propulsion"]["width"]);
	double propulsionBreadth = Ruller::meterToGrid ((double)dataVersion["propulsion"]["breadth"]);
	
	double hullWidthStraight = hullWidth - hullRadiusBack - hullRadiusFront;
	double hullRadius = hullBreadth * 0.5;
	double hullRadiusDivision = hullBreadthDivision * 0.5;

	this->imuDevicePosition = Ruller::meterToGrid ((double)dataVersion["imuDevice"]["position"]);
	this->planesWidth = Ruller::gridToMeter (max (planesFrontWidth, planesBackWidth));
	this->beam = Ruller::gridToMeter (hullBreadth);
	this->totalLength = (double)dataVersion["hull"]["width"] + (double)dataVersion["propulsion"]["width"];

	/** Front planes */
	this->body.addEllipse (
		COLOR_BACKGROUND,
		COLOR_GRID_BIG,
		COLOR_LINE,
		planesFrontBreadth * 0.5,
		planesFrontWidth,
		hullRadiusDivision,
		ANGLE_STRAIGHT,
		ANGLE_NULL,
		hullAngleDivision,
		true,
		sf::Vector2f (
			this->imuDevicePosition - planesFrontPosition,
			hullRadius
		)
	);
	this->body.addEllipse (
		COLOR_BACKGROUND,
		COLOR_GRID_BIG,
		COLOR_LINE,
		planesFrontBreadth * 0.5,
		planesFrontWidth,
		hullRadiusDivision,
		- ANGLE_STRAIGHT,
		ANGLE_NULL,
		hullAngleDivision,
		true,
		sf::Vector2f (
			this->imuDevicePosition - planesFrontPosition,
			- hullRadius
		)
	);

	/** Back planes */
	this->body.addEllipse (
		COLOR_BACKGROUND,
		COLOR_GRID_BIG,
		COLOR_LINE,
		planesBackBreadth * 0.5,
		planesBackWidth,
		hullRadiusDivision,
		ANGLE_STRAIGHT,
		ANGLE_NULL,
		hullAngleDivision,
		true,
		sf::Vector2f (
			this->imuDevicePosition - planesBackPosition,
			hullRadius
		)
	);
	this->body.addEllipse (
		COLOR_BACKGROUND,
		COLOR_GRID_BIG,
		COLOR_LINE,
		planesBackBreadth * 0.5,
		planesBackWidth,
		hullRadiusDivision,
		- ANGLE_STRAIGHT,
		ANGLE_NULL,
		hullAngleDivision,
		true,
		sf::Vector2f (
			this->imuDevicePosition - planesBackPosition,
			- hullRadius
		)
	);

	/** Hull */
	this->body.addEllipse (
		COLOR_BACKGROUND,
		COLOR_GRID_BIG,
		COLOR_LINE,
		hullRadiusFront,
		hullRadius,
		hullRadiusDivision,
		ANGLE_RIGHT,
		- ANGLE_RIGHT,
		hullAngleDivision,
		true,
		sf::Vector2f (
			this->imuDevicePosition - hullRadiusFront,
			0.0
		)
	);
	this->body.addRectangle (
		COLOR_BACKGROUND,
		COLOR_GRID_BIG,
		COLOR_LINE,
		hullWidthStraight,
		hullBreadth,
		hullBreadthDivision * hullWidthStraight / hullRadius * 0.5,
		hullBreadthDivision,
		false,
		sf::Vector2f (
			this->imuDevicePosition - hullRadiusFront - hullWidthStraight,
			- hullRadius
		)
	);
	this->body.addEllipse (
		COLOR_BACKGROUND,
		COLOR_GRID_BIG,
		COLOR_LINE,
		hullRadiusBack,
		hullRadius,
		hullRadiusDivision,
		ANGLE_RIGHT,
		ANGLE_FULL - ANGLE_RIGHT,
		hullAngleDivision,
		true,
		sf::Vector2f (
			this->imuDevicePosition - hullRadiusFront - hullWidthStraight,
			0.0
		)
	);
	this->body.addLine (
		this->imuDevicePosition - hullRadiusFront - hullWidthStraight,
		hullRadius,
		this->imuDevicePosition - hullRadiusFront,
		hullRadius,
		COLOR_LINE
	);
	this->body.addLine (
		this->imuDevicePosition - hullRadiusFront - hullWidthStraight,
		- hullRadius,
		this->imuDevicePosition - hullRadiusFront,
		- hullRadius,
		COLOR_LINE
	);

	/** Propulsion */
	this->propulsion.addRectangle (
		COLOR_BACKGROUND,
		COLOR_GRID_BIG,
		COLOR_LINE,
		propulsionWidth,
		propulsionBreadth,
		hullBreadthDivision * propulsionWidth / propulsionBreadth,
		hullBreadthDivision,
		true,
		sf::Vector2f (
			this->imuDevicePosition - hullRadiusFront - hullWidthStraight - hullRadiusBack - propulsionWidth,
			- propulsionBreadth * 0.5
		)
	);

	/** Navigation body */
	this->navigationBody.addEllipse (
		COLOR_BACKGROUND,
		COLOR_GRID_BIG,
		COLOR_LINE,
		navigationBodyWidth * 0.5,
		navigationBodyBreadth * 0.5,
		hullRadiusDivision,
		ANGLE_NULL,
		ANGLE_FULL,
		hullAngleDivision,
		true,
		sf::Vector2f (
			this->imuDevicePosition - navigationBodyPosition,
			0.0
		)
	);

	/** Rudders */
	this->upperRudder.addEllipse (
		COLOR_BACKGROUND,
		COLOR_GRID_BIG,
		COLOR_LINE,
		ruddersBreadth,
		ruddersThickness * 0.5,
		1.0,
		- ANGLE_RIGHT,
		ANGLE_RIGHT,
		hullAngleDivision,
		true,
		sf::Vector2f (
			this->imuDevicePosition - ruddersPosition - ruddersBreadth * 0.5,
			0.0
		)
	);
	this->upperRudder.addLine (
		this->imuDevicePosition - ruddersPosition - ruddersBreadth * 0.5,
		- ruddersThickness * 0.5,
		this->imuDevicePosition - ruddersPosition - ruddersBreadth * 0.5,
		ruddersThickness * 0.5,
		COLOR_LINE
	);

	this->imuDevicePosition = Ruller::gridToMeter (this->imuDevicePosition);

	this->updateComponents ();
}

/**
 *  @brief: .
 */
bool Ship::isOpen () {
	return this->totalLength > 0.0;
}

/**
 *  @brief: .
 */
bool Ship::isPointIn (sf::Vector2f point) {
	double lengthFront = Ruller::meterToPixel (this->imuDevicePosition);
	double lengthBack = Ruller::meterToPixel (this->totalLength - this->imuDevicePosition);
	double radius = Ruller::meterToPixel (this->getTotalBeam ()) * 0.4;
	double theCos = cos (this->getRotation () * radians);
	double theSin = sin (this->getRotation () * radians);

	sf::Vector2f a = Ruller::gridToPixel (this->getPosition ());
	sf::Vector2f b = a;
	sf::Vector2f c = a;
	sf::Vector2f d = a;

	a.x = a.x + lengthFront * theCos + radius * theSin;
	a.y = a.y + lengthFront * theSin - radius * theCos;
	b.x = b.x + lengthFront * theCos - radius * theSin;
	b.y = b.y + lengthFront * theSin + radius * theCos;

	c.x = c.x - lengthBack * theCos + radius * theSin;
	c.y = c.y - lengthBack * theSin - radius * theCos;
	d.x = d.x - lengthBack * theCos - radius * theSin;
	d.y = d.y - lengthBack * theSin + radius * theCos;

	return isInParalelogram (a, b, c, d, point);
}

/**
 *  @brief: .
 */
bool Ship::mouseOver () {

	return this->isPointIn (Ruller::mousePosition ());
}

/**
 *  @brief: .
 */
std::string Ship::getIdentificator () {
	return this->identificator;
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
std::string Ship::getVersion () {
	return this->version;
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
	return Writer::toString (this->getOrientation (), 1) + UNIT_ANGLE;
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
sf::String Ship::getPlanesWidthText () {
	return Writer::toString (this->getPlanesWidth ()) + UNIT_DISTANCE;
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
sf::String Ship::getTotalBeamText () {
	return Writer::toString (this->getTotalBeam ()) + UNIT_DISTANCE;
}

/**
 *  @brief: .
 */
sf::String Ship::getTotalLengthText () {
	return Writer::toString (this->getTotalLength ()) + UNIT_DISTANCE;
}

/**
 *  @brief: .
 */
sf::String Ship::getIdentificationText () {
	return this->getIdentificator () + " | " + this->getName ();
}

/**
 *  @brief: .
 */
sf::String Ship::getSizeText () {
	return Writer::toString (this->getSize ().x) + " x " + 
		   Writer::toString (this->getSize ().y) + UNIT_DISTANCE;
}

/**
 *  @brief: .
 */
sf::String Ship::getGuideText () {
	return this->getIdentificationText () + "\n" + 
		   this->getVersion () + "\n" + 
		   this->getOrientationText () + "\n" + 
		   this->getSpeedText () + "\n" + 
		   this->getSizeText ();
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
sf::Vector2f Ship::getSize () {
	return sf::Vector2f (this->getTotalLength (), this->getBeam ());
}

/**
 *  @brief: .
 */
double Ship::getRotation () {
	return this->body.getRotation ();
}

/**
 *  @brief: .
 */
double Ship::getOrientation () {
	return clockwiseToGeographic (this->body.getRotation ());
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
double Ship::getPlanesWidth () {
	return this->planesWidth;
}

/**
 *  @brief: .
 */
double Ship::getBeam () {
	return this->beam;
}

/**
 *  @brief: .
 */
double Ship::getTotalBeam () {
	return (this->beam + 2.0 * this->planesWidth);
}

/**
 *  @brief: .
 */
double Ship::getTotalLength () {
	return this->totalLength;
}