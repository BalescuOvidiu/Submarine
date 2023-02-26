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
#include "Utils.h"

#define DEFAULT_CONFIG_FILE_DIRECTORY "config.json"

/**
 * This function run the program. It initializes GUI 
 * objects and data, run execution loop and stop the
 * execution.
 */
int main () {
	json config = getJsonFromFile (DEFAULT_CONFIG_FILE_DIRECTORY);

	Log::initialize ();
	Ruller::initialize ();
	Writer::initialize (config["fontFile"]);
	Component::initialize ();

	Log::write ("Screen size: " + Writer::toString (Ruller::size (), 0, " x ") + ".");
	
	sf::RenderWindow window (
		sf::VideoMode ().getDesktopMode (), 
		sf::String ((std::string)config["windowTitle"]), 
		sf::Style::Fullscreen
	);
	Log::write ("The window is open.");
	if (config["verticalSyncEnabled"]) {
		window.setVerticalSyncEnabled(config["verticalSyncEnabled"]);
		Log::write ("The Vertical Sync is enabled.");
	}
	else {
		window.setFramerateLimit(config["framerate"]);
		Log::write ("The framerate is fixed.");
	}
	sf::View view (
		sf::FloatRect (0, 0, Ruller::width (), Ruller::height ())
	);

	ControlPanel panel (&window, &view);
	panel.loadShip (config["selectedShipFile"]);

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