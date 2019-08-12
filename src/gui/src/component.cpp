#include "component.h"

using namespace std;
using namespace sf;
using namespace gui;

// Public methods
Component::Component () {

}
Component::Component (Vector2f position) {
	position = toGrid (position);

	this->position = position;
	this->type = Lines;

	text (this->label, position, String (""));
}
Component::Component (sf::Vector2f position, sf::PrimitiveType type) {
	position = toGrid (position);

	this->position = position;
	this->type = type;

	text (this->label, position, String (""));
}
Component::Component (sf::Vector2f position, std::string label) {
	position = toGrid (position);

	this->position = position;

	text (this->label, position, label);
}
Component::Component (sf::Vector2f position, std::string label, sf::PrimitiveType type) {
	position = toGrid (position);

	this->position = position;
	this->type = Lines;

	text (this->label, position, label);
}
// Update
void Component::render (RenderWindow *window) {
	window->draw (this->label);
	window->draw (&this->line[0], this->line.size (), this->type);
}
void Component::move (double x, double y) {
	toGrid (x, y);

	this->position.x += x;
	this->position.y += y;
	this->label.move (x, y);
	for (unsigned i = 0; i < this->line.size (); i++) {
		this->line[i].position.x += x;
		this->line[i].position.y += y;
	}
}
// Draw
void Component::setLabel (String string) {
	this->label.setString (string);
}
void Component::setLabel (Color color) {
	this->label.setColor (color);
}
// Points
void Component::setPoint (unsigned long i, Vector2f position) {
	this->line[i].position = toGrid (position);
}
void Component::setPoint (unsigned long i, Color color) {
	this->line[i].color = color;
}
void Component::addPoint (double x, double y, Color color) {
	toGrid (x, y);
	this->line.push_back (Vertex (
		Vector2f (
			this->position.x + x, 
			this->position.y + y
			), 
		color
	));
}
void Component::addPoint (Vector2f position, Color color) {
	position = toGrid (position);
	this->line.push_back (Vertex (Vector2f (this->position + position), color));
}
// Joints
void Component::addJoint (double x, double y, Color color) {
	this->addPoint (x, y, color);
	this->addPoint (x, y, color);
}
void Component::addJoint (Vector2f position, Color color) {
	this->addPoint (position, color);
	this->addPoint (position, color);
}
// Lines
void Component::addLine (double a, double b, double c, double d, Color color) {
	this->addPoint (a, b, color);
	this->addPoint (c, d, color);
}
void Component::addLine (Vector2f begin, Vector2f end, Color color) {
	this->addPoint (begin, color);
	this->addPoint (end, color);
}
// Other draw functions
void Component::addCircle (sf::Vector2f origin, double radiusA, double radiusB, unsigned count, unsigned division, unsigned radiusDivision, double a, double b) {
	Color color = COLOR_GRID;
	double stepA = radiusA / radiusDivision;
	double stepB = radiusB / radiusDivision;
	// Lines
	for (unsigned i = a; i <= b; i++) {
		this->addLine (
		    origin.x,
		    origin.y,
		    origin.x + radiusA * cos (i * (2 * PI / division)),
		    origin.y + radiusB * sin (i * (2 * PI / division)),
		    color
		);
	}
	a = a * count / division;
	b = b * count / division;
	// Circles
	for (unsigned div = 1; div <= radiusDivision; div++) {
		// Color
		if (div == radiusDivision) {
			color = COLOR_TEXT;
		}
		// Lines
		this->addPoint (
		    origin.x + stepA * div * cos (a * (2 * PI / count)),
		    origin.y + stepB * div * sin (a * (2 * PI / count)),
		    color
		);
		for (unsigned i = a; i <= b; i++) {
			this->addJoint (
			    origin.x + stepA * div * cos (i * (2 * PI / count)),
			    origin.y + stepB * div * sin (i * (2 * PI / count)),
			    color
			);
		}
		this->addPoint (
		    origin.x + stepA * div * cos (b * (2 * PI / count)),
		    origin.y + stepB * div * sin (b * (2 * PI / count)),
		    color
		);
	}
}
void Component::clear () {
	this->line.clear ();
}
// Position
Vector2f Component::getPosition () {
	return fromGrid (this->position);
}
Vector2f Component::getPoint (unsigned long i) {
	return fromGrid (this->line[i].position);
}
Vector2f Component::getLeftWire () {
	return this->line.front ().position;
}
Vector2f Component::getRightWire () {
	return this->line.back ().position;
}
Vector2f Component::getLeftGrid () {
	return fromGrid (this->line.front ().position);
}
Vector2f Component::getRightGrid () {
	return fromGrid (this->line.back ().position);
}
Component::~Component () {
	this->line.clear ();
}
// Other
Component circleRadar (Vector2f position, double radius, unsigned count, unsigned division, unsigned radiusDivision) {
	Component c (position, Lines);
	c.addCircle (Vector2f (0, 0), radius, radius, count, division, radiusDivision, 0, count);
	// Principal lines
	c.addLine (radius, 0, -radius, 0, COLOR_TEXT);
	c.addLine (0, radius, 0, -radius, COLOR_TEXT);
	return c;
}