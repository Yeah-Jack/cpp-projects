// Create a program that calculates a vertical throw, a horizontal throw, or a
// combination of both (oblique throw) according to the user's selection and
// outputs the result. The user should select the type of calculation (vertical,
// horizontal, or both (oblique throw)). Only the desired calculation is then
// performed. The input and output should only be present once in the program.

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  short throwType;
  double power;

  std::cout << "Enter the type of the throw\n"
            << "1) Horizontal\n"
            << "2) Vertical\n"
            << "3) Horizontal and Vertical\n";
  std::cin >> throwType;

  std::cout << "How strong do you throw? ";
  std::cin >> power;

  switch (throwType) {
  case 1:
    std::cout << "You threw " << power << "m.\n";
    break;
  case 2:
    std::cout << "You threw 0m.\n";
    break;
  case 3:
    std::cout << "You threw " << power * 5 << "m.\n";
    break;
  default:
    std::cout << "Invalid throw type. Please enter a number between 1 and 3.\n";
    break;
  }

  return 0;
}