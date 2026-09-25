#include "Rect.h"


void Rect::move(int x, int y) {
	_x += x;
	_y += y;
};
void Rect::setStart(int x, int y) {
	_x = x;
	_y = y;
};
void Rect::setSize(int height, int width) {
	_height = height;
	_width = width;
};
std::vector<std::vector<std::string>>* Rect::get_empty_rect() {
	std::vector<std::vector<std::string>>* board = new std::vector<std::vector<std::string>>;

	for (int i = 0; i <= _height; i++) {
		std::vector<std::string> row;
		for (int j = 0; j <= _width; j++) {
			row.push_back("  ");
		}
		board->push_back(row);
	}
	return board;
}

bool Rect::is_correct_rect(int width, int height) {
	if (_width > width || _height > height) {
		return false;
	}

	if (width + 1 < _x || _x + _width < 1) return false;

	if (height + 1 < _y || _y + _height < 1) return false;

	return true;
}
std::string Rect::serialise() {
	return std::to_string(_x) + " "
		+ std::to_string(_y) + " "
		+ std::to_string(_height) + " "
		+ std::to_string(_width);
}