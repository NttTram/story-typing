#include "Background.h"

Background::Background(std::string path, sf::RenderWindow& window) {
	//get texture from path
	if (!texture.loadFromFile(path)) {} 
	texture.setSmooth(false); //smooth texture so no blurr

	background.setTexture(texture);
	
	//set sizes
	window_size = window.getSize();
	texture_size = texture.getSize();

	//assign the x and y scales to fit the image to the window
	scaleX = (float)window_size.x / texture_size.x;
	scaleY = (float)window_size.y / texture_size.y;
	background.setScale(scaleX, scaleY);
}

void Background::update(sf::RenderWindow& window) {
	//draw background
	window.draw(background);
}