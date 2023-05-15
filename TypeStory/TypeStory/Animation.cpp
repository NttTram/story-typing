#include "Animation.h"



Animation::Animation(sf::Texture* tecture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;

	totalTime = 0.0f;
	
	currentImage.x = 0;

}
