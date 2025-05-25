#include <iostream>
#include <windows.h>

void sort(int numbers[], int &size);

int main() {
  SetConsoleOutputCP(CP_UTF8);

  int numbers[] = {3, 2, 4, 1};
  int size = sizeof(numbers) / sizeof(numbers[0]);

  std::cout << "Current array: ";
  for (int i = 0; i < size; i++) {
    std::cout << numbers[i] << ' ';
  }
  std::cout << '\n';

  sort(numbers, size);

  std::cout << "Sorted array: ";
  for (int i = 0; i < size; i++) {
    std::cout << numbers[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}

void sort(int numbers[], int &size) {
  int temp;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (numbers[j] > numbers[j + 1]) {
        temp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = temp;
      }
    }
  }
}