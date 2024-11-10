// Create a program that calculates all prime factors of a number.
// Prime factors are divisors of the number that are also prime numbers.

#include <cmath>
#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  int number;

  std::cout << "Enter a number: ";
  std::cin >> number;

  while (number % 2 == 0) {
    std::cout << 2 << " ";
    number /= 2;
  }

  return 0;
}