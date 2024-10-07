#include <Windows.h>
#include <iostream>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  double coffeeTemperature = 85.0;
  const double ROOMTEMPATURE = 20.0;
  const double CHANGERATE = 0.10;
  const double TOLERANCE = 2.0;
  int minutes = 0;

  while ((coffeeTemperature - ROOMTEMPATURE) > TOLERANCE) {
    coffeeTemperature =
        ROOMTEMPATURE * CHANGERATE + coffeeTemperature * (1 - CHANGERATE);
    minutes++;
    std::cout << "Minute " << minutes << ": " << "Coffee temperature is "
              << coffeeTemperature << "°C." << std::endl;
  }

  std::cout
      << "The coffee temperature is approximately the room temperature after "
      << minutes << " minutes." << std::endl;

  return 0;
}