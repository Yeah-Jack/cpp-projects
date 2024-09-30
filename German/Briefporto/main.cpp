#include <Windows.h>
#include <iostream>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  const short gewichtStandardbrief = 20;
  const short gewichtKompaktbrief = 50;
  const short gewichtGroßbrief = 500;
  const short gewichtMaxibrief = 1000;

	short gewichtUser;

	std::cout << "Wie schwer ist dein Brief in Gramm?" << std::endl;
	std::cin >> gewichtUser;

	if (gewichtUser <= gewichtStandardbrief) {
		std::cout << "Dein Brief ist ein Standardbrief." << std::endl;
	} else if (gewichtUser <= gewichtKompaktbrief) {
		std::cout << "Dein Brief ist ein Kompaktbrief." << std::endl;
	} else if (gewichtUser <= gewichtGroßbrief) {
		std::cout << "Dein Brief ist ein Großbrief." << std::endl;
	} else if (gewichtUser <= gewichtMaxibrief) {
		std::cout << "Dein Brief ist ein Maxibrief." << std::endl;
	} else {
		std::cout << "Dein Brief ist zu schwer." << std::endl;
	}

  return 0;
}