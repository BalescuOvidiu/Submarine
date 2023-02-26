/**
 *  FilledComponent.h
 * 
 *  Created 26 February 2023
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 26 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef FILLED_COMPONENT_H_
#define FILLED_COMPONENT_H_

#include "Component.h"

/**
 *  @brief:
 */
class FilledComponent {

public:
	FilledComponent (const FilledComponent& source);
	FilledComponent (
		sf::Vector2f position = sf::Vector2f (0, 0),
		bool visible = true,
		double angle = ANGLE_NULL
	);

	~FilledComponent ();

	/** Update methods. */
	void render (sf::RenderWindow *window);
	void move (double x, double y);
	void move (sf::Vector2f vector);
	void movePoints (double x, double y);
	void movePoints (sf::Vector2f vector);
	void update ();
	void clear ();

	// * Visibilty methods. 
	void show ();
	void hide ();
	void toggleVisibility ();
	bool isHidden ();
	bool isVisible ();

	// /** Methods used to set position. */
	void setPosition (double x, double y);
	void setPosition (sf::Vector2f point);

	/** Methods used to edit points. */
	unsigned long size ();
	void erasePoint (unsigned long index);
	void erasePoint (unsigned long first, unsigned long last);
	
	// /** Methods used to add points. */
	void addPoint (
		double x, 
		double y,
		sf::Color colorBackground = COLOR_BACKGROUND, 
		sf::Color colorGrid = COLOR_GRID_BIG
	);
	void addPoint (
		sf::Vector2f position,
		sf::Color colorBackground = COLOR_BACKGROUND, 
		sf::Color colorGrid = COLOR_GRID_BIG
	);
	
	// /** Methods used to add joints. */
	void addJoint (
		double x, 
		double y,
		sf::Color colorBackground = COLOR_BACKGROUND, 
		sf::Color colorGrid = COLOR_GRID_BIG
	);
	void addJoint (
		sf::Vector2f position,
		sf::Color colorBackground = COLOR_BACKGROUND, 
		sf::Color colorGrid = COLOR_GRID_BIG
	);
	
	// /** Methods used to add lines on component. */
	void addLine (
		double a, 
		double b, 
		double c, 
		double d, 
		sf::Color colorGrid = COLOR_GRID_BIG
	);
	void addLine (
		sf::Vector2f begin, 
		sf::Vector2f end, 
		sf::Color colorGrid = COLOR_GRID_BIG
	);
	
	// /** Methods used to draw geometric figures. */
	void addRectangle (
		sf::Color colorBackground,
		sf::Color colorGrid,
		sf::Color colorMargin,
		double width, 
		double height, 
		double widthDivision, 
		double heightDivision,
		bool margin = true,
		sf::Vector2f origin = sf::Vector2f (0, 0)
	);
	void addSquare (
		sf::Color colorBackground,
		sf::Color colorGrid,
		sf::Color colorMargin,
		double width,
		double widthDivision,
		bool margin = true,
		sf::Vector2f origin = sf::Vector2f (0, 0)

	);
	void addEllipse (
		sf::Color colorBackground,
		sf::Color colorGrid,
		sf::Color colorMargin,
		double radiusX, 
		double radiusY, 
		double radiusDivision, 
		double angleBegin, 
		double angleEnd,
		double angleDivison,
		bool margin = true,
		sf::Vector2f origin = sf::Vector2f (0, 0)
	);
	void addCircle (
		sf::Color colorBackground,
		sf::Color colorGrid,
		sf::Color colorMargin,
		double radius, 
		double radiusDivision, 
		double angleBegin, 
		double angleEnd,
		double angleDivison,
		bool margin = true,
		sf::Vector2f origin = sf::Vector2f (0, 0)
	);
	void addEllipseWithHole (
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
		bool margin = true,
		sf::Vector2f origin = sf::Vector2f (0, 0)
	);
	void addCircleWithHole (
		sf::Color colorBackground,
		sf::Color colorGrid,
		sf::Color colorMargin,
		double radius,
		double radiusDivision, 
		double radiusHole, 
		double angleBegin, 
		double angleEnd,
		double angleDivison,
		bool margin = true,
		sf::Vector2f origin = sf::Vector2f (0, 0)
	);

	/** Methods used to get position of important points. */
	sf::Vector2f getPosition ();
	sf::Vector2f getPosition (double x, double y);
	sf::Vector2f getPosition (sf::Vector2f point);

	// /** Methods to check if a point is over the component */
	bool isInParalelogram (sf::Vector2f point);
	bool isInRectangle (sf::Vector2f point);
	bool isInCircle (sf::Vector2f point);

	// /** Methods that work with mouse. */
	bool clickLeft (bool conditionMouseOver);
	bool clickRight (bool conditionMouseOver);

	/** Methods used to work with angle and rotation. */
	void setRotation (double newAngle);
	void rotate (double newAngle);
	double getRotation ();

private:

	Component *background;
	Component *grids;
};

#endif