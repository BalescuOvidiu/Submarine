/**
 *  Writer.h
 * 
 *  Created 28 May 2018
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 20 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef WRITER_H_
#define WRITER_H_

#include <string>

#include "SFML/Graphics.hpp"

/**
 *  @brief:
 */
class Writer {

public:
	static void initialize (
		std::string directory,
		std::string decimalsDelimiter = ".",
		int decimals_number = 2
	);
	static void update (
		std::string directory,
		std::string decimalsDelimiter,
		int decimals_number
	);

	static void setFont (sf::Text &text);
	static void setFont (std::string directory);
	static void setDecimalsDelimiter (std::string decimalsDelimiter);
	static void setDecimalsNumber (int decimalsNumber);

	static void alignLeft (sf::Text &text);
	static void alignLeftTop (sf::Text &text);
	static void alignLeftMiddle (sf::Text &text);
	static void alignLeftBottom (sf::Text &text);

	static void alignCenter (sf::Text &text);
	static void alignCenterTop (sf::Text &text);
	static void alignCenterMiddle (sf::Text &text);
	static void alignCenterBottom (sf::Text &text);

	static void alignRight (sf::Text &text);
	static void alignRightTop (sf::Text &text);
	static void alignRightMiddle (sf::Text &text);
	static void alignRightBottom (sf::Text &text);

	static void alignTop (sf::Text &text);
	static void alignMiddle (sf::Text &text);
	static void alignBottom (sf::Text &text);

	static sf::Font getFont ();
	static std::string getDecimalsDelimiter ();
	static int getDecimalsNumber ();

	static std::string toString (
		double value = 0, 
		int precision = Writer::getDecimalsNumber ()
	);
	static std::string removeChars(
		const std::string& source, 
		std::string chars
	);

private:
	static sf::Font font;
	static std::string decimalsDelimiter;
	static int decimalsNumber;
};

#endif