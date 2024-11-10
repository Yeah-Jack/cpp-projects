// Create a program that calculates the check digit for an EAN barcode (EAN 8 or
// EAN 13).
// TODO: Add EAN 13

#include <iostream>
#include <vector>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  std::vector<int> digits;

  std::cout << "Enter 7 digits: ";

  for (int i = 0; i < 7; i++) {
    int temp;
    std::cin >> temp;
    digits.push_back(temp);
  }

  int temp;

  temp = (digits[0] + digits[2] + digits[4] + digits[6]) * 3 + digits[1] +
         digits[3] + digits[5];
  temp %= 10;
  temp = 10 - temp;
  if (temp == 10) {
    temp = 0;
  }

  digits.push_back(temp);

  std::cout << "Your check digit is: " << digits[7] << "\nYour whole code is: ";
  for (int digit : digits) {
    std::cout << digit;
  }
  std::cout << '\n';

  return 0;
}