#include "Rectangle.h"
#include "Color.h"
std::vector<std::vector<std::string>>* Rectangle::draw() {
	std::vector<std::vector<std::string>>* board = _bounding_box.get_empty_rect();
	for (auto& row : board[0]) {
		for (auto& string : row) {
			string = "\033[38;2" + _color.get_desc()
				+ std::string(2, char(219)) + "\033[0m";
		}
	}
	return board;
}