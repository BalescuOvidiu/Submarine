/**
 *  Component.cpp
 * 
 *  Created 15 May 2019
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 22 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#include "Component.h"
#include "Ruller.h"

using namespace std;
using namespace sf;

double Component::circlePrecision;
int Component::clickWaitTime;

/**
 *  @brief:
 */
Component::Component (const Component& source) {
	this->position = source.position;
	this->minim = source.minim;
	this->maxim = source.maxim;

	this->angle = source.angle;

	this->point = source.point;
	this->buffer = source.buffer;
	this->visible = source.visible;

	this->clickedLeft = source.clickedLeft;
	this->clickedRight = source.clickedRight;
	this->clock = source.clock;
}

/**
 *  @brief:
 */
Component::Component (
	sf::PrimitiveType type,
	sf::Vector2f position,
	bool visible,
	double angle
) {
	this->position = Ruller::gridToPixel (position);
	this->minim = position;
	this->maxim = position;

	this->visible = visible;

	this->setRotation (angle);

	this->buffer = VertexBuffer (type);

	this->clickedLeft = false;
	this->clickedRight = false;
	this->clock = sf::Clock();
}

/**
 *  @brief:
 */
Component::~Component () {
	this->buffer.create (0);
	this->point.clear ();
}



/**
 *  @brief:
 */
void Component::initialize (
	double circlePrecision, 
	int clickWaitTime
) {
	Component::circlePrecision = circlePrecision;
	Component::clickWaitTime = clickWaitTime;
}

/**
 *  @brief:
 */
void Component::render (RenderWindow *window) {
	if (this->visible) {
		window->draw (this->buffer);
	}
}

void Component::movePoints (double x, double y) {
	x = Ruller::gridToPixel (x);
	y = Ruller::gridToPixel (y);

	for (unsigned i = 0; i < this->point.size (); i++) {
		this->point[i].position.x += x;
		this->point[i].position.y += y;
	}
}

/**
 *  @brief:
 */
void Component::move (double x, double y) {
	x = Ruller::gridToPixel (x);
	y = Ruller::gridToPixel (y);

	

	this->position.x += x;
	this->position.y += y;

	for (unsigned i = 0; i < this->point.size (); i++) {
		this->point[i].position.x += x;
		this->point[i].position.y += y;
	}
	this->update ();
}

/**
 *  @brief:
 */
void Component::update () {

	/** Update bounds. */
	this->minim = this->position;
	this->maxim = this->position;

	for (unsigned i = 0; i < this->point.size (); i++) {
		
		/** Get min y and min x of points. */
		this->minim.x = min (this->minim.x, point[i].position.x);
		this->minim.y = min (this->minim.y, point[i].position.y);

		/** Get max y and min x of points. */
		this->maxim.x = max (this->maxim.x, point[i].position.x);
		this->maxim.y = max (this->maxim.y, point[i].position.y);
	}

	/** Update buffer. */
	this->buffer.create (this->point.size ());
	this->buffer.update (
		this->point.data (), 
		this->point.size (), 
		0
	);
}

/**
 *  @brief:
 */
void Component::clear () {
	this->buffer.create (0);
	this->point.clear ();
}

/**
 *  @brief:
 */
void Component::show () {
	this->visible = true;
}

/**
 *  @brief:
 */
void Component::hide () {
	this->visible = false;
}

/**
 *  @brief:
 */
void Component::toggleVisibility () {
	this->visible = !visible;
}

/**
 *  @brief:
 */
bool Component::isHidden () {
	return !this->visible;
}

/**
 *  @brief:
 */
bool Component::isVisible () {
	return this->visible;
}

/**
 *  @brief:
 */
void Component::setPosition (double x, double y) {
	this->position = Ruller::gridToPixel (x, y);
}

/**
 *  @brief:
 */
void Component::setPosition (sf::Vector2f point) {
	this->position = Ruller::gridToPixel (point);
}

/**
 *  @brief:
 */
unsigned long Component::size () {
	return this->point.size ();
}

/**
 *  @brief:
 */
void Component::erasePoint (unsigned long index) {
	if (index < this->point.size ()) {
		this->point.erase (this->point.begin () + index);
	}
}

/**
 *  @brief:
 */
void Component::erasePoint (unsigned long first, unsigned long last) {
	if (first < this->point.size () && last < this->point.size ()) {
		this->point.erase (
			this->point.begin () + first,
			this->point.begin () + last
		);
	}
}

/**
 *  @brief:
 */
void Component::addPoint (
	double x, 
	double y, 
	Color color
) {
	x = Ruller::gridToPixel (x);
	y = Ruller::gridToPixel (y);
	this->point.push_back (Vertex (
		Vector2f (
			this->position.x + x, 
			this->position.y + y
			), 
		color
	));
}

/**
 *  @brief:
 */
