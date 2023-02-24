/**
 *  Panel.cpp
 * 
 *  Created 22 February 2023
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 22 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#include "Panel.h"

/**
 *  @brief:
 */
Panel::Panel (
	double minX,
	double minY,
	double maxX,
	double maxY,
	double marginSize,
	double zoomInLimit,
	double zoomOutLimit,
	unsigned int characterSize,
	int keysWaitTime
) {
	this->setSizes (
		minX,
		minY,
		maxX,
		maxY,
		marginSize,
		zoomInLimit,
		zoomOutLimit,
		characterSize,
		keysWaitTime
	);
	this->open ();
}

/**
 *  @brief:
 */
Panel::~Panel () {

}

void Panel::setSizes (
	double minX,
	double minY,
	double maxX,
	double maxY,
	double marginSize,
	double zoomInLimit,
	double zoomOutLimit,
	unsigned int characterSize,
	int keysWaitTime
) {
	this->minX = minX;
	this->minY = minY;
	this->maxX = maxX;
	this->maxY = maxY;
	this->marginSize = marginSize;

	this->zoomInLimit = zoomInLimit;
	this->zoomOutLimit = zoomOutLimit;
	this->characterSize = characterSize;

	this->keysWaitTime = keysWaitTime;
}

/**
 *  @brief:
 */
void Panel::open () {
	this->on = true;
	this->keysClock = sf::Clock ();
}

/**
 *  @brief:
 */
void Panel::open (sf::View *view) {
	Ruller::reset (view);
	this->open ();
}

/**
 *  @brief:
 */
void Panel::close () {
	this->on = false;
}

/**
 *  @brief:
 */
double Panel::getWidth () {
	return (this->maxX - this->minX);
}

/**
 *  @brief:
 */
double Panel::getWidthGrid () {
	return Ruller::pixelToGrid (this->maxX - this->minX);
}

/**
 *  @brief:
 */
double Panel::getWidthMeter () {
	return Ruller::pixelToMeter (this->maxX - this->minX);
}

/**
 *  @brief:
 */
double Panel::getHeight () {
	return (this->maxY - this->minY);
}

/**
 *  @brief:
 */
double Panel::getHeightGrid () {
	return Ruller::pixelToGrid (this->maxY - this->minY);
}

/**
 *  @brief:
 */
double Panel::getHeightMeter () {
	return Ruller::pixelToMeter (this->maxY - this->minY);
}

/**
 *  @brief:
 */
bool Panel::canMove (double x, double y) {
	return true;
}

/**
 *  @brief:
 */
bool Panel::canZoom (double factor) {
	if (this->zoomInLimit < Ruller::getFactor () * factor) {
		return (this->zoomOutLimit > Ruller::getFactor () * factor);
	}
	return false;
}

/**
 *  @brief:
 */
bool Panel::canPressKeys () {
	return (this->keysWaitTime < keysClock.getElapsedTime ().asMilliseconds ());
}

/**
 *  @brief:
 */
bool Panel::isPointValid (double x, double y) {
	return (this->minX < x && this->maxX > x && this->minY < y && this->maxY > y);
}

/**
 *  @brief:
 */
bool Panel::isPointValid (sf::Vector2f point) {
	return this->isPointValid (point.x, point.y);
}

/**
 *  @brief:
 */
bool Panel::isOpen () {
	return this->on;
}

/**
 *  @brief:
 */
bool Panel::isClosed () {
	return !this->on;
}