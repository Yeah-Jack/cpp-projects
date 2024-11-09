// Design and create a program that calculates all divisors of a number.

#include <Windows.h>
#include <iostream>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  int number;
  int divisor;

  std::cout << "Enter a number: ";
  std::cin >> number;

  std::cout << "Divisors of " << number << ": ";
  for (divisor = 1; divisor <= number; divisor++) {
    if (number % divisor == 0) {
      std::cout << divisor << " ";
    }
  }

  return 0;
}