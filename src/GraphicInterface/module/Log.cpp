#include "Log.h"

#define DEFAULT_CONFIG_FILE_DIRECTORY "data/config/log.txt"
#define DEFAULT_OUTPUT_FILE_DIRECTORY "data/log.txt"
#define DEFAULT_TIME_FORMAT_STRING "%Y-%m-%d, %I:%M%p"
#define DEFAULT_SEPARATOR " - "

using namespace std;

/**
 * @brief: .
 */
bool Log::clear () {
	if (this->outputFile.is_open ()) {
		this->outputFile.close ();
	}

	this->outputFile.open(DEFAULT_OUTPUT_FILE_DIRECTORY);

	return this->outputFile.is_open ();
}

/**
 * @brief: .
 */
bool Log::close () {
	if (this->outputFile.is_open ()) {
		this->outputFile.close ();
	}

	return true;
}

/**
 * @brief: .
 */
bool Log::initialize () {
	std::ifstream configFile (DEFAULT_CONFIG_FILE_DIRECTORY);
	std::ofstream newFile;

	if (configFile.is_open ()) {

	}
	else {

	}

	configFile.close ();

	this->outputFile.open(DEFAULT_OUTPUT_FILE_DIRECTORY);

	return this->outputFile.is_open ();
}

/**
 * @brief: .
 */
bool Log::write (string line) {
	if (line.empty ()) {
		return false;
	}
	else {


		this->outputFile << this->getLastLine ();
	}

	return true;
}

/**
 * @brief: .
 */
string Log::getLastLine () {
	return this->getLastTime this->getLastMessage () + "\n";
}

/**
 * @brief: .
 */
string Log::getLastMessage () {
	return this-> 
}

/**
 * @brief: .
 */
string Log::getLastTime () {
	return this->lastTime;
}

/**
 * @brief: .
 */
string Log::getConfigFileDirectory () {
	return DEFAULT_CONFIG_FILE_DIRECTORY;
}

/**
 * @brief: .
 */
string Log::getOutputFileDirectory () {
	return DEFAULT_OUTPUT_FILE_DIRECTORY;
}