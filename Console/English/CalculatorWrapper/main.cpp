// This is a simple C++ program that serves as a wrapper for two different
// calculator versions. Make sure to put both programs in the same directory as
// this wrapper.

#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);
  char choice;

  do {
    std::cout << "Wähle die Version aus: Konsolen (k) oder GUI (g) Version: ";
    std::cin >> choice;

    if (choice == 'k' || choice == 'K') {
      std::cout << "Konsolen Version ausgewählt.\n";
      system("console_calculator.exe");
    } else if (choice == 'g' || choice == 'G') {
      std::cout << "GUI Version ausgewählt.\n";
      system("gui_calculator.exe");
    } else {
      std::cout << "Ungültige Auswahl.\n";
      std::cin.clear();
      std::cin.ignore();
    }
  } while (choice != 'k' && choice != 'K' && choice != 'g' && choice != 'G');

  return 0;
}