/**
 *  Panel.cpp
 * 
 *  Created 15 May 2019
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 25 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#include "Panel.h"

using namespace std;
using namespace sf;

/** Files. */
#define FILE_SUBMARINE "data/submarine.txt"

/** Size, margins, position macros. */ 
#define MARGIN                 3.0

#define RADAR_RADIUS          15.0
#define RADAR_RADIUS_MINOR    12.0
#define RADAR_RADIUS_MAJOR     3.0
#define RADAR_RADIUS_MAX       4.0
#define RADAR_RADIUS_RATE      2.0

#define RADAR_ANGLE_PRECISION 10.0

/** Measurement */
#define RADAR_SHIP_GRID        3.0
#define RADAR_SHIP_ANGLE      30.0

#define UNIT_SPEED    SYMBOL_M_PER_SECOND
#define UNIT_DISTANCE SYMBOL_CENTIMETER

/**
 *
 */
Panel::Panel (double speedMoveView) {
	ifstream in (FILE_SUBMARINE);

	this->background.setSize (Vector2f (getWidth (), getHeight ()));
	this->background.setFillColor (COLOR_BACKGROUND);

	this->speedMoveView = speedMoveView;

	/** Read data about ship. */
	if (in.is_open ()) {
		in>>this->ship.lengthHull;
		in>>this->ship.radiusHull;

		in>>this->ship.radiusPlane;

		in>>this->ship.radiusBack;

		in>>this->ship.positionBodyNavigation;
		in>>this->ship.radiusXBodyNavigation;
		in>>this->ship.radiusYBodyNavigation;

		in>>this->ship.distanceSensorMin;
		in>>this->ship.distanceSensorMax;

		in>>this->ship.positionInertialDevice;
	}
	else {
		logMessage ("Data of submarine wasn't loaded!");

		this->ship.lengthHull = 0.0;
		this->ship.radiusHull = 0.0;

		this->ship.radiusPlane = 0.0;

		this->ship.radiusBack = 0.0;

		this->ship.positionBodyNavigation = 0.0;
		this->ship.radiusXBodyNavigation = 0.0;
		this->ship.radiusYBodyNavigation = 0.0;

		this->ship.distanceSensorMin = 0.0;
		this->ship.distanceSensorMax = 0.0;
		
		this->ship.positionInertialDevice = 0.0;
	}

	this->ship.orientation = ANGLE_MIN;
	this->radarRadius = this->ship.distanceSensorMax;

	in.close ();

	/** Components. */
	this->radar = Component (
		sf::Lines, 
		Vector2f (
			MARGIN + RADAR_RADIUS, 
			getHeightGrid () - MARGIN - RADAR_RADIUS
		)
	);
	this->panelTrack = Component (
		sf::Lines
	);
	this->ship.body = Component (
		sf::Lines, 
		Vector2f(
			MARGIN + RADAR_RADIUS, 
			getHeightGrid () - MARGIN - RADAR_RADIUS
		)
	);

	/** Text. */
	config::text (this->radarGuide, ORIGIN, string (""));
}

/**
 *
 */
Panel::~Panel () {
	this->clear ();
}

/**
 *
 */
void Panel::render (RenderWindow *window) {

	/** Background. */
	window->draw (this->background);

	/** Components. */
	this->radar.render (window);
	this->panelTrack.render (window);
	this->ship.body.render (window);

	/** Text. */
	for (unsigned i = 0; i < radarText.size (); i++) {
		window->draw (radarText[i]);
	}
	window->draw (this->radarGuide);
}

/**
 *
 */
void Panel::move (RenderWindow *window, sf::View *view, double x, double y) {
	config::move (x, y);

	this->background.move (x, y);

	view->move (x, y);
	window->setView (*view);
}

/**
 * 
 */
