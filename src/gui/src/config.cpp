#include "config.h"

using namespace std;
using namespace sf;
using namespace mathematics;

/** Files directories. */
#define FILE_CONFIGURATION "data/configuration.txt"
#define FILE_FONT          "data/Verdana.ttf"
#define FILE_LOG           "data/log.txt"   

namespace config {
	/** Font variable. */
	Font font;

	/** Variables of screen. */
	const unsigned width = sf::VideoMode::getDesktopMode ().width;
	const unsigned height = sf::VideoMode::getDesktopMode ().height;
	const double grid = width * 0.01;

	Vector2f positionOfView = sf::Vector2f (0, 0);

	unsigned frameRate = 60;

	/** Variables for precision. */
	bool exitStatus = false;
	double moveViewSpeed = 10.0;
	double circlePrecision = 5.0;
	unsigned decimalsNumber = 1;

	/** Variables of view. */
	double zoomFactor = 1;

	/** Communications. */
	string nameOfApplication = "Unknown";
	string timeFormat = "%Y-%m-%d, %I:%M%p - ";
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
	 */;
	unsigned getWidth (short percent) {
		return width * percent / 100;
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
		return height * percent / 100;
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
		
		/** Config file. */
		ifstream settings (FILE_CONFIGURATION);
		if (settings.is_open ()) {
			getline (settings, nameOfApplication);
			getline (settings, timeFormat);
			settings >> frameRate;
			settings >> moveViewSpeed;
			settings >> circlePrecision;
			settings >> decimalsNumber;

			logMessage ("Execution of " + nameOfApplication + " begins.");
			logMessage (
				"File " + string (FILE_CONFIGURATION) + " was loaded!"
			);
		}
		else {

			logMessage ("Execution of " + nameOfApplication + " begins.");
			logMessage (
				"File " + string (FILE_CONFIGURATION) + " doesn't found!"
			);			
		}

		settings.close ();

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
  		char buffer [80];

		strftime (buffer, 80, timeFormat.c_str (), timeinfo);

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
			rectangle.left + rectangle.width /2.0,
       		rectangle.top  + rectangle.height/2.0
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
		return 0;
	}

	/**
	 * 
	 */
	bool canRight (short time) {
		if (Mouse::isButtonPressed (Mouse::Right))
			return (canClick (time));
		return 0;
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
		return positionOfView + Vector2f (width * 0.5, height * 0.5);
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
		stringstream stream;
		stream<<fixed<<setprecision (decimalsNumber)<<value;
		return stream.str ();
	}

	/**
	 *
	 */
	string format (short value) {

		if (value < 1000) {
			return toString (value);
		}

		string text = toString (value / 1000) + ".";
		text += toString (value / 100 % 10) + " k";

		return text;
	}

	/**
	 *
	 */
	string format (int value) {

		if (value < 1000) {
			return toString (value);
		}

		string text = toString (value / 1000) + ".";
		text += toString (value / 100 % 10) + " k";

		return text;
	}

	/**
	 *
	 */
	string format (unsigned value) {

		if (value < 1000) {
			return toString (value);
		}

		string text = toString (value / 1000) + ".";
		text += toString (value / 100 % 10) + " k";

		return text;
	}
}