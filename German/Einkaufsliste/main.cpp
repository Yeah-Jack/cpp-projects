// Entwerfen und erstellen Sie in Programm für eine einfache Einkaufliste. Der
// Benutzer soll die Anzahl von vier verschiedenen Artikeln eingeben. Das
// Programm soll anschließend die Rechnung erstellen (Summe aller Positionen).
// Die Preise legen Sie im Programm fest, Sie können optional auch Bezeichnungen
// für die Artikel angeben. Die Preise sollen als Fließkommazahl abgegeben
// werden, die Anzahl als Ganzzahl. Geben Sie die Summe mit und ohne
// Mehrwertsteuer aus. Verwenden Sie für alle Artikel den vollen Steuersatz.

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  const double bananePreis = 3.99;
  const double apfelPreis = 2.99;
  const double brotPreis = 0.49;
  const double milchPreis = 1.09;
  const double steuer = 0.07;

  short bananeAnzahl;
  short apfelAnzahl;
  short brotAnzahl;
  short milchAnzahl;

  std::cout << "Wie viele Bananen möchten Sie kaufen? ";
  std::cin >> bananeAnzahl;
  std::cout << "Wie viele Äpfel möchten Sie kaufen? ";
  std::cin >> apfelAnzahl;
  std::cout << "Wie viele Brote möchten Sie kaufen? ";
  std::cin >> brotAnzahl;
  std::cout << "Wie viel Milch möchten Sie kaufen? ";
  std::cin >> milchAnzahl;

  double gesamtKosten = (bananeAnzahl * bananePreis) +
                        (apfelAnzahl * apfelPreis) + (brotAnzahl * brotPreis) +
                        (milchAnzahl * milchPreis);

  double steuerBetrag = gesamtKosten * steuer;

  std::cout << "Die Gesamtkosten ohne Steuer betragen: " << gesamtKosten
            << "€\n"
            << "Die Gesamtkosten mit Steuer betragen: "
            << (gesamtKosten + steuerBetrag) << "€\n";

  return 0;
}