/**
 *  Writing.cpp
 * 
 *  Created 28 May 2018
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 25 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#include "Writing.h"

/**
 *
 */
string format (const double& value) {
	int n = floor (value);
	double absValue = abs (value);
	unsigned decimals = floor ( (absValue - floor (absValue)) * pow (10, decimalsNumber));
	stringstream stream;
	stream << n << decimalsDelimiter << decimals;
	return stream.str ();
}

/**
 *
 */
string format (double value) {
	int n = floor (value);
	double absValue = abs (value);
	unsigned decimals = floor ( (absValue - floor (absValue)) * pow (10, decimalsNumber));
	stringstream stream;
	stream << n << decimalsDelimiter << decimals;
	return stream.str ();
}

/**
 *
 */
string format (short value) {
	short decimals = pow (10, decimalsNumber);

	if (value < 1000) {
		return toString (value);
	}

	string text = toString (value / 1000) + SYMBOL_DECIMAL;
	text += toString (value / decimals / 10 % decimals) + SYMBOL_K;

	return text;
}

/**
 *
 */
string format (int value) {
	int decimals = pow (10, decimalsNumber);

	if (value < 1000) {
		return toString (value);
	}

	string text = toString (value / 1000) + SYMBOL_DECIMAL;
	text += toString (value / decimals / 10 % decimals) + SYMBOL_K;

	return text;
}

/**
 *
 */
string format (unsigned value) {
	unsigned decimals = pow (10, decimalsNumber);

	if (value < 1000) {
		return toString (value);
	}

	string text = toString (value / 1000) + SYMBOL_DECIMAL;
	text += toString (value / decimals / 10 % decimals) + SYMBOL_K;

	return text;
}