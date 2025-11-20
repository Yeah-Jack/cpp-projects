#include "model.h"
#include <iostream>

model::model() {
  start = nullptr;
  current = nullptr;
}

void model::insertStart(int age) {
  entry *newEntry = new entry;
  newEntry->setAge(age);

  if (start == nullptr) {
    start = newEntry;
  } else {
    newEntry->setNext(start);
    start->setPrevious(newEntry);
    start = newEntry;
    newEntry = nullptr;
  }
}

void model::insertEnd(int age) {
  entry *newEntry = new entry;
  newEntry->setAge(age);

  if (start == nullptr) {
    start = newEntry;
  } else {
    current = start;

    while (current->getNext() != nullptr) {
      current = current->getNext();
    }

    if (current != nullptr) {
      current->setNext(newEntry);
    }
  }
}

void model::printForward() const {
  entry *current = start;
  while (current != nullptr) {
    std::cout << current->getAge();
    if (current->getNext() != nullptr) {
      std::cout << " <-> ";
    }
    current = current->getNext();
  }
  std::cout << '\n';
}
