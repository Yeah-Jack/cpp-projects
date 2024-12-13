// Erstellen Sie ein Programm, dass Notenpunkte in Schulnoten übersetzt.

#include <iostream>
#include <vector>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  std::vector<std::pair<int, std::string>> noten = {
      {15, "1+"}, {14, "1"}, {13, "1-"}, {12, "2+"}, {11, "2"}, {10, "2-"},
      {9, "3+"},  {8, "3"},  {7, "3-"},  {6, "4+"},  {5, "4"},  {4, "4-"},
      {3, "5+"},  {2, "5"},  {1, "5-"},  {0, "6"}};

  int punkte;
  std::cout << "Wie viele Punkte hast du? ";
  std::cin >> punkte;

  for (const auto &note : noten) {
    if (punkte == note.first) {
      std::cout << "Deine Note ist: " << note.second << '\n';
      break;
    }
  }

  // short punkte;

  // std::cout << "Wie viele Punkte hast du? ";
  // std::cin >> punkte;

  // if (punkte >= 13) {
  //   std::cout << "Du hast eine 1\n";
  // } else if (punkte >= 10) {
  //   std::cout << "Du hast eine 2\n";
  // } else if (punkte >= 7) {
  //   std::cout << "Du hast eine 3\n";
  // } else if (punkte >= 4) {
  //   std::cout << "Du hast eine 4\n";
  // } else if (punkte >= 1) {
  //   std::cout << "Du hast eine 5\n";
  // } else if (punkte == 0) {
  //   std::cout << "Du hast eine 6\n";
  // }

  return 0;
}