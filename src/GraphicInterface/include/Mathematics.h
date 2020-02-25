/**
 *  Mathematics.h
 * 
 *  Created 28 May 2018
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 25 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef MATHEMATICS_H_
#define MATHEMATICS_H_

#include <cmath>
#include <SFML/Graphics.hpp>
#include <vector>

/** Arrays macros. */
#define LAST(vector, i) vector[vector.size () - (index) - 1]

/** Math constants. */
#define PI              3.141592653589793
#define EULER           2.718281828459045

/** Percents. */
#define PERCENT_MAX  100
#define PERCENT_HALF 50
#define PERCENT_NULL 0

/** Angles macross. */
#define ANGLE_NULL       0.0
#define ANGLE_RIGHT     90.0
#define ANGLE_STRAIGHT 180.0
#define ANGLE_FULL     360.0

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
double getCos (sf::Vector2f start, sf::Vector2f end);
double getSin (sf::Vector2f start, sf::Vector2f end);
double getTan (sf::Vector2f start, sf::Vector2f end);
double getCtan (sf::Vector2f start, sf::Vector2f end);
double getAngleInDegrees (sf::Vector2f start, sf::Vector2f end);
double getAngleInRadians (sf::Vector2f start, sf::Vector2f end);

/** Angle translations functions. */
double mapAngleInDegrees (double angle);
double toDegrees (double radians);
double toRadians (double degrees);
double degreesToScreen (double angle);
double radiansToScreen (double angle);

double cosDegrees (double angle);
double sinDegrees (double angle);
double tanDegrees (double angle);
double ctanDegrees (double angle);

/** Distances and positioning functions. */
double distance (sf::Vector2f pointA, sf::Vector2f pointB);
double distanceSquare (sf::Vector2f pointA, sf::Vector2f pointB);
bool distanceIsLessThan (D distance, sf::Vector2f pointA, sf::Vector2f pointB);
bool distanceIsBigThan (D distance, sf::Vector2f pointA, sf::Vector2f pointB);
bool distanceIsEqual (D distance, sf::Vector2f pointA, sf::Vector2f pointB);

/**
 * This function return maximum between two numeric values.
 *
 * @param a first numeric value,
 * @param b second numberic value.
 *
 * @return maximum between these two values.
 */
template <class N>
N max (N a, N b) {
	if (a > b) {
		return a;
	}
	return b;
}

/**
 * This function return minimum between two numeric values.
 *
 * @param a first numeric value,
 * @param b second numberic value.
 *
 * @return minimum between these two values.
 */
template <class N>
N min (N a, N b) {
	if (a < b) {
		return a;
	}
	return b;
}

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