void Component::addPoint (
	Vector2f position, 
	Color color
) {
	position = Ruller::gridToPixel (position);
	this->point.push_back (Vertex (
		Vector2f (this->position + position), 
		color
	));
}

/**
 *  @brief:
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
 *  @brief:
 */
void Component::addJoint (
	Vector2f position, 
	Color color
) {
	this->addPoint (position, color);
	this->addPoint (position, color);
}

/**
 *  @brief:
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
 *  @brief:
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
 *  @brief:
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
	widthDivision = width / widthDivision;
	heightDivision = height / heightDivision;

	/** Horizontal lines. */
	for (double y = 0; y <= height; y += heightDivision) {
		this->addLine (
			origin.x, 
			origin.y + y,
			origin.x + width, 
			origin.y + y,
			colorGrid
		);
	}

	/** Vertical lines. */
	for (double x = 0; x <= width; x += widthDivision) {
		this->addLine (
			origin.x + x,
			origin.y,
			origin.x + x, 
			origin.y + height,
			colorGrid
		);
	}

	/** Margins. */
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
 *  @brief:
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
 *  @brief:
 */
void Component::addEllipse (
	Color colorGrid,
	Color colorMargin,
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

	/** Lines. */
	for (
		double angle = angleBegin; 
		angle <= angleEnd; 
		angle += angleDivison
	) {
		this->addLine (
		    origin.x,
		    origin.y,
		    origin.x + radiusX * cos (angle * radians),
		    origin.y + radiusY * sin (angle * radians),
		    colorGrid
		);
	}

	/** Circles. */
	for (double div = 1; div <= radiusDivision; div ++) {

		/** Begin of circle. */
		this->addPoint (
		    origin.x + stepX * div * cos (angleBegin * radians),
		    origin.y + stepY * div * sin (angleBegin * radians),
		    colorGrid
		);

		for (
			double angle = angleBegin; 
			angle <= angleEnd; 
			angle += angleDivison / Component::circlePrecision
		)  {
			this->addJoint (
			    origin.x + stepX * div * cos (angle * radians),
			    origin.y + stepY * div * sin (angle * radians),
		    	colorGrid
			);
		}

		/** End of circle. */
		this->addPoint (
		    origin.x + stepX * div * cos (angleEnd * radians),
		    origin.y + stepY * div * sin (angleEnd * radians),
		    colorGrid
		);
	}

	/** Margin. */
	if (margin) {

		/** Begin of circle. */
		this->addPoint (
		    origin.x + radiusX * cos (angleBegin * radians),
		    origin.y + radiusY * sin (angleBegin * radians),
		    colorMargin
		);

		for (
			double angle = angleBegin; 
			angle <= angleEnd; 
			angle += angleDivison / Component::circlePrecision
		)  {
			this->addJoint (
			    origin.x + radiusX * cos (angle * radians),
			    origin.y + radiusY * sin (angle * radians),
		    	colorMargin
			);
		}

		/** End of circle. */
		this->addPoint (
		    origin.x + radiusX * cos (angleEnd * radians),
		    origin.y + radiusY * sin (angleEnd * radians),
		    colorMargin
		);
	}
}

/**
 *  @brief:
 */
