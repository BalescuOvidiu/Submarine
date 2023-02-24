/**
 *  Mathematics.h
 * 
 *  Created 28 May 2018
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 22 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef MATHEMATICS_H_
#define MATHEMATICS_H_

#include <cmath>
#include <vector>

#include "SFML/Graphics.hpp"

/** Text of measure units. */
#define TEXT_UNIT_DEGREE           sf::String (L" \u00B0")
#define TEXT_UNIT_METER            sf::String (L" m")
#define TEXT_UNIT_METER_PER_SECOND sf::String (L" m/s")

/** Selected measure units. */
#define UNIT_ANGLE    TEXT_UNIT_DEGREE
#define UNIT_DISTANCE TEXT_UNIT_METER
#define UNIT_SPEED    TEXT_UNIT_METER_PER_SECOND

/** Math constants. */
#define PI              3.141592653589793
#define EULER           2.718281828459045

/** Percents. */
#define PERCENT_NULL    0
#define PERCENT_QUARTER 25
#define PERCENT_HALF    50
#define PERCENT_MAX     100

/** Angles macross. */
#define ANGLE_NULL       0.0
#define ANGLE_RIGHT     90.0
#define ANGLE_STRAIGHT 180.0
#define ANGLE_FULL     360.0

const double radians = PI / ANGLE_STRAIGHT;
const double degrees = ANGLE_STRAIGHT / PI;

/** Geometric functions. */
bool isInCircle (
	sf::Vector2f center, 
	double radius, 
	sf::Vector2f point
);
bool isInRectangle (
	sf::Vector2f origin, 
	double width, 
	double height, 
	sf::Vector2f point
);
bool isInRectangle (
	sf::Vector2f a, 
	sf::Vector2f b, 
	sf::Vector2f c, 
	sf::Vector2f d, 
	sf::Vector2f point
);
bool isInTriangle (
	sf::Vector2f a, 
	sf::Vector2f b, 
	sf::Vector2f c, 
	sf::Vector2f point
);
bool isInParalelogram (
	sf::Vector2f a, 
	sf::Vector2f b, 
	sf::Vector2f c, 
	sf::Vector2f d, 
	sf::Vector2f point
);
double area (
	sf::Vector2f a, 
	sf::Vector2f b, 
	sf::Vector2f c
);

/** These functions work with determinants. */
double det (
	sf::Vector2f a,
	sf::Vector2f b,
	sf::Vector2f c
);

/** Interval functions. */
bool isInInterval (double value, double a, double b);
bool isNotInInterval (double value, double a, double b);
double scaleIntervalToInterval (double value, double a, double b, double c, double d);

/** Trigonometric functions. */
double cos (sf::Vector2f start, sf::Vector2f end);
double sin (sf::Vector2f start, sf::Vector2f end);
double tan (sf::Vector2f start, sf::Vector2f end);
double ctan (sf::Vector2f start, sf::Vector2f end);
double getAngleInDegrees (sf::Vector2f start, sf::Vector2f end);
double getAngleInRadians (sf::Vector2f start, sf::Vector2f end);

/** Angle translations functions. */
double mapAngleInDegrees (double angle);
double geographic (double angle);
double degreesToScreen (double angle);
double radiansToScreen (double angle);

/** Distances and positioning functions. */
double distance (sf::Vector2f pointA, sf::Vector2f pointB);
double distanceSquare (sf::Vector2f pointA, sf::Vector2f pointB);
bool distanceIsLessThan (double distance, sf::Vector2f pointA, sf::Vector2f pointB);
bool distanceIsBigThan (double distance, sf::Vector2f pointA, sf::Vector2f pointB);
bool distanceIsEqual (double distance, sf::Vector2f pointA, sf::Vector2f pointB);

/**
 * This function return maximum of a list of numeric values.
 *
 * @param b second numberic value.
 *
 * @return minimum of these values.
 */
template <class N>
N max (std::vector<N> value) {
	N maxValue = value[0];
	for (unsigned i = 1; i < value.size(); i++) {
		if (maxValue < value[i]) {
			maxValue = value[i];
		}
	}
	return maxValue;
}

/**
 * This function return minimum of a list of numeric values.
 *
 * @param b second numberic value.
 *
 * @return maximum of these values.
 */
template <class N>
N min (std::vector<N> value) {
	N maxValue = value[0];
	for (unsigned i = 1; i < value.size(); i++) {
		if (maxValue > value[i]) {
			maxValue = value[i];
		}
	}
	return maxValue;
}

#endif