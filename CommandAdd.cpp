#include "CommandAdd.h"
#include "Rectangle.h"

void CommandAdd::ExecuteParameters(Board* board, std::string parameters) {
    Shape* rect = new Rectangle(Color(0, 0, 255), Rect(14, 10, 5, 5));
    board->add(rect);
}