/**
 *  Log.h
 * 
 *  Created 22 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 21 February 2023
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef LOG_H_
#define LOG_H_

#include <fstream>
#include <string>

/**
 *  @brief:
 */
class Log {

public:
	static void initialize (
		std::string outputFileDirectory = "logs/",
		std::string timeFormat = "%Y-%m-%d, %X",
		std::string separator = " - "
	);
	static void update (
		std::string outputFileDirectory,
		std::string timeFormat,
		std::string separator
	);
	static void clear ();
	static void close ();

	static void reloadTime ();
	static void write (std::string line);

	static void setOutputFileDirectory (std::string outputFileDirectory);
	static void setTimeFormat (std::string timeFormat);
	static void setSeparator (std::string separator);

	static std::string getOutputFileDirectory();
	static std::string getTimeFormat();
	static std::string getSeparator();
	static std::string getLastLine ();
	static std::string getLastMessage ();
	static std::string getLastTime ();

	static bool isOpen ();

private:
	static std::string outputFileDirectory;
	static std::string timeFormat;
	static std::string separator;

	static std::string lastMessage;
	static std::string lastTime;
};

#endif