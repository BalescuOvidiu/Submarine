#include "component.h"

using namespace std;
using namespace sf;
using namespace gui;

/**
 * 
 */
Component::Component (const Component& source) {
	this->position = source.position;
	this->label = source.label;
	this->point = source.point;
	this->buffer = source.buffer;
}

/**
 * 
 */
Component::Component (
	Vector2f position, 
	PrimitiveType type, 
	string text
) {
	this->position = toGrid (position);

	this->buffer = VertexBuffer (type);

	gui::text (this->label, this->position, text);
}

/**
 * 
 */
Component::~Component () {
	this->buffer.create (0);
	this->point.clear ();
}

/**
 * 
 */
void Component::render (RenderWindow *window) {
	window->draw (this->label);
	window->draw (this->buffer);
}

/**
 * 
 */
void Component::move (double x, double y) {
	toGrid (x, y);

	this->position.x += x;
	this->position.y += y;
	this->label.move (x, y);
	for (unsigned i = 0; i < this->point.size (); i++) {
		this->point[i].position.x += x;
		this->point[i].position.y += y;
	}
}

/*
 *
 */
void Component::update () {
	this->buffer.create (this->point.size ());
	this->buffer.update (
		this->point.data (), 
		this->point.size (), 
		0
	);
}

/**
 * 
 */
void Component::clear () {
	this->buffer.create (0);
	this->point.clear ();
}

/**
 * 
 */
void Component::setPosition (double x, double y) {
	toGrid (x, y);
	this->position = Vector2f (x, y);
	this->label.setPosition (this->position);
}

/**
 * 
 */
void Component::setPosition (sf::Vector2f point) {
	this->position = toGrid (point);
	this->label.setPosition (this->position);
}


void Component::setLabel (sf::Color color) {
	this->label.setFillColor (color);	
}

/**
 * 
 */
void Component::setLabel (
	string text, 
	Color color
) {
	this->label.setString (text);
	this->label.setFillColor (color);
}

/**
 * 
 */
void Component::setLabel (
	String text, 
	Color color
) {
	this->label.setString (text);
	this->label.setFillColor (color);
}


/**
 * 
 */
void Component::setPoint (
	unsigned long i, 
	Vector2f position, 
	sf::Color color
) {
	this->point[i].position = toGrid (position);
	this->point[i].color = color;
}

/**
 * 
 */
void Component::setPoint (unsigned long i, Vector2f position) {
	this->point[i].position = toGrid (position);
}

/**
 * 
 */
void Component::setPoint (unsigned long i, Color color) {
	this->point[i].color = color;
}

/**
 * 
 */
void Component::addPoint (
	double x, 
	double y, 
	Color color
) {

	toGrid (x, y);
	this->point.push_back (Vertex (
		Vector2f (
			this->position.x + x, 
			this->position.y + y
			), 
		color
	));
}

/**
 * 
 */
void Component::addPoint (
	Vector2f position, 
	Color color
) {
	position = toGrid (position);
	this->point.push_back (Vertex (
		Vector2f (this->position + position), 
		color
	));
}

/**
 * 
 */
void Component::addJoint (
	double x, 
	double y, 
	Color color
) {
	this->addPoint (x, y, color);
	this->addPoint (x, y, color);
}

/**
 * 
 */
void Component::addJoint (
	Vector2f position, 
	Color color
) {
	this->addPoint (position, color);
	this->addPoint (position, color);
}

/**
 * 
 */
void Component::addLine (
	double a, 
	double b, 
	double c, 
	double d, 
	Color color
) {
	this->addPoint (a, b, color);
	this->addPoint (c, d, color);
}

/**
 * 
 */
void Component::addLine (
	Vector2f begin, 
	Vector2f end, 
	Color color
) {
	this->addPoint (begin, color);
	this->addPoint (end, color);
}

/**
 * 
 */
