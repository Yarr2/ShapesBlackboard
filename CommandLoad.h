#pragma once
#include "Command.h"
class CommandLoad :
    public Command
{
public:
    void ExecuteParameters(Board* board, std::string parameters) override;

};

