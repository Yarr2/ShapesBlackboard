#pragma once
#include <vector>
#include "Shape.h"
class Board
{
	int _width = 0;
	int _height = 0;
	int _selectedId = -1;	
	std::vector<Shape*> _shapes{};
	std::vector<std::vector<std::string>>* get_empty_board();
	void display(const std::vector<std::vector<std::string>>& board);
	Shape* getById(int id);
public:
	Board(int width, int height) {
		_width = width;
		_height = height;
	}
	std::string get_header();
	std::string serialise_shapes();

	void draw();
	void add(Shape* shape);
	void remove(int id);
	void paint(int id, Color color);
	void removeSelected();
	void paintSelected(Color color);
	void editSelected(std::string parameters);
	void moveSelected(std::string parameters);
	void selectById(int id);
	void selectByCoordinates(int x, int y);
	void list_shapes();
	void clear();
};

