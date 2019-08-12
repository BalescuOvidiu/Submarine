#include "panel.h"

using namespace std;
using namespace sf;
using namespace gui;

/**
 * This function run the program. It initializes GUI 
 * objects and data, run execution loop and stop the
 * execution.
 */
int main () {

	// Objects
	Panel panel;
	Event event;

	// Window
	RenderWindow window (
		VideoMode ().getDesktopMode (), 
		NAME, 
		sf::Style::Fullscreen
	);
	View view (FloatRect (0, 0, width, height));
	window.setFramerateLimit (60);
	window.setView (view);

	gui::initialize ();

	while (window.isOpen ()) {
		// Event
		while (window.pollEvent (event)) {
			if (event.type == Event::Closed) {
				window.close ();
			}
		}
		// Exit
		if (Keyboard::isKeyPressed (Keyboard::Key::Escape)) {
			LOG ("Execution of " << NAME << " end at " << __DATE__ << " " << __TIME__ << ".");
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