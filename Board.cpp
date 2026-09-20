#include "Board.h"




void Board::add(Shape* shape) {
	int max_id = 0;
	if (_shapes.size() != 0) {
		max_id = _shapes[_shapes.size() - 1]->getId();
	}
	max_id++;
	shape->SetId(max_id);
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

Shape* Board::getById(int id) {
	int element_id = -1;
	for (Shape* shape : _shapes) {
		element_id++;
		if (shape->getId() == id) {
			return shape;
		}
	}
	std::cout << "There is no shape with this id\n";
	return nullptr;

}

void Board::remove(int id) {
	Shape* shape = getById(id);
	
	if (shape == nullptr) return;
	
	int element_id = shape->getId();

	_shapes.erase(_shapes.begin() + element_id - 1);
}

void Board::removeSelected() {
	if (_selectedId == -1) {
		std::cout << "No shape is selected now\n";
	}
	else {
		remove(_selectedId);
		_selectedId = -1;
	}
}

void Board::paint(int id, Color color) {
	Shape* shape = getById(id);

	if (shape == nullptr) return;
	
	shape->setColor(color);

}

void Board::paintSelected(Color color) {
	if (_selectedId == -1) {
		std::cout << "No shape is selected now\n";
	}
	else {
		Shape* shape = getById(_selectedId);
		if (shape != nullptr) shape->setColor(color);
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
		width = shape_drawing[0][0].size();

			for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (0 < start_x + i && start_x + i < _height &&
					0 < start_y + j && start_y + j < _width) {
					board[0][start_y + i][start_x + j] = shape_drawing[0][i][j];
				}

			}
		}

		delete shape_drawing;

	}
	display(*board);
}

void Board::list_shapes() {
	for (Shape* shape : _shapes) {
		std::cout << shape->get_desc() << "\n";
	}
}

void Board::clear() {
	for (Shape* shape : _shapes) {
		delete shape;
	}
	_shapes.clear();
}

void Board::editSelected(std::string parameters) {
	Shape* shape = getById(_selectedId);

	if (shape == nullptr) {
		std::cout << "No shape is selected now.\n";
	}

	shape->edit(parameters);
}
void Board::moveSelected(std::string parameters) {
	Shape* shape = getById(_selectedId);

	if (shape == nullptr) {
		std::cout << "No shape is selected now.\n";
	}

	shape->move(parameters);

	int element_id = shape->getId();

	_shapes.erase(_shapes.begin() + element_id - 1);

	_shapes.push_back(shape);
}