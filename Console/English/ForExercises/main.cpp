#include <iostream>
#include <windows.h>

void PrintNumbersUpTo();
void PrintEvenNumbersUpTo();
int main() {
  SetConsoleOutputCP(CP_UTF8);

  short choice;

  std::cout << "Which program do you want to run? 1 or 2?\n";
  std::cin >> choice;

  switch (choice) {
  case 1:
    PrintNumbersUpTo();
    break;
  case 2:
    PrintEvenNumbersUpTo();
    break;
  default:
    std::cout << "You didn't enter a valid number.\n";
    break;
  }

  return 0;
}

void PrintNumbersUpTo() {
  // Write a program that uses a for loop to print the numbers from 1 to 10.
  int number;

  std::cout << "Enter the number up to which you want to print: ";
  std::cin >> number;

  for (int i = 1; i <= number; ++i) {
    std::cout << i << '\n';
  }
}

void PrintEvenNumbersUpTo() {
  // Create a program that prints all even numbers between 1 and N.
  int number;

  std::cout << "Enter the number up to which you want to print: ";
  std::cin >> number;

  for (int i = 2; i <= number; i += 2) {
    std::cout << i << '\n';
  }
}