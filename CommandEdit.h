#pragma once
#include "Command.h"
class CommandEdit :
    public Command
{
    void ExecuteParameters(Board* board, std::string parameters) override;
};

