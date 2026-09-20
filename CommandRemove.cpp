#include "CommandRemove.h"
#include <sstream>


void CommandRemove::ExecuteParameters(Board* board, std::string parameters) {
	int id;
	std::stringstream parameters_stream(parameters);
	if (parameters_stream >> id) {
		board->remove(id);
	}
	else {
		board->removeSelected();
	}
}
