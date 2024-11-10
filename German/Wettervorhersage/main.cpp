// Bei der Wettervorhersage betrachten wir ein einfaches Modell für Rhein­Main.
// Bei westlichem Wind kommt häufiger Regen, bei Ostwind seltener. Wenn der
// Luftdruck hoch ist, ist das Wetter meist besser, als bei niedrigem Luftdruck.
// Entwerfen und erstellen sie ein Programm, das die Windrichtung und den
// Luftdruck abfragt und daraus eine Prognose erstellt. Für die Windrichtungen
// verwenden Sie folgenden Schlüssel: 1 = West, 2 = Nord, 3 = Ost, 4 = Süd. Den
// Luftdruck soll der Benutzer in hPa (ohne Einheitsangabe) eingeben.
// +--------------+----------------------+-----------------------+
// | Windrichtung | Luftdruck > 1010 hPa | Luftdruck <= 1010 hPa |
// +--------------+----------------------+-----------------------+
// | West         | veränderlich         | regnerisch            |
// | Nord         | gut                  | veränderlich          |
// | Ost / Süd    | gut                  | veränderlich          |
// +--------------+----------------------+-----------------------+

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  int Windrichtung;
  double Luftdruck;

  std::cout
      << "Gebe die Windrichtung ein (1=Norden, 2=Osten, 3=Süden, 4=Westen): ";
  std::cin >> Windrichtung;

  std::cout << "Gebe den Luftdruck in hPa ein: ";
  std::cin >> Luftdruck;

  if (Luftdruck <= 1010) {
    switch (Windrichtung) {
    case 1:
      std::cout << "Das Wetter im Norden ist veränderlich.\n";
      break;
    case 2:
      std::cout << "Das Wetter im Osten ist veränderlich.\n";
      break;
    case 3:
      std::cout << "Das Wetter im Süden ist veränderlich.\n";
      break;
    case 4:
      std::cout << "Das Wetter im Westen ist regnerisch.\n";
      break;
    }
  } else if (Luftdruck > 1010) {
    switch (Windrichtung) {
    case 1:
      std::cout << "Das Wetter im Norden ist gut.\n";
      break;
    case 2:
      std::cout << "Das Wetter im Osten ist gut.\n";
      break;
    case 3:
      std::cout << "Das Wetter im Süden ist gut.\n";
      break;
    case 4:
      std::cout << "Das Wetter im Westen ist veränderlich.\n";
      break;
    }
  }

  return 0;
}