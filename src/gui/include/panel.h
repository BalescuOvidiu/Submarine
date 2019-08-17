#ifndef PANEL_H
#define PANEL_H

#include "button.h"

class Panel {

	public:
		Panel(double speedMove);

		~Panel();

		void render(sf::RenderWindow *window);
		void move(sf::View *view, double x, double y);
		void update(
			sf::RenderWindow *window, 
			sf::View *view
		);

		// Add/remove functions
		void add(Component component);
		void add(sf::Vector2f position, sf::String string);
		void load();
		void clear();


	private:
		// Background
		sf::RectangleShape background;

		// Components
		std::vector<Component> component;
		std::vector<sf::Text> text;

		// Variables
		double speedMove;
};

#endif