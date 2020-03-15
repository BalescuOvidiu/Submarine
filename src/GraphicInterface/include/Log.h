/**
 *  Log
 * 
 *  Created 22 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 22 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef LOG_H_
#define LOG_H_

#include <fstream>
#include <iostream>
#include <string>

/**
 *
 */
class Log {

public:
	static bool clear ();
	static bool close ();
	static bool initialize (
		std::string directoryOfConfigFile, 
		std::string directoryOfOutputFile
	);
	static bool write (std::string line);

	static std::string getLastLine ();
	static std::string getLastMessage ();
	static std::string getLastTime ();

private:
	static std::ofstream outputFile;

	static std::string lastMessage;
	static std::string lastTime;

	static std::string separator;
	static std::string timeFormat;
};

#endif