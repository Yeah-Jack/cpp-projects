#include <Windows.h>
#include <iostream>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  const short gewichtStandardbrief = 20;
  const short gewichtKompaktbrief = 50;
  const short gewichtGrossbrief = 500;
  const short gewichtMaxibrief = 1000;

  const double laengeStandardbrief = 23.5;
  const double laengeKompaktbrief = 23.5;
  const double laengeGrossbrief = 35.5;
  const double laengeMaxibrief = 35.5;

  const double breiteStandardbrief = 12.5;
  const double breiteKompaktbrief = 12.5;
  const double breiteGrossbrief = 25;
  const double breiteMaxibrief = 25;

  const double hoeheStandardbrief = 0.5;
  const double hoeheKompaktbrief = 1;
  const double hoeheGrossbrief = 2;
  const double hoeheMaxibrief = 5;

	const double preisStandardbrief = 0.85;
	const double preisKompaktbrief = 1;
	const double preisGrossbrief = 1.60;
	const double preisMaxibrief = 2.75;

  short gewichtUser;
  double laengeUser;
  double breiteUser;
  double hoeheUser;

  std::cout << "Wie schwer ist dein Brief in Gramm?" << std::endl;
  std::cin >> gewichtUser;

  std::cout << "Wie lang ist dein Brief in cm?" << std::endl;
  std::cin >> laengeUser;

  std::cout << "Wie breit ist dein Brief in cm?" << std::endl;
  std::cin >> breiteUser;

  std::cout << "Wie hoch ist dein Brief in cm?" << std::endl;
  std::cin >> hoeheUser;

  if (gewichtUser <= gewichtStandardbrief &&
      laengeUser <= laengeStandardbrief && breiteUser <= breiteStandardbrief &&
      hoeheUser <= hoeheStandardbrief) {
    std::cout << "Dein Brief ist ein Standardbrief und kostet " << preisStandardbrief << "€." << std::endl;
  } else if (gewichtUser <= gewichtKompaktbrief &&
             laengeUser <= laengeKompaktbrief &&
             breiteUser <= breiteKompaktbrief &&
             hoeheUser <= hoeheKompaktbrief) {
    std::cout << "Dein Brief ist ein Kompaktbrief und kostet " << preisKompaktbrief << "€." << std::endl;
  } else if (gewichtUser <= gewichtGrossbrief &&
             laengeUser <= laengeGrossbrief && breiteUser <= breiteGrossbrief &&
             hoeheUser <= hoeheGrossbrief) {
    std::cout << "Dein Brief ist ein Großbrief und kostet " << preisGrossbrief << "€." << std::endl;
  } else if (gewichtUser <= gewichtMaxibrief && laengeUser <= laengeMaxibrief &&
             breiteUser <= breiteMaxibrief && hoeheUser <= hoeheMaxibrief) {
    std::cout << "Dein Brief ist ein Maxibrief und kostet " << preisMaxibrief << "€." << std::endl;
  } else {
    std::cout << "Dein Brief ist zu groß oder zu schwer." << std::endl;
  }

  return 0;
}