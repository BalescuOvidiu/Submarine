/**
 *  FilledComponent.cpp
 * 
 *  Created 26 February 2023
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 26 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#include "FilledComponent.h"

/**
 *  @brief:
 */
FilledComponent::FilledComponent (const FilledComponent& source) {
	this->background = source.background;
	this->grids = source.grids;
}

/**
 *  @brief:
 */
FilledComponent::FilledComponent (
	sf::Vector2f position,
	bool visible,
	double angle
) {
	this->background = new Component (
		sf::TriangleStrip,
		position,
		visible,
		angle
	);
	this->grids = new Component (
		sf::Lines,
		position,
		visible,
		angle
	);
}

/**
 *  @brief:
 */
FilledComponent::~FilledComponent () {
	this->background = NULL;
	this->grids = NULL;
}

/**
 *  @brief:
 */
void FilledComponent::render (sf::RenderWindow *window) {
	this->background->render (window);
	this->grids->render (window);
}

/**
 *  @brief:
 */
void FilledComponent::move (double x, double y) {
	this->background->move (x, y);
	this->grids->move (x, y);
}

/**
 *  @brief:
 */
void FilledComponent::move (sf::Vector2f vector) {
	this->move (vector.x, vector.y);
}

/**
 *  @brief:
 */
void FilledComponent::movePoints (double x, double y) {
	this->background->movePoints (x, y);
	this->grids->movePoints (x, y);
}

/**
 *  @brief:
 */
void FilledComponent::movePoints (sf::Vector2f vector) {
	this->movePoints (vector.x, vector.y);
}

/**
 *  @brief:
 */
void FilledComponent::update () {
	this->background->update ();
	this->grids->update ();
}

/**
 *  @brief:
 */
void FilledComponent::clear () {
	this->background->clear ();
	this->grids->clear ();
}

/**
 *  @brief:
 */
void FilledComponent::show () {
	this->background->show ();
	this->grids->show ();
}

/**
 *  @brief:
 */
void FilledComponent::hide () {
	this->background->hide ();
	this->grids->hide ();
}

/**
 *  @brief:
 */
void FilledComponent::toggleVisibility () {
	this->background->toggleVisibility ();
	this->grids->toggleVisibility ();
}

/**
 *  @brief:
 */
bool FilledComponent::isHidden () {
	return this->background->isHidden ();
}

/**
 *  @brief:
 */
bool FilledComponent::isVisible () {
	return this->background->isVisible ();
}

/**
 *  @brief:
 */
void FilledComponent::setPosition (double x, double y) {
	this->background->setPosition (x, y);
	this->grids->setPosition (x, y);
}

/**
 *  @brief:
 */
void FilledComponent::setPosition (sf::Vector2f point) {
	this->background->setPosition (point);
	this->grids->setPosition (point);
}

/**
 *  @brief:
 */
unsigned long FilledComponent::size () {
	return this->background->size ();
}

/**
 *  @brief:
 */
void FilledComponent::erasePoint (unsigned long index) {
	this->background->erasePoint (index);
	this->grids->erasePoint (index);
}

/**
 *  @brief:
 */
void FilledComponent::erasePoint (unsigned long first, unsigned long last) {
	this->background->erasePoint (first, last);
	this->grids->erasePoint (first, last);
}

/**
 *  @brief:
 */
void FilledComponent::addPoint (
	double x, 
	double y, 
	sf::Color colorBackground,
	sf::Color colorGrid
) {
	this->background->addPoint (x, y, colorBackground);
	this->grids->addPoint (x, y, colorGrid);
}

/**
 *  @brief:
 */
void FilledComponent::addPoint (
	sf::Vector2f position, 
	sf::Color colorBackground,
	sf::Color colorGrid
) {
	this->background->addPoint (position, colorBackground);
	this->grids->addPoint (position, colorGrid);
}

/**
 *  @brief:
 */
void FilledComponent::addJoint (
	double x, 
	double y, 
	sf::Color colorBackground,
	sf::Color colorGrid
) {
	this->background->addJoint (x, y, colorBackground);
	this->grids->addJoint (x, y, colorGrid);
}

/**
 *  @brief:
 */
void FilledComponent::addJoint (
	sf::Vector2f position, 
	sf::Color colorBackground,
	sf::Color colorGrid
) {
	this->background->addJoint (position, colorBackground);
	this->grids->addJoint (position, colorGrid);
}

/**
 *  @brief:
 */
void FilledComponent::addLine (
	double a, 
	double b, 
	double c, 
	double d, 
	sf::Color colorGrid
) {
	this->grids->addLine (a, b, c, d, colorGrid);
}

/**
 *  @brief:
 */
void FilledComponent::addLine (
	sf::Vector2f begin, 
	sf::Vector2f end, 
	sf::Color colorGrid
) {
	this->grids->addLine (begin, end, colorGrid);
}

/**
 *  @brief:
 */
void FilledComponent::addRectangle (
	sf::Color colorBackground,
	sf::Color colorGrid,
	sf::Color colorMargin,
	double width,
	double height,
	double widthDivision, 
	double heightDivision,
	bool margin,
	sf::Vector2f origin
) {
	this->background->addRectangle (
		colorBackground,
		colorMargin,
		width,
		height,
		1.0,
		1.0,
		false,
		origin
	);
	this->grids->addRectangle (
		colorGrid,
		colorMargin,
		width,
		height,
		widthDivision,
		heightDivision,
		margin,
		origin
	);
}

