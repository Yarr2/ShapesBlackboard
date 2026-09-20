#pragma once
#include "Command.h"
class CommandSave :
    public Command
{
public: 
    void ExecuteParameters(Board* board, std::string parameters) override;

};

