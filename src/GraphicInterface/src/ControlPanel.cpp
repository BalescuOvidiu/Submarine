/**
 *  ControlPanel.cpp
 * 
 *  Created 15 May 2019
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 22 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#include "Ruller.h"
#include "Log.h"
#include "Mathematics.h"
#include "ControlPanel.h"
#include "Writer.h"

using namespace std;
using namespace sf;

/**
 *  @brief:
 */
ControlPanel::ControlPanel (
	sf::RenderWindow *window, 
	sf::View *view
) {
	this->setSizes ();
	this->open (view);

	Log::write ("GUI initialized!");

	/** Background */
	this->loadBackground (window, view);

	/** Text. */
	Writer::setFont (this->radarGuide);
	this->radarGuide.setFillColor (COLOR_TRANSPARENT);
	this->radarGuide.setCharacterSize (this->characterSize);

	/** Ship data */
	this->selectedShip = 0;

	this->move (window, view, 0, 0);
}

/**
 *  @brief:
 */
ControlPanel::~ControlPanel () {

}

/**
 *  @brief:
 */
void ControlPanel::render (RenderWindow *window) {

	/** Background. */
	window->draw (this->backgroundFill);
	this->backgroundGrids.render (window);
	this->backgroundGridsWide.render (window);

	/** Ships. */
	for (auto s = ship.begin(); s != ship.end(); s++) {
		s->render (window);
	}

	/** Text. */
	window->draw (this->radarGuide);
}

/**
 *  @brief:
 */
void ControlPanel::move (RenderWindow *window, sf::View *view, double x, double y) {
	x *= Ruller::getFactor ();
	y *= Ruller::getFactor ();

	if (this->canMove (x, y)) {
		Ruller::move (x, y);
		view->move (x, y);

		this->backgroundFill.setPosition (view->getCenter ());
		this->backgroundGrids.setPosition (view->getCenter ());

		window->setView (*view);
	}
}

/**
 *  @brief:
 */
void ControlPanel::zoom (RenderWindow *window, sf::View *view, float factor) {
	if (this->canZoom (factor)) {
		Ruller::zoom (factor);
		view->zoom (factor);
		window->setView (*view);
		this->backgroundFill.scale (factor, factor);
		this->backgroundFill.setPosition (view->getCenter ());
		this->radarGuide.scale (factor, factor);
	}
}

/**
 *  @brief:
 */
void ControlPanel::update (RenderWindow *window, View *view) {

	/** Keys events. */
	if (this->canPressKeys ()) {
		if (Keyboard::isKeyPressed (Keyboard::A) && !Keyboard::isKeyPressed (Keyboard::D)) {
			this->move (window, view, -Ruller::getViewMoveSpeed (), 0.0);
			keysClock.restart ();
		}
		if (Keyboard::isKeyPressed (Keyboard::D) && !Keyboard::isKeyPressed (Keyboard::A)) {
			this->move (window, view, Ruller::getViewMoveSpeed (), 0.0);
			keysClock.restart ();
		}
		if (Keyboard::isKeyPressed (Keyboard::W) && !Keyboard::isKeyPressed (Keyboard::S)) {
			this->move (window, view, 0.0, -Ruller::getViewMoveSpeed ());
			keysClock.restart ();
		}
		if (Keyboard::isKeyPressed (Keyboard::S) && !Keyboard::isKeyPressed (Keyboard::W)) {
			this->move (window, view, 0.0, Ruller::getViewMoveSpeed ());
			keysClock.restart ();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
			this->zoom (window, view, 1 / Ruller::getViewZoomSpeed ());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			this->zoom (window, view, Ruller::getViewZoomSpeed ());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			this->close ();
		}
	}

	/** Background */
	if (Ruller::getFactor () < this->zoomOutLimit / 2) {
		if (this->backgroundGrids.isHidden ()) {
			for (unsigned long i = 0; i < this->backgroundGridsWide.size(); i++) {
				this->backgroundGridsWide[i].color = COLOR_GRID_BIG;
			}
		}
		this->backgroundGrids.show ();
	}
	else {
		if (this->backgroundGrids.isVisible ()) {
			for (unsigned long i = 0; i < this->backgroundGridsWide.size(); i++) {
				this->backgroundGridsWide[i].color = COLOR_GRID_SMALL;
			}			
		}
		this->backgroundGrids.hide ();
	}

	/** Ships */
	for (unsigned i = 0; i < this->ship.size(); i++) {
		this->ship[i].update ();
	}
	if (this->selectedShip < this->ship.size ()) {
		if (this->ship[this->selectedShip].mouseOver ()) {
			this->radarGuide.setPosition (Ruller::mousePosition ());
			Writer::alignLeftBottom (this->radarGuide);
			this->radarGuide.setString (this->ship[this->selectedShip].getGuideText ());
			this->radarGuide.setFillColor (COLOR_TEXT);
		}
		else {
			this->radarGuide.setFillColor (COLOR_TRANSPARENT);
		}
		if (this->backgroundGrids.clickLeft (true)) {
			this->ship[this->selectedShip].setRotation (getAngleInDegrees (
				this->ship[this->selectedShip].getPosition (),
				Ruller::mousePositionGrid ()
			));
		}
	}
}

/**
 *  @brief:
 */
void ControlPanel::loadBackground (sf::RenderWindow *window, sf::View *view) {
	double backgroundWidth = this->getWidthGrid ();
	double backgroundHeight = this->getHeightGrid ();

	this->backgroundFill.setOrigin (Ruller::center());
	this->backgroundFill.setSize (Ruller::size ());
	this->backgroundFill.setFillColor (COLOR_BACKGROUND);

	this->backgroundGrids = Component (
		sf::Lines, 
		Ruller::centerGrid ()
	);
	this->backgroundGrids.addRectangle (
		COLOR_GRID_SMALL,
		COLOR_LINE,
		backgroundWidth,
		backgroundHeight,
		backgroundWidth,
		backgroundHeight,
		false,
		sf::Vector2f (- backgroundWidth / 2, - backgroundHeight / 2)
	);
	this->backgroundGrids.update ();

	this->backgroundGridsWide = Component (
		sf::Lines, 
		Ruller::centerGrid ()
	);
	this->backgroundGridsWide.addRectangle (
		COLOR_GRID_BIG,
		COLOR_LINE,
		backgroundWidth,
		backgroundHeight,
		Ruller::gridToMeter (backgroundWidth),
		Ruller::gridToMeter (backgroundHeight),
		false,
		sf::Vector2f (- backgroundWidth / 2, - backgroundHeight / 2)
	);
	this->backgroundGridsWide.update ();
}

/**
 *  @brief:
 */
void ControlPanel::loadShip (std::string directory) {
	this->ship.push_back (Ship (directory));
	if(this->ship.back ().isOpen ()) {
		Log::write ("Data for the ship " + this->ship.back ().getName () + " is loaded!");
	}
	else {
		Log::write ("Data for the ship can't be loaded!");
	}
}

/**
 *  @brief:
 */
void ControlPanel::close () {
	this->on = false;
}