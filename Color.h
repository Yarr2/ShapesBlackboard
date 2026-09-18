#pragma once
#include <iostream>
#include <string>
class Color
{
	uint8_t _r = 0;
	uint8_t _g = 0;
	uint8_t _b = 0;
public:
	Color(int r, int g, int b);
	Color(std::string color);
	std::string get_desc();
};

