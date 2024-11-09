// The temperature of a coffee is 85°C. The room temperature is 20°C. What
// temperature does the coffee have after 1, 2, 3 ... minutes? Create a program
// that calculates the change according to the following specification: The
// temperature in the cup decreases after every minute. The change is 10% of the
// difference between the last temperature and the room temperature. After what
// time has the coffee reached approximately (tolerance 2 °C) the room
// temperature?

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
    std::cout << "Minute " << minutes << ": " << "The coffee temperature is "
              << coffeeTemperature << "°C.\n";
  }

  std::cout
      << "The coffee temperature is approximately the room temperature after "
      << minutes << " minutes.\n";

  return 0;
}