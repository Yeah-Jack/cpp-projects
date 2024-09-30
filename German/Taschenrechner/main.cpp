#include <Windows.h>
#include <iostream>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  double zahl1;
  double zahl2;
  double summe;
  short grundrechenart;
  short wiederholung;

  do {
    std::cout << "Gebe Zahl 1 ein: ";
  std::cin >> zahl1;
  std::cout << "Gebe Zahl 2 ein: ";
  std::cin >> zahl2;

  std::cout << "Wähle eine Option aus." << std::endl << "1) Plus" << std::endl << "2) Minus" << std::endl<< "3) Multiplikation" << std::endl << "4) Division" << std::endl;

  std::cin >> grundrechenart;

  switch (grundrechenart) {
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

  std::cout << "Möchtest du eine weitere Rechnung durchführen?" << std::endl <<           "1) Ja" << std::endl << 
               "2) Nein" << std::endl;
  std::cin >> wiederholung;
  } while (wiederholung == 1);

  return 0;
}
