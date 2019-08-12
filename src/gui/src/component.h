#ifndef COMPONENT_H
#define COMPONENT_H

#include "gui.h"

class Component {
protected:
	std::vector<sf::Vertex> line;
	sf::Vector2f position;
	sf::Text label;
	sf::PrimitiveType type;
public:
	Component ();
	Component (sf::Vector2f position);
	Component (sf::Vector2f position, sf::PrimitiveType type);
	Component (sf::Vector2f position, std::string label);
	Component (sf::Vector2f position, std::string label, sf::PrimitiveType type);
	// Update
	void render (sf::RenderWindow *window);
	void move (double x, double y);
	// Draw
	void setLabel (sf::String string);
	void setLabel (sf::Color color);
	// Points
	void setPoint (unsigned long i, sf::Vector2f position);
	void setPoint (unsigned long i, sf::Color color);
	void addPoint (double x, double y, sf::Color color);
	void addPoint (sf::Vector2f position, sf::Color color);
	// Joints
	void addJoint (double x, double y, sf::Color color);
	void addJoint (sf::Vector2f position, sf::Color color);
	// Lines
	void addLine (double a, double b, double c, double d, sf::Color color);
	void addLine (sf::Vector2f begin, sf::Vector2f end, sf::Color color);
	// Other draw functions
	void addCircle (sf::Vector2f origin, double radiusA, double radiusB, unsigned count, unsigned division, unsigned radiusDivision, double a, double b);
	void clear ();
	// Position
	sf::Vector2f getPosition ();
	sf::Vector2f getPoint (unsigned long i);
	sf::Vector2f getLeftWire ();
	sf::Vector2f getRightWire ();
	sf::Vector2f getLeftGrid ();
	sf::Vector2f getRightGrid ();
	~Component ();
};

Component circleRadar (sf::Vector2f position, double radius, unsigned count, unsigned division, unsigned radiusDivision);

#endif