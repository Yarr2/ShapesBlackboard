#pragma once
#include <iostream>
#include <string>
class Color
{
	uint8_t _r = 0;
	uint8_t _g = 0;
	uint8_t _b = 0;
	bool _correct_color = true;
public:
	std::string ColorText(std::string text);
	std::string getRGBdefinition();
	bool is_correct_color() { return _correct_color; };
	Color(int r, int g, int b);
	Color(std::string color);
};

