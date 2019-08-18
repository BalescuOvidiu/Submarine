#include "component.h"

#define CLICK_TIME_WAIT 400

using namespace std;
using namespace sf;
using namespace gui;

/**
 * 
 */
Component::Component (const Component& source) {
	this->position = source.position;
	this->min = source.min;
	this->max = source.max;

	this->angle = source.angle;

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
	this->min = position;
	this->max = position;

	this->angle = 0;

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

	// Update bounds
	for (unsigned i = 0; i < this->point.size (); i++) {
		
		// Get min y and min x of points
		min.x = ::min (min.x, point[i].position.x);
		min.y = ::min (min.y, point[i].position.y);

		// Get max y and min x of points
		max.x = ::max (max.x, point[i].position.x);
		max.y = ::max (max.y, point[i].position.y);

	}

	// Update buffer
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
void Component::addEllipseWithHole (
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
	bool margin,
	sf::Vector2f origin
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
		    origin.x + radiusHoleX * COS (angle),
		    origin.y + radiusHoleY * SIN (angle),
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
void Component::addCircleWithHole (
	sf::Color colorGrid,
	sf::Color colorMargin,
	double circleCount,
	double radiusDivision,
	double radius,
	double radiusHole,
	double angleDivison,
	double angleBegin, 
	double angleEnd,
	bool margin,
	sf::Vector2f origin
) {
	this->addEllipseWithHole (
		colorGrid,
		colorMargin,
		circleCount,
		radiusDivision,
		radius,
		radius,
		radiusHole,
		radiusHole,
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

/**
 * 
 */
bool Component::isInRectangle (sf::Vector2f point) {
	return ::isInRectangle (
		this->min,
		this->max.x - this->min.x,
		this->max.y - this->min.y,
		point
	);
}

/**
 * 
 */
bool Component::isInCircle (sf::Vector2f point) {
	double radius = 0.5 * ::min (
		this->max.x - this->min.x, 
		this->max.y - this->min.y
	);

	return ::isInCircle (
		this->position,
		radius,
		point
	);
}

/**
 * 
 */
bool Component::click (bool conditionMouseOver) {

	if (left (conditionMouseOver)) {
		return true;
	}

	return right (conditionMouseOver);
}

/**
 * 
 */
bool Component::left (bool conditionMouseOver) {

	if (conditionMouseOver) {
		if (canRight (CLICK_TIME_WAIT)) {
			restartClick ();
			return true;
		}
	}

	return false;
}

/**
 * 
 */
bool Component::right (bool conditionMouseOver) {

	if (conditionMouseOver) {
		if (canLeft (CLICK_TIME_WAIT)) {
			restartClick ();
			return true;
		}
	}

	return false;
}

/**
 * 
 */
void Component::setRotation (double newAngle) {
	this->rotate (newAngle - this->angle);
}

/**
 * 
 */
void Component::rotate (double newAngle) {
	double oldX;
	double oldY;
	double newCos = COS (newAngle);
	double newSin = SIN (newAngle);

	newAngle = mapAngleInDegrees (newAngle);

	for (unsigned i = 0; i < this->point.size (); i++) {

		// Translate point to global origin.
		this->point[i].position.x -= this->position.x;
		this->point[i].position.y -= this->position.y;

		// Rotate point
		oldX = this->point[i].position.x;
		oldY = this->point[i].position.y;
		this->point[i].position.x = newCos * oldX - newSin * oldY;
		this->point[i].position.y = newCos * oldY + newSin * oldX;

		// Translate point to initial origin.
		this->point[i].position.x += this->position.x;
		this->point[i].position.y += this->position.y;
	}

	this->angle = mapAngleInDegrees (this->angle + newAngle);
	this->update ();
}

/**
 * 
 */
double Component::getRotation () {
	return this->angle;
}