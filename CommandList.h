#pragma once
#include "Command.h"
class CommandList :
    public Command
{
    void ExecuteParameters(Board* board, std::string parameters) override;

};

