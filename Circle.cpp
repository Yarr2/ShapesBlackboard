#include "Circle.h"

Circle::Circle(Color color, int center_x, int center_y, int radius)
	: Shape(color, Rect(center_x - radius, center_y - radius, 2 * radius + 1, 2 * radius + 1)) {
};

std::vector<std::vector<std::string>>* Circle::draw() {
	std::vector<std::vector<std::string>>* board = _bounding_box.get_empty_rect();

	int size = board->size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			if ((2 * i - size + 1) * (2 * i - size + 1) + (2 * j - size + 1)  * (2 * j - size + 1) <= size * size) {
				board[0][i][j] = _color.ColorText(std::string(2,char(219)));
			};
		}
	}

	return board;
}

std::string Circle::get_desc() {
	return std::to_string(_id) + " Circle";
}