void Component::addCircle (
	Color colorGrid,
	Color colorMargin,
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
 *  @brief:
 */
void Component::addEllipseWithHole (
	sf::Color colorGrid,
	sf::Color colorMargin,
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

	/** Lines. */
	for (
		double angle = angleBegin; 
		angle <= angleEnd; 
		angle += angleDivison
	) {
		this->addLine (
		    origin.x + radiusHoleX * cos (angle * radians),
		    origin.y + radiusHoleY * sin (angle * radians),
		    origin.x + radiusX * cos (angle * radians),
		    origin.y + radiusY * sin (angle * radians),
		    colorGrid
		);
	}

	/** Circles. */
	for (double div = 1; div <= radiusDivision; div ++) {

		/** Begin of circle. */
		this->addPoint (
		    origin.x + stepX * div * cos (angleBegin * radians),
		    origin.y + stepY * div * sin (angleBegin * radians),
		    colorGrid
		);

		for (
			double angle = angleBegin; 
			angle <= angleEnd; 
			angle += angleDivison / Component::circlePrecision
		)  {
			this->addJoint (
			    origin.x + stepX * div * cos (angle * radians),
			    origin.y + stepY * div * sin (angle * radians),
		    	colorGrid
			);
		}

		/** End of circle. */
		this->addPoint (
		    origin.x + stepX * div * cos (angleEnd * radians),
		    origin.y + stepY * div * sin (angleEnd * radians),
		    colorGrid
		);
	}

	/** Margin. */
	if (margin) {

		/** Begin of circle. */
		this->addPoint (
		    origin.x + radiusX * cos (angleBegin * radians),
		    origin.y + radiusY * sin (angleBegin * radians),
		    colorMargin
		);

		for (
			double angle = angleBegin; 
			angle <= angleEnd; 
			angle += angleDivison / Component::circlePrecision
		)  {
			this->addJoint (
			    origin.x + radiusX * cos (angle * radians),
			    origin.y + radiusY * sin (angle * radians),
		    	colorMargin
			);
		}

		/** End of circle. */
		this->addPoint (
		    origin.x + radiusX * cos (angleEnd * radians),
		    origin.y + radiusY * sin (angleEnd * radians),
		    colorMargin
		);
	}

}

/**
 *  @brief:
 */
void Component::addCircleWithHole (
	sf::Color colorGrid,
	sf::Color colorMargin,
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
 *  @brief:
 */
Vector2f Component::getPosition () {
	return Ruller::pixelToGrid (this->position);
}

/**
 *  @brief:
 */
Vector2f Component::getPosition (double x, double y) {
	return Ruller::pixelToGrid (this->position) + Vector2f(x, y);
}

/**
 *  @brief:
 */
Vector2f Component::getPosition (Vector2f point) {
	return Ruller::pixelToGrid (this->position) + point;
}

/**
 *  @brief:
 */
Vector2f Component::getPoint (unsigned long i) {
	if (i < this->point.size ()) {
		return Ruller::pixelToGrid (this->point[i].position);
	}
	return Vector2f (-1, -1);
}

/**
 *  @brief:
 */
Vector2f Component::getFirstPoint () {
	return Ruller::pixelToGrid (this->point[0].position);
}

/**
 *  @brief:
 */
Vector2f Component::getLastPoint () {
	if (this->point.size ()) {
		return Ruller::pixelToGrid (
			this->point[this->point.size () - 1].position
		);
	}
	return this->position;
}

/**
 *  @brief:
 */
bool Component::isInRectangle (Vector2f point) {
	return ::isInRectangle (
		this->minim,
		Vector2f (this->minim.x, this->maxim.y),
		Vector2f (this->maxim.x, this->minim.y),
		this->maxim,
		point
	);
}

/**
 *  @brief:
 */
bool Component::isInParalelogram (Vector2f point) {
	return ::isInParalelogram (
		this->minim,
		Vector2f (this->minim.x, this->maxim.y),
		Vector2f (this->maxim.x, this->minim.y),
		this->maxim,
		point
	);
}

/**
 *  @brief:
 */
bool Component::isInCircle (Vector2f point) {
	double radius = 0.5 * min (
		this->maxim.x - this->minim.x, 
		this->maxim.y - this->minim.y
	);

	return ::isInCircle (
		this->position,
		radius,
		point
	);
}

/**
 *  @brief:
 */
bool Component::clickLeft (bool conditionMouseOver) {
	if (conditionMouseOver) {
		this->clickedLeft = sf::Mouse::isButtonPressed (sf::Mouse::Left);
		if (this->clickedLeft) {
			if (clickWaitTime < this->clock.getElapsedTime ().asMilliseconds ()) {
				this->clock.restart ();
				return true;
			}
		}
	}

	return false;
}

/**
 *  @brief:
 */
bool Component::clickRight (bool conditionMouseOver) {
	if (conditionMouseOver) {
		this->clickedRight = sf::Mouse::isButtonPressed (sf::Mouse::Right);
		if (this->clickedRight) {
			if (clickWaitTime < this->clock.getElapsedTime ().asMilliseconds ()) {
				this->clock.restart ();
				return true;
			}
		}
	}

	return false;
}

/**
 *  @brief:
 */
void Component::setRotation (double newAngle) {
	this->rotate (newAngle - this->angle);
}

/**
 *  @brief:
 */
void Component::rotate (double newAngle) {
	double oldX;
	double oldY;
	double newCos = cos (newAngle * radians);
	double newSin = sin (newAngle * radians);

	newAngle = mapAngleInDegrees (newAngle);

	for (unsigned i = 0; i < this->point.size (); i++) {

		/** Translate point to global origin. */
		this->point[i].position.x -= this->position.x;
		this->point[i].position.y -= this->position.y;

		/** Rotate point. */
		oldX = this->point[i].position.x;
		oldY = this->point[i].position.y;
		this->point[i].position.x = newCos * oldX - newSin * oldY;
		this->point[i].position.y = newCos * oldY + newSin * oldX;

		/** Translate point to initial origin. */
		this->point[i].position.x += this->position.x;
		this->point[i].position.y += this->position.y;
	}

	this->angle = mapAngleInDegrees (this->angle + newAngle);
	this->update ();
}

/**
 *  @brief:
 */
double Component::getRotation () {
	return this->angle;
}

/**
 *  @brief:
 */
double Component::getCirclePrecision () {
	return Component::circlePrecision;
}