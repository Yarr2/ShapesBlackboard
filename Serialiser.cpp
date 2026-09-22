#include "Serialiser.h"
#include "FileManager.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "Triangle.h"


std::string Serialiser::serialize_board(Board* board) {
	std::string serialised_text = "";
	serialised_text += board->get_header();
	serialised_text += board->serialise_shapes();
	return serialised_text;
}

Board* Serialiser::decerialise(std::string text) {
	std::istringstream stream(text);
	std::string line;
	// setting up board
	if (!std::getline(stream, line)) {
		std::cout << "Wrong board file\n";
		return nullptr;
	}
	std::string header;
	int height, width, selectedId;
	std::stringstream header_stream(line);
	if (!(header_stream >> header >> width >> height >> selectedId)) {
		std::cout << "Incorrect board description\n";
		return nullptr;
	}
	if (header != "BOARD:") {
		std::cout << "Wrong header\n";
	}
	Board* loaded_board = new Board(width, height);

    while (std::getline(stream, line)) {
		std::stringstream line_stream(line);
		std::string header;
		int id;
		std::string color, fill ,type ,parameters;
		if (line_stream >> header >> id >> color >> fill >> type) {
			if (header == "SHAPE:" && (fill == "fill" || fill == "frame")) {
				Color new_color(color);
				if (!new_color.is_correct_color()) {
					std::cout << "Wrong color\n";
					delete loaded_board;
					return nullptr;
				}
				bool is_filled = (fill == "fill");
				if (type == "rect") {
					int start_x, start_y, height, width;
					if (line_stream >> start_x >> start_y >> height >> width) {
						Shape* shape = new Rectangle(is_filled, color, Rect(start_x, start_y, height, width));
						shape->SetId(id);
						loaded_board->add(shape);
						continue;
					};
				}
				if (type == "circle") {
					int center_x, center_y, radius;
					if (line_stream >> center_x >> center_y >> radius){
						Shape* shape = new Circle(is_filled, color, center_x, center_y, radius);
						shape->SetId(id);
						loaded_board->add(shape);
						continue;
					}
				}
				if (type == "line") {
					int x1, y1, x2, y2;
					if (line_stream >> x1 >> y1 >> x2 >> y2) {
						Shape* shape = new Line(is_filled, color, x1, y1, x2, y2);
						shape->SetId(id);
						loaded_board->add(shape);
						continue;
					}
				}
				if (type == "triangle") {
					int x1, y1, x2, y2, x3, y3;
					if (line_stream >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
						Shape* shape = new Triangle(is_filled, color, x1, y1, x2, y2,x3,y3);
						shape->SetId(id);
						loaded_board->add(shape);
						continue;
					}
				}
				delete loaded_board;
				return nullptr;
			}
		}
		else {
			std::cout << "Wrong shape line\n";
			delete loaded_board;
			return nullptr;
		}

	}
	loaded_board->selectById(selectedId);
	return loaded_board;


}