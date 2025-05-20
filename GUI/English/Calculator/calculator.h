#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "data.h"
#include <cmath>

class calculator {
private:
  data *dataStorage;

public:
  calculator(data *data);
  bool add();
  bool sub();
  bool mul();
  bool div();
  bool pow();
  bool sqrt();
  bool binaryAnd();
  bool binaryOr();
  bool binaryNand();
  bool calculateFormula(const std::string &formula);
};

#endif // CALCULATOR_H
