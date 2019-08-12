#ifndef GUI_H
#define GUI_H

// Math
#include <cmath>

// SFML
#include <SFML/Graphics.hpp>

// Input/output
#include <fstream>
#include <iostream>

// STL objects
#include <stack>
#include <string>
#include <vector>

// Math
#define PI              3.14159265358979323846
#define MID(a, b)       ( (a + b) * 0.5)
#define LAST(vector, i) vector[vector.size () - i - 1]

// Window
#define WIDTH(percent)  (gui::width * percent * 0.01)
#define HEIGHT(percent) (gui::height * percent * 0.01)

// Colors
#define COLOR_BACKGROUND sf::Color (32, 32, 32)
#define COLOR_GRID       sf::Color (64, 64, 64)
#define COLOR_GRID_MINOR sf::Color (48, 48, 48)
#define COLOR_TEXT       sf::Color (232, 232, 255)

// Files
#define FILE_FONT   "data/Verdana.ttf"
#define FILE_CONFIG "data/config.txt"
#define FILE_LOG    "data/log.txt"

// Communications
#define NAME "UB-FMI-212"
#define LOG(message)                                        \
	if (gui::log.is_open ()) {                              \
		gui::log << "( "<<__FILE__<<", "<<__LINE__<<" ): "; \
		gui::log << message << "\n";                        \
	}                                                       \
	std::cout << "( "<<__FILE__<<", "<<__LINE__<<" ): ";    \
	std::cout << message << "\n";                           

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

	// Variables of view
	extern double zoomFactor;
	extern sf::Vector2f positionOfView;

	// Communications
	extern std::fstream log;

	void initialize ();
	void move (sf::Vector2f position);

	// Functions used to create text label.
	void text (
		sf::Text &text, 
		sf::Vector2i position, 
		std::string string
	);
	void text (
		sf::Text &text, 
		sf::Vector2f position, 
		sf::String string
	);

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
	 * This function scale a point to grid values.
	 * @params: x - first coordinate of point;
	 *			y - second coordinate of point.
	 */
	template <class T>
	void toGrid (T& x, T& y) {
		x *= grid;
		y *= grid;
	}

	/**
	 * This function scale a point from grid values.
	 *
	 * @params: x - first coordinate of point;
	 *			y - second coordinate of point.
	 */
	template <class T>
	void fromGrid (T& x, T& y) {
		x /= grid;
		y /= grid;
	}


	template <class T>
	void move (T x, T y) {
		positionOfView += sf::Vector2f (x, y);
	}
}

#endif