// Let the user input its own variables. Declare, initialize, and print all
// elements of an integer array. Calculate the sum and average of elements in an
// array. Identify the largest and smallest values in an array. Reverse the
// order of elements and print the result.

#include <algorithm>
#include <iostream>
#include <windows.h>

void sort(int numbers[], int size);
int main() {
  SetConsoleOutputCP(CP_UTF8);

  int numbers[8] = {5, 3, 2, 6, 4, 1};

  for (int i = 6; i < 8; i++) {
    std::cout << "Enter a number: ";
    std::cin >> numbers[i];
  }

  int size = sizeof(numbers) / sizeof(numbers[0]);
  int sum = 0;
  double average = 0.0;

  sort(numbers, size);
  std::cout << "\nSorted array: ";
  for (int number : numbers) {
    std::cout << number << ' ';
    sum += number;
  }
  average = static_cast<double>(sum) / size;

  std::cout << "\nSum: " << sum << '\n';
  std::cout << "Average: " << average << '\n';
  std::cout << "Smallest number: " << numbers[0] << '\n';
  std::cout << "Largest number: " << numbers[size - 1] << '\n';

  std::reverse(numbers, numbers + size);
  std::cout << "Reversed array: ";
  for (int number : numbers) {
    std::cout << number << ' ';
  }
  std::cout << '\n';

  return 0;
}

void sort(int numbers[], int size) {
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