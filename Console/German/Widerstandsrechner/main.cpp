#include <iostream>
#include <windows.h>

int menu(int &auswahl);
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

  do {
    menu(auswahl);
    if (auswahl > 0) {
      berechnung(auswahl, widerstand1, widerstand2, widerstand3, ergebnis);
    }
  } while (auswahl > 0);

  return 0;
}

int menu(int &auswahl) {
  std::cout << "Menü:\n"
            << "1) Reihenschaltung von 2 Widerständen\n"
            << "2) Parallelschaltung von 2 Widerständen\n"
            << "3) Reihenschaltung von 3 Widerständen\n"
            << "0) Programm beenden\n";
  std::cin >> auswahl;

  return 0;
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
    ausgabe(ergebnis);
    break;
  case 2:
    std::cout << "Bitte Wert für Widerstand 1 eingeben: ";
    std::cin >> widerstand1;
    std::cout << "Bitte Wert für Widerstand 2 eingeben: ";
    std::cin >> widerstand2;
    ergebnis = (widerstand1 * widerstand2) / (widerstand1 + widerstand2);
    ausgabe(ergebnis);
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
    ausgabe(ergebnis);
    break;
  default:
    std::cout << "Fehler\n";
    break;
  }
}

void ausgabe(double &ergebnis) {
  std::cout << "Ergebnis: " << ergebnis << "\n\n";
}