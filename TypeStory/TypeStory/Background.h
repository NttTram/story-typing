#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class Background {
public:
	Background(std::string path, sf::RenderWindow& window);
	void update(sf::RenderWindow&);

private: 
	sf::Texture texture;
	sf::Sprite background;

	sf::Vector2u window_size;
	sf::Vector2u texture_size;

	float scaleX;
	float scaleY;
};