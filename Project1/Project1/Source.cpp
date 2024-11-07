#include <windows.h>
#include <iostream>

void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main() {
    // Set first color (green) and print
    setTextColor(2);
    std::cout << "This is green text. ";

    // Set second color (red) and print
    setTextColor(4);
    std::cout << "This is red text." << std::endl;

    // Reset to default color (light gray)
    setTextColor(7);
    std::cout << "This is default color text." << std::endl;

    return 0;
}
