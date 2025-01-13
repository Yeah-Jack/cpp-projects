#include <iostream>
#include <windows.h>

void menu(int &auswahl);
void berechnung(int &auswahl, double &widerstand1, double &widerstand2,
                double &widerstand3, double &ergebnis);
void ausgabe(double &ergebnis);
int main() {
  SetConsoleOutputCP(CP_UTF8);

  int auswahl = 0;
  double widerstand1 = 0;
  double widerstand2 = 0;
  double widerstand3 = 0;
  double ergebnis = 0;
  char wiederholung;

  do {
    menu(auswahl);
    berechnung(auswahl, widerstand1, widerstand2, widerstand3, ergebnis);
    ausgabe(ergebnis);

    std::cout << "Möchtest du eine weitere Rechnung durchführen? (J/N)\n";
    std::cin >> wiederholung;
  } while (wiederholung == 'J' || wiederholung == 'j');

  return 0;
}

void menu(int &auswahl) {
  std::cout << "Menü:\n"
            << "1) Reihenschaltung von 2 Widerständen\n"
            << "2) Parallelschaltung von 2 Widerständen\n"
            << "3) Reihenschaltung von 3 Widerständen\n";
  std::cin >> auswahl;
}

void berechnung(int &auswahl, double &widerstand1, double &widerstand2,
                double &widerstand3, double &ergebnis) {
  switch (auswahl) {
  case 1:
    std::cout << "Bitte Wert für Widerstand 1 eingeben: ";
    std::cin >> widerstand1;
    std::cout << "Bitte Wert für Widerstand 2 eingeben: ";
    std::cin >> widerstand2;
    ergebnis = widerstand1 + widerstand2;
    break;
  case 2:
    std::cout << "Bitte Wert für Widerstand 1 eingeben: ";
    std::cin >> widerstand1;
    std::cout << "Bitte Wert für Widerstand 2 eingeben: ";
    std::cin >> widerstand2;
    ergebnis = (widerstand1 * widerstand2) / (widerstand1 + widerstand2);
    break;
  case 3:
    std::cout << "Bitte Wert für Widerstand 1 eingeben: ";
    std::cin >> widerstand1;
    std::cout << "Bitte Wert für Widerstand 2 eingeben: ";
    std::cin >> widerstand2;
    std::cout << "Bitte Wert für Widerstand 3 eingeben: ";
    std::cin >> widerstand3;
    ergebnis = widerstand1 + widerstand2;
    ergebnis = ergebnis + widerstand3;
    break;
  default:
    std::cout << "Ungültige Auswahl.\n";
    break;
  }
}

void ausgabe(double &ergebnis) {
  std::cout << "Ergebnis: " << ergebnis << "\n\n";
}