#include "config.h"

using namespace std;
using namespace sf;
using namespace mathematics;

/** Files directories. */
#define FILE_CONFIGURATION "data/configuration.txt"
#define FILE_FONT          "data/Verdana.ttf"
#define FILE_LOG           "data/.log.txt"

/** Standard values for configuration. */
#define CONFIG_NAME_OF_APPLICATION "SFML Application"
#define CONFIG_TIME_FORMAT         "%Y-%m-%d, %I:%M%p - "

#define CONFIG_DECIMALS_DELIMITER  ","

#define CONFIG_FRAME_RATE       60
#define CONFIG_GRID_RATE         0.01
#define CONFIG_MOVE_VIEW_SPEED  10.0
#define CONFIG_CIRCLE_PRECISION  5.0
#define CONFIG_DECIMALS_NUMBER   2

#define BUFFER_TIME_FORMAT_SIZE 80

namespace config {
	/** Font variable. */
	Font font;

	/** Variables of screen. */
	const unsigned width = sf::VideoMode::getDesktopMode ().width;
	const unsigned height = sf::VideoMode::getDesktopMode ().height;
	
	/** Grid variables. */
	double grid = width * CONFIG_GRID_RATE;
	unsigned widthGrid = fromGrid (width);
	unsigned heightGrid = fromGrid (height);

	Vector2f positionOfView = ORIGIN;

	unsigned frameRate = CONFIG_FRAME_RATE;

	/** Variables for precision. */
	bool exitStatus = false;
	double moveViewSpeed = CONFIG_MOVE_VIEW_SPEED;
	double circlePrecision = CONFIG_CIRCLE_PRECISION;

	/** Variables used to represent numbers. */
	unsigned decimalsNumber = CONFIG_DECIMALS_NUMBER;
	string decimalsDelimiter = CONFIG_DECIMALS_DELIMITER;

	/** Variables of view. */
	double zoomFactor = 1;

	/** Communications. */
	string nameOfApplication = CONFIG_NAME_OF_APPLICATION;
	string timeFormat = CONFIG_TIME_FORMAT;
	fstream log (FILE_LOG, fstream::out | fstream::app);
	time_t currentTime = time(0);

	/** Time variable. */
	Clock click;

	/**
	 * 
	 */
	void exit () {
		logMessage ("Execution of " + nameOfApplication + " ends.");
		config::log.close ();
		exitStatus = true;
	}

	/**
	 * 
	 */
	bool canExit () {
		return exitStatus;
	}

	/**
	 * 
	 */
	double getMoveViewSpeed () {
		return moveViewSpeed;
	}

	/**
	 * 
	 */
	double getCirclePrecision () {
		return circlePrecision;
	}

	/**
	 * 
	 */
	unsigned getDecimalsNumber () {
		return decimalsNumber;
	}

	/**
	 *
	 */
	bool writeConfigFile () {
		ofstream configuration (FILE_CONFIGURATION);

		if (configuration.is_open ()) {
			configuration << nameOfApplication;
			configuration << timeFormat;
			configuration << decimalsDelimiter;
			configuration << frameRate;
			configuration << (double) (grid / width);
			configuration << moveViewSpeed;
			configuration << circlePrecision;
			configuration << decimalsNumber;

			configuration.close ();

			return true;
		}

		configuration.close ();
		return false;
	}

	/**
	 * 
	 */
	std::string getNameOfApplication () {
		return nameOfApplication;
	}

	/**
	 * 
	 */
	double getGrid () {
		return grid;
	}

	/**
	 * 
	 */
	unsigned getWidth () {
		return width;
	}

	/**
	 * 
	 */
	unsigned getWidth (short percent) {
		return width * percent / PERCENT_MAX;
	}

	/**
	 * 
	 */
	unsigned getWidthGrid () {
		return widthGrid;
	}

	/**
	 * 
	 */
	unsigned getWidthGrid (short percent) {
		return widthGrid * percent / PERCENT_MAX;
	}

	/**
	 * 
	 */
	unsigned getHeight () {
		return height;
	}

	/**
	 * 
	 */
	unsigned getHeight (short percent) {
		return height * percent / PERCENT_MAX;
	}

	/**
	 * 
	 */
	unsigned getHeightGrid () {
		return heightGrid;
	}

	/**
	 * 
	 */
	unsigned getHeightGrid (short percent) {
		return heightGrid * percent / PERCENT_MAX;
	}

	/**
	 * 
	 */
	unsigned getFrameRate () {
		return frameRate;
	}

	/**
	 * 
	 */

