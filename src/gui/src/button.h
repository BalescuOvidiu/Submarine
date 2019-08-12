#ifndef BUTTON_H
#define BUTTON_H
#include "gui.h"

class Button {
private:
	std::vector<sf::Vertex> background;
	std::vector<sf::Vertex> border;
	sf::Text *text;
	void pressed();
public:
	//Basic
	Button(short x, short y, short width, short height, std::string text);
	//Render
	void render(sf::RenderWindow *window);
	//Transforms
	void move(float x, float y);
	void zoom(float factor);
	void setPosition(float x, float y);
	void setFontSize(short size);
	void setColor(sf::Color color);
	void setBorder(sf::Color color);
	void setBackground(sf::Color color);
	void setBackground(sf::Color a, sf::Color b);
	void setBackground(sf::Color a, sf::Color b, sf::Color c, sf::Color d);
	void setGradient(sf::Color a, sf::Color b);
	void setText(sf::Color color);
	void setText(sf::Color color, std::string text);
	void setText(std::string text);
	void setTextLeft(sf::Color color);
	//Get data
	sf::Color getBorderColor();
	//Mouse cursor
	bool mouseOver();
	//Mouse buttons
	bool left();
	bool left(sf::Color a, sf::Color b);
	bool left(sf::Color a, sf::Color b, sf::Color c, sf::Color d);
	bool left(sf::Color a, sf::Color b, sf::Color c, sf::Color d, sf::Keyboard::Key key);
	bool leftGradient(sf::Color a, sf::Color b, sf::Color c, sf::Color d);
	bool right();
	bool right(sf::Color a, sf::Color b, sf::Color c, sf::Color d);
	~Button();
};

#endif