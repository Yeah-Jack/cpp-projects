// Die Sparbank hat ein neues Gebührenmodell erstellt: Die ersten 10 Buchungen
// im Monat sind kostenfrei, Buchung 11 bis 20 kosten je 15 Cent, alle weiteren
// je 10 Cent. Entwerfen und entwickeln Sie ein Programm, das die Gebühren nach
// Eingabe der Buchungsanzahl berechnet.

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  int Buchungen;
  double Gebühren;

  std::cout << "Wie viele Buchungen haben Sie im Monat getätigt? ";
  std::cin >> Buchungen;

  if (Buchungen <= 10) {
    std::cout << "Sie zahlen 0€ Gebühren pro Transaktion." << std::endl;
    Gebühren = 0;
  } else if (Buchungen > 10 && Buchungen <= 20) {
    Buchungen = Buchungen - 10;
    std::cout << "Sie zahlen 0.15€ Gebühren pro Transaktion." << std::endl;
    Gebühren = 0.15;
  } else {
    Buchungen = Buchungen - 10;
    std::cout << "Sie zahlen 0.10€ Gebühren pro Transaktion." << std::endl;
    Gebühren = 0.10;
  }

  std::cout << "Ihre Gebühren betragen: " << Buchungen * Gebühren << "€"
            << std::endl;

  return 0;
}