// /**
//  *  @brief:
//  */
void FilledComponent::addSquare (
	sf::Color colorBackground,
	sf::Color colorGrid,
	sf::Color colorMargin,
	double width,
	double widthDivision,
	bool margin,
	sf::Vector2f origin
) {
	this->background->addSquare (
		colorBackground,
		colorMargin,
		width,
		1.0,
		false,
		origin
	);
	this->grids->addSquare (
		colorGrid,
		colorMargin,
		width,
		widthDivision,
		margin,
		origin
	);
}

// /**
//  *  @brief:
//  */
void FilledComponent::addEllipse (
	sf::Color colorBackground,
	sf::Color colorGrid,
	sf::Color colorMargin,
	double radiusX, 
	double radiusY, 
	double radiusDivision, 
	double angleBegin, 
	double angleEnd,
	double angleDivison,
	bool margin,
	sf::Vector2f origin
) {
	this->background->addEllipse (
		colorBackground,
		colorMargin,
		radiusX,
		radiusY,
		1.0,
		angleBegin,
		angleEnd,
		angleDivison,
		false,
		origin
	);
	this->grids->addEllipse (
		colorGrid,
		colorMargin,
		radiusX,
		radiusY,
		radiusDivision,
		angleBegin,
		angleEnd,
		angleDivison,
		margin,
		origin		
	);
}

// /**
//  *  @brief:
//  */
void FilledComponent::addCircle (
	sf::Color colorBackground,
	sf::Color colorGrid,
	sf::Color colorMargin,
	double radius, 
	double radiusDivision, 
	double angleBegin, 
	double angleEnd,
	double angleDivison,
	bool margin,
	sf::Vector2f origin
) {
	this->background->addCircle (
		colorBackground,
		colorMargin,
		radius,
		1.0,
		angleBegin,
		angleEnd,
		angleDivison,
		false,
		origin
	);
	this->grids->addCircle (
		colorGrid,
		colorMargin,
		radius,
		radiusDivision,
		angleBegin,
		angleEnd,
		angleDivison,
		margin,
		origin
	);
}

// /**
//  *  @brief:
//  */
void FilledComponent::addEllipseWithHole (
	sf::Color colorBackground,
	sf::Color colorGrid,
	sf::Color colorMargin,
	double radiusX, 
	double radiusY, 
	double radiusDivision, 
	double radiusHoleX, 
	double radiusHoleY, 
	double angleBegin, 
	double angleEnd,
	double angleDivison,
	bool margin,
	sf::Vector2f origin
) {
	this->background->addEllipseWithHole (
		colorBackground,
		colorMargin,
		radiusX,
		radiusY,
		1.0,
		radiusHoleX,
		radiusHoleY,
		angleBegin,
		angleEnd,
		angleDivison,
		false,
		origin
	);
	this->grids->addEllipseWithHole (
		colorGrid,
		colorMargin,
		radiusX,
		radiusY,
		radiusDivision,
		radiusHoleX,
		radiusHoleY,
		angleBegin,
		angleEnd,
		angleDivison,
		margin,
		origin
	);
}

// /**
//  *  @brief:
//  */
void FilledComponent::addCircleWithHole (
	sf::Color colorBackground,
	sf::Color colorGrid,
	sf::Color colorMargin,
	double radius,
	double radiusDivision, 
	double radiusHole, 
	double angleBegin, 
	double angleEnd,
	double angleDivison,
	bool margin,
	sf::Vector2f origin
) {
	this->background->addCircleWithHole (
		colorBackground,
		colorMargin,
		radius,
		1.0,
		radiusHole,
		angleBegin,
		angleEnd,
		angleDivison,
		false,
		origin
	);
	this->grids->addCircleWithHole (
		colorGrid,
		colorMargin,
		radius,
		radiusDivision,
		radiusHole,
		angleBegin,
		angleEnd,
		angleDivison,
		margin,
		origin
	);
}

/**
 *  @brief:
 */
sf::Vector2f FilledComponent::getPosition () {
	return this->background->getPosition ();
}

/**
 *  @brief:
 */
sf::Vector2f FilledComponent::getPosition (double x, double y) {
	return this->background->getPosition (x, y);
}

/**
 *  @brief:
 */
sf::Vector2f FilledComponent::getPosition (sf::Vector2f point) {
	return this->background->getPosition (point);
}

/**
 *  @brief:
 */
bool FilledComponent::isInParalelogram (sf::Vector2f point) {
	return this->background->isInParalelogram (point);
}

/**
 *  @brief:
 */
bool FilledComponent::isInRectangle (sf::Vector2f point) {
	return this->background->isInRectangle (point);
}

/**
 *  @brief:
 */
bool FilledComponent::isInCircle (sf::Vector2f point) {
	return this->background->isInCircle (point);
}

/**
 *  @brief:
 */
bool FilledComponent::clickLeft (bool conditionMouseOver) {
	return this->background->clickLeft (conditionMouseOver);
}

/**
 *  @brief:
 */
bool FilledComponent::clickRight (bool conditionMouseOver) {
	return this->background->clickRight (conditionMouseOver);
}

/**
 *  @brief:
 */
void FilledComponent::setRotation (double newAngle) {
	this->background->setRotation (newAngle);
	this->grids->setRotation (newAngle);
}

/**
 *  @brief:
 */
void FilledComponent::rotate (double newAngle) {
	this->background->rotate (newAngle);
	this->grids->rotate (newAngle);
}

/**
 *  @brief:
 */
double FilledComponent::getRotation () {
	return this->background->getRotation ();
}