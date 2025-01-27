// Erstelle ein Programm, das die Anzahl der Wechselgeldmünzen berechnet. Der
// Benutzer gibt den zu zahlenden Betrag und den gegebenen Betrag an, das
// Programm berechnet das Rückgeld und die Anzahl der Münzen und Scheinen. Es
// sollen möglichst wenige Münzen und Scheine ausgeben werden.

#include <cmath>
#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  double zuZahlenderBetrag;
  double gegebenerBetrag;
  double rueckgeld;
  int rueckgeldInCents;

  int anzahlEinCent = 0;
  int anzahlZweiCent = 0;
  int anzahlFuenfCent = 0;
  int anzahlZehnCent = 0;
  int anzahlZwanzigCent = 0;
  int anzahlFuenfzigCent = 0;
  int anzahlEinEuro = 0;
  int anzahlZweiEuro = 0;
  int anzahlFuenfEuro = 0;
  int anzahlZehnEuro = 0;
  int anzahlZwanzigEuro = 0;
  int anzahlFuenfzigEuro = 0;
  int anzahlHundertEuro = 0;
  int anzahlZweihundertEuro = 0;

  std::cout << "Gebe den zu zahlenden Betrag in € ein: ";
  std::cin >> zuZahlenderBetrag;

  std::cout << "Gebe den gegebenen Betrag in € ein: ";
  std::cin >> gegebenerBetrag;

  rueckgeld = gegebenerBetrag - zuZahlenderBetrag;
  rueckgeldInCents = static_cast<int>(rueckgeld * 100);
  std::cout << "Dein Rückgeld beträgt: " << rueckgeld << "€.\n";

  while (rueckgeldInCents >= 20000) {
    rueckgeldInCents -= 20000;
    anzahlZweihundertEuro++;
  }

  while (rueckgeldInCents >= 10000) {
    rueckgeldInCents -= 10000;
    anzahlHundertEuro++;
  }

  while (rueckgeldInCents >= 5000) {
    rueckgeldInCents -= 5000;
    anzahlFuenfzigEuro++;
  }

  while (rueckgeldInCents >= 2000) {
    rueckgeldInCents -= 2000;
    anzahlZwanzigEuro++;
  }

  while (rueckgeldInCents >= 1000) {
    rueckgeldInCents -= 1000;
    anzahlZehnEuro++;
  }

  while (rueckgeldInCents >= 500) {
    rueckgeldInCents -= 500;
    anzahlFuenfEuro++;
  }

  while (rueckgeldInCents >= 200) {
    rueckgeldInCents -= 200;
    anzahlZweiEuro++;
  }

  while (rueckgeldInCents >= 100) {
    rueckgeldInCents -= 100;
    anzahlEinEuro++;
  }

  while (rueckgeldInCents >= 50) {
    rueckgeldInCents -= 50;
    anzahlFuenfzigCent++;
  }

  while (rueckgeldInCents >= 20) {
    rueckgeldInCents -= 20;
    anzahlZwanzigCent++;
  }

  while (rueckgeldInCents >= 10) {
    rueckgeldInCents -= 10;
    anzahlZehnCent++;
  }

  while (rueckgeldInCents >= 5) {
    rueckgeldInCents -= 5;
    anzahlFuenfCent++;
  }

  while (rueckgeldInCents >= 2) {
    rueckgeldInCents -= 2;
    anzahlZweiCent++;
  }

  while (rueckgeldInCents >= 1) {
    rueckgeldInCents -= 1;
    anzahlEinCent++;
  }

  std::cout << "Anzahl 200€ Scheine: " << anzahlZweihundertEuro << '\n';
  std::cout << "Anzahl 100€ Scheine: " << anzahlHundertEuro << '\n';
  std::cout << "Anzahl 50€ Scheine: " << anzahlFuenfzigEuro << '\n';
  std::cout << "Anzahl 20€ Scheine: " << anzahlZwanzigEuro << '\n';
  std::cout << "Anzahl 10€ Scheine: " << anzahlZehnEuro << '\n';
  std::cout << "Anzahl 5€ Scheine: " << anzahlFuenfEuro << '\n';
  std::cout << "Anzahl 2€ Münzen: " << anzahlZweiEuro << '\n';
  std::cout << "Anzahl 1€ Münzen: " << anzahlEinEuro << '\n';
  std::cout << "Anzahl 50c Münzen: " << anzahlFuenfzigCent << '\n';
  std::cout << "Anzahl 20c Münzen: " << anzahlZwanzigCent << '\n';
  std::cout << "Anzahl 10c Münzen: " << anzahlZehnCent << '\n';
  std::cout << "Anzahl 5c Münzen: " << anzahlFuenfCent << '\n';
  std::cout << "Anzahl 2c Münzen: " << anzahlZweiCent << '\n';
  std::cout << "Anzahl 1c Münzen: " << anzahlEinCent << '\n';

  return 0;
}