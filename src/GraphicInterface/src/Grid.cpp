<<<<<<< HEAD
=======
/**
 *  Grid.cpp
 * 
 *  Created 22 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 26 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
#include "Grid.h"

#include <fstream>

using namespace std;

/**
 *  @brief:
 */
static void Grid::initialize (char directoryOfConfigFile[]) {
<<<<<<< HEAD

}

/**
 *  @brief:
 */
static void Grid::update (char directoryOfConfigFile[]) {

}

/**
 *  @brief:
 */
static void Grid::setPrimaryGridOnWidth (double numbers) {
	
}

/**
 *  @brief:
 */
static void Grid::setPrimaryGridOnHeight (double numbers) {
	
=======
	ifstream configFile (directoryOfConfigFile);

	if (configFile.is_open ()) {
		this->primary = ;
		this->secondary = ;
	}
	else {
		this->primary = ;
		this->secondary = ;
	}

	configFile.close ();
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
}

/**
 *  @brief:
<<<<<<< HEAD
 */
static void Grid::setSecondaryGridOnWidth (double numbers) {
	
=======
 *
 *  @return: .
 */
static double width () {
	return (double)sf::VideoMode::getDesktopMode ().width;
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
}

/**
 *  @brief:
<<<<<<< HEAD
 */
static void Grid::setSecondaryGridOnHeight (double numbers) {
	
=======
 *
 *  @return: .
 */
static double height () {
	return (double)sf::VideoMode::getDesktopMode ().height;
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
}

/**
 *  @brief:
 *
 *  @return: .
 */
static double Grid::getPrimary () {
	return this->primary;
}

/**
 *  @brief:
 *
 *  @return: .
 */
static double Grid::getSecondary () {
	return this->secondary;
}

/**
 *  @brief:
 *
 *  @return: .
 */
static sf::Vector2f convertTo (sf::Vector2f vector) {
	vector.x *= this->primary;
	vector.y *= this->primary;

	return vector;
}

/**
 *  @brief:
 *
 *  @return: .
 */
static double convertTo (double vector) {
	vector *= this->primary;

	return vector;
}

/**
 *  @brief:
 *
 *  @return: .
 */
static sf::Vector2f convertFrom (sf::Vector2f vector) {
	vector.x /= this->primary;
	vector.y /= this->primary;

	return vector;
}

/**
 *  @brief:
 *
 *  @return: .
 */
static double convertFrom (double vector) {
	vector /= this->primary;

	return vector;
}