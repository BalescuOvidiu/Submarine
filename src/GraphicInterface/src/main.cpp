#include "main.h"

using namespace std;

/**
 * This function check if conditions of exit from
 * applications are true.
 */
bool checkForExit () {
	if (config::canExit ()) {
		return true;
	}

	/** Standard exit. */
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Escape)) {
		config::exit ();
		return true;
	}

	/** Linux stop process style. */
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::LControl)) {
		if (sf::Keyboard::isKeyPressed (sf::Keyboard::C)) {
			config::exit ();
			return true;
		}
	}

	return false;
}

/**
 * This function run the program. It initializes GUI 
 * objects and data, run execution loop and stop the
 * execution.
 */
int main () {
	config::initialize ();

	sf::RenderWindow window (
		sf::VideoMode ().getDesktopMode (), 
		config::getNameOfApplication (), 
		sf::Style::Fullscreen
	);
	sf::View view (
		sf::FloatRect (
			0, 
			0, 
			config::getWidth (), 
			config::getHeight ()
		)
	);

	Panel panel (config::getMoveViewSpeed ());

	sf::Event event;


	window.setFramerateLimit (config::getFrameRate ());
	window.setView (view);

	panel.load ();

	while (window.isOpen ()) {

		/** Event */
		while (window.pollEvent (event)) {
			if (event.type == sf::Event::Closed) {
				config::exit ();
			}
		}

		/** Exit. */
		if (checkForExit ()) {
			window.close ();
		}

		/** Draw. */
		window.clear ();

		panel.render (&window);
		panel.update (&window, &view);

		window.display ();
	}
	return EXIT_SUCCESS;
}