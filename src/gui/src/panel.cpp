#include "panel.h"

// Namespaces
using namespace std;
using namespace sf;
using namespace gui;

// Components
#define RADAR this->component[0]

/**
 *
 */
Panel::Panel () {
	this->background.setSize (Vector2f (width, height));
	this->background.setFillColor (COLOR_BACKGROUND);
	this->add (circleRadar (Vector2f (12, height / grid - 12), 10, 48, 32, 5));
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
	view->move (x, y);
}

/**
 *
 */
void Panel::update (RenderWindow *window, View *view) {
	// View
	if (Keyboard::isKeyPressed (Keyboard::A)) {
		this->move (view, -10, 0);
	}
	if (Keyboard::isKeyPressed (Keyboard::D)) {
		this->move (view, 10, 0);
	}
	if (Keyboard::isKeyPressed (Keyboard::W)) {
		this->move (view, 0, -10);
	}
	if (Keyboard::isKeyPressed (Keyboard::S)) {
		this->move (view, 0, 10);
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
	position.x *= grid;
	position.y *= grid;
	Text a;
	gui::text (a, Vector2f (position), string);
	this->text.push_back (a);
}

/**
 *
 */
void Panel::load () {

}

/**
 *
 */
void Panel::clear () {
	this->component.clear ();
	this->text.clear ();
}