	/**
	 * 
	 */
	void initialize () {
		
		double gridRate;

		/** Config file. */
		ifstream configuration (FILE_CONFIGURATION);
		if (configuration.is_open ()) {
			getline (configuration, nameOfApplication);
			getline (configuration, timeFormat);
			getline (configuration, decimalsDelimiter);
			configuration >> frameRate;
			configuration >> gridRate;
			configuration >> moveViewSpeed;
			configuration >> circlePrecision;
			configuration >> decimalsNumber;

			logMessage ("Execution of " + nameOfApplication + " begins.");
			logMessage (
				"File " + string (FILE_CONFIGURATION) + " was loaded!"
			);

			/** Grids. */
			grid = width * gridRate;
			widthGrid = fromGrid (width);
			heightGrid = fromGrid (height);
		}
		else {

			logMessage ("Execution of " + nameOfApplication + " begins.");
			logMessage (
				"File " + string (FILE_CONFIGURATION) + " doesn't found!"
			);

			if (writeConfigFile ()) {
				logMessage ("A configuration file was create.");
			}
			else {				
				logMessage ("Configuration file can't be create!");
			}
		}

		configuration.close ();

		/** Vertex buffer. */
		if (VertexBuffer::isAvailable ()) {
			logMessage ("The VertexBuffer is available.");
		}
		else {
			logMessage ("The VertexBuffer is not available.");			
		}

		/** Font file. */
		if (!font.loadFromFile (FILE_FONT)) {
			logMessage (
				"File " + string (FILE_FONT) + " doesn't found!"
			);
		}
		else {
			logMessage (
				"File " + string (FILE_FONT) + " was loaded!"
			);
		}

	}

	/**
	 * 
	 */
	void logMessage (string message) {
		/** Time. */
		currentTime = time(0);
		tm* timeinfo = localtime (&currentTime);
  		char buffer [BUFFER_TIME_FORMAT_SIZE];

		strftime (
			buffer, 
			BUFFER_TIME_FORMAT_SIZE, 
			timeFormat.c_str (), 
			timeinfo
		);

		/** Message on file. */
		if (log.is_open ()) {
			log << buffer;
			log << message << "\n"; 
		}

		/** Message on console. */
		cout << buffer;
		cout << message << "\n"; 
	}

	/**
	 * 
	 */
	void move (Vector2f position) {
		positionOfView += position;
	}
	
	/**
	 * 
	 */
	void text (
		Text &text, 
		Vector2f position, 
		string string
	) {
		text = Text (string, font, grid);
		text.setFillColor (COLOR_TEXT);
		text.setPosition (toGrid (position));
	}

	/**
	 * 
	 */
	void text (
		Text &text, 
		Vector2f position, 
		String string
	) {
		text = Text (string, font, grid);
		text.setFillColor (COLOR_TEXT);
		text.setPosition (toGrid (position));
	}

	/**
	 *
	 */
	void textCentered (Text &text) {
		FloatRect rectangle = text.getLocalBounds();
		text.setOrigin(
			rectangle.left + 0.5 * rectangle.width,
       		rectangle.top  + 0.5 * rectangle.height
       	);
	}
	
	/**
	 * 
	 */
	bool canClick (short time) {
		return (time <= click.getElapsedTime ().asMilliseconds ());
	}

	/**
	 * 
	 */
	bool canLeft (short time) {
		if (Mouse::isButtonPressed (Mouse::Left))
			return (canClick (time));
		return false;
	}

	/**
	 * 
	 */
	bool canRight (short time) {
		if (Mouse::isButtonPressed (Mouse::Right))
			return (canClick (time));
		return false;
	}

	/**
	 * 
	 */
	void restartClick () {
		click.restart ();
	}

	/**
	 * 
	 */
	Vector2f mousePositionOnGrid () {
		return fromGrid (mousePosition ());
	}

	/**
	 * 
	 */
	Vector2f mousePosition () {
		return Vector2f (
			Mouse::getPosition ().x + positionOfView.x,
			Mouse::getPosition ().y + positionOfView.y
		);
	}

	/**
	 * 
	 */
	Vector2f mouseZoomed () {
		return zoomPoint (mousePosition ());
	}

	/**
	 *
	 */
	void move (double x, double y) {
		positionOfView += sf::Vector2f (x, y);
	}

	/**
	 * 
	 */
	Vector2f centerOfScreen () {
		return positionOfView + Vector2f (0.5 * width, 0.5 * height);
	}

	/**
	 * 
	 */
	Vector2f zoomPoint (Vector2f point) {
		return Vector2f (
           (point.x - centerOfScreen ().x) * zoomFactor + centerOfScreen ().x,
           (point.y - centerOfScreen ().y) * zoomFactor + centerOfScreen ().y
       );
	}

	/**
	 * 
	 */
	Vector2f toGrid (Vector2f vector) {
		vector.x *= grid;
		vector.y *= grid;
		return vector;
	}

	/**
	 * 
	 */
	Vector2f fromGrid (Vector2f vector) {
		vector.x /= grid;
		vector.y /= grid;
		return vector;
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
}