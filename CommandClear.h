#pragma once
#include "Command.h"
#include "Board.h"


class CommandClear : public Command
{
	void ExecuteParameters(Board* board, std::string parameters) override;
};

