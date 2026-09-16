#include "Color.h"
Color::Color(int r, int g, int b) {
	_r = r;
	_g = g;
	_b = b;
}
Color::Color(const std::string color) {
	
	std::cout << "Not implemented\n";
}

std::string Color::get_desc() {
	return ";" + std::to_string(_r) +
		";" + std::to_string(_g) +
		";" + std::to_string(_b) + 'm';
}