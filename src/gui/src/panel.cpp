#include "panel.h"

using namespace std;
using namespace sf;
using namespace config;
using namespace mathematics;

/** Components list. */
#define RADAR       this->component[0]
#define PANEL_TRACK this->component[1]
#define SHIP        this->component[2]

/** Labels list. */
#define RADAR_GUIDE this->text[0]

/** Size, margins... */ 
#define MARGIN                 3.0
#define RADAR_RADIUS          15.0
#define RADAR_RADIUS_MINOR    12.0
#define RADAR_RADIUS_MAJOR     3.0
#define RADAR_ANGLE_PRECISION 10.0

/** Test. */
#define DISTANCE_SENSOR_MIN   0.0
#define DISTANCE_SENSOR_MAX 200.0

/**
 *
 */
Panel::Panel (double speedMoveView) {
	this->background.setSize (Vector2f (width, height));
	this->background.setFillColor (COLOR_BACKGROUND);

	this->speedMoveView = speedMoveView;

	this->add (Component (Vector2f (
		MARGIN + RADAR_RADIUS, 
		fromGrid (height) - MARGIN - RADAR_RADIUS
	)));
	this->add (Component ());
	this->add (Component (Vector2f(
			MARGIN + RADAR_RADIUS, 
			fromGrid (height) - MARGIN - RADAR_RADIUS
	)));
	this->add (
		sf::Vector2f (0, 0),
		""
	);
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
	window->draw (this->background);

	for (unsigned i = 0; i < component.size (); i++) {
		this->component[i].render (window);
	}
	for (unsigned i = 0; i < text.size (); i++) {
		window->draw (text[i]);
	}
}

/**
 *
 */
void Panel::move (sf::View *view, double x, double y) {
	config::move (x, y);
	view->move (x, y);
}

/**
 * 
 */
void Panel::update (RenderWindow *window, View *view) {

	Vector2f mousePositionOnGrid = fromGrid (mousePosition ());

	double orientation = translateDegreesToScreen (	getAngleInDegrees (
		toGrid (RADAR.getPosition ()),
		mousePosition ()
	));
	double distanceOnRadar = scaleToInterval (
		DISTANCE (RADAR.getPosition (), mousePositionOnGrid),
		2.0 * RADAR_RADIUS / RADAR_RADIUS_MINOR,
		RADAR_RADIUS,
		DISTANCE_SENSOR_MIN,
		DISTANCE_SENSOR_MAX
	);

	/** View. */
	if (Keyboard::isKeyPressed (Keyboard::A)) {
		this->move (view, -this->speedMoveView, 0.0);
	}
	if (Keyboard::isKeyPressed (Keyboard::D)) {
		this->move (view, this->speedMoveView, 0.0);
	}
	if (Keyboard::isKeyPressed (Keyboard::W)) {
		this->move (view, 0.0, -this->speedMoveView);
	}
	if (Keyboard::isKeyPressed (Keyboard::S)) {
		this->move (view, 0.0, this->speedMoveView);
	}

	/** Radar. */
	if (DISTANCE_SENSOR_MAX >= distanceOnRadar) {
		SHIP.setRotation (getAngleInDegrees (
			RADAR.getPosition (),
			mousePositionOnGrid
		));

		RADAR_GUIDE.setPosition (mousePosition ());

		if (DISTANCE_SENSOR_MIN <= distanceOnRadar) {
			RADAR_GUIDE.setString (
				format (orientation) + SYMBOL_DEGREES + String("\n") +
				format (distanceOnRadar) + SYMBOL_CENTIMETER
			);
			
		}
		else {
			RADAR_GUIDE.setString (
				format (orientation) + SYMBOL_DEGREES + "\n" + 
				config::getNameOfApplication ()
			);
		}
	}
	else {
		RADAR_GUIDE.setString (String (""));
	}
}

/**
 *
 */
void Panel::add (Component component) {
	this->component.push_back (component);
}

/**
 *
 */
void Panel::add (Vector2f position, String string) {
	this->text.push_back (Text ());

	config::text (LAST (this->text, 0), position, string);
}

/**
 *
 */
void Panel::load () {
	RADAR.addCircleWithHole (
		COLOR_GRID_MINOR,
		COLOR_LINE,
		getCirclePrecision (),
		RADAR_RADIUS_MINOR,
		RADAR_RADIUS,
		RADAR_RADIUS / RADAR_RADIUS_MINOR,
		RADAR_ANGLE_PRECISION,
		0.0,
		360.0,
		false
	);
	RADAR.addCircle (
		COLOR_GRID,
		COLOR_LINE,
		getCirclePrecision (), 
		RADAR_RADIUS_MAJOR, 
		RADAR_RADIUS, 
		RADAR_ANGLE_PRECISION * RADAR_RADIUS_MAJOR,
		0.0, 
		360.0
	);
	RADAR.update ();

	for (double angle = 0.0; angle < 360.0; angle += RADAR_ANGLE_PRECISION) {

		this->add (
			RADAR.getPosition () + sf::Vector2f (
				(+ 1.5 + RADAR_RADIUS) * COS (angle),
				(- 1.5 - RADAR_RADIUS) * SIN (angle)
			),
			toString ( (int)angle)
		);

		textCentered (LAST (this->text, 0));
	}

	double panelWidth = fromGrid (width) - 2 * RADAR_RADIUS - 4 * MARGIN;
	panelWidth = floor (panelWidth / (RADAR_RADIUS / RADAR_RADIUS_MAJOR));
	panelWidth *= RADAR_RADIUS / RADAR_RADIUS_MAJOR;

	PANEL_TRACK.setPosition (
		fromGrid (width) - MARGIN - panelWidth, 
		fromGrid (height) - MARGIN - 2 * RADAR_RADIUS
	);

	PANEL_TRACK.addRectangle (
		COLOR_GRID_MINOR,
		COLOR_LINE,
		panelWidth,
		2 * RADAR_RADIUS,
		RADAR_RADIUS / RADAR_RADIUS_MINOR,
		RADAR_RADIUS / RADAR_RADIUS_MINOR,
		false
	);
	PANEL_TRACK.addRectangle (
		COLOR_GRID,
		COLOR_LINE,
		panelWidth,
		2 * RADAR_RADIUS,
		RADAR_RADIUS / RADAR_RADIUS_MAJOR,
		RADAR_RADIUS / RADAR_RADIUS_MAJOR
	);
	PANEL_TRACK.update ();

	SHIP.addEllipse (
		COLOR_GRID,
		COLOR_LINE,
		getCirclePrecision (),
		1.0,
		2.0 * RADAR_RADIUS / RADAR_RADIUS_MINOR,
		RADAR_RADIUS / RADAR_RADIUS_MINOR,
		90.0,
		0.0,
		360.0

	);
	SHIP.addPoint (
		- 0.5 * RADAR_RADIUS / RADAR_RADIUS_MINOR,
		- 0.5 * RADAR_RADIUS / RADAR_RADIUS_MINOR,
		COLOR_LINE
	);
	SHIP.addJoint (
		0.5 * RADAR_RADIUS / RADAR_RADIUS_MINOR,
		0.0,
		COLOR_LINE
	);
	SHIP.addPoint (
		- 0.5 * RADAR_RADIUS / RADAR_RADIUS_MINOR,
		+ 0.5 * RADAR_RADIUS / RADAR_RADIUS_MINOR,
		COLOR_LINE
	);
	SHIP.update ();

	RADAR_GUIDE.setOrigin (0, 2.5 * getGrid ());
}

/**
 *
 */
void Panel::clear () {
	this->component.clear ();
	this->text.clear ();
}