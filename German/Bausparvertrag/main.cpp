// Erstellen Sie ein Programm, das die Bausparprämie berechnet.
// Bei einer Sparleistung von max. 800€ pro Jahr erhält ein Lediger eine Prämie
// von 14% der Sparleistung. Verheiratete erhalten je die Hälfte. Für jedes
// Kinder wird eine Prämie von 2% (Punkten) zusätzlich gewährt. Erstellen Sie
// ein Programm, das die Höhe der Prämie berechnet. Es soll die Sparleistung,
// den Familienstand und die Anzahl der Kinder berücksichtigen.

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  double Sparleistung;
  double Prämie;
  short Kinder;
  short Verheiratet;

  std::cout << "Wie viel Euro möchten Sie monatlich sparen? ";
  std::cin >> Sparleistung;

  if (Sparleistung > 800) {
    Sparleistung = 800;
    std::cout << "Der Maximalsparbetrag beträgt 800€ und wurde deshalb auf "
                 "800€ runtergesetzt.\n";
  }

  std::cout << "Sind Sie verheiratet? (1 = Ja, 0 = Nein)\n";
  std::cin >> Verheiratet;

  if (Verheiratet == 1) {
    Prämie = Sparleistung * 0.07;
  } else {
    Prämie = Sparleistung * 0.14;
  }

  std::cout << "Wie viele Kinder haben Sie?\n";
  std::cin >> Kinder;

  Prämie += Kinder * 0.02 * Sparleistung;

  std::cout << "Deine Prämie ist: " << Prämie << "€\n";

  return 0;
}
