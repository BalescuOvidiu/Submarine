#ifndef GUI_H
#define GUI_H

// Math
#include <cmath>

// SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>

// Input/output
#include <fstream>
#include <iostream>

// STL objects
#include <stack>
#include <string>
#include <vector>

// Time
#include <ctime>

// Math constants
#define PI              3.14159265358979323846

// Math macro           
#define COS(angle)      cos ( (angle) * PI / 180.0)
#define SIN(angle)      sin ( (angle) * PI / 180.0)
#define MID(a, b)       0.5 * (a + b)
#define LAST(vector, i) vector[vector.size () - i - 1]

// Window
#define WIDTH(percent)  0.01 * gui::width * percent
#define HEIGHT(percent) 0.01 * gui::height * percent
#define FRAME_LIMIT     60

// Colors
#define COLOR_BACKGROUND sf::Color (32, 32, 32)
#define COLOR_GRID_MINOR sf::Color (48, 48, 48)
#define COLOR_GRID       sf::Color (64, 64, 64)
#define COLOR_LINE       sf::Color (128, 128, 128)
#define COLOR_TEXT       sf::Color (232, 232, 255)

// Files
#define FILE_FONT   "data/Verdana.ttf"
#define FILE_CONFIG "data/config.txt"
#define FILE_LOG    "data/log.txt"                          

// Log macros
#define LOG_LINE   "  File: " << __FILE__
#define LOG_FILE   "  Line: " << __LINE__
#define LOG_F      gui::log << LOG_FILE << LOG_LINE << "\n"
#define LOG_C      std::cout << LOG_FILE << LOG_LINE << "\n"
#define LOG(text)  gui::logMessage (text); LOG_C; LOG_F

/**
 * This namespace contains data of screen, grid, font, position
 * of view and zoom information. It's functions modularize work
 * with mouse, positioning and text.
 */
namespace gui {
	// Font variable
	extern sf::Font font;

	// Variables of screen
	extern const unsigned width;
	extern const unsigned height;
	extern const double grid;
	extern bool exit;
	extern double moveViewSpeed;
	extern double circlePrecision;

	// Variables of view
	extern double zoomFactor;
	extern sf::Vector2f positionOfView;

	// Communications
	extern std::string name;
	extern std::fstream log;

	void initialize ();
	void logMessage (std::string message);
	void move (sf::Vector2f position);

	// Functions used to create text label.
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
	void textCenter (sf::Text &text);

	// Functions used for mouse click.
	bool canClick (short time);
	bool canLeft (short time);
	bool canRight (short time);
	void restartClick ();

	// Functions used to get mouse coordinate.
	sf::Vector2f mousePosition ();
	sf::Vector2f mouseZoomed ();

	// Points functions
	sf::Vector2f centerOfScreen ();
	sf::Vector2f zoomPoint (sf::Vector2f point);

	// Functions used for conversion between bidimensional vectors and grid values.
	sf::Vector2f toGrid (sf::Vector2f vector);
	sf::Vector2f fromGrid (sf::Vector2f vector);

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

	/**
	 * This function move center of view.
	 */
	template <class T>
	void move (T x, T y) {
		positionOfView += sf::Vector2f (x, y);
	}
}

#endif