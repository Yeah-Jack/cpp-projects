#include "lounger.h"

Lounger::Lounger() : id(0), type(0), condition(100) {}

Lounger::Lounger(unsigned short id, unsigned short type)
    : id(id), type(type), condition(100) {}

unsigned short Lounger::getId() const { return id; }

unsigned short Lounger::getType() const { return type; }

unsigned short Lounger::getCondition() const { return condition; }

void Lounger::setCondition(unsigned short cond) { condition = cond; }

bool Lounger::isAvailable() const {
  return condition > 50; // Available if condition is good
}
