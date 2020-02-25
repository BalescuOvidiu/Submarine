/**
 *  Grid.cpp
 * 
 *  Created 22 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 22 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#include "Grid.h"

#include <fstream>

using namespace std;

/**
 *  @brief:
 */
static void Grid::initialize (char directoryOfConfigFile[]) {

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
	
}

/**
 *  @brief:
 */
static void Grid::setSecondaryGridOnWidth (double numbers) {
	
}

/**
 *  @brief:
 */
static void Grid::setSecondaryGridOnHeight (double numbers) {
	
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