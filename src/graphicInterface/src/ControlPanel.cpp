/**
 *  ControlPanel.cpp
 * 
 *  Created 15 May 2019
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 26 February 2023
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
	double scale = this->zoomOutLimit;

	this->setSizes (
		-0.5 * Ruller::width () * scale,
		-0.5 * Ruller::height () * scale,
		0.5 * Ruller::width () * scale,
		0.5 * Ruller::height () * scale
	);
	this->open (view);

	/** Ship data */
	this->selectedShip = 0;

	Log::write ("The GUI is initialized.");

	/** Background */
	this->loadBackground (window, view);

	/** Radar guide. */
	Writer::setFont (this->radarGuideText);
	this->radarGuideText.setCharacterSize (this->characterSize);

	/** View. */
	this->move (window, view, 0.0, 0.0);
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

	/** Radar guide. */
	window->draw (this->radarGuideFill);
	window->draw (this->radarGuideText);
}

/**
 *  @brief:
 */
void ControlPanel::move (RenderWindow *window, sf::View *view, double x, double y) {
	double distanceX;
	double distanceY;

	x *= Ruller::getFactor ();
	y *= Ruller::getFactor ();

	if (this->canMove (x, y)) {
		Ruller::move (x, y);
		view->move (x, y);

		this->backgroundFill.setPosition (view->getCenter ());

		distanceX = fabs (Ruller::pixelToGrid (view->getCenter ().x) - this->backgroundGrids.getPosition ().x);
		if (distanceX >= Ruller::getMeterGrid ()) {
			if (Ruller::pixelToGrid (view->getCenter ().x) < this->backgroundGrids.getPosition ().x) {
				distanceX *= -1.0;
			}

			this->backgroundGrids.move (distanceX, 0.0);
			this->backgroundGridsWide.move (distanceX, 0.0);
		}

		distanceY = fabs (Ruller::pixelToGrid (view->getCenter ().y) - this->backgroundGrids.getPosition ().y);
		if (distanceY >= Ruller::getMeterGrid ()) {
			if (Ruller::pixelToGrid (view->getCenter ().y) < this->backgroundGrids.getPosition ().y) {
				distanceY *= -1.0;
			}

			this->backgroundGrids.move (0.0, distanceY);
			this->backgroundGridsWide.move (0.0, distanceY);
		}

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
		this->radarGuideFill.scale (factor, factor);
		this->radarGuideText.scale (factor, factor);
	}
}

/**
 *  @brief:
 */
