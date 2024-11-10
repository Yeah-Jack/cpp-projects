// Create a program that enters two numbers and then calculates the sum of all
// numbers that lie between the limits. The input should be in ascending order.

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  int number1;
  int number2;
  int result = 0;

  std::cout << "Enter the first number: ";
  std::cin >> number1;
  std::cout << "Enter the second number: ";
  std::cin >> number2;

  for (int i = number1; i <= number2; i++) {
    result += i;
  }

  std::cout << result << '\n';

  return 0;
}