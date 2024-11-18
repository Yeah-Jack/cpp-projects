#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  std::string str;
  char search;

  std::cout << "Enter a text: ";
  std::getline(std::cin, str);

  std::cout << "Enter a character to search: ";
  std::cin >> search;
  
  std::cout << "Your text ist " << str << " and the character " << search << " is at character " << str.find(search)+1 << ".\n";

  return 0;
}