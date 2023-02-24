/**
 *  Ship.h
 * 
 *  Modified 20 February 2023
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 22 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef SHIP_H_
#define SHIP_H_

#include <string>

#include "Component.h"


/**
 *  @brief:
 */
class Ship {

public:
	Ship (std::string directory);

	void render (sf::RenderWindow *window);

	void update ();
	void updateComponents ();
	void move (double x, double y);
	void rotate (double angle);
	void loadFromFile (std::string directory);
	void draw ();

	void setPosition (double x, double y);
	void setPosition (sf::Vector2f position);
	void setRotation (double angle);

	bool isOpen ();
	bool mouseOver ();

	std::string getName ();

	sf::String getSpeedText ();
	sf::String getRotationText ();
	sf::String getOrientationText ();
	sf::String getLengthText ();
	sf::String getBeamText ();
	sf::String getGuideText ();

	sf::Vector2f getPosition ();

	double getSpeed ();
	double getRotation ();
	double getOrientation ();
	double getLength ();
	double getBeam ();

private:
	std::string name;

	double lengthHull;
	double radiusHull;

	double radiusPlane;

	double radiusBack;

	double positionBodyNavigation;
	double radiusXBodyNavigation;
	double radiusYBodyNavigation;

	double distanceSensorMin;
	double distanceSensorMax;

	double positionInertialDevice;

	double divisionWidth;
	double divisionAngle;

	double totalLength;

	double speed;
	double orientation;

	Component body;
	Component shadow;
};

#endif