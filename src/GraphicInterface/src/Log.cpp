/**
 *  Log.cpp
 * 
 *  Created 22 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 21 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#include <iostream>
#include <ctime>

#include "Writer.h"
#include "Log.h"

#define BUFFER_SIZE 128

std::fstream outputFile;

std::string Log::outputFileDirectory;
std::string Log::timeFormat;
std::string Log::separator;

std::string Log::lastMessage;
std::string Log::lastTime;

/**
 *  @brief: .
 *
 *  @return: .
 */
void Log::initialize (
	std::string outputFileDirectory,
	std::string timeFormat,
	std::string separator
) {
	Log::update(outputFileDirectory, timeFormat, separator);
}

/**
 *  @brief: .
 *
 *  @return: .
 */
void Log::update (
	std::string outputFileDirectory,
	std::string timeFormat,
	std::string separator
) {
	Log::setTimeFormat(timeFormat);
	Log::setSeparator(separator);
	Log::setOutputFileDirectory(outputFileDirectory);
}

/**
 *  @brief: .
 *
 *  @return: .
 */
void Log::clear () {
	if (outputFile.is_open ()) {
		outputFile.close ();
		outputFile.open (Log::outputFileDirectory);
	}
}

/**
 *  @brief: .
 *
 *  @return: .
 */
void Log::close () {
	if (outputFile.is_open ()) {
		outputFile.close ();
	}
}

/**
 *  @brief: .
 */

void Log::reloadTime () {
	time_t rawtime;

	struct tm * timeInfo;
	char buffer[BUFFER_SIZE];

	time (&rawtime);
    timeInfo = localtime (&rawtime);

	strftime (buffer, BUFFER_SIZE, Log::timeFormat.c_str (), timeInfo);
	Log::lastTime = buffer;
}

/**
 *  @brief: .
 */
void Log::write (std::string line) {
	Log::reloadTime ();
	Log::lastMessage = line;

	std::cout << Log::getLastLine ();
	outputFile << getLastLine ();
}

/**
 *  @brief: .
 */
void Log::setOutputFileDirectory (std::string outputFileDirectory) {
	Log::reloadTime ();
	std::string name = Log::lastTime;
	name = Writer::removeChars (name, " ");
	name = Writer::removeChars (name, "-");
	name = Writer::removeChars (name, ":");
	name = Writer::removeChars (name, ",");

	outputFileDirectory = outputFileDirectory + name + ".log";
	Log::close();
	outputFile.open(outputFileDirectory, std::fstream::out | std::fstream::app);

	if (outputFile.is_open ()) {
		Log::write ("Log file " + outputFileDirectory + " is open.");
	}
	else {
		Log::write ("Log file " + outputFileDirectory + " can't be created!");
	}
}
/**
 *  @brief: .
 */
void Log::setTimeFormat (std::string timeFormat) {
	Log::timeFormat = timeFormat;
}
/**
 *  @brief: .
 */
void Log::setSeparator (std::string separator) {
	Log::separator = separator;
}

/**
 *  @brief: .
 *
 *  @return: .
 */
std::string Log::getOutputFileDirectory () {
	return Log::outputFileDirectory;
}

/**
 *  @brief: .
 *
 *  @return: .
 */
std::string Log::getTimeFormat () {
	return Log::timeFormat;
}

/**
 *  @brief: .
 *
 *  @return: .
 */
std::string Log::getSeparator () {
	return Log::separator;
}

/**
 *  @brief: .
 *
 *  @return: .
 */
std::string Log::getLastLine () {
	return Log::lastTime + Log::separator + Log::lastMessage + "\n";
}

/**
 *  @brief: .
 *
 *  @return: .
 */
std::string Log::getLastMessage () {
	return Log::lastMessage;
}

/**
 *  @brief: .
 *
 *  @return: .
 */
std::string Log::getLastTime () {
	return Log::lastTime;
}

/**
 *  @brief: .
 *
 *  @return: .
 */
bool Log::isOpen () {
	return outputFile.is_open ();
}