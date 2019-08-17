#ifndef COMPONENT_H
#define COMPONENT_H

#include "gui.h"

class Component {

	public:
		Component (const Component& source);
		Component (
			sf::Vector2f position = sf::Vector2f (0, 0), 
			sf::PrimitiveType type = sf::Lines,
			std::string text = std::string ("")
		);

		~Component ();

		// Update methods.
		void render (sf::RenderWindow *window);
		void move (double x, double y);
		void update ();
		void clear ();

		// Methods used to set position.
		void setPosition (double x, double y);
		void setPosition (sf::Vector2f point);

		// Methods used to set label.
		void setLabel (sf::Color color);
		void setLabel (
			std::string text = std::string (""), 
			sf::Color color = COLOR_TEXT
		);
		void setLabel (
			sf::String text = sf::String (""), 
			sf::Color color = COLOR_TEXT
		);
		
		// Methods used to add points.
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
		
		// Methods used to add joints.
		void addJoint (
			double x, 
			double y, 
			sf::Color color = COLOR_GRID
		);
		void addJoint (
			sf::Vector2f position, 
			sf::Color color = COLOR_GRID
		);
		
		// Methods used to add lines on component.
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
		
		// Other methods used to draw
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

		// Methods used to get position of important points
		sf::Vector2f getPosition ();
		sf::Vector2f getPoint (unsigned long i);
		sf::Vector2f getFirstPoint ();
		sf::Vector2f getLastPoint ();

	protected:
		std::vector<sf::Vertex> point;

		sf::VertexBuffer buffer;
		sf::Vector2f position;
		sf::Text label;
};

#endif