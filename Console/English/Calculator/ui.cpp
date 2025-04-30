#include "ui.h"
#include <iostream>

/**
 * @brief Startet die Hauptschleife der UI
 */
void ui::main() {
  int choice;
  do {
    showMenu();
    choice = getChoice();
    if (choice != 9) {
      calculate(choice);
    }
  } while (choice != 9);
}

/**
 * @brief Zeigt die Menüoptionen an
 */
void ui::showMenu() {
  std::cout << "Wähle eine Operation:\n1) Addition\n2) Subtraktion\n3) "
               "Multiplikation\n4) Division\n5) Potenzierung\n6) "
               "Quadratwurzel ziehen\n7) Bitweises AND\n8) Bitweises OR\n9) "
               "Beenden\n";
}

/**
 * @brief Eingabe der Operationsnummer vom Benutzer
 * @return Die ausgewählte Operationsnummer
 */
int ui::getChoice() {
  int choice;
  std::cout << "Deine Wahl: ";
  while (!(std::cin >> choice) || choice < 1 || choice > 9) {
    std::cout << "Ungültige Eingabe. Wähle eine Zahl zwischen 1 und 9: ";
    std::cin.clear();
    std::cin.ignore();
  }
  return choice;
}

/**
 * @brief Eingabe eines double-Wertes vom Benutzer
 * @return Der eingegebene double-Wert
 */
double ui::getDoubleInput() {
  double input;
  while (!(std::cin >> input)) {
    std::cout << "Ungültige Eingabe. Gebe eine Zahl ein: ";
    std::cin.clear();
    std::cin.ignore();
  }
  return input;
}

/**
 * @brief Eingabe eines int-Wertes vom Benutzer
 * @return Der eingegebene Ganzzahl-Wert
 */
int ui::getIntInput() {
  int input;
  while (!(std::cin >> input)) {
    std::cout << "Ungültige Eingabe. Gebe eine Ganzzahl ein: ";
    std::cin.clear();
    std::cin.ignore();
  }
  return input;
}

/**
 * @brief Führt die gewählte Operation aus
 * @param choice Die auszuführende Operation
 */
void ui::calculate(int choice) {
  double a;
  double b;
  double result;

  int intA;
  int intB;
  int intResult;

  switch (choice) {
  case 1:
    std::cout << "Gebe die erste Zahl ein: ";
    a = getDoubleInput();
    std::cout << "Gebe die zweite Zahl ein: ";
    b = getDoubleInput();
    result = myCalculator.add(a, b);
    std::cout << "Ergebnis: " << result;
    break;
  case 2:
    std::cout << "Gebe die erste Zahl ein: ";
    a = getDoubleInput();
    std::cout << "Gebe die zweite Zahl ein: ";
    b = getDoubleInput();
    result = myCalculator.sub(a, b);
    std::cout << "Ergebnis: " << result;
    break;
  case 3:
    std::cout << "Gebe die erste Zahl ein: ";
    a = getDoubleInput();
    std::cout << "Gebe die zweite Zahl ein: ";
    b = getDoubleInput();
    result = myCalculator.mul(a, b);
    std::cout << "Ergebnis: " << result;
    break;
  case 4:
    std::cout << "Gebe die erste Zahl ein: ";
    a = getDoubleInput();
    std::cout << "Gebe die zweite Zahl ein: ";
    b = getDoubleInput();
    result = myCalculator.div(a, b);
    std::cout << "Ergebnis: " << result;
    break;
  case 5:
    std::cout << "Gebe die Basis ein: ";
    a = getDoubleInput();
    std::cout << "Gebe den Exponenten ein: ";
    b = getDoubleInput();
    result = myCalculator.pow(a, b);
    std::cout << "Ergebnis: " << result;
    break;
  case 6:
    std::cout << "Gebe die Zahl ein: ";
    a = getDoubleInput();
    result = myCalculator.sqrt(a);
    std::cout << "Ergebnis: " << result;
    break;
  case 7:
    std::cout << "Gebe die erste Ganzzahl ein: ";
    intA = getIntInput();
    std::cout << "Gebe die zweite Ganzzahl ein: ";
    intB = getIntInput();
    intResult = myCalculator.bitwiseAnd(intA, intB);
    std::cout << "Ergebnis: " << intResult;
    break;
  case 8:
    std::cout << "Gebe die erste Ganzzahl ein: ";
    intA = getIntInput();
    std::cout << "Gebe die zweite Ganzzahl ein: ";
    intB = getIntInput();
    intResult = myCalculator.bitwiseOr(intA, intB);
    std::cout << "Ergebnis: " << intResult;
    break;
  }
  std::cout << "\n\n";
}