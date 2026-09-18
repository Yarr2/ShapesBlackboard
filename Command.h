#pragma once
#include <string>
#include <iostream>
#include "Board.h"

class Command
{
public:
	virtual void ExecuteParameters(Board* board, std::string parameters) = 0;
	virtual ~Command() = default;
};

