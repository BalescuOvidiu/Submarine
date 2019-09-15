/**
 * Programmer: Balescu Ovidiu-Gheorghe
 * Date:       15 May 2019
 * Library:    SFML 2.5.1
 */

#ifndef CONFIG_H_
#define CONFIG_H_

/** Other headers. */
#include <cstdlib>

/** Time. */
#include <ctime>

/** STL objects. */
#include <stack>
#include <string>

/** SFML. */
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>

/** Mathematical constants and functions. */
#include "mathematics.h"

/** Colors codes. */
#define COLOR_TRANSPARENT sf::Color (0, 0, 0, 0)
#define COLOR_BACKGROUND  sf::Color (32, 32, 32)
#define COLOR_GRID_MINOR  sf::Color (48, 48, 48)
#define COLOR_GRID        sf::Color (64, 64, 64)
#define COLOR_LINE        sf::Color (128, 128, 128)
#define COLOR_TEXT        sf::Color (232, 232, 255)                       

#define LOG(text)  gui::logMessage (text);

/**
 * This namespace contains data of screen, grid, font, position
 * of view and zoom information. It's functions modularize work
 * with mouse, positioning and text.
 *
 * File configuration.txt must contain on each line:
 * 1. name of application,
 * 2. timeFormat string to format time for log file,
 * 3. frame rate of window,
 * 4. move view speed of view(camera),
 * 5. circle precision, numbers of lines of polygon who make the circle,
 * 6. decimals number printed on screen.
 */
namespace config {

	/** Variables of screen. */
	extern const unsigned width;
	extern const unsigned height;
	extern const double grid;
	extern sf::Vector2f positionOfView;

	/** Precision. */
	void exit ();
	bool canExit ();
	double getMoveViewSpeed ();
	double getCirclePrecision ();
	unsigned getDecimalsNumber ();

	/** Communications. */
	std::string getNameOfApplication ();

	double getGrid ();
	unsigned getWidth ();
	unsigned getWidth (short percent);
	unsigned getHeight ();
	unsigned getHeight (short percent);
	unsigned getFrameRate ();

	void initialize ();
	void logMessage (std::string message);
	void move (sf::Vector2f position);

	/** Functions used to create text label. */
	void text (
		sf::Text &text, 
		sf::Vector2f position, 
		std::string string
	);
	void text (
		sf::Text &text, 
		sf::Vector2f position, 
		sf::String string
	);
	void textCentered (sf::Text &text);

	/** Functions used for mouse click. */
	bool canClick (short time);
	bool canLeft (short time);
	bool canRight (short time);
	void restartClick ();

	/** Functions used to get mouse coordinate. */
	sf::Vector2f mousePosition ();
	sf::Vector2f mouseZoomed ();

	/** Points functions */
	void move (double x, double y);
	sf::Vector2f centerOfScreen ();
	sf::Vector2f zoomPoint (sf::Vector2f point);

	/** 
	 * Functions used for conversion between bidimensional 
	 * vectors and grid values.
	 */
	sf::Vector2f toGrid (sf::Vector2f vector);
	sf::Vector2f fromGrid (sf::Vector2f vector);

	/** Functions who convert numbers to string. */
	std::string format (double value);
	std::string format (short value);
	std::string format (int value);
	std::string format (unsigned value);

	/**
	 * This function transform numbers and objects into a string,
	 * with measure units.
	 *
	 * @param object, number,
	 * @param measure unit.
	 * 
	 * @return string.
	 */
	template <typename T>
	sf::String format (const T& object, sf::String measureUnit) {
		return sf::String (format (object)) + measureUnit;
	}

	/**
	 * This function transform numbers and objects into a string.
	 *
	 * @param object.
	 * 
	 * @return string.
	 */
	template <typename T>
	std::string toString(const T& object) {
	    std::ostringstream stream;
	    stream << object;
	    return stream.str();
	}

	/**
	 * This function scale a number to grid values.
	 *
	 * @param a value of number scaled to grid values.
	 * 
	 * @return scaled value to grids.
	 */
	template <class T>
	T toGrid (T a) {
		return a * grid;
	}

	/**
	 * This function scale a point to grid values.
	 *
	 * @param x first coordinate of point;
	 * @param y second coordinate of point.
	 */
	template <class T>
	void toGrid (T& x, T& y) {
		x *= grid;
		y *= grid;
	}

	/**
	 * This function scale a point from grid values.
	 *
	 * @param x first coordinate of point;
	 * @param y second coordinate of point.
	 */
	template <class T>
	void fromGrid (T& x, T& y) {
		x /= grid;
		y /= grid;
	}

	/**
	 * This function scale a numeric value from grid values.
	 *
	 * @param a value of number.
	 * 
	 * @return scaled value to grids.
	 */
	template <class T>
	T fromGrid (T a) {
		return a / grid;
	}
}

#endif