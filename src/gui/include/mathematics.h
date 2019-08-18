/**
 * Programmer: Balescu Ovidiu-Gheorghe
 * Date:       15 May 2019
 * Library:    SFML 2.5.1
 */

#ifndef MATHEMATICS_H
#define MATHEMATICS_H

// Basic math functions
#include <cmath>

// SFML library
#include <SFML/Graphics.hpp>

//Input/output
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

// STL objects
#include <vector>

// Symbols
#define S_DEGREES       String (L" \u00B0")
#define S_CENTIMETER    String (" cm")

// Math constants
#define PI              3.14159265358979323846
#define Euler           2.71

// Position macros
#define MID(a, b)       0.5 * (a + b)
#define MIDDLE(a, b)    sf::Vector2f (MID (a.x, b.x), MID (a.y, b.y))

// List macros
#define LAST(vector, i) vector[vector.size () - i - 1]

// Distance macros
#define SQUARE(a)       (a) * (a)
#define DIST(a, b)		(SQUARE (a.x - b.x) + SQUARE (a.y - b.y))
#define DISTANCE(a, b)  sqrt (DIST (a, b))

// Trigonometric macros
#define COS(angle)      cos ( RADIANS (angle))
#define SIN(angle)      sin ( RADIANS (angle))
#define DEGREES(angle)  (angle) * 180.0 / PI
#define RADIANS(angle)  (angle) * PI / 180.0

// Geometric functions
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
	sf::Vector2f d
);
double area (
	sf::Vector2f a,
	sf::Vector2f b,
	sf::Vector2f c
);

// These functions work with determinants.
double det (
	sf::Vector2f a,
	sf::Vector2f b,
	sf::Vector2f c
);

// Interval functions
bool isInInterval (double value, double a, double b);
bool isNotInInterval (double value, double a, double b);
double scaleToInterval (double value, double a, double b, double c, double d);

// Trigonometric functions
double getCosInDegrees (sf::Vector2f start, sf::Vector2f end);
double getSinInDegrees (sf::Vector2f start, sf::Vector2f end);
double getCosInRadians (sf::Vector2f start, sf::Vector2f end);
double getSinInRadians (sf::Vector2f start, sf::Vector2f end);
double getAngleInDegrees (sf::Vector2f start, sf::Vector2f end);
double getAngleInRadians (sf::Vector2f start, sf::Vector2f end);
double mapAngleInDegrees (double angle);
double translateDegreesToScreen (double angle);

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