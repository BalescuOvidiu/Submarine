/**
 *  Panel.h
 * 
 *  Created 22 February 2023
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 26 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef PANEL_H_
#define PANEL_H_

#include "Ruller.h"

/**
 *  @brief:
 */
class Panel {
	public:
		Panel (
			double minX = -5000,
			double minY = -5000,
			double maxX = 5000,
			double maxY = 5000,
			double marginSize = 1.0,
			double zoomInLimit = 0.1,
			double zoomOutLimit = 10.0,
			unsigned int characterSize = 14,
			int keysWaitTime = 20
		);
		~Panel ();

		void setSizes (
			double minX = -5000,
			double minY = -5000,
			double maxX = 5000,
			double maxY = 5000,
			double marginSize = 1.0,
			double zoomInLimit = 0.1,
			double zoomOutLimit = 10.0,
			unsigned int characterSize = 14,
			int keysWaitTime = 20
		);

		void open ();
		void open (sf::View *view);
		void close ();

		double getWidth ();
		double getWidthGrid ();
		double getWidthMeter ();
		double getHeight ();
		double getHeightGrid ();
		double getHeightMeter ();

		double getMargin ();
		double getMarginGrid ();
		double getMarginMeter ();
		sf::Vector2f getMarginVector2f ();
		sf::Vector2f getMarginVector2fGrid ();
		sf::Vector2f getMarginVector2fMeter ();

		bool canMove (double x, double y);
		bool canZoom (double factor);
		bool canPressKeys ();

		bool isPointValid (double x, double y);
		bool isPointValid (sf::Vector2f point);
		bool isOpen ();
		bool isClosed ();

	protected:
		double marginSize;

		double zoomInLimit; 
		double zoomOutLimit;

		unsigned int characterSize;

		sf::Clock keysClock;
		bool on;

	private:
		double minX;
		double minY;
		double maxX;
		double maxY;

		int keysWaitTime;
};

#endif