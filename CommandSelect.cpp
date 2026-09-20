#include "CommandSelect.h"
#include <sstream>
void CommandSelect::ExecuteParameters(Board* board, std::string parameters) {
	int id = 0, x_coordinate = 0, y_coordinate = 0;

	std::stringstream parameters_input(parameters);

	if (parameters_input >> x_coordinate >> y_coordinate) {
		board->selectByCoordinates(x_coordinate, y_coordinate);
	}
	else {
		id = x_coordinate;
		board->selectById(id);
	}
}