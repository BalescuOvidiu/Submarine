/**
 *  Component.h
 * 
 *  Created 15 May 2019
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 26 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <SFML/Graphics.hpp>

#include "Mathematics.h"

/** RGB codes of used colors in the application. */
#define COLOR_BLACK       sf::Color (32, 32, 32)
#define COLOR_GRAY_DARK   sf::Color (48, 48, 48)
#define COLOR_GRAY        sf::Color (64, 64, 64)
#define COLOR_GRAY_LIGHT  sf::Color (128, 128, 128)
#define COLOR_WHITE       sf::Color (232, 232, 255) 
#define COLOR_VIOLET      sf::Color (128, 32, 216)
#define COLOR_BLUE        sf::Color (32, 32, 216)
#define COLOR_CYAN        sf::Color (32, 128, 216)
#define COLOR_GREEN       sf::Color (32, 216, 32)
#define COLOR_YELLOW      sf::Color (216, 216, 32)
#define COLOR_ORANGE      sf::Color (216, 128, 32)
#define COLOR_RED         sf::Color (216, 32, 32)
#define COLOR_TRANSPARENT sf::Color (0, 0, 0, 0)

#define COLOR_LABEL       sf::Color (48, 48, 48, 128)
#define COLOR_BACKGROUND  COLOR_BLACK
#define COLOR_GRID_SMALL  COLOR_GRAY_DARK
#define COLOR_GRID_BIG    COLOR_GRAY
#define COLOR_LINE        COLOR_GRAY_LIGHT
#define COLOR_TEXT        COLOR_WHITE 
#define COLOR_WARNING     COLOR_RED   

/**
 *  @brief:
 */
class Component {

public:
	Component (const Component& source);
	Component (
		sf::PrimitiveType type = sf::PrimitiveType::Points,
		sf::Vector2f position = sf::Vector2f (0, 0),
		bool visible = true,
		double angle = ANGLE_NULL
	);

	~Component ();

	static void initialize (
		double circlePrecision = 5.0, 
		int clickWaitTime = 320
	);

	/** Update methods. */
	void render (sf::RenderWindow *window);
	void move (double x, double y);
	void move (sf::Vector2f vector);
	void movePoints (double x, double y);
	void movePoints (sf::Vector2f vector);
	void update ();
	void clear ();

	/** Visibilty methods. */
	void show ();
	void hide ();
	void toggleVisibility ();
	bool isHidden ();
	bool isVisible ();

	/** Methods used to set position. */
	void setPosition (double x, double y);
	void setPosition (sf::Vector2f point);
	
	/** Methods used to edit points. */
	sf::Vertex& operator [] (std::size_t index);
	unsigned long size ();
	void erasePoint (unsigned long index);
	void erasePoint (unsigned long first, unsigned long last);
	
	/** Methods used to add points. */
	void addPoint (
		double x, 
		double y, 
		sf::Color color = COLOR_GRID_BIG
	);
	void addPoint (
		sf::Vector2f position, 
		sf::Color color = COLOR_GRID_BIG
	);
	
	/** Methods used to add joints. */
	void addJoint (
		double x, 
		double y, 
		sf::Color color = COLOR_GRID_BIG
	);
	void addJoint (
		sf::Vector2f position, 
		sf::Color color = COLOR_GRID_BIG
	);
	
	/** Methods used to add lines on component. */
	void addLine (
		double a, 
		double b, 
		double c, 
		double d, 
		sf::Color color = COLOR_GRID_BIG
	);
	void addLine (
		sf::Vector2f begin, 
		sf::Vector2f end, 
		sf::Color color = COLOR_GRID_BIG
	);
	
	/** Methods used to draw geometric figures. */
	void addRectangle (
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
		sf::Color colorGrid,
		sf::Color colorMargin,
		double width,
		double widthDivision,
		bool margin = true,
		sf::Vector2f origin = sf::Vector2f (0, 0)

	);
	void addEllipse (
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
	sf::Vector2f getPoint (unsigned long i);
	sf::Vector2f getFirstPoint ();
	sf::Vector2f getLastPoint ();

	/** Methods to check if a point is over the component */
	bool isInParalelogram (sf::Vector2f point);
	bool isInRectangle (sf::Vector2f point);
	bool isInCircle (sf::Vector2f point);

	/** Methods that work with mouse. */
	bool clickLeft (bool conditionMouseOver);
	bool clickRight (bool conditionMouseOver);

	/** Methods used to work with angle and rotation. */
	void setRotation (double newAngle);
	void rotate (double newAngle);
	double getRotation ();
	static double getCirclePrecision ();

protected:

	/** Variables used for draw. */
	bool visible;
	std::vector<sf::Vertex> point;
	sf::VertexBuffer buffer;
	static double circlePrecision;

	/** Variables used for calculations. */
	double angle;
	sf::Vector2f position;
	sf::Vector2f minim;
	sf::Vector2f maxim;

	/** Variables used for mouse interactions */
	bool clickedLeft;
	bool clickedRight;
	sf::Clock clock;
	static int clickWaitTime;
};

#endif