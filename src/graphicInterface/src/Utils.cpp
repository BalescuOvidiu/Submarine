/**
 *  Utils.cpp
 * 
 *  Created 25 February 2023
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 25 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#include "Utils.h"

/**
 *  @brief:
 *
 *  @return: .
 */
json getJsonFromFile (std::string fileDirectory) {
	std::ifstream file (fileDirectory);
	json data = json::parse (file);
	file.close ();

	return data;
}

/**
 *  @brief:
 *
 *  @return: .
 */
std::string getFileName (std::string directory) {
	std::size_t foundSlash = directory.find_last_of("/\\") + 1;
	std::size_t foundPoint = directory.find_last_of(".");
	return directory.substr (
		foundSlash,
		foundPoint - foundSlash
	);
}

/**
 *  @brief: Remove substring from a string.
 *
 *  @return: the string without removed substring.
 */
std::string removeChars (
	const std::string& source, 
	std::string chars
) {
    std::string result = "";
	for (unsigned int i = 0; i < source.length(); i++) {
		bool found = false;
		for (unsigned int j = 0; j < chars.length() && !found; j++) {
			found = (source[i] == chars[j]);
		}
		if (!found) {
			result += source[i];
		}
	}
	return result;
}