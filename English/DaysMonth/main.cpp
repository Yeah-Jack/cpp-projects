// Create a program that calculates the number of days in the month. Use a
// multiple branch with a maximum of three alternatives. The program should not
// take leap years into account.

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  short month;

  do {
    std::cout << "Enter a month number (1-12): ";
    std::cin >> month;

    if (month < 1 || month > 12) {
      std::cout << "Invalid month. Please enter a number between 1 and 12.\n";
    } else if (month == 2) {
      std::cout << "The month has 28 or 29 days.\n";
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
      std::cout << "The month has 30 days.\n";
    } else {
      std::cout << "The month has 31 days.\n";
    }

  } while (month < 1 || month > 12);

  return 0;
}