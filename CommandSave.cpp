#include "CommandSave.h"
#include "Serialiser.h"
#include "FileManager.h"

void CommandSave::ExecuteParameters(Board* board, std::string parameters) {
	std::string file_path = parameters;

	std::string serialised_board = Serialiser::serialize_board(board);

	FileManager::save(file_path, serialised_board);
	std::cout << "Saved board\n";
}