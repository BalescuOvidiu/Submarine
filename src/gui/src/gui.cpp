#include "gui.h"

namespace gui {
	// Font variable
	sf::Font font;

	// Variables of screen
	const unsigned width = sf::VideoMode::getDesktopMode ().width;
	const unsigned height = sf::VideoMode::getDesktopMode ().height;
	const double grid = width * 0.01;
	double moveViewSpeed = 10.0;
	double circlePrecision = 5.0;
	bool exit = false;

	// Variables of view
	double zoomFactor = 1;
	sf::Vector2f positionOfView = sf::Vector2f (0, 0);

	// Communications
	std::string name = "Unknown";
	std::string timeFormat = "%Y-%m-%d, %I:%M%p - ";
	std::fstream log (FILE_LOG, std::fstream::out | std::fstream::app);
	time_t currentTime = time(0);

	// Time
	sf::Clock click;

	/**
	 * 
	 */
	void initialize () {
		
		// Config file
		std::ifstream config (FILE_CONFIG);
		if (config.is_open ()) {
			std::getline (config, name);
			std::getline (config, timeFormat);
			config >> moveViewSpeed;
			config >> circlePrecision;

			LOG ("Execution of " + name + " begins.");
			LOG (
				"File " + std::string (FILE_CONFIG) + " was loaded!"
			);
		}
		else {

			LOG ("Execution of " + name + " begins.");
			LOG (
				"File " + std::string (FILE_CONFIG) + " doesn't found!"
			);			
		}

		// Vertex buffer
		if (sf::VertexBuffer::isAvailable ()) {
			LOG ("The VertexBuffer is available.");
		}
		else {
			LOG ("The VertexBuffer is not available.");			
		}

		config.close ();

		// Font file
		if (!font.loadFromFile (FILE_FONT)) {
			LOG (
				"File " + std::string (FILE_FONT) + " doesn't found!"
			);
		}
		else {
			LOG (
				"File " + std::string (FILE_FONT) + " was loaded!"
			);
		}

	}

	/**
	 * 
	 */
	void logMessage (std::string message) {
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
		std::cout << buffer;
		std::cout << message; 
	}

	/**
	 * 
	 */
	void move (sf::Vector2f position) {
		positionOfView += position;
	}
	
	/**
	 * 
	 */
	void text (
		sf::Text &text, 
		sf::Vector2f position, 
		std::string string
	) {
		text = sf::Text (string, font, grid);
		text.setFillColor (COLOR_TEXT);
		text.setPosition (toGrid (position));
	}

	/**
	 * 
	 */
	void text (
		sf::Text &text, 
		sf::Vector2f position, 
		sf::String string
	) {
		text = sf::Text (string, font, grid);
		text.setFillColor (COLOR_TEXT);
		text.setPosition (toGrid (position));
	}

	/**
	 *
	 */
	void textCenter (sf::Text &text) {
		sf::FloatRect rectangle = text.getLocalBounds();
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
		if (sf::Mouse::isButtonPressed (sf::Mouse::Left))
			return (canClick (time));
		return 0;
	}

	/**
	 * 
	 */
	bool canRight (short time) {
		if (sf::Mouse::isButtonPressed (sf::Mouse::Right))
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
	sf::Vector2f mousePosition () {
		return sf::Vector2f (
			sf::Mouse::getPosition ().x + positionOfView.x,
			sf::Mouse::getPosition ().y + positionOfView.y
		);
	}

	/**
	 * 
	 */
	sf::Vector2f mouseZoomed () {
		return zoomPoint (mousePosition ());
	}

	/**
	 * 
	 */
	sf::Vector2f centerOfScreen () {
		return positionOfView + sf::Vector2f (width * 0.5, height * 0.5);
	}

	/**
	 * 
	 */
	sf::Vector2f zoomPoint (sf::Vector2f point) {
		return sf::Vector2f (
		           (point.x - centerOfScreen ().x) * zoomFactor + centerOfScreen ().x,
		           (point.y - centerOfScreen ().y) * zoomFactor + centerOfScreen ().y
		       );
	}

	/**
	 * 
	 */
	sf::Vector2f toGrid (sf::Vector2f vector) {
		vector.x *= grid;
		vector.y *= grid;
		return vector;
	}

	/**
	 * 
	 */
	sf::Vector2f fromGrid (sf::Vector2f vector) {
		vector.x /= grid;
		vector.y /= grid;
		return vector;
	}
}