#ifndef DISTANCE_H_
#define DISTANCE_H_

/** Basic math functions. */
#include <cmath>

/** SFML library. */
#include <SFML/Graphics.hpp>

/**Input/output. */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

template<class D, class P>
bool isInDistance (D distance, P firstPoint, P SecondPoint) {
	return 0;
}

template<class D>
D distance () {

}

template<class D>
D distanceSquare (sf::Vector2f pointA, sf::Vector2f pointB) {
	return (pointA.x - pointB.x) * (pointA.x - pointB.x) + (pointA.y - pointB.y) * (pointA.y - pointB.y);
}

bool distanceIsLessThan (D distance, sf::Vector2f pointA, sf::Vector2f pointB) {
	if (distance * distance > squareDistance (pointA, pointB)) {
		return false;
	}

	true;
}

double distance (sf::Vector2f pointA, sf::Vector2f pointB) {
	return sqrt ((pointA.x - pointB.x) * (pointA.x - pointB.x) + (pointA.y - pointB.y) * (pointA.y - pointB.y));
}

#endif