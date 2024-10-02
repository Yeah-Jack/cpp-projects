#include <Windows.h>
#include <iostream>
#include <random>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  std::random_device rd;
  std::uniform_int_distribution<short> dist(1, 6);

  short first = dist(rd);
  short second = dist(rd);

  std::cout << "First dice: " << first << std::endl
            << "Second dice: " << second << std::endl;

  return 0;
}
