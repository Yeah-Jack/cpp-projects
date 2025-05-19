#include "ui.h"
#include <iostream>
#include <sstream>
#include <vector>

ui::ui() : myCalculator(&myData) {}

/**
 * @brief Startet die Hauptschleife der UI
 */
void ui::main() {
  int choice;
  do {
    std::cout << "Wähle eine Operation:\n1) Addition\n2) Subtraktion\n3) "
                 "Multiplikation\n4) Division\n5) Potenzierung\n6) "
                 "Quadratwurzel ziehen\n7) Binäres AND\n8) Binäres OR\n9) "
                 "Binäres NAND\n10) Formel eingeben\n11) Beenden\n";
    choice = getChoice();
    if (choice != 11) {
      calculate(choice);
    }
  } while (choice != 11);
}

/**
 * @brief Eingabe der Operationsnummer vom Benutzer
 * @return Die ausgewählte Operationsnummer
 */
int ui::getChoice() {
  int choice;
  std::cout << "Deine Wahl: ";
  while (!(std::cin >> choice) || choice < 1 || choice > 11) {
    std::cout << "Ungültige Eingabe. Wähle eine Zahl zwischen 1 und 11: ";
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
  bool success = false;

  if (choice >= 1 && choice <= 5) {
    std::cout << "Gebe die erste Zahl ein: ";
    myData.setOperandA(getDoubleInput());

    std::cout << "Gebe die zweite Zahl ein: ";
    myData.setOperandB(getDoubleInput());

  } else if (choice == 6) {
    std::cout << "Gebe die Zahl ein: ";
    myData.setOperandA(getDoubleInput());
  } else if (choice >= 7 && choice <= 9) {
    std::cout << "Gebe die erste Ganzzahl ein: ";
    myData.setIntOperandA(getIntInput());
    std::cout << "Gebe die zweite Ganzzahl ein: ";
    myData.setIntOperandB(getIntInput());
  }

  switch (choice) {
  case 1:
    success = myCalculator.add();
    break;
  case 2:
    success = myCalculator.sub();
    break;
  case 3:
    success = myCalculator.mul();
    break;
  case 4:
    success = myCalculator.div();
    break;
  case 5:
    success = myCalculator.pow();
    break;
  case 6:
    success = myCalculator.sqrt();
    break;
  case 7:
    success = myCalculator.binaryAnd();
    break;
  case 8:
    success = myCalculator.binaryOr();
    break;
  case 9:
    success = myCalculator.binaryNand();
    break;
  case 10:
    std::string formula;
    std::cout << "Gebe die Formel mit ein: ";
    std::cin.ignore();
    std::getline(std::cin, formula);

    success = myCalculator.calculateFormula(formula);
    break;
  }

  if (success) {
    if (choice >= 7 && choice <= 9) {
      std::cout << "Ergebnis: " << myData.getIntResult();
    } else {
      std::cout << "Ergebnis: " << myData.getResult();
    }
  } else {
    std::cout << myData.getErrorMessage();
  }

  std::cout << "\n\n";
}
