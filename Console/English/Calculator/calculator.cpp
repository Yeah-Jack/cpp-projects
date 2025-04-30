#include "calculator.h"
#include <iostream>

/**
 * @brief calculator::add Addiert zwei Zahlen
 * @param a Erster Summand
 * @param b Zweiter Summand
 * @return Summe von a und b
 */
double calculator::add(double a, double b) { return a + b; }

/**
 * @brief Subtrahiert zwei Zahlen
 * @param a Minuend
 * @param b Subtrahend
 * @return Differenz von a und b
 */
double calculator::sub(double a, double b) { return a - b; }

/**
 * @brief Multipliziert zwei Zahlen
 * @param a Erster Faktor
 * @param b Zweite Faktor
 * @return Produkt von a und b
 */
double calculator::mul(double a, double b) { return a * b; }

/**
 * @brief Dividiert zwei Zahlen
 * @param a Dividend
 * @param b Divisor
 * @return Quotient von a und b
 */
double calculator::div(double a, double b) {
  if (b == 0) {
    std::cout << "Fehler: Division durch Null.\n";
  }
  return a / b;
}

/**
 * @brief Potenziert Basis mit einem Exponenten
 * @param a Basiszahl
 * @param b Exponent
 * @return Potenz
 */
double calculator::pow(double a, double b) { return std::pow(a, b); }

/**
 * @brief Zieht die Quadratwurzel
 * @param a Zahl
 * @return Quadratwurzel
 */
double calculator::sqrt(double a) {
  if (a < 0) {
    std::cout << "Fehler: Wurzel aus negativer Zahl.\n";
  }
  return std::sqrt(a);
}

/**
 * @brief Bitweise UND-Operation von zwei Ganzzahlen
 * @param a Erste Ganzzahl
 * @param b Zweite Ganzzahl
 * @return Ergebnis von a & b
 */
int calculator::bitwiseAnd(int a, int b) { return a & b; }

/**
 * @brief Bitweise ODER-Operation von zwei Ganzzahlen
 * @param a Erste Ganzzahl
 * @param b Zweite Ganzzahl
 * @return Ergebnis von a | b
 */
int calculator::bitwiseOr(int a, int b) { return a | b; }
