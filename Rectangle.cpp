#include "Rectangle.h"
#include "Color.h"
#include <string>

std::vector<std::vector<std::string>>* Rectangle::draw() {
	std::vector<std::vector<std::string>>* board = _bounding_box.get_empty_rect();
	
	for (auto& row : board[0]) {
		for (auto& string : row) {
			string = _color.ColorText(std::string(2,char(219)));
		}
	}
	return board;
}
std::string Rectangle::get_desc() {
	return std::to_string(_id) + " Rectangle";
}