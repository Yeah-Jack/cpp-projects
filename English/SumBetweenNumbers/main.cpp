// Create a program that enters two numbers and then calculates the sum of all
// numbers that lie between the limits. The input should be in ascending order.

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  int num1;
  int num2;
  int result = 0;

  std::cout << "Enter the first number: ";
  std::cin >> num1;
  std::cout << "Enter the second number: ";
  std::cin >> num2;

  for (int i = num1; i <= num2; i++) {
    result += i;
  }

  std::cout << result << '\n';

  return 0;
}