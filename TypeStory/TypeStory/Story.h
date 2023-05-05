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
	std::vector <std::string> chapters;
	int chapter_numbers = 0;
	Json::Value json_value;

	//Methods
	Story(Json::Value);
	~Story();

	void newChapter();
	void editChapter(int, std::string, std::string);


};