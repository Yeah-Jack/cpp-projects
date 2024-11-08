#include <Windows.h>
#include <iostream>
#include <cmath>

int main() {
	SetConsoleOutputCP(CP_UTF8);

	int number;

	std::cout << "Enter a number: ";
	std::cin >> number;

	while(number % 2 == 0) {
		std::cout << 2 << " ";
		number /= 2;
	}

	return 0;
}