#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cmath>

class calculator {
public:
  // calculator();
  double add(double a, double b);
  double sub(double a, double b);
  double mul(double a, double b);
  double div(double a, double b);
  double pow(double a, double b);
  double sqrt(double a);
  int bitwiseAnd(int a, int b);
  int bitwiseOr(int a, int b);
};

#endif // CALCULATOR_H