void Component::addRectangle ( 
	Color colorGrid,
	Color colorMargin,
	double width, 
	double height, 
	double widthDivision, 
	double heightDivision,
	bool margin,
	Vector2f origin
) {

	// Horizontal lines
	for (double y = 0; y <= height; y += heightDivision) {
		this->addLine (
			origin.x, 
			origin.y + y,
			origin.x + width, 
			origin.y + y,
			colorGrid
		);
	}

	// Vertical lines
	for (double x = 0; x <= width; x += widthDivision) {
		this->addLine (
			origin.x + x,
			origin.y,
			origin.x + x, 
			origin.y + height,
			colorGrid
		);
	}

	// Margins
	if (margin) {
		this->addLine (
			origin.x, 
			origin.y,
			origin.x, 
			origin.y + height,
			colorMargin
		);
		this->addLine (
			origin.x, 
			origin.y + height,
			origin.x + width, 
			origin.y + height,
			colorMargin
		);
		this->addLine (
			origin.x + width, 
			origin.y,
			origin.x + width, 
			origin.y + height,
			colorMargin
		);
		this->addLine (
			origin.x, 
			origin.y,
			origin.x + width, 
			origin.y,
			colorMargin
		);
	}
}

/**
 *
 */
void Component::addSquare (
	Color colorGrid,
	Color colorMargin,
	double width,
	double widthDivision,
	bool margin,
	Vector2f origin
) {
	this->addRectangle (
		colorGrid,
		colorMargin,
		width,
		width,
		widthDivision,
		widthDivision,
		margin,
		origin
	);
}

/**
 * 
 */
void Component::addEllipse (
	Color colorGrid,
	Color colorMargin,
	double ellipseCount,
	double radiusDivision, 
	double radiusX, 
	double radiusY,
	double angleDivison,
	double angleBegin, 
	double angleEnd,
	bool margin,
	Vector2f origin
) {
	double stepX = radiusX / radiusDivision;
	double stepY = radiusY / radiusDivision;

	// Lines
	for (
		double angle = angleBegin; 
		angle <= angleEnd; 
		angle += angleDivison
	) {
		this->addLine (
		    origin.x,
		    origin.y,
		    origin.x + radiusX * COS (angle),
		    origin.y + radiusY * SIN (angle),
		    colorGrid
		);
	}

	// Circles
	for (double div = 1; div <= radiusDivision; div ++) {

		// Begin of circle
		this->addPoint (
		    origin.x + stepX * div * COS (angleBegin),
		    origin.y + stepY * div * SIN (angleBegin),
		    colorGrid
		);

		for (
			double angle = angleBegin; 
			angle <= angleEnd; 
			angle += angleDivison / ellipseCount
		)  {
			this->addJoint (
			    origin.x + stepX * div * COS (angle),
			    origin.y + stepY * div * SIN (angle),
		    	colorGrid
			);
		}

		// End of circle
		this->addPoint (
		    origin.x + stepX * div * COS (angleEnd),
		    origin.y + stepY * div * SIN (angleEnd),
		    colorGrid
		);
	}

	// Margin
	if (margin) {

		// Begin of circle
		this->addPoint (
		    origin.x + radiusX * COS (angleBegin),
		    origin.y + radiusY * SIN (angleBegin),
		    colorMargin
		);

		for (
			double angle = angleBegin; 
			angle <= angleEnd; 
			angle += angleDivison / ellipseCount
		)  {
			this->addJoint (
			    origin.x + radiusX * COS (angle),
			    origin.y + radiusY * SIN (angle),
		    	colorMargin
			);
		}

		// End of circle
		this->addPoint (
		    origin.x + radiusX * COS (angleEnd),
		    origin.y + radiusY * SIN (angleEnd),
		    colorMargin
		);
	}
}

/**
 * 
 */
void Component::addCircle (
	Color colorGrid,
	Color colorMargin,
	double circleCount, 
	double radiusDivision, 
	double radius, 
	double angleDivison,
	double angleBegin, 
	double angleEnd,
	bool margin,
	Vector2f origin
) {
	this->addEllipse (
		colorGrid,
		colorMargin,
		circleCount,
		radiusDivision,
		radius,
		radius,
		angleDivison,
		angleBegin,
		angleEnd,
		margin,
		origin
	);
}

/**
 * 
 */
Vector2f Component::getPosition () {
	return fromGrid (this->position);
}

/**
 * 
 */
Vector2f Component::getPoint (unsigned long i) {
	if (i < this->point.size ()) {
		return fromGrid (this->point[i].position);
	}
	return Vector2f (-1, -1);
}

/**
 * 
 */
Vector2f Component::getFirstPoint () {
	return fromGrid (this->point[0].position);
}

/**
 * 
 */
Vector2f Component::getLastPoint () {
	return fromGrid (
		this->point[this->point.size () - 1].position
	);
}