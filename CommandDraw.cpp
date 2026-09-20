#include "CommandDraw.h"

void CommandDraw::ExecuteParameters(Board* board, std::string parameters) {
	board->draw();
}