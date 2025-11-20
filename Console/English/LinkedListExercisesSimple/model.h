#ifndef MODEL_H
#define MODEL_H

#include "entry.h"

class model {
public:
  model();

  void insertStart(int age);
  void insertEnd(int age);

  void printForward() const;

private:
  entry *start;
  entry *current;
};

#endif // MODEL_H
