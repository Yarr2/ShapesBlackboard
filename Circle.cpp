#include "Circle.h"
#include <sstream>

Rect Circle::get_rect(int center_x, int center_y, int radius) {
	return Rect(center_x - radius, center_y - radius, 2 * radius + 1, 2 * radius + 1);
}

Circle::Circle(bool filled, Color color, int center_x, int center_y, int radius)
	: Shape(filled, color, Circle::get_rect(center_x, center_y, radius)) {
	_radius = radius;
	_center_x = center_x;
	_center_y = center_y;
};

std::vector<std::vector<std::string>>* Circle::draw() {
	std::vector<std::vector<std::string>>* board = _bounding_box.get_empty_rect();

	int size = board->size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int radius = (2 * i - size + 1) * (2 * i - size + 1) + (2 * j - size + 1) * (2 * j - size + 1);
			if (radius <= size * size && radius >= (size - 1) * (size - 1)) {
				board[0][i][j] = _color.ColorText(std::string(2,char(219)));
			};
			if (radius <= (size - 1) * (size - 1) && is_filled) {
				board[0][i][j] = _color.ColorText(std::string(2, char(219)));
			}
		}
	}

	return board;
}

std::string Circle::get_desc() {
	return std::to_string(_id) + " Circle" + " " + _color.getRGBdefinition() +
		" " + std::to_string(_center_x) + " " + std::to_string(_center_y) + " " + std::to_string(_radius);
}

void Circle::edit(std::string parameters) {
	std::stringstream parameters_input(parameters);
	int radius;

	std::string token;

	parameters_input >> token;

	if (token == "-") {
		radius = _radius;
	}
	else {
		try {
			radius = std::stoi(token);
		}
		catch (std::exception&) {
			std::cout << "Wrong parameter for edit command. \n";
			return;
		}
	}

	_bounding_box = Circle::get_rect(_center_x, _center_y, radius);
	_radius = radius;

}

void Circle::move(std::string parameters) {
	std::stringstream parameters_input(parameters);

	int center_x, center_y;

	std::string token1, token2;

	parameters_input >> token1 >> token2;

	if (token1 == "-") {
		center_x = _center_x;
	}
	else {
		try {
			center_x = std::stoi(token1);
		}
		catch (std::exception&) {
			std::cout << "Wrong parameter for edit command. \n";
			return;
		}
	}

	if (token2 == "-") {
		center_y = _center_y;
	}
	else {
		try {
			center_y = std::stoi(token2);
		}
		catch (std::exception&) {
			std::cout << "Wrong parameter for edit command. \n";
			return;
		}
	}
	_bounding_box = Circle::get_rect(center_x, center_y, _radius);
	_center_x = center_x;
	_center_y = center_y;   
}

std::string Circle::serialise() {
	return Shape::serialise() + "circle "
		+ std::to_string(_center_x) + " "
		+ std::to_string(_center_y) + " "
		+ std::to_string(_radius);
}