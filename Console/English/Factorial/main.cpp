// Create a program that calculates the factorial.
// Example: 5! (5 factorial) = 1 * 2 * 3 * 4 * 5 = 120.

#include <iostream>
#include <windows.h>

long factorialIterative(long number);
long factorialRecursive(long number);

int main() {
  SetConsoleOutputCP(CP_UTF8);

  long number;
  short choice;

  std::cout << "Enter a number: ";
  std::cin >> number;

  if (number < 0) {
    std::cout << "Factorial is not defined for negative numbers.\n";
    return 1;
  }

  std::cout << "Choose a method to calculate the factorial\n1) Iterative\n2) "
               "Recursive\n";
  std::cin >> choice;

  switch (choice) {
  case 1:
    std::cout << "Factorial of your number is: " << factorialIterative(number)
              << '\n';
    break;

  case 2:
    std::cout << "Factorial of your number is: " << factorialRecursive(number)
              << '\n';
    break;

  default:
    std::cout << "Invalid choice\n";
    break;
  }

  return 0;
}

long factorialIterative(long number) {
  long result = 1;

  for (int i = 1; i <= number; i++) {
    result *= i;
  }

  return result;
}

long factorialRecursive(long number) {
  if (number > 1) {
    return number * factorialRecursive(number - 1);
  } else {
    return 1;
  }
}