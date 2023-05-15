#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "TypeStory/Background.h"
#include "TypeStory/ReadJSON.h"
#include "TypeStory/Story.h"
#include "TypeStory/Textbox.h"

int main()
{
	//Setup window size(pixels) and title
	sf::RenderWindow window(sf::VideoMode(1280, 720), "TypeStory");
	window.setFramerateLimit(60); //Set frame limit to 60hz

	// Brief/temp info
	std::string title = "Twins";
	std::string author = "Mandy Thai";
	std::string description = "Lily. She lived with her parents in a cozy little house on the edge of the village. Lily was known for her love of adventure and exploration, often wandering deep into the forest to discover new things. One day, while exploring, Lily came across an oldand rusted key lying on the ground.Intrigued, she picked it upand decided to find out what it unlocked.After searching for hours, she finally found an old chest hidden deep in the forest.She used the key to unlock itand inside, she found a map.";

	sf::Event event;

	//Setup font for text
	sf::Font font;
	if (!font.loadFromFile("../font/jmh_typewriter/JMHTypewriter.ttf"))
	{
		std::cout << "font not loaded"<<std::endl; //Cant find the font file; Check the address
	}
	
	std::string bg_path = "../images/bg.jpg";
	Background bg(bg_path, window);

	//Json reader
	ReadJSON json_file("../stories/Cat-Adventure/info.json");

	//Story.h init
	Story story_1(json_file.completeJsonData);
	story_1.newChapter();
	story_1.newChapter();
	story_1.editChapter(1, "text", title);
	story_1.editChapter(2, "text", description);
	std::cout << "chapter 2: " << story_1.getText(2) << std::endl;

	// Textbox section
	Textbox textbox(font, 50, 500);

	//to change chapter by pressing enters
	int i = 1;

	//Sprites section
	sf::Texture sprite_texture;
	sprite_texture.loadFromFile("../images/Walk.png");
	sf::Sprite sprite(sprite_texture);


	while (window.isOpen()) {

		//pollEvent is when it detect new event. 
		//This helps with textentered else 
		//it will loop the same key = printing multiple "a" when only pressed "a" once
		
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			
			textbox.update(window, event);

			if (event.type == sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::Enter && i < story_1.chapter_numbers) {
					i++;
				}

			}

			
		}
		

		window.clear();
		window.setActive(); //Activate the window for OpenGL rendering
		bg.update(window);
		//any text should be below this
		//textbox.draw(window);

		//
		//
		//sf::Text loaded_story = textbox.loadStory(story_1.getText(i), window);
		//std::string temp_str = loaded_story.getString();
		
		window.draw(sprite);

		window.display();
		
	}

	return 0;
}