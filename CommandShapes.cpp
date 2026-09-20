#include "CommandShapes.h"


void CommandShapes::ExecuteParameters(Board* board, std::string parameters) {
	std::cout << "You can use following shapes: \n\n";

	std::cout << "Rectangle: add rect [color] start_x start_y height width\n";
	std::cout << "Circle: add circle [color] center_x center_y radius\n";

	std::cout << "Instead of [color] you should put either name of common color('red', 'green' etc.) \n";
	std::cout << " or it's RGB equivalent in this format 255-255-255\n";
}