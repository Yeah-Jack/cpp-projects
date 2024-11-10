// Create a program that calculates the number of days in the month. Use a
// multiple branch with a maximum of three alternatives. The program should not
// take leap years into account.

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  short month;

  do {
    std::cout << "Enter in a month number (1 - 12): ";
    std::cin >> month;

    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      std::cout << "The month has 31 days.\n";
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      std::cout << "The month has 30 days.\n";
      break;
    case 2:
      std::cout << "The month has 28 or 29 days.\n";
      break;
    default:
      break;
    }
  } while (month < 1 || month > 12);

  return 0;
}