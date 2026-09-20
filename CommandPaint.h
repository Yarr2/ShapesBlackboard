#pragma once
#include "Command.h"
class CommandPaint :
    public Command
{
public:
    void ExecuteParameters(Board* board, std::string parameters) override;

};

