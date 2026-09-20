#pragma once
#include "Command.h"
class CommandMove :
    public Command
{
    void ExecuteParameters(Board* board, std::string parameters) override;

};

