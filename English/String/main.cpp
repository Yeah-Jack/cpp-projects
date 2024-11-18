#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  std::string str;

  std::cout << "Gebe einen Text ein: ";
  std::getline(std::cin, str);
  
  std::cout << "Dein Text ist: " << str << '\n';

  return 0;
}