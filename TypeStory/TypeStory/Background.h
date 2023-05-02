#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class Background {
public:
	sf::Texture texture;
	sf::Sprite background;

	sf::Vector2u window_size;
	sf::Vector2u texture_size;

	float scaleX;
	float scaleY;
	Background(std::string, sf::RenderWindow&);
	void update(sf::RenderWindow&);
	
};