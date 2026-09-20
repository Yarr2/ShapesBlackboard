#pragma once
#include "Board.h"
#include "Command.h"
#include "CommandAdd.h"
#include "CommandClear.h"
#include "CommandDraw.h"
#include "CommandError.h"
#include "CommandList.h"
#include "CommandShapes.h"
#include "CommandRemove.h"
#include "CommandPaint.h"
#include "CommandEdit.h"
#include "CommandMove.h"
#include "CommandSelect.h"

class CommandLine
{
	static void SplitCommand(std::string& command, std::string& name, std::string& parameters);
public:
	static void ExecuteCommand(Board& board, std::string command);
	static Command* GetCommand(std::string name);
};

