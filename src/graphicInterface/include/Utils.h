/**
 *  Utils.h
 * 
 *  Created 25 February 2023
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 25 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <fstream>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

json getJsonFromFile (std::string fileDirectory);

std::string getFileName (std::string directory);

std::string removeChars (
	const std::string& source, 
	std::string chars
);

#endif