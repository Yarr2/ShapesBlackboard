#pragma once
#include "Command.h"
class CommandRemove :
    public Command
{
    void ExecuteParameters(Board* board, std::string parameters) override;

};

