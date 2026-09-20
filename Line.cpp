#include "Line.h"
#include <algorithm>
Rect Line::get_rect(int x_point1, int y_point1, int x_point2, int y_point2) {
	return Rect(
		std::min(x_point1, x_point2),
		std::min(y_point1, y_point2),
		std::abs(y_point1 - y_point2) + 1,
		std::abs(x_point1 - x_point2) + 1);
}

Line::Line(bool filled, Color color, int x_point1, int y_point1, int x_point2, int y_point2)
	: Shape(filled, color, get_rect(x_point1, y_point1, x_point2, y_point2)) {
	if (x_point1 < x_point2) {
		_x_point1 = x_point1;
		_x_point2 = x_point2;
		_y_point1 = y_point1;
		_y_point2 = y_point2;
	}
	else {
		_x_point1 = x_point2;
		_x_point2 = x_point1;
		_y_point1 = y_point2;
		_y_point2 = y_point1;
	}
}

std::vector<std::vector<std::string>>* Line::draw() {

  	std::vector<std::vector<std::string>>* board = _bounding_box.get_empty_rect();
	int rows = board[0].size();
	int cols = board[0][0].size();

	int x1 = 0,
		x2 = _x_point2 - _bounding_box.get_start_x(),
		y1 = _y_point1 - _bounding_box.get_start_y(),
		y2 = _y_point2 - _bounding_box.get_start_y();

	int x_cur = 0;
	int y_cur = _y_point1 - _bounding_box.get_start_y();
	int dx = std::abs(x2 - x1);
	int dy = -std::abs(y2 - y1);
	int error = dx + dy;

	while (true) {
		if (y_cur >= 0 && y_cur < rows &&
			x_cur >= 0 && x_cur < cols) {
			board[0][y_cur][x_cur] = _color.ColorText(std::string(2, char(219)));
		}

		if (x_cur == x2 && y_cur == y2) {
			break;
		}

		int doubled_error = 2 * error;

		if (doubled_error >= dy) {
			error += dy;
			x_cur += 1;
		}

		if (doubled_error <= dx) {
			error += dx;
			if (y2 > y1) {
				y_cur += 1;
			}
			else {
				y_cur -= 1;
			}
		}
	}
	return board;

}

std::string Line::get_desc() {
    return std::to_string(_id) + "Line\n";
}

void Line::edit(std::string parameters) {
	std::stringstream parameters_input(parameters);

	int x1,y1,x2,y2;

	std::string token1, token2,token3,token4;

	if (parameters_input >> token1 >> token2 >> token3 >> token4) {
		x1 = get_int_or_default(token1, _x_point1);
		y1 = get_int_or_default(token2, _y_point1);
		x2 = get_int_or_default(token3, _x_point2);
		y2 = get_int_or_default(token4, _y_point2);

		_bounding_box = Line::get_rect(x1, y1, x2, y2);

		_x_point1 = x1;
		_y_point1 = y1;
		_x_point2 = x2;
		_y_point2 = y2;
	}
	else {
		std::cout << "Not enough parameters for edit\n";
	}
}