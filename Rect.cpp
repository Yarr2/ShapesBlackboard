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

	for (int i = 0; i < _height; i++) {
		std::vector<std::string> row;
		for (int j = 0; j < _width; j++) {
			row.push_back("  ");
		}
		board->push_back(row);
	}
	return board;
}