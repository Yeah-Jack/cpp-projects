#include "calculator.h"
#include <iostream>
#include <sstream>
#include <vector>

calculator::calculator(data *newData) { dataStorage = newData; }

/**
 * @brief Addiert die in dataStorage gespeicherten Operanden.
 * @return true bei Erfolg, false bei Fehler.
 */
bool calculator::add() {
  dataStorage->clearError();
  double a = dataStorage->getOperandA();
  double b = dataStorage->getOperandB();
  dataStorage->setResult(a + b);
  return true;
}

/**
 * @brief Subtrahiert die in dataStorage gespeicherten Operanden.
 * @return true bei Erfolg, false bei Fehler.
 */
bool calculator::sub() {
  dataStorage->clearError();
  double a = dataStorage->getOperandA();
  double b = dataStorage->getOperandB();
  dataStorage->setResult(a - b);
  return true;
}

/**
 * @brief Multipliziert die in dataStorage gespeicherten Operanden.
 * @return true bei Erfolg, false bei Fehler.
 */
bool calculator::mul() {
  dataStorage->clearError();
  double a = dataStorage->getOperandA();
  double b = dataStorage->getOperandB();
  dataStorage->setResult(a * b);
  return true;
}

/**
 * @brief Dividiert die in dataStorage gespeicherten Operanden.
 * @return true bei Erfolg, false bei Fehler (Division durch Null).
 */
bool calculator::div() {
  dataStorage->clearError();
  double a = dataStorage->getOperandA();
  double b = dataStorage->getOperandB();

  if (b == 0) {
    dataStorage->setErrorMessage("Fehler: Division durch Null.");
    dataStorage->setError(true);
    return false;
  }

  dataStorage->setResult(a / b);
  return true;
}

/**
 * @brief Potenziert Basis mit Exponent aus dataStorage.
 * @return true bei Erfolg, false bei Fehler.
 */
bool calculator::pow() {
  dataStorage->clearError();
  double a = dataStorage->getOperandA();
  double b = dataStorage->getOperandB();

  if (a == 0 && b == 0) {
    dataStorage->setErrorMessage("Fehler: 0^0 ist undefiniert.");
    dataStorage->setError(true);
    return false;
  }

  dataStorage->setResult(std::pow(a, b));
  return true;
}

/**
 * @brief Zieht die Quadratwurzel der Zahl in OperandA aus dataStorage.
 * @return true bei Erfolg, false bei Fehler (negative Zahl).
 */
bool calculator::sqrt() {
  dataStorage->clearError();
  double a = dataStorage->getOperandA();
  if (a < 0) {
    dataStorage->setErrorMessage("Fehler: Wurzel aus negativer Zahl.");
    dataStorage->setError(true);
    return false;
  }
  dataStorage->setResult(std::sqrt(a));
  return true;
}

/**
 * @brief Binäre AND-Operation der Ganzzahlen aus dataStorage.
 * @return true bei Erfolg, false bei Fehler.
 */
bool calculator::binaryAnd() {
  dataStorage->clearError();
  int a = dataStorage->getIntOperandA();
  int b = dataStorage->getIntOperandB();
  dataStorage->setIntResult(a & b);
  return true;
}

/**
 * @brief Binäre OR-Operation der Ganzzahlen aus dataStorage.
 * @return true bei Erfolg, false bei Fehler.
 */
bool calculator::binaryOr() {
  dataStorage->clearError();
  int a = dataStorage->getIntOperandA();
  int b = dataStorage->getIntOperandB();
  dataStorage->setIntResult(a | b);
  return true;
}

/**
 * @brief Binäre NAND-Operation der Ganzzahlen aus dataStorage.
 * @return true bei Erfolg, false bei Fehler.
 */
bool calculator::binaryNand() {
  dataStorage->clearError();
  int a = dataStorage->getIntOperandA();
  int b = dataStorage->getIntOperandB();
  dataStorage->setIntResult(!(a & b));
  return true;
}

/**
 * @brief Liest eine Formel ein und berechnet sie
 * @param formula Die Formel als string
 * @return true bei Erfolg, false bei Fehler.
 */
bool calculator::calculateFormula(const std::string &formula) {
  dataStorage->clearError();
  std::istringstream iss(formula);
  std::vector<std::string> formulaFormated;
  std::string item;
  while (iss >> item) {
    formulaFormated.push_back(item);
  }

  if (formulaFormated.size() < 3 || (formulaFormated.size() % 2 == 0)) {
    dataStorage->setErrorMessage(
        "Ungültige Formel. Gebe eine Formel mit Leerzeichen, Zahlen und "
        "Operatoren abwechselnd ein.");
    dataStorage->setError(true);
    return false;
  }

  double initialValue = std::stod(formulaFormated[0]);
  dataStorage->setResult(initialValue);

  for (size_t i = 1; i < formulaFormated.size(); i += 2) {
    std::string op = formulaFormated[i];
    double nextNumber = std::stod(formulaFormated[i + 1]);
    dataStorage->setOperandA(dataStorage->getResult());
    dataStorage->setOperandB(nextNumber);

    bool success = false;
    if (op == "+") {
      success = add();
    } else if (op == "-") {
      success = sub();
    } else if (op == "*") {
      success = mul();
    } else if (op == "/") {
      success = div();
    } else {
      dataStorage->setErrorMessage("Unbekannter Operator: " + op);
      dataStorage->setError(true);
      return false;
    }

    if (!success) {
      return false;
    }
  }
  return true;
}