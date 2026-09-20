#include "CommandLoad.h"
#include "FileManager.h"
#include "Serialiser.h"
void CommandLoad::ExecuteParameters(Board* board, std::string parameters) {
	std::string file_path = parameters;
	std::string text = FileManager::load(file_path);

	Board* loaded_board = Serialiser::decerialise(text);
	if (loaded_board == nullptr) {
		std::cout << "Not loaded board\n";
		return; 
	}
	loaded_board->draw();

	*board = *loaded_board;
	return;
}