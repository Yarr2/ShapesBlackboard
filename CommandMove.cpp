#include "CommandMove.h"
void CommandMove::ExecuteParameters(Board* board, std::string parameters) {
	board->moveSelected(parameters);
}