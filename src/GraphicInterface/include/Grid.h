/**
 *  Grid
 * 
 *  Created 22 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 22 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef GRID_H_
#define GRID_H_

#include <SFML/Graphics.hpp>

/**
 *  @brief:
 */
class Grid {

public:
	static void initialize (char directoryOfConfigFile[]);
	static void update (char directoryOfConfigFile[]);

	static void setPrimaryGridOnWidth (double numbers);
	static void setPrimaryGridOnHeight (double numbers);

	static void setSecondaryGridOnWidth (double numbers);
	static void setSecondaryGridOnHeight (double numbers);

	static double width ();
	static double height ();

	static double getPrimary ();
	static double getSecondary ();

	static sf::Vector2f convertTo (sf::Vector2f vector);
	static double convertTo (double vector);

	static sf::Vector2f convertFrom (sf::Vector2f vector);
	static double convertFrom (double vector);

private:
	static double primary;
	static double secondary;

};

#endif