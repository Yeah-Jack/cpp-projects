#include <iostream>
#include <random>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  std::random_device rd;
  std::uniform_int_distribution<short> dist(1, 6);

  short first = dist(rd);
  short second = dist(rd);

  std::cout << "First dice: " << first << '\n'
            << "Second dice: " << second << '\n';

  return 0;
}
