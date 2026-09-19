#pragma once
#include "Command.h"
class CommandShapes :
    public Command
{
    void ExecuteParameters(Board* board, std::string parameters) override;
};

