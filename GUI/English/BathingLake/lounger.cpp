#include "lounger.h"

Lounger::Lounger() {}

unsigned short Lounger::getId() const { return id; }

unsigned short Lounger::getType() const { return type; }

unsigned short Lounger::getCondition() const { return condition; }

void Lounger::setType(const unsigned short newType) { type = newType; }

void Lounger::setCondition(const unsigned short newCondition) {
  condition = newCondition;
}

void Lounger::setId(const unsigned short newId) { id = newId; }
