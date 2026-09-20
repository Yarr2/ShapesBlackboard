

#include <iostream>
#include <string>
#include "Board.h"
#include "Rectangle.h"
#include "CommandLine.h"
#include "Color.h"
#include "Line.h"

std::string colorRGB(const uint8_t R, const uint8_t G, const uint8_t B, std::string text) {
    return "\033[38;2;" 
        + std::to_string(R) + ';' 
        + std::to_string(G) + ';' 
        + std::to_string(B) + 'm' + text + "\033[0m";
}

int main(int argc, char** argv) {
    std::string command;
    Board* board = new Board(25,20);
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command == "exit") {
            return 0;
        }
        CommandLine::ExecuteCommand(*board,command);
    }

    }


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
