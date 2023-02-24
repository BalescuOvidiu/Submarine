/**
 *  Mathematics.cpp
 * 
 *  Created 28 May 2018
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 22 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#include "Mathematics.h"

/**
 *  @brief:
 *
 *  @return: .
 */
bool isInCircle (
	sf::Vector2f center, 
	double radius,
	sf::Vector2f point
) {
	return distanceIsLessThan (radius, center, point);
}

/**
 *  @brief:
 *
 *  @return: .
 */
bool isInRectangle (
	sf::Vector2f origin, 
	sf::Vector2f point, 
	double width, 
	double height
) {
	if (point.x > origin.x + width || point.x < origin.x) {
		return false;
	}
	if (point.y > origin.y + height || point.y < origin.y) {
		return false;
	}

	return  true;
}

/**
 *  @brief:
 *
 *  @return: .
 */
bool isInRectangle (
	sf::Vector2f a, 
	sf::Vector2f b, 
	sf::Vector2f c, 
	sf::Vector2f d,
	sf::Vector2f point
) {
	if (point.x > d.x || point.x < a.x) {
		return false;
	}
	if (point.y > d.y || point.y < a.y) {
		return false;
	}

	return  true;
}

/**
 *  @brief:
 *
 *  @return: .
 */
bool isInTriangle (
	sf::Vector2f a, 
	sf::Vector2f b, 
	sf::Vector2f c,
	sf::Vector2f point
) {
	bool condition1 = det (a, point, b) < 0;
	bool condition2 = det (a, c, point) < 0;

	if(condition1 != condition2) {
		return false;
	}

	return condition1 == (det (b, point, c) < 0);
}

/**
 *  @brief:
 *
 *  @return: .
 */
bool isInParalelogram (
	sf::Vector2f a, 
	sf::Vector2f b, 
	sf::Vector2f c, 
	sf::Vector2f d, 
	sf::Vector2f point
) {
	if (isInTriangle (a, b, c, point)) {
		return true;
	}

	return isInTriangle (b, c, d, point);
}

/**
 *  @brief:
 *
 *  @return: .
 */
double area (sf::Vector2f a, sf::Vector2f b, sf::Vector2f c) {
	return abs (0.5 * det (a, b, c));
}

/**
 *  @brief:
 *
 *  @return: .
 */
double det (sf::Vector2f a, sf::Vector2f b, sf::Vector2f c) {
	return a.x * b.y + a.y * c.x + b.x * c.y - b.y*c.x - a.x * c.y - a.y * b.x;
}

/**
 *  @brief:
 *
 *  @return: .
 */
bool isInInterval (double value, double a, double b) {
	return a <= value && value <= b;
}

/**
 *  @brief:
 *
 *  @return: .
 */
bool isNotInInterval (double value, double a, double b) {
	return a > value || value > b;
}

/**
 *  @brief:
 */
double scaleIntervalToInterval (double value, double a, double b, double c, double d) {
	return c + (d - c) * (value - a) / (b - a);
}

/**
 *  @brief:
 *
 *  @return: .
 */
double cos (sf::Vector2f start, sf::Vector2f end) {
	return  (end.x - start.x) / distance (start, end);
}

/**
 *  @brief:
 *
 *  @return: .
 */
double sin (sf::Vector2f start, sf::Vector2f end) {
	return  (end.y - start.y) / distance (start, end);
}

/**
 *  @brief:
 *
 *  @return: .
 */
double tan (sf::Vector2f start, sf::Vector2f end) {
	return (end.y - start.y) / (end.x - start.x);
}

/**
 *  @brief:
 *
 *  @return: .
 */
double ctan (sf::Vector2f start, sf::Vector2f end) {
	return (end.x - start.x) / (end.y - start.y);
}

/**
 *  @brief:
 *
 *  @return: .
 */
double getAngleInDegrees (sf::Vector2f start, sf::Vector2f end) {
	double angle =  atan ( (end.y - start.y) / (end.x - start.x)) * degrees;
	
	if (end.x < start.x){
		angle += ANGLE_STRAIGHT;
	}
	if (angle < ANGLE_NULL){
		angle += ANGLE_FULL;
	}

	return angle;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double getAngleInRadians (sf::Vector2f start, sf::Vector2f end) {
	double angle = atan ( (end.y - start.y) / (end.x - start.x)) * radians;
	
	if (end.x < start.x){
		angle += ANGLE_STRAIGHT;
	}
	if (angle < ANGLE_NULL){
		angle += ANGLE_FULL;
	}

	return angle * radians;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double mapAngleInDegrees (double angle) {

	while (ANGLE_FULL < angle) {
		angle -= ANGLE_FULL;
	}
	while (ANGLE_NULL > angle) {
		angle += ANGLE_FULL;
	}

	return angle;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double geographic (double angle) {
	return mapAngleInDegrees (ANGLE_RIGHT - degreesToScreen (angle));
}

/**
 *  @brief:
 *
 *  @return: .
 */
double degreesToScreen (double angle) {
	return ANGLE_FULL - angle;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double radiansToScreen (double angle) {
	return ANGLE_FULL - angle * degrees;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double distance (sf::Vector2f pointA, sf::Vector2f pointB) {
	return sqrt ((pointA.x - pointB.x) * (pointA.x - pointB.x) + (pointA.y - pointB.y) * (pointA.y - pointB.y));
}

/**
 *  @brief:
 *
 *  @return: .
 */
double distanceSquare (sf::Vector2f pointA, sf::Vector2f pointB) {
	return ((pointA.x - pointB.x) * (pointA.x - pointB.x) + (pointA.y - pointB.y) * (pointA.y - pointB.y));
}

/**
 *  @brief:
 *
 *  @return: .
 */
bool distanceIsLessThan (double distance, sf::Vector2f pointA, sf::Vector2f pointB) {
	if (distance * distance < distanceSquare (pointA, pointB)) {
		return false;
	}

	return true;
}

/**
 *  @brief:
 *
 *  @return: .
 */
bool distanceIsBigThan (double distance, sf::Vector2f pointA, sf::Vector2f pointB) {
	if (distance * distance > distanceSquare (pointA, pointB)) {
		return false;
	}

	return true;
}

/**
 *  @brief:
 *
 *  @return: .
 */
bool distanceIsEqual (double distance, sf::Vector2f pointA, sf::Vector2f pointB) {
	if (distance * distance != distanceSquare (pointA, pointB)) {
		return false;
	}

	return true;
}