#pragma once
#include <vector>
#include "Shape.h"
class Board
{
	int _width = 0;
	int _height = 0;
	std::vector<Shape*> _shapes{};
	std::vector<std::vector<std::string>>* get_empty_board();
	void display(const std::vector<std::vector<std::string>>& board);
public:
	Board(int width, int height) {
		_width = width;
		_height = height;
	}
	void draw();
	void add(Shape* shape);
	void remove(int id);
	void list_shapes();
	void clear();
};

