/**
 *  Writing.h
 * 
 *  Created 28 May 2018
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 25 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef WRITING_H_
#define WRITING_H_

/** SFML library. */
#include <SFML/Graphics.hpp>

/**Input/output. */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

class Writing {

private:
	static Font font;


public:
	static void initialize (std::string directory);
	static void loadFont (std::string directory);
	static void text (
		sf::Text &text,
		sf::Color color,
		std::string string
	);
	static void text (
		sf::Text &text, 
		sf::Color color,
		sf::String string
	);
	static void text (
		sf::Text &text,
		sf::Color color,
		const std::string& string
	);
	static void text (
		sf::Text &text, 
		sf::Color color,
		const sf::String& string
	);

}

/** Functions who convert numbers to string. */
std::string format (const double& value);
std::string format (double value);
std::string format (short value);
std::string format (int value);
std::string format (unsigned value);

#endif