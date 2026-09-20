#include "Rectangle.h"
#include "Color.h"
#include <string>
#include <sstream>
#include <cctype>

std::vector<std::vector<std::string>>* Rectangle::draw() {
	std::vector<std::vector<std::string>>* board = _bounding_box.get_empty_rect();
	
	int height = board[0].size();
	int width = board[0][0].size();


	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
				board[0][i][j] = _color.ColorText(std::string(2, char(219)));
			}
			if (is_filled) {
				board[0][i][j] = _color.ColorText(std::string(2, char(219)));
			}

		}
	}
	return board;
}


void Rectangle::edit(std::string parameters) {
	std::stringstream parameters_input(parameters);
	
	int height, width;

	std::string token1, token2;

	parameters_input >> token1 >> token2;

	if (token1 == "-") {
		height = -1;
	}
	else {
		try {
			height = std::stoi(token1);
		}
		catch (std::exception&) {
			std::cout << "Wrong parameter for edit command. \n";
			return;
		}
	}

	if (token2 == "-") {
		width = -1;
	}
	else {
		try {
			width = std::stoi(token2);
		}
		catch (std::exception&) {
			std::cout << "Wrong parameter for edit command. \n";
			return;
		}
	}
	if (height != -1)_bounding_box.setHeight(height);
	if (width != -1) _bounding_box.setWidth(width);
}	

std::string Rectangle::get_desc() {
	return std::to_string(_id) + " Rectangle " + _color.getRGBdefinition() + " "
		+ _bounding_box.serialise();
}
std::string Rectangle::serialise() {
	return Shape::serialise() + "rect "
		+ _bounding_box.serialise();
}