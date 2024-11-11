// In der gymnasialen Oberstufe (vereinfachtes Modell) gilt: Wer maximal ein
// Hauptfach unter 5 Punkte (Note 4) hat, kann das ausgleichen. Entweder mit
// einem Hauptfach mit min. 10 Punkte (Note 2) oder zwei Hauptfächern mit min. 7
// Punkten (Note 3). Eine Note unter 5 Punkte im Schwerpunkthauptfach kann man
// nicht ausgleichen. Erstellen Sie ein Programm, das die Noten
// abfragt und anschließend eine Prüfung vornimmt, ob man zugelassen wird und
// Ihnen das ausgibt.

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  short punkteHauptfach;
  short punkteHauptfachAusgleich1;
  short punkteHauptfachAusgleich2;

  std::cout << "Wie viele Punkte hast du in deinem Hauptfach?\n";
  std::cin >> punkteHauptfach;

  if (punkteHauptfach >= 5) {
    std::cout << "Du musst dein Hauptfach nicht ausgleichen.\n";
  } else {
    std::cout << "Du musst dein Hauptfach ausgleichen.\n"
              << "Wie viele Punkte hast du in deinem ersten Hauptfach zum "
                 "Ausgleichen?\n";
    std::cin >> punkteHauptfachAusgleich1;
    if (punkteHauptfachAusgleich1 >= 10) {
      std::cout << "Du kannst dein Hauptfach ausgleichen.\n";
    } else {
      std::cout << "Wie viele Punkte hast du in deinem zweiten Hauptfach zum "
                   "Ausgleichen?\n";
      std::cin >> punkteHauptfachAusgleich2;
      if (punkteHauptfachAusgleich1 >= 7 && punkteHauptfachAusgleich2 >= 7) {
        std::cout << "Du kannst dein Hauptfach ausgleichen.\n";
      } else {
        std::cout << "Du kannst dein Hauptfach nicht ausgleichen.\n";
      }
    }
  }

  return 0;
}