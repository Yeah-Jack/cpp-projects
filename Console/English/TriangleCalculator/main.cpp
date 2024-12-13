// Create a program that calculates the missing side from three specifications
// (side length(s), angle). The user should select which side/angle is to be
// calculated. The program should then calculate the area and the perimeter.

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  short choice;
  double sideA;
  double sideB;
  double sideC;
  double height;
  double area;
  double perimeter;

  std::cout << "What do you want to calculate?\n"
            << "1) Area\n"
            << "2) Perimeter\n"
            << "3) Height\n";
  std::cin >> choice;

  switch (choice) {
  case 1:
    std::cout << "Enter the length of side b: ";
    std::cin >> sideB;
    std::cout << "Enter the length of the height: ";
    std::cin >> height;

    area = height * sideB / 2;
    std::cout << "Area: " << area << '\n';
    break;
  case 2:
    std::cout << "Enter the length of side a: ";
    std::cin >> sideA;
    std::cout << "Enter the length of side b: ";
    std::cin >> sideB;
    std::cout << "Enter the length of side c: ";
    std::cin >> sideC;

    perimeter = sideA + sideB + sideC;
    std::cout << "Perimeter: " << perimeter << '\n';
    break;
  case 3:
    std::cout << "Enter the length of the area: ";
    std::cin >> area;
    std::cout << "Enter the length of side b: ";
    std::cin >> sideB;

    height = 2 * area / sideB;
    std::cout << "Height: " << height << '\n';
    break;
  default:
    std::cout << "Invalid choice.\n";
    break;
  }
  return 0;
}