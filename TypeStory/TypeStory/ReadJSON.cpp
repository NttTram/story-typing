#include "ReadJSON.h"
#include <fstream>

ReadJSON::ReadJSON(std::string path)
{
	//path includes the 
	std::ifstream file(path);

	if (!reader.parse(file, completeJsonData)) {
		std::cout << "JSON parse error" << std::endl;
		EXIT_FAILURE;
	}
	std::cout << "title: " << completeJsonData["title"] << std::endl;
}
//
//void NextChapter(Json::Value currentChapter)
//{
//	std::cout << "Nothing yet" << std::endl;
//}
//
Json::Value ReadJSON::getInfo(std::string key)
{
	return completeJsonData[key];
}