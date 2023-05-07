#include "Textbox.h"

Textbox::Textbox(sf::Font& font, float posX, float posY) : selected(false) {
	textbox.setSize(sf::Vector2f(1180, 200));
	textbox.setPosition(posX, posY);

	text.setFont(font);
	text.setCharacterSize(35);
	text.setPosition(posX + 10, posY + 1);
	textbox.setFillColor(sf::Color(255, 255, 255, 50));
	text.setFillColor(sf::Color(50, 50, 50));
	character = 0;

}


void Textbox::draw(sf::RenderWindow& window) const{

	window.draw(textbox);
	window.draw(text);

 }

bool Textbox::update(sf::RenderWindow& window, sf::Event& event) {
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		//textboxx is selected
		if (textbox.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
			selected = true;

			textbox.setFillColor(sf::Color(255, 255, 255, 150));
			text.setFillColor(sf::Color(50, 50, 50));
		}
		else {
			selected = false;
			textbox.setFillColor(sf::Color(255, 255, 255, 50));
			text.setFillColor(sf::Color(50, 50, 50, 200)); 
		}
	} //end if

	//Typewriter effect
	/*if (timer.getElapsedTime().asSeconds() > 0.005 && character < input.getSize()) {
		timer.restart();
		character++;
		text.setString(input.substring(0, character));
	}*/

	std::array<bool, sf::Keyboard::KeyCount> keyState;
	keyState.fill(true);

	if (selected) {
		
		if (event.type == sf::Event::TextEntered ) {
			
			//ignore nothing and tab 
			if(event.text.unicode == '\0' || event.text.unicode == '\t'){}
			else if (event.text.unicode == 8) { //backspace
				input = input.substring(0, input.getSize() - 1);
				text.setString(input); //remove the last letter
			}
			else if (text.getGlobalBounds().width < 1140) {
				input += (char)event.text.unicode;
				std::cout << event.text.unicode << std::endl;
				text.setString(input);
			}
			
			
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			// Update state of current key:
			keyState[event.key.code] = false;
		}
		return 1;
	}
	return 0;

}

float Textbox::getWidth() const {
	return text.getLocalBounds().width;
}

void Textbox::setPosition(float posX, float posY) {
	textbox.setPosition(posX, posY);
	text.setPosition(posX + 10, posY + 1);
}
