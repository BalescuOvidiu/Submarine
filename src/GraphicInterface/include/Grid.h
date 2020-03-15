/**
<<<<<<< HEAD
 *  Grid
 * 
 *  Created 22 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 22 February 2020
=======
 *  Grid.h
 * 
 *  Created 22 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 26 February 2020
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
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
<<<<<<< HEAD
	static void update (char directoryOfConfigFile[]);

	static void setPrimaryGridOnWidth (double numbers);
	static void setPrimaryGridOnHeight (double numbers);

	static void setSecondaryGridOnWidth (double numbers);
	static void setSecondaryGridOnHeight (double numbers);
=======
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21

	static double width ();
	static double height ();

	static double getPrimary ();
	static double getSecondary ();

<<<<<<< HEAD
=======
	static double getPrimaryOnWidth ();
	static double getSecondaryOnWidth ();

	static double getPrimaryOnHeight ();
	static double getSecondaryOnHeight ();

>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
	static sf::Vector2f convertTo (sf::Vector2f vector);
	static double convertTo (double vector);

	static sf::Vector2f convertFrom (sf::Vector2f vector);
	static double convertFrom (double vector);

private:
	static double primary;
	static double secondary;

};

#endif