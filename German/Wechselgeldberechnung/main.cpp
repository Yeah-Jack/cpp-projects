#include <Windows.h>
#include <iostream>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  const double einCent = 0.01;
  const double zweiCent = 0.02;
  const double fuenfCent = 0.05;
  const double zehnCent = 0.10;
  const double zwanzigCent = 0.20;
  const double fuenfzigCent = 0.50;
  const double einEuro = 1.00;
  const double zweiEuro = 2.00;

  double zuZahlenderBetrag;
  double gegebenerBetrag;
  double rueckgeld;

	int anzahlEinCent;
	int anzahlZweiCent;
	int anzahlFuenfCent;
	int anzahlZehnCent;
	int anzahlZwanzigCent;
	int anzahlFuenfzigCent;
	int anzahlEinEuro;
	int anzahlZweiEuro;

  std::cout << "Gebe den zu zahlenden Betrag in € ein: ";
  std::cin >> zuZahlenderBetrag;

  std::cout << "Gebe den gegebenen Betrag in € ein: ";
  std::cin >> gegebenerBetrag;

  rueckgeld = gegebenerBetrag - zuZahlenderBetrag;

  std::cout << "Das Rückgeld beträgt: " << rueckgeld << "€." << std::endl;

  anzahlZweiEuro = rueckgeld / zweiEuro;
  rueckgeld -= anzahlZweiEuro * zweiEuro;
  std::cout << "Anzahl 2€ Münzen: " << anzahlZweiEuro << std::endl;

  anzahlEinEuro = rueckgeld / einEuro;
  rueckgeld -= anzahlEinEuro * einEuro;
  std::cout << "Anzahl 1€ Münzen: " << anzahlEinEuro << std::endl;

  anzahlFuenfzigCent = rueckgeld / fuenfzigCent;
  rueckgeld -= anzahlFuenfzigCent * fuenfzigCent;
  std::cout << "Anzahl 50c Münzen: " << anzahlFuenfzigCent << std::endl;

  anzahlZwanzigCent = rueckgeld / zwanzigCent;
  rueckgeld -= anzahlZwanzigCent * zwanzigCent;
  std::cout << "Anzahl 20c Münzen: " << anzahlZwanzigCent << std::endl;

  anzahlZehnCent = rueckgeld / zehnCent;
  rueckgeld -= anzahlZehnCent * zehnCent;
  std::cout << "Anzahl 10c Münzen: " << anzahlZehnCent << std::endl;

  anzahlFuenfCent = rueckgeld / fuenfCent;
  rueckgeld -= anzahlFuenfCent * fuenfCent;
  std::cout << "Anzahl 5c Münzen: " << anzahlFuenfCent << std::endl;

  anzahlZweiCent = rueckgeld / zweiCent;
  rueckgeld -= anzahlZweiCent * zweiCent;
  std::cout << "Anzahl 2c Münzen: " << anzahlZweiCent << std::endl;

  anzahlEinCent = rueckgeld / einCent;
  rueckgeld -= anzahlEinCent * einCent;
  std::cout << "Anzahl 1c Münzen: " << anzahlEinCent << std::endl;
	
  return 0;
}