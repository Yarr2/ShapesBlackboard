#include "Color.h"
#include <sstream>


Color::Color(int r, int g, int b) {
	_r = r;
	_g = g;
	_b = b;
}
Color::Color(const std::string color) {
	
	if (color == "red") {
		_r = 255;
		_g = 0;
		_b = 0;
		return;
	}
	if (color == "green") {
		_r = 0;
		_g = 255;
		_b = 0;
		return;
	}
	if (color == "blue") {
		_r = 0;
		_g = 0;
		_b = 255;
		return;
	}

	
	std::stringstream color_input(color);
	int RED, GREEN, BLUE;
	char a, b;
	if (color_input
		>> RED
		>> a
		>> GREEN
		>> b
		>> BLUE)
	{
		if (a == '-' && b == '-') {
			_r = RED;
			_g = GREEN;
			_b = BLUE;
			return;
		}
		return;
	}
	

	return;
}
std::string Color::getRGBdefinition() {
	return std::to_string(_r) + '-'
		+ std::to_string(_g) + '-'
		+ std::to_string(_b);
}
std::string Color::ColorText(std::string text) {
	return "\033[38;2;"
		+ std::to_string(_r) + ';'
		+ std::to_string(_g) + ';'
		+ std::to_string(_b) + 'm' + text + "\033[0m";
}