// Create a program that calculates the surface area and volume of a solid body
// (all angles are right-angled). The user should be able to select which body
// he wants to calculate, then the necessary the necessary lengths should be
// queried.

#include <Windows.h>
#include <cmath>
#include <iostream>

short displayMenu(short &choice);
double calculateCube(double &length, double &volume, double &surfaceArea);
double calculateCuboid(double &length, double &width, double &height,
                       double &volume, double &surfaceArea);
double calculatePyramid(double &length, double &width, double &height,
                        double &volume, double &surfaceArea);
double calculateCylinder(double &radius, double &height, double &volume,
                         double &surfaceArea, const double &PI);
double calculateSphere(double &radius, double &volume, double &surfaceArea,
                       const double &PI);

int main() {
  SetConsoleOutputCP(CP_UTF8);

  short choice;
  double length;
  double width;
  double height;
  double radius;
  double volume;
  double surfaceArea;
  const double PI = 3.14159265359;

  displayMenu(choice);
  switch (choice) {
  case 1:
    calculateCube(length, volume, surfaceArea);
    std::cout << "Volume: " << volume << "\nSurface Area: " << surfaceArea
              << '\n';
    break;
  case 2:
    calculateCuboid(length, width, height, volume, surfaceArea);
    std::cout << "Volume: " << volume << "\nSurface Area: " << surfaceArea
              << '\n';
    break;
  case 3:
    calculatePyramid(length, width, height, volume, surfaceArea);
    std::cout << "Volume: " << volume << "\nSurface Area: " << surfaceArea
              << '\n';
    break;
  case 4:
    calculateCylinder(radius, height, volume, surfaceArea, PI);
    std::cout << "Volume: " << volume << "\nSurface Area: " << surfaceArea
              << '\n';
    break;
  case 5:
    calculateSphere(radius, volume, surfaceArea, PI);
    std::cout << "Volume: " << volume << "\nSurface Area: " << surfaceArea
              << '\n';
    break;
  default:
    std::cout << "Invalid choice\n";
    break;
  }

  return 0;
}

short displayMenu(short &choice) {
  std::cout << "Choose a solid geometry type:\n"
            << "1) Cube\n"
            << "2) Cuboid\n"
            << "3) Pyramid\n"
            << "4) Cylinder\n"
            << "5) Sphere\n";
  std::cin >> choice;

  return 0;
}

double calculateCube(double &length, double &volume, double &surfaceArea) {
  std::cout << "Enter the length of the cube: ";
  std::cin >> length;

  volume = length * length * length;
  surfaceArea = 6 * length * length;

  return 0;
}

double calculateCuboid(double &length, double &width, double &height,
                       double &volume, double &surfaceArea) {
  std::cout << "Enter the length of the cuboid: ";
  std::cin >> length;
  std::cout << "Enter the width of the cuboid: ";
  std::cin >> width;
  std::cout << "Enter the height of the cuboid: ";
  std::cin >> height;

  volume = length * width * height;
  surfaceArea = 2 * (length * width + length * height + width * height);

  return 0;
}

double calculatePyramid(double &length, double &width, double &height,
                        double &volume, double &surfaceArea) {
  std::cout << "Enter the length of the pyramid: ";
  std::cin >> length;
  std::cout << "Enter the width of the pyramid: ";
  std::cin >> width;
  std::cout << "Enter the height of the pyramid: ";
  std::cin >> height;

  volume = length * width * height / 3;
  surfaceArea = length * width +
                length * sqrt((width / 2) * (width / 2) + height * height) +
                width * sqrt((length / 2) * (length / 2) + height * height);

  return 0;
}

double calculateCylinder(double &radius, double &height, double &volume,
                         double &surfaceArea, const double &PI) {
  std::cout << "Enter the radius of the cylinder: ";
  std::cin >> radius;
  std::cout << "Enter the height of the cylinder: ";
  std::cin >> height;

  volume = PI * radius * radius * height;
  surfaceArea = 2 * PI * radius * height + 2 * PI * radius * radius;

  return 0;
}

double calculateSphere(double &radius, double &volume, double &surfaceArea,
                       const double &PI) {
  std::cout << "Enter the radius of the sphere: ";
  std::cin >> radius;

  volume = (4.0 / 3.0) * PI * radius * radius * radius;
  surfaceArea = 4 * PI * radius * radius;

  return 0;
}