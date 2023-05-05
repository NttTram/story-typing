#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <json/json.h>
#include <fstream>

class ReadJSON {
public:
	Json::Reader reader;
	Json::Value completeJsonData;

	ReadJSON(std::string);
	/*void NextChapter(Json::Value);*/
	Json::Value getInfo(std::string);
};