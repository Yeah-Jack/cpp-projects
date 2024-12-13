// Create a program that calculates the factorial.
// Example: 5! (5 factorial) = 1 * 2 * 3 * 4 * 5 = 120.

#include <iostream>
#include <windows.h>

long factorialIterative(long &number);
// long factorialRecursive(long &number);

int main() {
  SetConsoleOutputCP(CP_UTF8);

  long number;

  std::cout << "Enter a number: ";
  std::cin >> number;

  std::cout << "Factorial of your number is: " << factorialIterative(number)
            << '\n';
  // std::cout << "Factorial of your number is: " << factorialRecursive(number)
  //           << '\n';;

  return 0;
}

long factorialIterative(long &number) {
  long result = 1;

  for (int i = 1; i <= number; i++) {
    result *= i;
  }

  return result;
}

// long factorialRecursive(long &number) {
//   if (number > 1) {
//     return number * factorialRecursive(number - 1);
//   } else {
//     return 1;
//   }
// }