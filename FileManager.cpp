#include "FileManager.h"


void FileManager::save(std::string file_path, std::string data) {
	std::ofstream file(file_path);

	if (file.is_open()) {
		file << data;
	}
	else {
		std::cout << "File could not open. \n";
	}
	file.close();
}
std::string FileManager::load(std::string file_path) {
	std::ifstream file(file_path);

	if (!file.is_open()) {
		std::cout << "Error opening file!\n";
		return "";
	}
	std::string text = "";
	std::string line;
	while (std::getline(file, line)) {
		text += line + "\n";
	}

	file.close();
	return text;
}