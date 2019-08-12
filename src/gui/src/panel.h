#ifndef PANEL_H
#define PANEL_H

#define NAME "UB-FMI-212"

#include "button.h"
#include "component.h"

class Panel {

	public:
		Panel();

		~Panel();

		void render(sf::RenderWindow *window);
		void move(sf::View *view, double x, double y);
		void update(
			sf::RenderWindow *window, 
			sf::View *view
		);


	private:
		// Background
		sf::RectangleShape background;

		// Components
		std::vector<Component> component;
		std::vector<sf::Text> text;

		// Add/remove functions
		void add(Component component);
		void add(sf::Vector2f position, sf::String string);
		void load();
		void clear();
};

#endif