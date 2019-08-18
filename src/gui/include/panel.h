/**
 * Programmer: Balescu Ovidiu-Gheorghe
 * Date:       15 May 2019
 * Library:    SFML 2.5.1
 */

#ifndef PANEL_H
#define PANEL_H

#include "component.h"

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
		double speedMoveView;
};

#endif