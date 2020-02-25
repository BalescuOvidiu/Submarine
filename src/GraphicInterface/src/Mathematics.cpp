/**
 *  Mathematics.cpp
 * 
 *  Created 28 May 2018
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 25 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#include "mathematics.h"

using namespace std;
using namespace sf;

const double degreesToRadiansRatio = PI / ANGLE_STRAIGHT;
const double radiansToDegreesRatio = ANGLE_STRAIGHT / PI;

/**
 *  @brief:
 *
 *  @return: .
 */
bool isInCircle (
	Vector2f center, 
	double radius, 
	Vector2f point
) {
	return distanceIsLessThan (radius, center, point);
}	

/**
 *  @brief:
 *
 *  @return: .
 */
bool isInRectangle (
	Vector2f origin, 
	double width, 
	double height, 
	Vector2f point
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
bool isInTriangle (Vector2f a, Vector2f b, Vector2f c, Vector2f point) {
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
	Vector2f a,
	Vector2f b,
	Vector2f c,
	Vector2f d,
	Vector2f point

) {
	bool condition1 = isInTriangle (a, b, c, point);

	if (condition1) {
		return true;
	}

	return isInTriangle (b, c, d, point)
}

/**
 *  @brief:
 *
 *  @return: .
 */
double area (Vector2f a, Vector2f b, Vector2f c) {
	return abs (0.5 * det (a, b, c));
}

/**
 *  @brief:
 *
 *  @return: .
 */
double det (Vector2f a, Vector2f b, Vector2f c) {
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
double getCos (Vector2f start, Vector2f end) {
	return  (end.x - start.x) / DISTANCE (start, end);
}

/**
 *  @brief:
 *
 *  @return: .
 */
double getSin (Vector2f start, Vector2f end) {
	return  (end.y - start.y) / DISTANCE (start, end);
}

/**
 *  @brief:
 *
 *  @return: .
 */
double getTan (Vector2f start, Vector2f end) {
	return (end.y - start.y) / (end.x - start.x);
}

/**
 *  @brief:
 *
 *  @return: .
 */
double getCtan (Vector2f start, Vector2f end) {
	return (end.x - start.x) / (end.y - start.y);
}

/**
 *  @brief:
 *
 *  @return: .
 */
double getAngleInDegrees (Vector2f start, Vector2f end) {
	double angle=DEGREES ( atan ( (end.y - start.y) / (end.x - start.x)));
	
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
double getAngleInRadians (Vector2f start, Vector2f end) {
	double angle=DEGREES ( atan ( (end.y - start.y) / (end.x - start.x)));
	
	if (end.x < start.x){
		angle += ANGLE_STRAIGHT;
	}
	if (angle < ANGLE_NULL){
		angle += ANGLE_FULL;
	}

	return degreesToRadiansRatio * angle;
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
double toRadians (double degrees) {
	return degrees * degreesToRadiansRatio;
}

/**
 *  @brief:
 *
 *  @return: .
 */
double toDegrees (double radians) {
	return radians * radiansToDegreesRatio;
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
	return ANGLE_FULL - toDegrees (angle);
}

/**
 *  @brief:
 *
 *  @return: .
 */
double distance (Vector2f pointA, Vector2f pointB) {
	return sqrt ((pointA.x - pointB.x) * (pointA.x - pointB.x) + (pointA.y - pointB.y) * (pointA.y - pointB.y));
}

/**
 *  @brief:
 *
 *  @return: .
 */
double distanceSquare (Vector2f pointA, Vector2f pointB) {
	return (pointA.x - pointB.x) * (pointA.x - pointB.x) + (pointA.y - pointB.y) * (pointA.y - pointB.y);
}

/**
 *  @brief:
 *
 *  @return: .
 */
bool distanceIsLessThan (D distance, Vector2f pointA, Vector2f pointB) {
	if (distance * distance > squareDistance (pointA, pointB)) {
		return false;
	}

	return true;
}

/**
 *  @brief:
 *
 *  @return: .
 */
bool distanceIsBigThan (D distance, Vector2f pointA, Vector2f pointB) {
	if (distance * distance > squareDistance (pointA, pointB)) {
		return false;
	}

	return true;
}

/**
 *  @brief:
 *
 *  @return: .
 */
bool distanceIsEqual (D distance, Vector2f pointA, Vector2f pointB) {
	if (distance * distance != squareDistance (pointA, pointB)) {
		return false;
	}

	return true;
}