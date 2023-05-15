#include "Textbox.h"

Textbox::Textbox(sf::Font& font, float posX, float posY) : selected(false) {
	textbox.setSize(sf::Vector2f(1180, 200));
	textbox.setPosition(posX, posY);
	textbox.setFillColor(sf::Color(255, 255, 255, 50));

	text.setFont(font);
	text.setCharacterSize(35);
	text.setPosition(posX + 10, posY + 10);
	text.setFillColor(sf::Color(50, 50, 50));
	character = 0;
	this->posX = posX + 10;
	this->posY = posY + 10;
	
	display_story.setFont(font);
	display_story.setCharacterSize(35);
	display_story.setPosition(posX + 10, posY + 10);
	display_story.setFillColor(sf::Color(255,0,0,50));

}


void Textbox::draw(sf::RenderWindow& window) const{

	window.draw(textbox);
	window.draw(display_story);
	window.draw(text);

 }

bool Textbox::update(sf::RenderWindow& window, sf::Event& event) {
	
	//Check to see if user click on textbox if so change the textbox colour
	clickTextbox(window);
	textWarp(event, display_story, story_input);

	if (selected) {
		//warp text within textbox
		textWarp(event, text, input);	
		

		return 1;
	}
	return 0;

}


//bool Textbox::checkInput(sf::Event& event) {
//	if (event.type == sf::Event::TextEntered) {
//		if ((char)event.text.unicode != 
//	}
//}


void Textbox::textWarp(sf::Event& event, sf::Text& txt, sf::String& txt_input) {

	if (event.type == sf::Event::TextEntered) {

		//ignore nothing and tab 
		if (event.text.unicode == '\0' || event.text.unicode == '\t') {} //tab and enter does nothing;
		else if (event.text.unicode == 8) { //backspace
			txt_input = txt_input.substring(0, txt_input.getSize() - 1);
			txt.setString(txt_input); //remove the last letter
		}

		else if (txt.findCharacterPos(-1).x < 1200) { //when the position of the last character is less than 1200
			txt_input += (char)event.text.unicode;
			txt.setString(txt_input);

		}
		else if (txt.findCharacterPos(-1).x >= 1200) {
			//create newline when out of bound based on the last character's position. 
			txt_input += "\n";
			txt_input += (char)event.text.unicode;
			txt.setString(txt_input);
			if (txt.findCharacterPos(-1).y > 645) { // when text vertically out of textbox
				txt_input = "";
				std::cout << "Here" << std::endl;
				txt_input += (char)event.text.unicode;
				txt.setString(txt_input);
			}
			

		}


	}
}

void Textbox::typeWriter(std::string str_story) {
	//Typewriter effect
	if (timer.getElapsedTime().asSeconds() > 0.1 && character < str_story.size()) {
		timer.restart();
		character++;
		display_story.setString(str_story.substr(0, character));
	}
}

void Textbox::clickTextbox(sf::RenderWindow& window) {

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
}

float Textbox::getWidth() const {
	return text.getLocalBounds().width;
}

void Textbox::setPosition(float posX, float posY) {
	textbox.setPosition(posX, posY);
	text.setPosition(posX + 10, posY + 1);
}


sf::Text Textbox::loadStory(std::string story, sf::RenderWindow& window) {
	std::cout << "story: " << story << std::endl;
	typeWriter(story);
	draw(window);

	return display_story;
}
