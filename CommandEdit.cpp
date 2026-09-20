#include "CommandEdit.h"

void CommandEdit::ExecuteParameters(Board* board, std::string parameters) {
	board->editSelected(parameters);
}