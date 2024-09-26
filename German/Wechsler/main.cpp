#include <Windows.h>
#include <iostream>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  int zahl1;
  int zahl2;
  int temp;

  std::cout << "Gebe Zahl 1 ein: " << std::endl;
  std::cin >> zahl1;
  std::cout << "Gebe Zahl 2 ein: " << std::endl;
  std::cin >> zahl2;

  temp = zahl1;
  zahl1 = zahl2;
  zahl2 = temp;

  std::cout << "Neue Zahl 1: " << zahl1 << std::endl
            << "Neue Zahl 2: " << zahl2 << std::endl;

  return 0;
}
