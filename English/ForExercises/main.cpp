// Write a program that uses a for loop to print the numbers from 1 to 10.

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  int count;

  std::cout << "Who many times do you want to repeat the loop?\n";
  std::cin >> count;

  for (int i = 0; i < count; i++) {
    std::cout << i + 1 << '\n';
  }

  return 0;
}