#pragma once
#include <SFML/Graphics.hpp>


class Animation
{
public:
	Animation(sf::Texture* tecture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	sf::Vector2u uvRect;

private:

	sf::Vector2u currentImage;
	sf::Vector2u imageCount;

	float totalTime;
	float switchTime;
};