void ControlPanel::update (RenderWindow *window, View *view) {
	bool mouseOverGui = this->overGui (Ruller::mousePosition ());
	bool mouseOverBackground = !mouseOverGui;

	sf::FloatRect rectangleRadarGuide = radarGuideFill.getLocalBounds ();
	sf::Vector2f positionRadarGuide;
	sf::Vector2f margin = sf::Vector2f (
		this->getMargin () * Ruller::getFactor (),
		- this->getMargin () * Ruller::getFactor ()
	);

	/** Keys events. */
	if (this->canPressKeys ()) {
		/** Move on map. */
		if (Keyboard::isKeyPressed (Keyboard::Left)) {
			this->move (window, view, -Ruller::getViewMoveSpeed (), 0.0);
			keysClock.restart ();
		}
		else if (Keyboard::isKeyPressed (Keyboard::Right)) {
			this->move (window, view, Ruller::getViewMoveSpeed (), 0.0);
			keysClock.restart ();
		}
		if (Keyboard::isKeyPressed (Keyboard::Up)) {
			this->move (window, view, 0.0, -Ruller::getViewMoveSpeed ());
			keysClock.restart ();
		}
		else if (Keyboard::isKeyPressed (Keyboard::Down)) {
			this->move (window, view, 0.0, Ruller::getViewMoveSpeed ());
			keysClock.restart ();
		}

		/** Zoom on map. */
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add) || sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)) {
			this->zoom (window, view, 1.0 / Ruller::getViewZoomSpeed ());
			keysClock.restart ();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract) || sf::Keyboard::isKeyPressed(sf::Keyboard::Hyphen)) {
			this->zoom (window, view, Ruller::getViewZoomSpeed ());
			keysClock.restart ();
		}

		/** Exit. */
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			this->close ();
		}

		/** Control ships. */
		if (this->selectedShip < this->ship.size ()) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
				keysClock.restart ();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
				keysClock.restart ();
			}

			if (Keyboard::isKeyPressed (Keyboard::A)) {
				keysClock.restart ();
			}
			else if (Keyboard::isKeyPressed (Keyboard::D)) {
				keysClock.restart ();
			}

			if (Keyboard::isKeyPressed (Keyboard::W)) {
				keysClock.restart ();
			}
			else if (Keyboard::isKeyPressed (Keyboard::S)) {
				keysClock.restart ();
			}
			if (Keyboard::isKeyPressed (Keyboard::Space)) {
				keysClock.restart ();
			}
		}
	}

	if (this->selectedShip < this->ship.size ()) {
		if (this->backgroundGrids.clickLeft (true)) {
			this->ship[this->selectedShip].setRotation (getAngleInDegrees (
				this->ship[this->selectedShip].getPosition (),
				Ruller::mousePositionGrid ()
			));
		}
	}

	/** Background. */
	if (Ruller::getFactor () < this->zoomOutLimit * 0.5) {
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

	/** Ships. */
	for (unsigned i = 0; i < this->ship.size(); i++) {
		this->ship[i].update ();

		if (mouseOverBackground) {
			if (this->ship[i].mouseOver ()) {
				this->radarGuideText.setString (this->ship[i].getGuideText ());
				mouseOverBackground = false;
			}
		}
	}

	if (mouseOverBackground) {
		this->radarGuideText.setString (Writer::toString (Ruller::mousePositionMeter () - Ruller::centerMeter ()));
	}

	/** Radar guide */
	positionRadarGuide = Ruller::mousePosition ();
	this->radarGuideFill.setSize (sf::Vector2f (
		this->radarGuideText.getLocalBounds ().width + 2.0 * this->getMargin (),
		this->radarGuideText.getLocalBounds ().height + 2.0 * this->getMargin ()
	));
	this->radarGuideFill.setPosition (positionRadarGuide);
	this->radarGuideFill.setOrigin (
		rectangleRadarGuide.left,
   		rectangleRadarGuide.top + rectangleRadarGuide.height
   	);
	this->radarGuideText.setPosition (positionRadarGuide + margin);
	Writer::alignLeftBottom (this->radarGuideText);

	if (!mouseOverGui) {

		this->radarGuideFill.setFillColor (COLOR_LABEL);
		this->radarGuideText.setFillColor (COLOR_TEXT);
	}
	else {
		this->radarGuideText.setFillColor (COLOR_TRANSPARENT);
		this->radarGuideFill.setFillColor (COLOR_TRANSPARENT);
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
		sf::Vector2f (- backgroundWidth * 0.5, - backgroundHeight * 0.5)
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
		sf::Vector2f (- backgroundWidth * 0.5, - backgroundHeight * 0.5)
	);
	this->backgroundGridsWide.update ();
}

/**
 *  @brief:
 */
void ControlPanel::loadShip (std::string directory) {
	this->ship.push_back (Ship (directory));

	if(this->ship.back ().isOpen ()) {
		Log::write ("The data for the ship " + this->ship.back ().getName () + " is loaded.");
	}
	else {
		Log::write ("The data for the ship can't be loaded!");
	}
}

/**
 *  @brief:
 */
void ControlPanel::close () {
	this->on = false;
}

/**
 *  @brief:
 */
bool ControlPanel::overGui (sf::Vector2f point) {
	return false;
}