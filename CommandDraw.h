#pragma once
#include "Command.h"
#include "Board.h"

class CommandDraw : public Command
{
	void ExecuteParameters(Board* board, std::string parameters) override;
};

