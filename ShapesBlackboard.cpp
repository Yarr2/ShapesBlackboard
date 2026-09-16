

#include <iostream>
#include <string>
#include <iostream>

std::string colorRGB(const uint8_t R, const uint8_t G, const uint8_t B, std::string text) {
    return "\033[38;2;" 
        + std::to_string(R) + ';' 
        + std::to_string(G) + ';' 
        + std::to_string(B) + 'm' + text + "\033[0m";
}

int main(int argc, char** argv) {
    uint8_t a = 0;
    uint8_t c = 5;
    int b = 255 + 256+4096;
    a = b;
    a = a + c;
    std::cout << +a << "TEMA";

    std::cout << "\n";
    std::cout << colorRGB(255, 0, 0, "RED");
    std::cout << "\033[38;2;255;165;0mOrange Text\033[0m\n";
    return 0;
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
