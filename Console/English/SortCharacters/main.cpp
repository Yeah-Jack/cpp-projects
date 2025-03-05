// The user should enter a predefined number of letters. The program should then
// sort the letters alphabetically.

#include <iostream>
#include <windows.h>

void sort(char characters[], int size);
int main() {
  SetConsoleOutputCP(CP_UTF8);

  char characters[6] = {'d', 'b', 'C', 'a'};

  std::cout << "Enter 2 more characters: ";
  for (int i = 4; i < 6; i++) {
    std::cin >> characters[i];
  }

  std::cout << "Current array: ";
  for (char character : characters) {
    std::cout << character << ' ';
  }

  int size = sizeof(characters) / sizeof(characters[0]);
  sort(characters, size);

  std::cout << "\nSorted array: ";
  for (char character : characters) {
    std::cout << character << ' ';
  }
  std::cout << '\n';

  return 0;
}

void sort(char characters[], int size) {
  char temp;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (characters[j] > characters[j + 1]) {
        temp = characters[j];
        characters[j] = characters[j + 1];
        characters[j + 1] = temp;
      }
    }
  }
}