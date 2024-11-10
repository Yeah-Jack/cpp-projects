// Entwerfen und erstellen Sie ein Programm für einen einfachen Taschenrechner.
// Der Rechner soll zwei Zahlen abfragen. Anschließend soll er abfragen, was
// berechnet werden soll. Das Programm soll die gewünschte Rechnung ausführen
// und das Ergebnis ausgeben. Nach der Berechnung soll der Benutzer gefragt
// werden, ob er noch eine Rechnung machen will, wenn ja soll das Programm
// erneut beginnen. Verwenden Sie eine Schleife (while oder do – while).

#include <Windows.h>
#include <iostream>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  double zahl1;
  double zahl2;
  double ergebnis;
  short grundrechenart;
  char wiederholung;

  do {
    std::cout << "Gebe deine erste Zahl ein: ";
    std::cin >> zahl1;
    std::cout << "Gebe deine zweite Zahl ein: ";
    std::cin >> zahl2;

    do {
      std::cout << "Wähle eine Option aus:\n"
                << "1) Plus\n"
                << "2) Minus\n"
                << "3) Multiplikation\n"
                << "4) Division\n";
      std::cin >> grundrechenart;

      switch (grundrechenart) {
      case 1:
        ergebnis = zahl1 + zahl2;
        std::cout << "Ergebnis: " << ergebnis << '\n';
        break;
      case 2:
        ergebnis = zahl1 - zahl2;
        std::cout << "Ergebnis: " << ergebnis << '\n';
        break;
      case 3:
        ergebnis = zahl1 * zahl2;
        std::cout << "Ergebnis: " << ergebnis << '\n';
        break;
      case 4:
        ergebnis = zahl1 / zahl2;
        std::cout << "Ergebnis: " << ergebnis << '\n';
        break;
      default:
        break;
      }
    } while (grundrechenart < 1 || grundrechenart > 4);

    std::cout << "Möchtest du eine weitere Rechnung durchführen? (J/N)\n";
    std::cin >> wiederholung;
  } while (wiederholung == 'J' || wiederholung == 'j');

  return 0;
}
