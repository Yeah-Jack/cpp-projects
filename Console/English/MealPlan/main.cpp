// A family has the same lunch every day of the week. The week starts on Monday
// with sausage. On Tuesday it's pasta. Pancakes on Wednesday. Noodles on
// Thursday. Fish on Friday. Vegetable soup on Saturday. Schnitzel on Sunday.
// The family would like a program that displays the corresponding meal after
// entering the day of the week. If an invalid entry is made, the query should
// be repeated.

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  short day;
  std::string meal;

  std::cout << "Welcome to the Family Lunch Menu Program!\n"
               "Please enter a day of the week to see the lunch menu: ";

  do {
    std::cin >> day;
    switch (day) {
    case 1:
      meal = "sausage";
      break;
    case 2:
      meal = "pasta";
      break;
    case 3:
      meal = "pancakes";
      break;
    case 4:
      meal = "noodles";
      break;
    case 5:
      meal = "fish";
      break;
    case 6:
      meal = "vegetable soup";
      break;
    case 7:
      meal = "schnitzel";
      break;
    default:
      std::cout << "Invalid choice. Try again: ";
      break;
    }
  } while (meal.empty());

  std::cout << "The meal for the " << day << ". day of the week is " << meal
            << ".\n";

  return 0;
}