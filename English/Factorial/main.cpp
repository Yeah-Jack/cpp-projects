#include <Windows.h>
#include <iostream>

// int factorialIterative(int num);
int factorialRecursive(int num);

int main() {
  SetConsoleOutputCP(CP_UTF8);

  int num;

  std::cout << "Enter a number: ";
  std::cin >> num;

  // std::cout << "Factorial of your number is: " << factorialIterative(num) <<
  // std::endl;
  std::cout << "Factorial of your number is: " << factorialRecursive(num)
            << std::endl;

  return 0;
}

/* int factorialIterative(int num) {
  int result = 1;

  for (int i = 1; i <= num; i++) {
    result *= i;
  }

  return result;
} */

int factorialRecursive(int num) {
  if (num > 1) {
    return num * factorialRecursive(num - 1);
  } else {
    return 1;
  }
}