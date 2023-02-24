/**
 *  ControlPanel.h
 * 
 *  Created 15 May 2019
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 22 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef CONTROL_PANEL_H_
#define CONTROL_PANEL_H_

#include <string>
#include <vector>

#include "Panel.h"
#include "Component.h"
#include "Ship.h"


/**
 *  @brief:
 */
class ControlPanel : public Panel {

public:
	ControlPanel (
		sf::RenderWindow *window, 
		sf::View *view
	);

	~ControlPanel ();

	void render (sf::RenderWindow *window);
	void update (
		sf::RenderWindow *window, 
		sf::View *view
	);
	void move (
		sf::RenderWindow *window, 
		sf::View *view, 
		double x, 
		double y
	);
	void move (
		sf::RenderWindow *window, 
		sf::View *view, 
		sf::Vector2f point
	);
	void zoom (
		sf::RenderWindow *window, 
		sf::View *view, 
		float factor
	);

	void loadBackground (
		sf::RenderWindow *window, 
		sf::View *view
	);
	void loadShip (std::string directory);

	void close ();

private:
	/** Background */
	sf::RectangleShape backgroundFill;
	Component backgroundGrids;
	Component backgroundGridsWide;

	/** Text */
	sf::Text radarGuide;

	/** Ships data */
	unsigned selectedShip;
	std::vector<Ship> ship;
};

#endif