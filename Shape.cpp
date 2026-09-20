#include "Shape.h"
#include <sstream>
#include <iostream>

int get_int_or_default(std::string input, int default_value) {
	int value;
	if (input == "-") {
		value = default_value;
	}
	else {
		try {
			value = std::stoi(input);
		}
		catch (std::exception&) {
			std::cout << "Wrong parameter for edit command. \n";
			return -1;
		}
	}
	return value;
}
bool Shape::is_correct_rect(int width, int height) {
	return _bounding_box.is_correct_rect(width, height);
}

void Shape::move(int x, int y) {
	_bounding_box.move(x, y);
}
void Shape::SetId(int id) {
	if (_setted_id) {
		return;
	}
	_id = id;
	_setted_id = true;
}
int Shape::getId() {
	return _id;
}
void Shape::move(std::string parameters) {
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

std::string Shape::serialise() {
	return "SHAPE: " + std::to_string(_id) + " " + 
		_color.getRGBdefinition() + " "
		+ (is_filled ? "fill " : "frame ");
}

std::string Shape::get_hash() {
	std::string serialised = serialise();
	std::string result, temp;
	int id;

	std::stringstream stream(serialised);

	stream >> temp >> id;

	std::getline(stream, result);
	return result;
}