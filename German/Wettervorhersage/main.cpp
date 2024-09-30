#include <Windows.h>
#include <iostream>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  int Windrichtung;
  double Luftdruck;

  std::cout
      << "Gebe die Windrichtung ein (1=Norden, 2=Osten, 3=Süden, 4=Westen)"
      << std::endl;
  std::cin >> Windrichtung;

  std::cout << "Gebe den Luftdruck in hPa ein:" << std::endl;
  std::cin >> Luftdruck;

  if (Luftdruck <= 1010) {
    switch (Windrichtung) {
    case 1:
      std::cout << "Das Wetter im Norden ist veränderlich." << std::endl;
      break;
    case 2:
      std::cout << "Das Wetter im Osten ist veränderlich." << std::endl;
      break;
    case 3:
      std::cout << "Das Wetter im Süden ist veränderlich." << std::endl;
      break;
    case 4:
      std::cout << "Das Wetter im Westen ist regnerisch." << std::endl;
      break;
    }
  } else if (Luftdruck > 1010) {
    switch (Windrichtung) {
    case 1:
      std::cout << "Das Wetter im Norden ist gut." << std::endl;
      break;
    case 2:
      std::cout << "Das Wetter im Osten ist gut." << std::endl;
      break;
    case 3:
      std::cout << "Das Wetter im Süden ist gut." << std::endl;
      break;
    case 4:
      std::cout << "Das Wetter im Westen ist veränderlich." << std::endl;
      break;
    }
  }

  return 0;
}