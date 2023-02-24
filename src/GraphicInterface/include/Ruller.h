/**
 *  Ruller.h
 * 
 *  Created 22 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 22 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef RULLER_H_
#define RULLER_H_

#include "SFML/Graphics.hpp"

/**
 *  @brief:
 */
class Ruller {

public:
	static void initialize (
		double w = sf::VideoMode::getDesktopMode ().width,
		double h = sf::VideoMode::getDesktopMode ().height,
		double grid = 100, 
		double meter = 10,
		double viewMoveSpeed = sf::VideoMode::getDesktopMode ().width / 100, 
		double viewZoomSpeed = 1.01
	);
	static void update (double viewMoveSpeed, double viewZoomSpeed);
	static void reset (sf::View *view);

	static void setSize (double w, double h);
	static void setSize (sf::Vector2f size);
	static void setWidth (double pixels);
	static void setHeight (double pixels);

	static void setGrid (double pixels);
	static void setMeter (double pixels);

	static void setPosition (double x = 0.0, double y = 0.0);
	static void moveReset ();
	static void move (double x, double y);

	static void setViewMoveSpeed (double pixels);
	static void setViewZoomSpeed (double ratio);

	static void setZoom (double factor = 1.0);
	static void zoomReset ();
	static void zoom (double factor);

	static double width ();
	static double width (double percent);
	static double widthGrid ();
	static double widthGrid (double percent);
	static double widthMeter ();
	static double widthMeter (double percent);

	static double height ();
	static double height (double percent);
	static double heightGrid ();
	static double heightGrid (double percent);
	static double heightMeter ();
	static double heightMeter (double percent);

	static sf::Vector2f size ();
	static sf::Vector2f size (double percent);
	static sf::Vector2f sizeGrid ();
	static sf::Vector2f sizeGrid (double percent);
	static sf::Vector2f sizeMeter ();
	static sf::Vector2f sizeMeter (double percent);

	static double getGrid ();
	static double getGridMeter ();
	static double getMeter ();
	static double getMeterGrid ();

	static sf::Vector2f getPosition ();
	static sf::Vector2f getPositionGrid ();
	static sf::Vector2f getPositionMeter ();

	static double getViewMoveSpeed ();
	static double getViewZoomSpeed ();

	static double getFactor ();

	static sf::Vector2f center ();
	static sf::Vector2f centerGrid ();
	static sf::Vector2f centerMeter ();

	static sf::Vector2f mousePosition ();
	static sf::Vector2f mousePositionGrid ();
	static sf::Vector2f mousePositionMeter ();

	static double pixelToGrid (double vector);
	static sf::Vector2f pixelToGrid (double x, double y);
	static sf::Vector2f pixelToGrid (sf::Vector2f vector);

	static double pixelToMeter (double vector);
	static sf::Vector2f pixelToMeter (double x, double y);
	static sf::Vector2f pixelToMeter (sf::Vector2f vector);

	static double gridToPixel (double vector);
	static sf::Vector2f gridToPixel (double x, double y);
	static sf::Vector2f gridToPixel (sf::Vector2f vector);

	static double gridToMeter (double vector);
	static sf::Vector2f gridToMeter (double x, double y);
	static sf::Vector2f gridToMeter (sf::Vector2f vector);

	static double meterToPixel (double vector);
	static sf::Vector2f meterToPixel (double x, double y);
	static sf::Vector2f meterToPixel (sf::Vector2f vector);

	static double meterToGrid (double vector);
	static sf::Vector2f meterToGrid (double x, double y);
	static sf::Vector2f meterToGrid (sf::Vector2f vector);

private:
	static double w;
	static double h;

	static double grid;
	static double meter;

	static double viewMoveSpeed;
	static double viewZoomSpeed;

	static double x;
	static double y;

	static double factor;
};

#endif