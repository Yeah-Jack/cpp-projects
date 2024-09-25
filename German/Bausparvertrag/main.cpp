#include <Windows.h>
#include <iostream>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  double Sparleistung, Prämie;
  short Kinder;
  bool Verheiratet;

  std::cout << "Wie viel Euro möchten Sie monatlich sparen? ";
  std::cin >> Sparleistung;

  if (Sparleistung > 800) {
    Sparleistung = 800;
    std::cout << "Der Maximalsparbetrag beträgt 800 Euro und wurde deshalb "
                 "auch auf 800 Euro geändert."
              << std::endl;
  }

  std::cout << "Sind Sie verheiratet? (1 = Ja, 0 = Nein)" << std::endl;
  std::cin >> Verheiratet;

  if (Verheiratet == true) {
    Prämie = Sparleistung * 0.07;
  } else {
    Prämie = Sparleistung * 0.14;
  }

  std::cout << "Wie viele Kinder haben Sie?" << std::endl;
  std::cin >> Kinder;

  Prämie += Kinder * 0.02 * Sparleistung;

  std::cout << "Deine Prämie ist: " << Prämie << "€" << std::endl;

  return 0;
}
