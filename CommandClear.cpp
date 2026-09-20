#include "CommandClear.h"

void CommandClear::ExecuteParameters(Board* board, std::string parameters) {
	board->clear();
}