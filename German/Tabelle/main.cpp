#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  std::cout << "Test 1: " << (2 + 3 == 5 ? "Bestanden" : "Fehlgeschlagen")
            << std::endl;
  std::cout << "Test 2: " << (6 + 4 == 10 ? "Bestanden" : "Fehlgeschlagen")
            << std::endl;
  std::cout << "Test 3: " << (10 + 20 == 30 ? "Bestanden" : "Fehlgeschlagen")
            << std::endl;
  std::cout << "Test 4: " << (5 + 3 == 7 ? "Bestanden" : "Fehlgeschlagen")
            << std::endl;
  std::cout << "Test 5: " << (100 + 200 == 250 ? "Bestanden" : "Fehlgeschlagen")
            << std::endl;

  return 0;
}
