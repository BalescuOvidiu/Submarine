#include "button.h"
// Basic
Button::Button(short x, short y, short width, short height, std::string text) {
	// Background
	background.push_back(sf::Vertex(sf::Vector2f(x, y)));
	background.push_back(sf::Vertex(sf::Vector2f(x + width, y)));
	background.push_back(sf::Vertex(sf::Vector2f(x + width, y + height)));
	background.push_back(sf::Vertex(sf::Vector2f(x, y + height)));
	// Border
	border.push_back(sf::Vertex(sf::Vector2f(x, y)));
	border.push_back(sf::Vertex(sf::Vector2f(x + width, y)));
	border.push_back(sf::Vertex(sf::Vector2f(x + width, y + height)));
	border.push_back(sf::Vertex(sf::Vector2f(x, y + height)));
	border.push_back(sf::Vertex(sf::Vector2f(x, y)));
	// Text
	this->text = new sf::Text();
	this->text->setString(sf::String(text));
	this->text->setFont(gui::font);
	this->text->setCharacterSize(20);
	this->text->setPosition(x + (width - this->text->getLocalBounds().width) * 0.5, y + height * 0.25 - this->text->getLocalBounds().height * 0.25);
}
// Render
void Button::render(sf::RenderWindow *window) {
	window->draw(&this->background[0], this->background.size(), sf::Quads);
	window->draw(&this->border[0], this->border.size(), sf::LinesStrip);
	window->draw(*this->text);
}
// Transforms
void Button::move(float x, float y) {
	// Background
	for (unsigned i = 0; i < 4; i++) {
		this->background[i].position.x += x;
		this->background[i].position.y += y;
	}
	// Border
	for (unsigned i = 0; i < 5; i++) {
		this->border[i].position.x += x;
		this->border[i].position.y += y;
	}
	this->text->move(x, y);
}
void Button::zoom(float factor) {
	// Background
	for (unsigned i = 0; i < 4; i++) {
		this->background[i].position = gui::zoomPoint(this->background[i].position);
	}
	// Border
	for (unsigned i = 0; i < 5; i++) {
		this->border[i].position = gui::zoomPoint(this->border[i].position);
	}
	// Text
	this->text->setPosition(gui::zoomPoint(this->text->getPosition()));
	this->text->setScale(factor, factor);
}
void Button::setPosition(float x, float y) {
	short width = border[1].position.x - border[0].position.x;
	short height = border[3].position.y - border[0].position.y;
	// Background
	background[0].position = sf::Vector2f(x, y);
	background[1].position = sf::Vector2f(x + width, y);
	background[2].position = sf::Vector2f(x + width, y + height);
	background[3].position = sf::Vector2f(x, y + height);
	// Border
	border[0].position = sf::Vector2f(x, y);
	border[1].position = sf::Vector2f(x + width, y);
	border[2].position = sf::Vector2f(x + width, y + height);
	border[3].position = sf::Vector2f(x, y + height);
	border[4].position = sf::Vector2f(x, y);
	// Text
	this->text->setPosition(
	    x + (width - this->text->getLocalBounds().width) * 0.5,
	    y + (height - this->text->getLocalBounds().height) * 0.25
	);
}
void Button::setFontSize(short size) {
	this->text->setCharacterSize(size);
	this->setPosition(this->border[0].position.x, this->border[0].position.y);
}
void Button::setColor(sf::Color color) {
	for (unsigned i = 0; i < 5; i++)
		this->border[i].color = color;
	this->text->setColor(color);
}
void Button::setBorder(sf::Color color) {
	for (unsigned i = 0; i < 5; i++)
		this->border[i].color = color;
}
void Button::setBackground(sf::Color color) {
	for (unsigned i = 0; i < 4; i++)
		this->background[i].color = color;
}
void Button::setBackground(sf::Color a, sf::Color b) {
	this->background[0].color = a;
	this->background[1].color = a;
	this->background[2].color = b;
	this->background[3].color = b;
}
void Button::setBackground(sf::Color a, sf::Color b, sf::Color c, sf::Color d) {
	this->background[0].color = a;
	this->background[1].color = b;
	this->background[2].color = c;
	this->background[3].color = d;
}
void Button::setGradient(sf::Color a, sf::Color b) {
	this->background[0].color = a;
	this->background[1].color = b;
	this->background[2].color = b;
	this->background[3].color = a;
}
void Button::setText(sf::Color color) {
	this->text->setColor(color);
}
void Button::setText(sf::Color color, std::string text) {
	this->text->setColor(color);
	this->text->setString(sf::String(text));
}
void Button::setText(std::string text) {
	this->text->setString(sf::String(text));
}
void Button::setTextLeft(sf::Color color) {
	this->text->setColor(color);
	this->text->setPosition(this->border[0].position.x + 5, this->border[0].position.y + 5);
}
// Mouse cursor
bool Button::mouseOver() {
	if (gui::mouseZoomed().x >= this->border[0].position.x) {
		if (gui::mouseZoomed().x <= this->border[1].position.x) {
			if (gui::mouseZoomed().y >= this->border[0].position.y) {
				return gui::mouseZoomed().y <= this->border[2].position.y;
			}
		}
	}
	return 0;
}
// Get data
sf::Color Button::getBorderColor() {
	return this->border[0].color;
}
// Mouse button
bool Button::left() {
	if (this->mouseOver()) {
		if (gui::canLeft(400)) {
			this->pressed();
			return 1;
		}
	}
	return 0;
}
bool Button::left(sf::Color a, sf::Color b) {
	if (this->mouseOver()) {
		for (unsigned i = 0; i < 5; i++)
			this->border[i].color = a;
		if (gui::canLeft(400)) {
			this->pressed();
			return 1;
		}
	} else {
		for (unsigned i = 0; i < 5; i++)
			this->border[i].color = b;
	}
	return 0;
}
bool Button::left(sf::Color a, sf::Color b, sf::Color c, sf::Color d) {
	if (this->mouseOver()) {
		this->background[0].color = a;
		this->background[1].color = a;
		this->background[2].color = b;
		this->background[3].color = b;
		if (gui::canLeft(400)) {
			this->pressed();
			return 1;
		}
	} else {
		this->background[0].color = c;
		this->background[1].color = c;
		this->background[2].color = d;
		this->background[3].color = d;
	}
	return 0;
}
bool Button::left(sf::Color a, sf::Color b, sf::Color c, sf::Color d, sf::Keyboard::Key key) {
	// Mouse
	if (this->mouseOver()) {
		this->background[0].color = a;
		this->background[1].color = a;
		this->background[2].color = b;
		this->background[3].color = b;
		if (gui::canLeft(400)) {
			this->pressed();
			return 1;
		}
	} else {
		this->background[0].color = c;
		this->background[1].color = c;
		this->background[2].color = d;
		this->background[3].color = d;
	}
	// Key
	if (gui::canClick(400)) {
		if (sf::Keyboard::isKeyPressed(key)) {
			this->pressed();
			this->background[0].color = a;
			this->background[1].color = a;
			this->background[2].color = b;
			this->background[3].color = b;
			return 1;
		}
	}
	return 0;
}
bool Button::leftGradient(sf::Color a, sf::Color b, sf::Color c, sf::Color d) {
	if (this->mouseOver()) {
		this->background[0].color = a;
		this->background[1].color = b;
		this->background[2].color = b;
		this->background[3].color = a;
		if (gui::canLeft(400)) {
			this->pressed();
			return 1;
		}
	} else {
		this->background[0].color = c;
		this->background[1].color = d;
		this->background[2].color = d;
		this->background[3].color = c;
	}
	return 0;
}
bool Button::right() {
	if (this->mouseOver()) {
		if (gui::canRight(400)) {
			this->pressed();
			return 1;
		}
	}
	return 0;
}
bool Button::right(sf::Color a, sf::Color b, sf::Color c, sf::Color d) {
	if (this->mouseOver()) {
		this->background[0].color = a;
		this->background[1].color = a;
		this->background[2].color = b;
		this->background[3].color = b;
		if (gui::canRight(400)) {
			this->pressed();
			return 1;
		}
	} else {
		this->background[0].color = c;
		this->background[1].color = c;
		this->background[2].color = d;
		this->background[3].color = d;
	}
	return 0;
}
void Button::pressed() {
	gui::restartClick();
}
Button::~Button() {
	this->text = NULL;
	this->background.clear();
	this->border.clear();
}