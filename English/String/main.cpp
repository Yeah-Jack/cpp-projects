#include <iostream>
#include <windows.h>

int main() {
	SetConsoleOutputCP(CP_UTF8);

	std::string str;

	std::cout << "Gebe einen Text ein: ";
	std::cin >> str;

	std::cout << "Dein Text ist: " << str << std::endl;

	return 0;
}