// Create a program that reads in a string. A character is then to be read in
// for searching. Display the position of the character you are looking for. If
// the character appears several times, all digits (separated by spaces) should
// be output.

// Create a program that reads in a string. Subsequently, a second text is to be
// read in. Finally, the position at which the text is to be inserted is to be
// read in. text is to be inserted.

#include <iostream>
#include <windows.h>

void searchString();
void insertString();
int main() {
  SetConsoleOutputCP(CP_UTF8);

  short choice;
  std::cout << "1) Search a character in a string\n";
  std::cout << "2) Insert a string in a string\n";
  std::cout << "Enter your choice: ";
  std::cin >> choice;
  std::cin.ignore(); // Clear the newline character from the input buffer

  switch (choice) {
  case 1:
    searchString();
    break;
  case 2:
    insertString();
    break;
  }

  return 0;
}

void searchString() {
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
}

void insertString() {
  std::string text;
  std::string text1;
  std::string text2;
  size_t position;

  std::cout << "Enter the first text: ";
  std::getline(std::cin, text1);
  std::cout << "Enter the second text: ";
  std::getline(std::cin, text2);

  std::cout << "The second text has to be appended at character "
            << text1.size()
            << "\nAt which character do you want to insert the second text? ";
  std::cin >> position;
  text = text1;
  text.insert(position, text2);
  std::cout << "The new text is: " << text << '\n';
}