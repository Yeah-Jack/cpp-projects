#include <Windows.h>
#include <iostream>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  double zahl1;
  double zahl2;
  double summe;
  short option;

  std::cout << "Gebe Zahl 1 ein: " << std::endl;
  std::cin >> zahl1;
  std::cout << "Gebe Zahl 2 ein: " << std::endl;
  std::cin >> zahl2;

  std::cout << "Waehle eine Option aus:" << std::endl;
  std::cout << "1) Plus" << std::endl;
  std::cout << "2) Minus" << std::endl;
  std::cout << "3) Multiplikation" << std::endl;
  std::cout << "4) Division" << std::endl;

  std::cin >> option;

  switch (option) {
  case 1:
    summe = zahl1 + zahl2;
    std::cout << " Ergebnis: " << summe << std::endl;
    break;
  case 2:
    summe = zahl1 - zahl2;
    std::cout << " Ergebnis: " << summe << std::endl;
    break;
  case 3:
    summe = zahl1 * zahl2;
    std::cout << " Ergebnis: " << summe << std::endl;
    break;
  case 4:
    summe = zahl1 / zahl2;
    std::cout << "Ergebnis: " << summe << std::endl;
    break;
  default:
    std::cout << "Wähle eine Option aus";
  }

  return 0;
}
