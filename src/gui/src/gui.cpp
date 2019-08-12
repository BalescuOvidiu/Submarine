#include "gui.h"

namespace gui {
	// Font variable
	sf::Font font;

	// Variables of screen
	const unsigned width = sf::VideoMode::getDesktopMode ().width;
	const unsigned height = sf::VideoMode::getDesktopMode ().height;
	const double grid = width * 0.01;

	// Variables of view
	double zoomFactor = 1;
	sf::Vector2f positionOfView = sf::Vector2f (0, 0);

	// Communications
	std::fstream log;

	// Time
	sf::Clock click;

	/**
	 * 
	 */
	void initialize () {
		log.open (FILE_LOG, std::fstream::out | std::fstream::app);
		if (!font.loadFromFile (FILE_FONT)) {
			LOG ("File " << FILE_FONT << " not found!");
		}
		else {
			LOG ("Font was loaded!");
		}
		LOG ("Execution of " << NAME << " has begun at " << __DATE__ << " " << __TIME__ << ".");
	}

	/**
	 * 
	 */
	void move (sf::Vector2f position) {

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
		text.setColor (COLOR_TEXT);
		text.setPosition (position);
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
		text.setColor (COLOR_TEXT);
		text.setPosition (position);
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