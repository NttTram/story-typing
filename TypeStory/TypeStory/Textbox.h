#pragma once

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <json/json.h>
#include <ostream>


class Textbox {

public:
	Textbox(sf::Font&, float, float);
	void draw(sf::RenderWindow&) const;
	bool update(sf::RenderWindow&, sf::Event&);

	float getWidth() const;

	bool bound_check = false;
	float posX, posY;
	void setPosition(float, float);
	bool selected;
	sf::RectangleShape textbox;

	//Typerwriter effect
	sf::Clock timer;
	unsigned int character;
	sf::Text display_text;

	sf::Text loadStory(std::string, sf::RenderWindow&);
	//bool endOfChapter(std::string);

private: 
	sf::String input;
	sf::Text text;
	
	
	sf::Text display_story;
	bool checkInput(sf::Event&);
	
	void textWarp(sf::Event&);
	void typeWriter(std::string);
	void clickTextbox(sf::RenderWindow&);
};