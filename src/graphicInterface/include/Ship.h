/**
 *  Ship.h
 * 
 *  Modified 20 February 2023
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 24 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef SHIP_H_
#define SHIP_H_

#include <string>
#include <vector>

#include "FilledComponent.h"
#include "Utils.h"


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
	void move (sf::Vector2f point);
	void rotate (double angle);

	void setSpeed (double value);
	void setPosition (double x, double y);
	void setPosition (sf::Vector2f position);
	void setRotation (double angle);

	void loadFromFile (std::string directory);
	void draw (json dataVersion);

	bool isOpen ();
	bool isPointIn (sf::Vector2f point);
	bool mouseOver ();

	std::string getIdentificator ();
	std::string getName ();
	std::string getVersion ();

	sf::String getRotationText ();
	sf::String getOrientationText ();
	sf::String getSpeedText ();
	sf::String getPlanesWidthText ();
	sf::String getBeamText ();
	sf::String getTotalBeamText ();
	sf::String getTotalLengthText ();

	sf::String getIdentificationText ();
	sf::String getSizeText ();
	sf::String getGuideText ();

	sf::Vector2f getPosition ();
	sf::Vector2f getSize ();

	double getRotation ();
	double getOrientation ();
	double getSpeed ();
	double getPlanesWidth ();
	double getBeam ();
	double getTotalBeam ();
	double getTotalLength ();

private:
	std::string identificator;
	std::string name;
	std::string version;

	double speed;
	double planesWidth;
	double beam;
	double totalLength;
	double imuDevicePosition;

	FilledComponent body;
	FilledComponent navigationBody;
	FilledComponent upperRudder;
	FilledComponent propulsion;

	sf::Clock clock;
};

#endif