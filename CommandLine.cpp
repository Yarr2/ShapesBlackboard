#include "CommandLine.h"


void CommandLine::SplitCommand(std::string& command, std::string& name, std::string& parameters) {
	bool is_name = true;

	for (char& element : command) {

		if (element == ' ' && is_name) {
			is_name = false;
			continue;
		};

		if (is_name) {
			name += element;
		}
		else {
			parameters += element;
		}
	}
}

Command* CommandLine::GetCommand(std::string name) {
	Command* command;
	if (name == "draw") {
		command = new CommandDraw();
	}
	else if (name == "clear") {
		command = new CommandClear();
	}
	else if (name == "add") {
		command = new CommandAdd();
	}
	else if (name == "list") {
		command = new CommandList();
	}
	else if (name == "shapes") {
		command = new CommandShapes();
	}
	else if (name == "remove") {
		command = new CommandRemove();
	}
	else if (name == "paint") {
		command = new CommandPaint();
	}
	else if (name == "edit") {
		command = new CommandEdit();
	}
	else if (name == "move") {
		command = new CommandMove();
	}
	else if (name == "select") {
		command = new CommandSelect();
	}
	else if (name == "save") {
		command = new CommandSave();
	}
	else if (name == "load") {
		command = new CommandLoad();
	}
	else {
		command = new CommandError();
	};
	
	return command;
}

void CommandLine::ExecuteCommand(Board& board, std::string command) {

	std::string name, parameters;
	bool is_name = true;

	SplitCommand(command, name, parameters);

	Command* command_object = GetCommand(name);

	command_object->ExecuteParameters(&board, parameters);

	delete command_object;
}