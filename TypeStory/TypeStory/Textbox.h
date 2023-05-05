#pragma once

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <json/json.h>

class Textbox {

public:
	Textbox(sf::Font&, float, float);
	void draw(sf::RenderWindow&) const;
	bool update(sf::RenderWindow&, sf::Event&);

	float getWidth() const;

	void setPosition(float, float);
	bool selected;
	sf::RectangleShape textbox;

	//Typerwriter effect
	sf::Clock timer;
	unsigned int character;
	sf::Text display_text;

private: 
	sf::String input;
	sf::Text text;

};