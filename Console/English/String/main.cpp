// Create a program that reads in a string. A character is then to be read in
// for searching. Display the position of the character you are looking for. If
// the character appears several times, all digits (separated by spaces) should
// be output.

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  std::string text;
  size_t position;
  char search;

  std::cout << "Enter a text: ";
  std::getline(std::cin, text);

  std::cout << "Enter a character to search: ";
  std::cin >> search;

  position = text.find(search);

  std::cout << "Your text is \"" << text << "\" and the character " << search
            << " is positioned at character: ";

  while (position != std::string::npos) {
    std::cout << position + 1 << ' ';
    position = text.find(search, position + 1);
  }
  std::cout << '\n';

  return 0;
}