#include "Rectangle.h"
#include "Color.h"
#include <string>
#include <sstream>
#include <cctype>

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
void Rectangle::move(std::string parameters) {
	std::stringstream parameters_input(parameters);

	int start_x, start_y;

	std::string token1, token2;

	parameters_input >> token1 >> token2;

	if (token1 == "-") {
		start_x = _bounding_box.get_start_x();
	}
	else {
		try {
			start_x = std::stoi(token1);
		}
		catch (std::exception&) {
			std::cout << "Wrong parameter for edit command. \n";
			return;
		}
	}

	if (token2 == "-") {
		start_y = _bounding_box.get_start_y();
	}
	else {
		try {
			start_y = std::stoi(token2);
		}
		catch (std::exception&) {
			std::cout << "Wrong parameter for edit command. \n";
			return;
		}
	}
	_bounding_box.setStart(start_x, start_y);
}