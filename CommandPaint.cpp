#include "CommandPaint.h"
#include <sstream>

void CommandPaint::ExecuteParameters(Board* board, std::string parameters) {
	int id;
	std::stringstream parameters_stream(parameters);
	
	std::string color_input;
	std::getline(parameters_stream, color_input, ' ');
	Color color(color_input);

	if (parameters_stream >> id) {
		board->paint(id, color);
		return;
	}
	board->paintSelected(color);
}