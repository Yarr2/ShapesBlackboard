#pragma once
#include <fstream>
#include <iostream>
#include <sstream>

class FileManager
{
public:
	static void save(std::string file_path, std::string data);
	static std::string load(std::string file_path);

};

