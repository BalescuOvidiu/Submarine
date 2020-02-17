#ifndef SYMBOL_UNIT_H_
#define SYMBOL_UNIT_H_

/** SFML library. */
#include <SFML/Graphics.hpp>

/**Input/output. */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

enum IndexUnit {
	FIRST = 0,
	
	CENTIMETER = FIRST,
	METER,
	KILOMETER,
	
	LAST = 10,
};


class SymbolUnit {

private:
	

public:
	static void initialize (std::string directory);
	static void update ();
	static void setFile (std::string directory);
	static sf::String get (IndexUnit notation);
	static sf::String set (IndexUnit notation, sf::String string);
}

#endif