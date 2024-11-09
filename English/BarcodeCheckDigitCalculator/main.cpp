#include <Windows.h>
#include <iostream>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  short digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8;

  std::cout << "Enter your number, seperated by space or enter: ";
  std::cin >> digit1 >> digit2 >> digit3 >> digit4 >> digit5 >> digit6 >>
      digit7;

  digit8 = (digit1 + digit3 + digit5 + digit7) * 3 + digit2 + digit4 + digit6;
  digit8 %= 10;
  digit8 = 10 - digit8;
  if (digit8 == 10) {
    digit8 = 0;
  }

  std::cout << "Your check digit is: " << digit8 << '\n';
  std::cout << "Your whole code is: " << digit1 << digit2 << digit3 << digit4
            << digit5 << digit6 << digit7 << digit8 << '\n';

  return 0;
}