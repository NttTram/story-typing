#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <json/json.h>
#include <fstream>

class Story {
public:
	//Variables
	std::string title;
	std::string author;
	std::string description;
	int chapter_numbers = 0;
	
	

	//Methods
	//Create a new story -> info.json -> title, author. description
	Story(Json::Value);
	~Story();

	//Add new chapter
	void newChapter();
	//edit chapter based on key: "text", "image", "sound"
	void editChapter(int, std::string, std::string);

	//Get text for certain chapter number (int)
	std::string getText(int);


};