#pragma once
#include "Board.h"
class Serialiser
{
public:
	static std::string serialize_board(Board* board);
	static Board* decerialise(std::string file_path);
};

