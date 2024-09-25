#include <iostream>

int main() {
  const double bananePreis = 3.99;
  const double apfelPreis = 2.99;
  const double brotPreis = 0.49;
  const double milchPreis = 1.09;
  const double steuer = 0.07;

  int bananeAnzahl;
  int apfelAnzahl;
  int brotAnzahl;
  int milchAnzahl;

  std::cout << "Wie viele Bananen möchten Sie kaufen? ";
  std::cin >> bananeAnzahl;
  std::cout << "Wie viele Äpfel möchten Sie kaufen? ";
  std::cin >> apfelAnzahl;
  std::cout << "Wie viele Brote möchten Sie kaufen? ";
  std::cin >> brotAnzahl;
  std::cout << "Wie viele Milch möchten Sie kaufen? ";
  std::cin >> milchAnzahl;

  double gesamtKosten = (bananeAnzahl * bananePreis) +
                        (apfelAnzahl * apfelPreis) + (brotAnzahl * brotPreis) +
                        (milchAnzahl * milchPreis);

  double steuerBetrag = gesamtKosten * steuer;

  std::cout << "Die Gesamtkosten mit Steuer betragen: "
            << (gesamtKosten + steuerBetrag) << " Euro" << std::endl
            << "Die Gesamtkosten ohne Steuer betragen: " << gesamtKosten
            << " Euro" << std::endl;

  return 0;
}