void Panel::update (RenderWindow *window, View *view) {

	double orientation = translateDegreesToScreen (	getAngleInDegrees (
		toGrid (this->radar.getPosition ()),
		mousePosition ()
	));
	double distanceOnRadar = scaleFromRadar (
		DISTANCE (this->radar.getPosition (), mousePositionOnGrid ())
	);

	/** Keys events. */
	if (canClick (KEY_TIMEOUT)) {
		if (Keyboard::isKeyPressed (Keyboard::A)) {
			this->move (window, view, -this->speedMoveView, 0.0);
			restartClick ();
		}
		if (Keyboard::isKeyPressed (Keyboard::D)) {
			this->move (window, view, this->speedMoveView, 0.0);
			restartClick ();
		}
		if (Keyboard::isKeyPressed (Keyboard::W)) {
			this->move (window, view, 0.0, -this->speedMoveView);
			restartClick ();
		}
		if (Keyboard::isKeyPressed (Keyboard::S)) {
			this->move (window, view, 0.0, this->speedMoveView);
			restartClick ();
		}

		if (Keyboard::isKeyPressed (Keyboard::Q)) {
			if (this->ship.totalLength < this->radarRadius) {
				this->setRadarRadius (this->radarRadius - RADAR_RADIUS_RATE);
				restartClick ();
			}
		}
		else if (Keyboard::isKeyPressed (Keyboard::E)) {
			if (this->ship.totalLength * RADAR_RADIUS_MAX > this->radarRadius) {
				this->setRadarRadius (radarRadius + RADAR_RADIUS_RATE);
				restartClick ();
			}
		}
	}

	/** Radar. */
	if (this->radarRadius >= distanceOnRadar) {
		this->radarGuide.setFillColor (COLOR_TEXT);

		this->radarGuide.setPosition (mousePosition ());

		if (this->ship.body.isInRectangle (mousePosition ())) {
			this->radarGuide.setString (
				config::getNameOfApplication () + String("\n") +
				format (translateDegreesToScreen (this->ship.body.getRotation ())) + SYMBOL_DEGREES  + String("\n") +
				format (this->ship.speed) + UNIT_SPEED			
			);
			this->radarGuide.setOrigin (0, 3.5 * getGrid ());
		}
		else {
			this->radarGuide.setString (
				format (orientation) + SYMBOL_DEGREES + String("\n") +
				format (distanceOnRadar) + UNIT_DISTANCE
			);
			this->radarGuide.setOrigin (0, 2.5 * getGrid ());
		}

		if (this->radar.left (true)) {
			this->setOrientationOfShip (getAngleInDegrees (
				this->radar.getPosition (),
				mousePositionOnGrid ()
			));
		}
	}
	else {
		this->radarGuide.setFillColor (COLOR_TRANSPARENT);
	}
}

/**
 *
 */
void Panel::clear () {
	this->radarText.clear ();
}


/**
 *
 */
void Panel::setRadarRadius (double radius) {
	this->radarRadius = radius;
	this->loadRadar ();
	this->loadShip ();

	this->ship.body.setRotation (this->ship.orientation);
}
/**
 *
 */
void Panel::load () {
	this->loadPanelTrack ();	
	this->loadRadar ();
	this->loadShip ();
	this->loadTextRadar ();
}

void Panel::loadPanelTrack () {
	double panelWidth = getWidthGrid () - 2 * RADAR_RADIUS - 4 * MARGIN;
	
	panelWidth = floor (panelWidth / (RADAR_RADIUS / RADAR_RADIUS_MAJOR));
	panelWidth *= RADAR_RADIUS / RADAR_RADIUS_MAJOR;

	panelTrack.setPosition (
		getWidthGrid () - MARGIN - panelWidth, 
		getHeightGrid () - MARGIN - 2 * RADAR_RADIUS
	);

	panelTrack.addRectangle (
		COLOR_GRID_MINOR,
		COLOR_LINE,
		panelWidth,
		2 * RADAR_RADIUS,
		RADAR_RADIUS / RADAR_RADIUS_MINOR,
		RADAR_RADIUS / RADAR_RADIUS_MINOR,
		false
	);
	panelTrack.addRectangle (
		COLOR_GRID,
		COLOR_LINE,
		panelWidth,
		2 * RADAR_RADIUS,
		RADAR_RADIUS / RADAR_RADIUS_MAJOR,
		RADAR_RADIUS / RADAR_RADIUS_MAJOR
	);
	panelTrack.update ();	
}

