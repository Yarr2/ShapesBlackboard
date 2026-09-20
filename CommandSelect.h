#pragma once
#include "Command.h"
class CommandSelect :
    public Command
{
public:
    void ExecuteParameters(Board* board, std::string parameters) override;
};

