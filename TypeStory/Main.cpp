#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>


int main()
{
	//Setup window size(pixels) and title
	sf::RenderWindow window(sf::VideoMode(1280, 720), "TypeStory");
	window.setFramerateLimit(60); //Set frame limit to 60hz

	// Brief/temp info
	std::string title = "Twins";
	std::string author = "Mandy Thai";
	std::string description = "About a set of twins in a family of assassin got separated.";

	sf::Event event;

	//Setup font for text
	sf::Font font;
	if (!font.loadFromFile("../font/jmh_typewriter/JMHTypewriter.ttf"))
	{
		std::cout << "font not loaded"<<std::endl; //Cant find the font file; Check the address
	}

	sf::Texture texture;
	if (!texture.loadFromFile("../images/bg.jpg")) {
		std::cout << "background image not found" << std::endl; //Cant find background imgae
	}


	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.setActive(); //Activate the window for OpenGL rendering

		window.display();
	}

	return 0;
}