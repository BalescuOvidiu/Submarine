/**
 *  Ruller.cpp
 * 
 *  Created 22 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 22 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#include "Ruller.h"

double Ruller::w;
double Ruller::h;

double Ruller::grid;
double Ruller::meter;

double Ruller::viewMoveSpeed;
double Ruller::viewZoomSpeed;

double Ruller::x;
double Ruller::y;

double Ruller::factor;

/**
 *  @brief:
 */
void Ruller::initialize (
	double w, 
	double h, 
	double grid, 
	double meter,
	double viewMoveSpeed,
	double viewZoomSpeed
) {
	Ruller::setSize (w, h);
	Ruller::moveReset ();
	Ruller::zoomReset ();
	Ruller::setGrid (grid);
	Ruller::setMeter (meter);
	Ruller::update (viewMoveSpeed, viewZoomSpeed);
}

/**
 *  @brief:
 */
void Ruller::update (double viewMoveSpeed, double viewZoomSpeed) {
	Ruller::setViewMoveSpeed (viewMoveSpeed);
	Ruller::setViewZoomSpeed (viewZoomSpeed);
}

/**
 *  @brief:
 */
void Ruller::reset (sf::View *view) {
	view->move (-Ruller::x, -Ruller::y);
	view->zoom (1.0 / Ruller::getFactor ());
	Ruller::moveReset ();
	Ruller::zoomReset ();
}

/**
 *  @brief:
 */
void Ruller::setSize (double w, double h) {
	Ruller::setWidth (w);
	Ruller::setHeight (h);
}

/**
 *  @brief:
 */
void Ruller::setSize (sf::Vector2f size) {
	Ruller::setSize (size.x, size.y);
}

/**
 *  @brief:
 */
void Ruller::setWidth (double pixels) {
	Ruller::w = pixels;	
}

/**
 *  @brief:
 */
void Ruller::setHeight (double pixels) {
	Ruller::h = pixels;
}

/**
 *  @brief:
 */
void Ruller::setGrid (double pixels) {
	Ruller::grid = Ruller::width () / pixels;
}

/**
 *  @brief:
 */
void Ruller::setMeter (double pixels) {
	Ruller::meter = Ruller::width () / pixels;	
}

/**
 *  @brief:
 */
void Ruller::setPosition (double x, double y) {
	Ruller::x = x;
	Ruller::y = y;
}

/**
 *  @brief:
 */
void Ruller::moveReset () {
	Ruller::setPosition ();
}

/**
 *  @brief:
 */
void Ruller::move (double x, double y) {
	Ruller::x += x;
	Ruller::y += y;
}

/**
 *  @brief:
 */
void Ruller::setViewMoveSpeed (double pixels) {
	Ruller::viewMoveSpeed = pixels;
}

/**
 *  @brief:
 */
void Ruller::setViewZoomSpeed (double ratio) {
	Ruller::viewZoomSpeed = ratio;	
}

/**
 *  @brief:
 */
void Ruller::setZoom (double factor) {
	Ruller::factor = factor;
}

/**
 *  @brief:
 */
void Ruller::zoomReset () {
	Ruller::setZoom ();
}

/**
 *  @brief:
 */
