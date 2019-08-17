#include "panel.h"

using namespace std;
using namespace sf;
using namespace gui;

// Components list
#define RADAR       this->component[0]
#define PANEL_TRACK this->component[1]
#define SHIP        this->component[2]

// Size, margins... 
#define MARGIN                 3.0
#define RADAR_RADIUS          15.0
#define RADAR_ANGLE_PRECISION 15.0

/**
 *
 */
Panel::Panel (double speedMove) {
	this->background.setSize (Vector2f (width, height));
	this->background.setFillColor (COLOR_BACKGROUND);

	this->speedMove = speedMove;

	this->add (Component (Vector2f (
		MARGIN + RADAR_RADIUS, 
		fromGrid (height) - MARGIN - RADAR_RADIUS
	)));
	this->add (Component (Vector2f (
		3 * MARGIN + 2 * RADAR_RADIUS, 
		fromGrid (height) - MARGIN - 2 * RADAR_RADIUS
	)));
	this->add (Component (
		Vector2f(
			MARGIN + RADAR_RADIUS, 
			fromGrid (height) - MARGIN - RADAR_RADIUS
		),
		sf::TriangleStrip

	));
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
	gui::move (x, y);
	view->move (x, y);
}

/**
 * 
 */
void Panel::update (RenderWindow *window, View *view) {
	// View
	if (Keyboard::isKeyPressed (Keyboard::A)) {
		this->move (view, -this->speedMove, 0);
	}
	if (Keyboard::isKeyPressed (Keyboard::D)) {
		this->move (view, this->speedMove, 0);
	}
	if (Keyboard::isKeyPressed (Keyboard::W)) {
		this->move (view, 0, -this->speedMove);
	}
	if (Keyboard::isKeyPressed (Keyboard::S)) {
		this->move (view, 0, this->speedMove);
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

	gui::text (LAST (this->text, 0), position, string);
}

/**
 *
 */
void Panel::load () {
	RADAR.addCircle (
		COLOR_GRID_MINOR,
		COLOR_LINE,
		circlePrecision,
		12.0,
		RADAR_RADIUS,
		RADAR_ANGLE_PRECISION,
		0.0,
		360.0,
		false
	);
	RADAR.addCircle (
		COLOR_GRID,
		COLOR_LINE,
		circlePrecision, 
		3.0, 
		RADAR_RADIUS, 
		3.0 * RADAR_ANGLE_PRECISION,
		0.0, 
		360.0
	);
	RADAR.update ();

	for (unsigned angle = 0; angle < 360; angle += 15) {

		this->add (
			RADAR.getPosition () + sf::Vector2f (
				(1 + RADAR_RADIUS) * COS (angle),
				(- 1 - RADAR_RADIUS) * SIN (angle)
			),
			std::to_string (angle)
		);

		textCenter (LAST (this->text, 0));
	}

	PANEL_TRACK.addRectangle (
		COLOR_GRID_MINOR,
		COLOR_LINE,
		fromGrid (width) - 2 * RADAR_RADIUS - 4 * MARGIN,
		2 * RADAR_RADIUS,
		RADAR_RADIUS / 12.0,
		RADAR_RADIUS / 12.0,
		false
	);
	PANEL_TRACK.addRectangle (
		COLOR_GRID,
		COLOR_LINE,
		fromGrid (width) - 2 * RADAR_RADIUS - 4 * MARGIN,
		2 * RADAR_RADIUS,
		RADAR_RADIUS / 3.0,
		RADAR_RADIUS / 3.0
	);
	PANEL_TRACK.update ();

	SHIP.addCircle (
		COLOR_BACKGROUND,
		COLOR_LINE,
		circlePrecision,
		1.0,
		RADAR_RADIUS / 13,
		RADAR_ANGLE_PRECISION,
		0.0,
		360.0,
		false

	);
	SHIP.update ();
}

/**
 *
 */
void Panel::clear () {
	this->component.clear ();
	this->text.clear ();
}