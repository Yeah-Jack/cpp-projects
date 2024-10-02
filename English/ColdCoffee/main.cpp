#include <Windows.h>
#include <iostream>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  double coffeeTemperature = 85.0;
  const double kRoomTemperature = 20.0;
  const double kChangeRate = 0.10;
  const double kTolerance = 2.0;
  int minutes = 0;

  while ((coffeeTemperature - kRoomTemperature) > kTolerance) {
    coffeeTemperature =
        kRoomTemperature * kChangeRate + coffeeTemperature * (1 - kChangeRate);
    minutes++;
    std::cout << "Minute " << minutes << ": " << "Coffee temperature is "
              << coffeeTemperature << "°C." << std::endl;
  }

  std::cout
      << "The coffee temperature is approximately the room temperature after "
      << minutes << " minutes." << std::endl;

  return 0;
}