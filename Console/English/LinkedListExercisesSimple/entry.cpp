#include "entry.h"

entry::entry() { next = nullptr; }

int entry::getAge() const { return age; }

void entry::setAge(int newAge) { age = newAge; }

entry *entry::getNext() const { return next; }

void entry::setNext(entry *newNext) { next = newNext; }

entry *entry::getPrevious() const { return previous; }

void entry::setPrevious(entry *newPrevious) { previous = newPrevious; }
