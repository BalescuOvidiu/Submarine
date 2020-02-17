/**
 * Programmer: Balescu Ovidiu-Gheorghe
 * Date:       15 May 2019
 * Library:    SFML 2.5.1
 */

#ifndef PANEL_H_
#define PANEL_H_

#include "component.h"

struct Submarine {

	double lengthHull;
	double radiusHull;

	double radiusPlane;

	double radiusBack;

	double positionBodyNavigation;
	double radiusXBodyNavigation;
	double radiusYBodyNavigation;

	double distanceSensorMin;
	double distanceSensorMax;

	double positionInertialDevice;

	double totalLength;

	double speed;
	double orientation;

	Component body;
};

class Panel {

	public:
		Panel (double speedMove);

		~Panel ();

		void render (sf::RenderWindow *window);

		/** Update functions */
		void move (
			sf::RenderWindow *window, 
			sf::View *view, 
			double x, 
			double y
		);
		void update (
			sf::RenderWindow *window, 
			sf::View *view
		);
		void clear ();
		void setRadarRadius (double radius);

		/** Load functions. */
		void load ();
		void loadPanelTrack ();
		void loadRadar ();
		void loadShip ();
		void loadTextRadar ();

		/** Radar functions. */
		double scaleToRadar (double value);
		double scaleFromRadar (double value);

		/** Ship functions. */
		void setOrientationOfShip (double angle);

	private:
		/** Background. */
		sf::RectangleShape background;

		/** Components. */
		Component panelTrack;
		Component radar;

		/** Text. */
		sf::Text radarGuide;
		std::vector<sf::Text> radarText;

		/** View variables. */
		double speedMoveView;
		double radarRadius;

		/** Submarine data. */
		Submarine ship;
};

#endif