void Ruller::zoom (double factor) {
	Ruller::factor *= factor;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::width () {
	return Ruller::w;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::width (double percent) {
	return Ruller::w * percent / 100.0;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::widthGrid () {
	return Ruller::w / Ruller::grid;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::widthGrid (double percent) {
	return Ruller::w * percent / 100.0 / Ruller::grid;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::widthMeter () {
	return Ruller::w / Ruller::meter;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::widthMeter (double percent) {
	return Ruller::w * percent / 100.0 / Ruller::meter;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::height () {
	return Ruller::h;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::height (double percent) {
	return Ruller::h * percent / 100.0;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::heightGrid () {
	return Ruller::h / Ruller::grid;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::heightGrid (double percent) {
	return Ruller::h * percent / 100.0 / Ruller::grid;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::heightMeter () {
	return Ruller::h / Ruller::meter;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::heightMeter (double percent) {
	return Ruller::h * percent / 100.0 / Ruller::meter;
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::size () {
	return sf::Vector2f(
		Ruller::w,
		Ruller::h
	);
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::size (double percent) {
	return sf::Vector2f(
		Ruller::w * percent / 100.0,
		Ruller::h * percent / 100.0
	);
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::sizeGrid () {
	return sf::Vector2f(
		Ruller::w / Ruller::grid,
		Ruller::h / Ruller::grid
	);
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::sizeGrid (double percent) {
	return sf::Vector2f(
		Ruller::w * percent / 100.0 / Ruller::grid,
		Ruller::h * percent / 100.0 / Ruller::grid
	);
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::sizeMeter () {
	return sf::Vector2f(
		Ruller::w / Ruller::meter,
		Ruller::h / Ruller::meter
	);
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::sizeMeter (double percent) {
	return sf::Vector2f(
		Ruller::w * percent / 100.0 / Ruller::meter,
		Ruller::h * percent / 100.0 / Ruller::meter
	);
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::getGrid () {
	return Ruller::grid;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::getGridMeter () {
	return Ruller::grid / Ruller::meter;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::getMeter () {
	return Ruller::meter;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::getMeterGrid () {
	return Ruller::meter / Ruller::grid;
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::getPosition () {
	return sf::Vector2f (Ruller::w, Ruller::h);
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::getPositionGrid () {
	return Ruller::pixelToGrid (Ruller::getPosition ());
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::getPositionMeter () {
	return Ruller::pixelToMeter (Ruller::getPosition ());
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::getViewMoveSpeed () {
	return Ruller::viewMoveSpeed;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::getViewZoomSpeed () {
	return Ruller::viewZoomSpeed;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::getFactor () {
	return Ruller::factor;
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::center() {
	return sf::Vector2f(
		Ruller::w / 2,
		Ruller::h / 2
	);
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::centerGrid() {
	return sf::Vector2f(
		Ruller::w / 2 / Ruller::grid,
		Ruller::h / 2 / Ruller::grid
	);
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::centerMeter() {
	return sf::Vector2f(
		Ruller::w / 2 / Ruller::meter,
		Ruller::h / 2 / Ruller::meter
	);
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::mousePosition () {
	//(sf::Mouse::getPosition().x-(x+w/2))*factor+x+w/2;
	return sf::Vector2f (
		((double)sf::Mouse::getPosition ().x - Ruller::w / 2) * Ruller::factor + Ruller::x + Ruller::w / 2,
		((double)sf::Mouse::getPosition ().y - Ruller::h / 2) * Ruller::factor + Ruller::y + Ruller::h / 2
	);
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::mousePositionGrid () {
	return Ruller::pixelToGrid (Ruller::mousePosition ());
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::mousePositionMeter () {
	return Ruller::pixelToMeter (Ruller::mousePosition ());
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::pixelToGrid (double vector) {
	return vector / Ruller::grid;
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::pixelToGrid (double x, double y) {
	return sf::Vector2f(x / Ruller::grid, y / Ruller::grid);
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::pixelToGrid (sf::Vector2f vector) {
	vector.x /= Ruller::grid;
	vector.y /= Ruller::grid;

	return vector;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::pixelToMeter (double vector) {
	return vector / Ruller::meter;
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::pixelToMeter (double x, double y) {
	return sf::Vector2f(x / Ruller::meter, y / Ruller::meter);
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::pixelToMeter (sf::Vector2f vector) {
	vector.x /= Ruller::meter;
	vector.y /= Ruller::meter;

	return vector;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::gridToPixel (double vector) {
	return vector * Ruller::grid;
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::gridToPixel (double x, double y) {
	return sf::Vector2f(x * Ruller::grid, y * Ruller::grid);
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::gridToPixel (sf::Vector2f vector) {
	vector.x *= Ruller::grid;
	vector.y *= Ruller::grid;

	return vector;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::gridToMeter (double vector) {
	return vector * Ruller::grid / Ruller::meter;
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::gridToMeter (double x, double y) {
	return sf::Vector2f(
		x * Ruller::grid / Ruller::meter, 
		y * Ruller::grid / Ruller::meter
	);
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::gridToMeter (sf::Vector2f vector) {
	vector.x *= Ruller::grid / Ruller::meter;
	vector.y *= Ruller::grid / Ruller::meter;

	return vector;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::meterToPixel (double vector) {
	return vector * Ruller::meter;
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::meterToPixel (double x, double y) {
	return sf::Vector2f(x * Ruller::meter, y * Ruller::meter);
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::meterToPixel (sf::Vector2f vector) {
	vector.x *= Ruller::meter;
	vector.y *= Ruller::meter;

	return vector;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double Ruller::meterToGrid (double vector) {
	return vector * Ruller::meter / Ruller::grid;
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::meterToGrid (double x, double y) {
	return sf::Vector2f(
		x * Ruller::meter / Ruller::grid, 
		y * Ruller::meter / Ruller::grid
	);
}

/**
 *  @brief:
 *
 *  @return: .
 */
sf::Vector2f Ruller::meterToGrid (sf::Vector2f vector) {
	vector.x *= Ruller::meter / Ruller::grid;
	vector.y *= Ruller::meter / Ruller::grid;

	return vector;
}