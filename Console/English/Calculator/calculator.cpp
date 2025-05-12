#include "calculator.h"
#include <iostream>

calculator::calculator(data *data) { dataStorage = data; }

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
