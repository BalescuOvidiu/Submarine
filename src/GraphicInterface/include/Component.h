/**
 *  Component.h
 * 
 *  Created 15 May 2019
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 25 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "Config.h"
#include "Grid.h"
#include "Mathematics.h"
#include "Writing.h"

/** RGB codes of used colors in application. */
#define COLOR_TRANSPARENT sf::Color (0, 0, 0, 0)
#define COLOR_BACKGROUND  sf::Color (32, 32, 32)
#define COLOR_GRID_MINOR  sf::Color (48, 48, 48)
#define COLOR_GRID        sf::Color (64, 64, 64)
#define COLOR_LINE        sf::Color (128, 128, 128)
#define COLOR_TEXT        sf::Color (232, 232, 255) 
#define COLOR_WARNING     sf::Color (216, 128, 32)   

class Component {

	public:
		Component (const Component& source);
		Component (
			sf::Vector2f position = sf::Vector2f (0, 0),
			sf::PrimitiveType type = sf::Lines,
			std::string text = std::string (""),
			bool visible = true,
			double angle = ANGLE_MIN
		);
		Component (
			sf::PrimitiveType type,
			sf::Vector2f position = sf::Vector2f (0, 0),
			bool visible = true,
			double angle = ANGLE_MIN
		);

		~Component ();

		/** Update methods. */
		void render (sf::RenderWindow *window);
		void move (double x, double y);
		void movePoints (double x, double y);
		void update ();
		void clear ();

		/** Visibilty methods. */
		void show ();
		void hide ();
		void toggleVisibility ();
		bool isVisible ();

		/** Methods used to set position. */
		void setPosition (double x, double y);
		void setPosition (sf::Vector2f point);

		/** Methods used to set label. */
		void setLabel (sf::Color color);
		void setLabel (
			std::string text = std::string (""), 
			sf::Color color = COLOR_TEXT
		);
		void setLabel (
			sf::String text = sf::String (""), 
			sf::Color color = COLOR_TEXT
		);
		void removeLabel ();
		
		/** Methods used to add points. */
		void setPoint (
			unsigned long i, 
			sf::Vector2f position, 
			sf::Color color
		);
		void setPoint (unsigned long i, sf::Vector2f position);
		void setPoint (unsigned long i, sf::Color color);
		void addPoint (
			double x, 
			double y, 
			sf::Color color = COLOR_GRID
		);
		void addPoint (
			sf::Vector2f position, 
			sf::Color color = COLOR_GRID
		);
		
		/** Methods used to add joints. */
		void addJoint (
			double x, 
			double y, 
			sf::Color color = COLOR_GRID
		);
		void addJoint (
			sf::Vector2f position, 
			sf::Color color = COLOR_GRID
		);
		
		/** Methods used to add lines on component. */
		void addLine (
			double a, 
			double b, 
			double c, 
			double d, 
			sf::Color color = COLOR_GRID
		);
		void addLine (
			sf::Vector2f begin, 
			sf::Vector2f end, 
			sf::Color color = COLOR_GRID
		);
		
		/** Other methods used to draw */
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
			double ellipseCount, 
			double radiusDivision, 
			double radiusX, 
			double radiusY, 
			double angleDivison,
			double angleBegin, 
			double angleEnd,
			bool margin = true,
			sf::Vector2f origin = sf::Vector2f (0, 0)
		);
		void addCircle (
			sf::Color colorGrid,
			sf::Color colorMargin,
			double circleCount, 
			double radiusDivision, 
			double radius, 
			double angleDivison,
			double angleBegin, 
			double angleEnd,
			bool margin = true,
			sf::Vector2f origin = sf::Vector2f (0, 0)
		);
		void addEllipseWithHole (
			sf::Color colorGrid,
			sf::Color colorMargin,
			double ellipseCount, 
			double radiusDivision, 
			double radiusX, 
			double radiusY, 
			double radiusHoleX, 
			double radiusHoleY, 
			double angleDivison,
			double angleBegin, 
			double angleEnd,
			bool margin = true,
			sf::Vector2f origin = sf::Vector2f (0, 0)
		);
		void addCircleWithHole (
			sf::Color colorGrid,
			sf::Color colorMargin,
			double circleCount, 
			double radiusDivision, 
			double radius,
			double radiusHole, 
			double angleDivison,
			double angleBegin, 
			double angleEnd,
			bool margin = true,
			sf::Vector2f origin = sf::Vector2f (0, 0)
		);

		/** Methods used to get position of important points. */
		sf::Vector2f getPosition ();
		sf::Vector2f getPoint (unsigned long i);
		sf::Vector2f getFirstPoint ();
		sf::Vector2f getLastPoint ();

		/** Methods to check if a point is over the component */
		bool isInRectangle (sf::Vector2f point);
		bool isInCircle (sf::Vector2f point);

		/** Methods that work with mouse. */
		bool click (bool conditionMouseOver);
		bool left (bool conditionMouseOver);
		bool right (bool conditionMouseOver);

		/** Methods used to work with angle and rotation. */
		void setRotation (double newAngle);
		void rotate (double newAngle);
		double getRotation ();

	protected:

		/** Variables used for draw. */
		bool visible;
		std::vector<sf::Vertex> point;
		sf::VertexBuffer buffer;

		/** Variables used for calculations. */
		double angle;
		sf::Vector2f position;
		sf::Vector2f min;
		sf::Vector2f max;

		/** Text if it's necessary. */
		sf::Text *label;
};

#endif