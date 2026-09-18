#include "Board.h"

void Board::add(Shape* shape) {
	_shapes.push_back(shape);
}

void Board::display(const std::vector<std::vector<std::string>>& board) {
	for (auto& row : board) {
		for (auto& string : row) {
			std::cout << string;
		}
		std::cout << "\n";
	}
}
std::vector<std::vector<std::string>>* Board::get_empty_board() {
	std::vector<std::vector<std::string>>* board = new std::vector<std::vector<std::string>>;
	for (int i = -1; i <= _height; i++) {
		std::vector<std::string> row;
		for (int j = -1; j <= _width; j++) {
			if (j == -1 || j == _width) {
				row.push_back("|");
				continue;
			}
			if (i == -1 || i == _height) {
				row.push_back("--");
				continue;
			}
			row.push_back("  ");


		}
		board->push_back(row);
	}
	return board;
}

void Board::draw(){
	std::vector<std::vector<std::string>>* board = get_empty_board();
	
	for (Shape* shape : _shapes) {
		std::vector<std::vector<std::string>>* shape_drawing = shape->draw();
		int start_x = shape->get_start_x();
		int start_y = shape->get_start_y();
		int height, width;
		height = shape_drawing->size();
		width = shape_drawing[0].size();

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (0 <= start_x + i && start_x + i < _height &&
					0 <= start_y + j && start_y + j < _width) {
					board[0][start_x + i][start_y + j] = shape_drawing[0][i][j];
				}

			}
		}

		delete shape_drawing;

	}
	display(*board);
}