<<<<<<< HEAD
=======
/**
 *  Log.cpp
 * 
 *  Created 22 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 22 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
#include "Log.h"

#define DEFAULT_TIME_FORMAT_STRING "%Y-%m-%d, %I:%M%p"
#define DEFAULT_SEPARATOR " - "

#define BUFFER_SIZE 128

using namespace std;

/**
 *  @brief: .
 *
 *  @return: .
 */
bool Log::clear () {
	if (this->outputFile.is_open ()) {
		this->outputFile.close ();
	}

	this->outputFile.open(DEFAULT_OUTPUT_FILE_DIRECTORY);

	return this->outputFile.is_open ();
}

/**
 *  @brief: .
 *
 *  @return: .
 */
bool Log::close () {
	if (this->outputFile.is_open ()) {
		this->outputFile.close ();
	}

	return true;
}

/**
 *  @brief: .
 *
 *  @return: .
 */
bool Log::initialize (
	std::string directoryOfConfigFile, 
	std::string directoryOfOutputFile
) {
	std::ifstream configFile (directoryOfConfigFile);
	std::ofstream newFile;

	if (configFile.is_open ()) {

		getline (configFile, this->timeFormat, '=');
		getline (configFile, this->timeFormat);
		getline (configFile, this->separator, '=');
		getline (configFile, this->separator);

		configFile.close ();
	}
	else {
		configFile.close ();

		newFile.open(directoryOfConfigFile);

		newFile << DEFAULT_TIME_FORMAT_STRING << '\n';
		newFile << DEFAULT_SEPARATOR;

		newFile.close ();
	}


	this->outputFile.open(directoryOfOutputFile);

	return (this->outputFile.is_open ());
}

/**
 *  @brief: .
 *
 *  @return: .
 */
bool Log::write (string line) {
	struct tm * timeInfo;
	char buffer[BUFFER_SIZE];

	if (line.empty ()) {
		return false;
	}

	strftime (buffer, BUFFER_SIZE, this->timeFormat.c_str (), timeInfo);

	this->lastMessage = line;
	this->lastTime = buffer;

	cout << this->getLastLine ();

	return (this->outputFile << this->getLastLine ());
}

/**
 *  @brief: .
 *
 *  @return: .
 */
string Log::getLastLine () {
	return this->getLastTime + this->separator + this->lastMessage + "\n";
}

/**
 *  @brief: .
 *
 *  @return: .
 */
string Log::getLastMessage () {
	return this->lastMessage;
}

/**
 *  @brief: .
 *
 *  @return: .
 */
string Log::getLastTime () {
	return this->lastTime;
}