#include "mathematics.h"

using namespace std;
using namespace sf;

namespace mathematics {

	/**
	 *
	 */
	bool isInCircle (
		sf::Vector2f center, 
		double radius, 
		sf::Vector2f point
	) {
		return DIST (center, point) <= SQUARE (radius);
	}

	/**
	 * 
	 */
	bool isInRectangle (
		sf::Vector2f origin, 
		double width, 
		double height, 
		sf::Vector2f point
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
	 *
	 */
	bool isInTriangle (Vector2f a, Vector2f b, Vector2f c, Vector2f d) {
		bool condition1 = det (a, d, b) < 0;
		bool condition2 = det (a, c, d) < 0;

		if(condition1 != condition2) {
			return false;
		}

		return condition1 == (det (b, d, c) < 0);
	}

	/**
	 * 
	 */
	double area (Vector2f a, Vector2f b, Vector2f c) {
		return abs (0.5 * det (a, b, c));
	}

	/**
	 * 
	 */
	double det (Vector2f a, Vector2f b, Vector2f c) {
		return a.x * b.y + a.y * c.x + b.x * c.y - b.y*c.x - a.x * c.y - a.y * b.x;
	}

	/**
	 *
	 */
	bool isInInterval (double value, double a, double b) {
		return a <= value && value <= b;
	}

	/**
	 *
	 */
	bool isNotInInterval (double value, double a, double b) {
		return a > value || value > b;
	}

	/**
	 *
	 */
	double scaleToInterval (double value, double a, double b, double c, double d) {
		return c + (d - c) / (b - a) * (value - a);
	}

	/**
	 *
	 */
	double getCosInDegrees (Vector2f start, Vector2f end) {
		return  (end.x - start.x) / DISTANCE (start, end);
	}

	/**
	 *
	 */
	double getSinInDegrees (Vector2f start, Vector2f end) {
		return  (end.y  -  start.y) / DISTANCE (start, end);
	}

	/**
	 *
	 */
	double getCosInRadians (Vector2f start, Vector2f end) {
		return RADIANS ((end.x - start.x) / DISTANCE (start, end));
	}

	/**
	 *
	 */
	double getSinInRadians (Vector2f start, Vector2f end) {
		return RADIANS ((end.y  -  start.y) / DISTANCE (start, end));
	}

	/**
	 *
	 */
	double getAngleInDegrees (Vector2f start, Vector2f end) {
		double angle=DEGREES ( atan ( (end.y - start.y) / (end.x - start.x)));
		
		if (end.x < start.x){
			angle += ANGLE_MIDDLE;
		}
		if (angle < ANGLE_MIN){
			angle += ANGLE_MAX;
		}

		return angle;
	}

	/**
	 *
	 */
	double getAngleInRadians (Vector2f start, Vector2f end) {
		double angle=DEGREES ( atan ( (end.y - start.y) / (end.x - start.x)));
		
		if (end.x < start.x){
			angle += ANGLE_MIDDLE;
		}
		if (angle < ANGLE_MIN){
			angle += ANGLE_MAX;
		}

		return RADIANS (angle);
	}

	/**
	 *
	 */
	double mapAngleInDegrees (double angle) {

		while (ANGLE_MAX < angle) {
			angle -= ANGLE_MAX;
		}
		while (ANGLE_MIN > angle) {
			angle += ANGLE_MAX;
		}

		return angle;
	}

	/**
	 *
	 */
	double translateDegreesToScreen (double angle) {
		return ANGLE_MAX - angle;
	}
}