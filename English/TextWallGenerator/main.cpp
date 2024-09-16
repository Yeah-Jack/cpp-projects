#include <iostream>

int main() {
  int rows;
  int columns;
  std::string text;

  std::cout << "Enter the number of rows: ";
  std::cin >> rows;

  std::cout << "Enter the number of columns: ";
  std::cin >> columns;

  std::cin.ignore();

  std::cout << "Enter your text: ";
  std::getline(std::cin, text);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      std::cout << text;
    }
    std::cout << std::endl;
  }

  return 0;
}