void Panel::loadRadar () {
	this->radar.clear ();

	this->radar.addCircleWithHole (
		COLOR_GRID_MINOR,
		COLOR_LINE,
		getCirclePrecision (),
		RADAR_RADIUS_MINOR,
		RADAR_RADIUS,
		RADAR_RADIUS / RADAR_RADIUS_MINOR,
		RADAR_ANGLE_PRECISION,
		ANGLE_MIN,
		ANGLE_MAX,
		false
	);
	this->radar.addCircle (
		COLOR_GRID,
		COLOR_LINE,
		getCirclePrecision (), 
		RADAR_RADIUS_MAJOR, 
		RADAR_RADIUS, 
		RADAR_ANGLE_PRECISION * RADAR_RADIUS_MAJOR,
		ANGLE_MIN, 
		ANGLE_MAX
	);
	this->radar.update ();
}

/**
 *
 */
void Panel::loadShip () {
	/** Submarine image. */
	Submarine canvas;

	canvas.lengthHull = scaleToRadar (this->ship.lengthHull);
	canvas.radiusHull = scaleToRadar (this->ship.radiusHull);
	
	canvas.radiusPlane = scaleToRadar (this->ship.radiusPlane);
	
	canvas.radiusBack = scaleToRadar (this->ship.radiusBack);
	
	canvas.positionBodyNavigation = scaleToRadar (this->ship.positionBodyNavigation);
	canvas.radiusXBodyNavigation  = scaleToRadar (this->ship.radiusXBodyNavigation);
	canvas.radiusYBodyNavigation  = scaleToRadar (this->ship.radiusYBodyNavigation);
	
	this->ship.totalLength = this->ship.lengthHull + this->ship.radiusHull + this->ship.radiusBack;

	this->ship.body.clear ();
	this->ship.body.setRotation (ANGLE_MIN);

	/** Planes. */	
	this->ship.body.addCircle (
		COLOR_GRID,
		COLOR_LINE,
		getCirclePrecision (),
		RADAR_SHIP_GRID,
		canvas.radiusPlane,
		RADAR_SHIP_ANGLE,
		ANGLE_MIDDLE,
		ANGLE_MAX,
		true,
		Vector2f (
			-0.5 * canvas.lengthHull,
			-canvas.radiusHull
		)
	);
	this->ship.body.addCircle (
		COLOR_GRID,
		COLOR_LINE,
		getCirclePrecision (),
		RADAR_SHIP_GRID,
		canvas.radiusPlane,
		RADAR_SHIP_ANGLE,
		ANGLE_MIN,
		ANGLE_MIDDLE,
		true,
		Vector2f (
			-0.5 * canvas.lengthHull,
			canvas.radiusHull
		)
	);
	this->ship.body.addCircle (
		COLOR_GRID,
		COLOR_LINE,
		getCirclePrecision (),
		RADAR_SHIP_GRID,
		canvas.radiusPlane,
		RADAR_SHIP_ANGLE,
		ANGLE_MIDDLE,
		ANGLE_MAX,
		true,
		Vector2f (
			0.5 * canvas.lengthHull + canvas.radiusHull - canvas.positionBodyNavigation,
			-canvas.radiusHull
		)
	);
	this->ship.body.addCircle (
		COLOR_GRID,
		COLOR_LINE,
		getCirclePrecision (),
		RADAR_SHIP_GRID,
		canvas.radiusPlane,
		RADAR_SHIP_ANGLE,
		ANGLE_MIN,
		ANGLE_MIDDLE,
		true,
		Vector2f (
			0.5 * canvas.lengthHull + canvas.radiusHull - canvas.positionBodyNavigation,
			canvas.radiusHull
		)
	);

	/** Hull. */
	this->ship.body.addRectangle (
		COLOR_GRID,
		COLOR_LINE,
		canvas.lengthHull,
		2.0 * canvas.radiusHull,
		0.5 * canvas.lengthHull / RADAR_SHIP_GRID,
		canvas.radiusHull / RADAR_SHIP_GRID,
		false,
		Vector2f (
			-0.5 * canvas.lengthHull,
			-canvas.radiusHull
		)
	);
	this->ship.body.addLine (
		- 0.5 * canvas.lengthHull,
		canvas.radiusHull,
		0.5 * canvas.lengthHull,
		canvas.radiusHull,
		COLOR_LINE
	);
	this->ship.body.addLine (
		- 0.5 * canvas.lengthHull,
		- canvas.radiusHull,
		0.5 * canvas.lengthHull,
		- canvas.radiusHull,
		COLOR_LINE
	);
	this->ship.body.addCircle (
		COLOR_GRID,
		COLOR_LINE,
		getCirclePrecision (),
		RADAR_SHIP_GRID,
		canvas.radiusHull,
		RADAR_SHIP_ANGLE,
		ANGLE_MIN, 
		ANGLE_RIGHT,
		true,
		Vector2f (
			0.5 * canvas.lengthHull,
			0.0
		)
	);
	this->ship.body.addCircle (
		COLOR_GRID,
		COLOR_LINE,
		getCirclePrecision (),
		RADAR_SHIP_GRID,
		canvas.radiusHull,
		RADAR_SHIP_ANGLE,
		ANGLE_MAX - ANGLE_RIGHT,
		ANGLE_MAX,
		true,
		Vector2f (
			0.5 * canvas.lengthHull,
			0.0
		)
	);
	this->ship.body.addEllipse (
		COLOR_GRID,
		COLOR_LINE,
		getCirclePrecision (),
		RADAR_SHIP_GRID,
		canvas.radiusBack,
		canvas.radiusHull,
		RADAR_SHIP_ANGLE,
		ANGLE_RIGHT,
		ANGLE_MAX - ANGLE_RIGHT,
		true,
		Vector2f (
			-0.5 * canvas.lengthHull,
			0.0
		)
	);

	/** Navigation body. */
	this->ship.body.addEllipse (
		COLOR_GRID,
		COLOR_LINE,
		getCirclePrecision (),
		RADAR_SHIP_GRID,
		canvas.radiusYBodyNavigation,
		canvas.radiusXBodyNavigation,
		RADAR_SHIP_ANGLE,
		ANGLE_MIN,
		ANGLE_MAX,
		true,
		Vector2f (
			0.5 * canvas.lengthHull + canvas.radiusHull - canvas.positionBodyNavigation,
			0.0
		)
	);

	/** Up rudder. */
	this->ship.body.addLine (
		- 0.5 * canvas.lengthHull - canvas.radiusPlane,
		0.0,
		- 0.5 * canvas.lengthHull + canvas.radiusPlane,
		0.0,
		COLOR_LINE
	);

	/** Position of inertial device */
	this->ship.body.movePoints (
		- 0.5 * canvas.lengthHull - canvas.radiusHull + canvas.positionBodyNavigation,
		0.0
	);

	this->ship.body.update ();
}

/**
 *
 */
void Panel::loadTextRadar () {
	Vector2f position;

	this->radarText.clear ();

	for (
		double angle = ANGLE_MIN; 
		angle < ANGLE_MAX; 
		angle += RADAR_ANGLE_PRECISION
	) {
		this->radarText.push_back (sf::Text ());

		position = this->radar.getPosition () + Vector2f (
			(+ 1.5 + RADAR_RADIUS) * COS (angle),
			(- 1.5 - RADAR_RADIUS) * SIN (angle)
		);

		text (LAST (this->radarText, 0 ), position, toString ( (int)angle));
		textCentered (LAST (this->radarText, 0));
	}
}

/**
 *
 */
double Panel::scaleToRadar (double value) {
	return scaleToInterval (
		value,
		0,
		radarRadius,
		0,
		RADAR_RADIUS
	);
}

/**
 *
 */
double Panel::scaleFromRadar (double value) {
	return scaleToInterval (
		value,
		0,
		RADAR_RADIUS,
		0,
		radarRadius
	);
}

/**
 *
 */
void Panel::setOrientationOfShip (double angle) {
	this->ship.orientation = angle;
	this->ship.body.setRotation (angle);
}