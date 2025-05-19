#ifndef UI_H
#define UI_H

#include "calculator.h"
#include "data.h"

class ui {
public:
  ui();
  void main();

private:
  data myData;
  calculator myCalculator;
  int getChoice();
  double getDoubleInput();
  int getIntInput();
  void calculate(int choice);
  void calculateFormula();
};

#endif // UI_H
