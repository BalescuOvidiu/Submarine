#include "main.h"

using namespace std;
using namespace sf;
using namespace gui;

/**
 * This function check if conditions of exit from
 * applications are true.
 */
bool checkForExit () {
	if (gui::exit) {
		return true;
	}

	// Standard exit
	if (Keyboard::isKeyPressed (Keyboard::Key::Escape)) {
		return true;
	}

	// Linux stop process style
	if (Keyboard::isKeyPressed (Keyboard::Key::LControl)) {
		if (Keyboard::isKeyPressed (Keyboard::Key::C)) {
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

	// Window
	RenderWindow window (
		VideoMode ().getDesktopMode (), 
		name, 
		sf::Style::Fullscreen
	);
	View view (FloatRect (0, 0, width, height));
	window.setFramerateLimit (FRAME_LIMIT);
	window.setView (view);

	gui::initialize ();

	Event event;
	Panel panel (gui::moveViewSpeed);
	panel.load ();

	while (window.isOpen ()) {

		// Event
		while (window.pollEvent (event)) {
			if (event.type == Event::Closed) {
				gui::exit = true;
			}
		}

		// Exit
		if (checkForExit ()) {
			LOG ("Execution of " + name + " ends.");
			gui::log.close ();
			window.close ();
		}

		// Draw		
		window.clear ();

		panel.render (&window);

		panel.update (&window, &view);

		window.display ();
	}
	return 0;
}