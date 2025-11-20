#include "model.h"
// #include <iostream>

int main() {
  model *list = new model;
  list->insertStart(10);
  list->insertStart(20);
  list->insertEnd(50);

  list->printForward();

  return 0;
}
