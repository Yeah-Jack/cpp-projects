// Erstellen Sie ein Programm, mit dem die Zinsen berechnet werden können. Das
// Programm soll die benötigten Werte für k, p, t und z abfragen. Anschließend
// soll es die fehlende Information berechnen.
// Kaufmännischen Zinsformel: z = k * p * t / (100 * 360). Verwenden Sie für die
// Auswahl, die der Benutzer hat, eine Mehrfachverzweigung.

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  double zinsbetrag;
  double kapital;
  double zinssatz;
  double verzinsungszeit;

  std::cout << "Gebe dein Kapital ein: ";
  std::cin >> kapital;
  std::cout << "Gebe den Zinssatz ein: ";
  std::cin >> zinssatz;
  std::cout << "Gebe die Verzinsungszeit ein: ";
  std::cin >> verzinsungszeit;

  zinsbetrag = kapital * zinssatz * verzinsungszeit / 36000.0;

  std::cout << "Der Zinsbetrag beträgt: " << zinsbetrag << '\n';

  return 0;
}