#include "Story.h"

Story::Story(Json::Value jsonData) {
	Json::StreamWriterBuilder builder;
	title = Json::writeString(builder, jsonData["title"]);
	author = Json::writeString(builder, jsonData["author"]);
	description = Json::writeString(builder, jsonData["desciption"]);
}

Story::~Story()
{
}

void Story::newChapter() {
	
	Json::Value json_value;
	json_value["text"] = "";
	json_value["image"] = "";
	json_value["sound"] = "";
 	std::string filename = "../stories/Cat-Adventure/chapter" + std::to_string(chapter_numbers+1) + ".json";
	
	//create and open .json file to writing
	std::ofstream file(filename);
	if (file.is_open()) {
		Json::StreamWriterBuilder builder;
		std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
		writer->write(json_value, &file);
		std::cout << "File created successfully." << std::endl;
	}
	else {
		std::cerr << "Failed to create file." << std::endl;
	}
	chapter_numbers++;

}

void Story::editChapter(int chap_num, std::string key, std::string add_text) {
	std::string filename = "../stories/Cat-Adventure/chapter" + std::to_string(chap_num-1) + ".json";
	Json::Value json_value;

	//read .json file and put it into json_value;
	std::ifstream open_file(filename);
	open_file >> json_value;
	
	json_value[key] = add_text;

	//open .json file for writing and error checking
	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Failed to open file." << std::endl;
		}

	Json::StreamWriterBuilder builder;
	std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
	writer->write(json_value, &file);

	//close file
	file.close();

	std::cout << "Json data written to file" << std::endl;
}

std::string Story::getText(int chap_num) {
	 std::string filename = "../stories/Cat-Adventure/chapter" + std::to_string(chap_num-1) + ".json";
	 Json::Value json_value;

	 //open .json file for read
	 std::ifstream open_file(filename);
	 open_file >> json_value;
	 
	 //Json value to string;
	 std::ostringstream output;
	 Json::StreamWriterBuilder builder;
	 std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
	 writer->write(json_value["text"], &output);
	 std::string json_string = output.str();

	 return json_string;
	       
}
