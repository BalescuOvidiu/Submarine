/**
 *  Writing.h
 * 
 *  Created 28 May 2018
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 25 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef SYMBOL_UNIT_H_
#define SYMBOL_UNIT_H_

/** SFML library. */
#include <SFML/Graphics.hpp>

/**Input/output. */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

class Writing {

private:
	

public:
	static void initialize (std::string directory);
	static void update ();
	static void setFile (std::string directory);
	static sf::String get (IndexUnit notation);
	static sf::String set (IndexUnit notation, sf::String string);
}

#endif