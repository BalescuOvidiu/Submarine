#include "gui.h"

using namespace std;
using namespace sf;

namespace gui {
	// Font variable
	Font font;

	// Variables of screen
	const unsigned width = VideoMode::getDesktopMode ().width;
	const unsigned height = VideoMode::getDesktopMode ().height;
	const double grid = width * 0.01;

	// Variables for precision
	bool exit = false;
	double moveViewSpeed = 10.0;
	double circlePrecision = 5.0;
	unsigned decimalsNumber = 1;

	// Variables of view
	double zoomFactor = 1;
	Vector2f positionOfView = Vector2f (0, 0);

	// Communications
	string name = "Unknown";
	string timeFormat = "%Y-%m-%d, %I:%M%p - ";
	fstream log (FILE_LOG, fstream::out | fstream::app);
	time_t currentTime = time(0);

	// Time
	Clock click;

	/**
	 * 
	 */
	void initialize () {
		
		// Config file
		ifstream config (FILE_CONFIG);
		if (config.is_open ()) {
			getline (config, name);
			getline (config, timeFormat);
			config >> moveViewSpeed;
			config >> circlePrecision;
			config >> decimalsNumber;

			LOG ("Execution of " + name + " begins.");
			LOG (
				"File " + string (FILE_CONFIG) + " was loaded!"
			);
		}
		else {

			LOG ("Execution of " + name + " begins.");
			LOG (
				"File " + string (FILE_CONFIG) + " doesn't found!"
			);			
		}

		config.close ();

		// Vertex buffer
		if (VertexBuffer::isAvailable ()) {
			LOG ("The VertexBuffer is available.");
		}
		else {
			LOG ("The VertexBuffer is not available.");			
		}

		// Font file
		if (!font.loadFromFile (FILE_FONT)) {
			LOG (
				"File " + string (FILE_FONT) + " doesn't found!"
			);
		}
		else {
			LOG (
				"File " + string (FILE_FONT) + " was loaded!"
			);
		}

	}

	/**
	 * 
	 */
	void logMessage (string message) {
		// Time
		currentTime = time(0);
		tm* timeinfo = localtime (&currentTime);
  		char buffer [80];

		strftime (buffer, 80, timeFormat.c_str (), timeinfo);

		// Message on file
		if (log.is_open ()) {
			log << buffer;
			log << message;
		}

		// Message on console
		cout << buffer;
		cout << message; 
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
	void textCenter (Text &text) {
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
			return to_string (value);
		}

		string text = to_string (value / 1000) + ".";
		text += to_string (value / 100 % 10) + " k";

		return text;
	}

	/**
	 *
	 */
	string format (int value) {

		if (value < 1000) {
			return to_string (value);
		}

		string text = to_string (value / 1000) + ".";
		text += to_string (value / 100 % 10) + " k";

		return text;
	}

	/**
	 *
	 */
	string format (unsigned value) {

		if (value < 1000) {
			return to_string (value);
		}

		string text = to_string (value / 1000) + ".";
		text += to_string (value / 100 % 10) + " k";

		return text;
	}
}