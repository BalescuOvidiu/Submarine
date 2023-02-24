/**
 *  Writer.cpp
 * 
 *  Created 28 May 2018
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 20 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Writer.h"

sf::Font Writer::font;
std::string Writer::decimalsDelimiter;
int Writer::decimalsNumber;

/**
 *  @brief: .
 */
void Writer::initialize (
	std::string directory,
	std::string decimalsDelimiter,
	int decimalsNumber
) {
	Writer::update(directory, decimalsDelimiter, decimalsNumber);
}

void Writer::update (
	std::string directory,
	std::string decimalsDelimiter,
	int decimalsNumber
) {
	Writer::setFont (directory);
	Writer::setDecimalsDelimiter (decimalsDelimiter);
	Writer::setDecimalsNumber (decimalsNumber);
}

/**
 *  @brief: Initialize a text with a string from SFML Framework.
 */
void Writer::setFont (sf::Text &text) {
	text = sf::Text ("", Writer::font);
}

/**
 *  @brief: .
 */
void Writer::setFont (std::string directory) {
	font.loadFromFile (directory);
}

/**
 *  @brief: .
 */
void Writer::setDecimalsDelimiter (std::string decimalsDelimiter) {
	Writer::decimalsDelimiter = decimalsDelimiter;
}

/**
 *  @brief: .
 */
void Writer::setDecimalsNumber (int decimalsNumber) {
	Writer::decimalsNumber = decimalsNumber;
}

/**
 *  @brief: Align text how the title says.
 */
void Writer::alignLeft (sf::Text &text) {
	sf::FloatRect rectangle = text.getLocalBounds ();
	text.setOrigin (
		rectangle.left,
   		text.getOrigin ().y
   	);
}

/**
 *  @brief: Align text how the title says.
 */
void Writer::alignLeftTop (sf::Text &text) {
	sf::FloatRect rectangle = text.getLocalBounds ();
	text.setOrigin (
		rectangle.left,
   		rectangle.top
   	);
}

/**
 *  @brief: Align text how the title says.
 */
void Writer::alignLeftMiddle (sf::Text &text) {
	sf::FloatRect rectangle = text.getLocalBounds ();
	text.setOrigin (
		rectangle.left,
   		rectangle.top + 0.5 * rectangle.height
   	);
}

/**
 *  @brief: Align text how the title says.
 */
void Writer::alignLeftBottom (sf::Text &text) {
	sf::FloatRect rectangle = text.getLocalBounds ();
	text.setOrigin (
		rectangle.left,
   		rectangle.top + rectangle.height
   	);
}

/**
 *  @brief: Align text how the title says.
 */
void Writer::alignCenter (sf::Text &text) {
	sf::FloatRect rectangle = text.getLocalBounds ();
	text.setOrigin (
		rectangle.left + 0.5 * rectangle.width,
   		text.getOrigin ().y
   	);
}

/**
 *  @brief: Align text how the title says.
 */
void Writer::alignCenterTop (sf::Text &text) {
	sf::FloatRect rectangle = text.getLocalBounds ();
	text.setOrigin (
		rectangle.left + 0.5 * rectangle.width,
   		rectangle.top
   	);
}

/**
 *  @brief: Align text how the title says.
 */
void Writer::alignCenterMiddle (sf::Text &text) {
	sf::FloatRect rectangle = text.getLocalBounds ();
	text.setOrigin (
		rectangle.left + 0.5 * rectangle.width,
   		rectangle.top + 0.5 * rectangle.height
   	);
}

/**
 *  @brief: Align text how the title says.
 */
void Writer::alignCenterBottom (sf::Text &text) {
	sf::FloatRect rectangle = text.getLocalBounds ();
	text.setOrigin (
		rectangle.left + 0.5 * rectangle.width,
   		rectangle.top + rectangle.height
   	);
}

/**
 *  @brief: Align text how the title says.
 */
void Writer::alignRight (sf::Text &text) {
	sf::FloatRect rectangle = text.getLocalBounds ();
	text.setOrigin (
		rectangle.left + rectangle.width,
   		text.getOrigin ().y
   	);
}

/**
 *  @brief: Align text how the title says.
 */
void Writer::alignRightTop (sf::Text &text) {
	sf::FloatRect rectangle = text.getLocalBounds ();
	text.setOrigin (
		rectangle.left + 0.5 * rectangle.width,
   		rectangle.top
   	);
}

/**
 *  @brief: Align text how the title says.
 */
void Writer::alignRightMiddle (sf::Text &text) {
	sf::FloatRect rectangle = text.getLocalBounds ();
	text.setOrigin (
		rectangle.left + rectangle.width,
   		rectangle.top + 0.5 * rectangle.height
   	);
}

/**
 *  @brief: Align text how the title says.
 */
void Writer::alignRightBottom (sf::Text &text) {
	sf::FloatRect rectangle = text.getLocalBounds ();
	text.setOrigin (
		rectangle.left + rectangle.width,
   		rectangle.top + rectangle.height
   	);
}

/**
 *  @brief: Align text how the title says.
 */
void Writer::alignTop (sf::Text &text) {
	sf::FloatRect rectangle = text.getLocalBounds ();
	text.setOrigin (
		text.getOrigin ().x,
   		rectangle.top
   	);
}

/**
 *  @brief: Align text how the title says.
 */
void Writer::alignMiddle (sf::Text &text) {
	sf::FloatRect rectangle = text.getLocalBounds ();
	text.setOrigin (
		text.getOrigin ().x,
   		rectangle.top + 0.5 * rectangle.height
   	);
}

/**
 *  @brief: Align text how the title says.
 */
void Writer::alignBottom (sf::Text &text) {
	sf::FloatRect rectangle = text.getLocalBounds ();
	text.setOrigin (
		text.getOrigin ().x,
   		rectangle.top + rectangle.height
   	);
}

/**
 *  @brief: .
 *
 *  @return: .
 */
sf::Font Writer::getFont () {
	return font;
}

/**
 *  @brief: .
 *
 *  @return: .
 */
std::string Writer::getDecimalsDelimiter () {
	return Writer::decimalsDelimiter;
}

/**
 *  @brief: .
 *
 *  @return: .
 */
int Writer::getDecimalsNumber () {
	return Writer::decimalsNumber;
}

/**
 *  @brief: Convert a number with decimals to a string.
 *
 *  @return: string that contain the number.
 */
std::string Writer::toString (double value, int precision) {
	double whole = abs (value);
	unsigned decimals = (value - whole) * pow (10, precision);
	std::stringstream stream;
	stream << whole << decimalsDelimiter << decimals;
	return stream.str ();
}

/**
 *  @brief: Remove substring from a string.
 *
 *  @return: the string without removed substring.
 */
std::string Writer::removeChars(const std::string& source, std::string chars) {
    std::string result = "";
	for (unsigned int i = 0; i < source.length(); i++) {
		bool found = false;
		for (unsigned int j = 0; j < chars.length() && !found; j++) {
			found = (source[i] == chars[j]);
		}
		if (!found) {
			result += source[i];
		}
	}
	return result;
}