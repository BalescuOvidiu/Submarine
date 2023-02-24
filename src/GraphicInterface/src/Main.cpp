/**
 *  Main.h
 * 
 *  Created 15 May 2019
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 22 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#include "Log.h"
#include "Ruller.h"
#include "Writer.h"

#include "ControlPanel.h"

#define DEFAULT_WINDOW_TITLE "Controller Software - Metere Submarine Class"
#define DEFAULT_FONT_FILE    "data/fonts/Verdana.ttf"
#define DEFAULT_SHIP_FILE    "data/ships/ME-212.txt"

#define DEFAULT_FRAMERATE_LIMIT       60
#define DEFAULT_VERTICAL_SYNC_ENABLED true

/**
 * This function run the program. It initializes GUI 
 * objects and data, run execution loop and stop the
 * execution.
 */
int main () {
	Log::initialize ();
	Ruller::initialize ();
	Writer::initialize (DEFAULT_FONT_FILE);
	Component::initialize ();

	Log::write ("Screen size: " + Writer::toString (Ruller::width ()) + " x " + Writer::toString (Ruller::height ()));
	
	sf::RenderWindow window (
		sf::VideoMode ().getDesktopMode (), 
		DEFAULT_WINDOW_TITLE, 
		sf::Style::Fullscreen
	);
	window.setFramerateLimit(DEFAULT_FRAMERATE_LIMIT);
	window.setVerticalSyncEnabled(DEFAULT_VERTICAL_SYNC_ENABLED);
	sf::View view (
		sf::FloatRect (0, 0, Ruller::width (), Ruller::height ())
	);

	ControlPanel panel (&window, &view);
	panel.loadShip (DEFAULT_SHIP_FILE);

	while (window.isOpen ()) {

		/** Event */
		sf::Event event;
		while (window.pollEvent (event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		/** Draw. */
		window.clear ();

		panel.render (&window);
		panel.update (&window, &view);

		window.display ();

		/** Check for the close */
		if (panel.isClosed ()) {
			window.close ();
		}
	}

	/** Closing */
	Log::write ("Close!");
	Log::close();

	return EXIT_SUCCESS;
}