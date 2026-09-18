#pragma once
#include "Command.h"
#include "Board.h"
class CommandError :
    public Command
{

	void ExecuteParameters(Board* board, std::string parameters) override;
};

