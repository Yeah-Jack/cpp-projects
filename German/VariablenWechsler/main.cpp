// Entwerfen und erstellen Sie ein Programm, das zwei Werte (z.B. Zahlen oder
// Buchstaben) einließt. Das Programm soll die Inhalte der internen Variablen
// vertauschen und dann die Werte ausgeben.

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  int zahl1;
  int zahl2;
  int temp;

  std::cout << "Gebe Zahl 1 ein: ";
  std::cin >> zahl1;
  std::cout << "Gebe Zahl 2 ein: ";
  std::cin >> zahl2;

  temp = zahl1;
  zahl1 = zahl2;
  zahl2 = temp;

  std::cout << "Neue Zahl 1: " << zahl1 << '\n'
            << "Neue Zahl 2: " << zahl2 << '\n';

  return 0;
}
