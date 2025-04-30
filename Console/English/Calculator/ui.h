#ifndef UI_H
#define UI_H

#include "calculator.h"

class ui {
public:
  // ui();
  void main();

private:
  calculator myCalculator;
  void showMenu();
  int getChoice();
  double getDoubleInput();
  int getIntInput();
  void calculate(int choice);
};

#endif // UI_H
