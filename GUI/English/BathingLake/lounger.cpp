#include "lounger.h"

Lounger::Lounger() {}

unsigned int Lounger::getId() const { return id; }

short Lounger::getType() const { return type; }

short Lounger::getCondition() const { return condition; }

void Lounger::setType(const short newType) { type = newType; }

void Lounger::setCondition(const short newCondition) {
  condition = newCondition;
}

void Lounger::setId(const unsigned int newId) { id = newId; }

QString Lounger::getTypeName(short type) {
  switch (type) {
  case BeachLoungerTypeBeachLoungerSimple:
    return "Simple";
  case BeachLoungerTypeBeachLoungerLuxury:
    return "Luxury";
  case BeachLoungerTypeBeachLoungerWithUmbrella:
    return "With Umbrella";
  case BeachLoungerTypeBeachLoungerWithService:
    return "With Service";
  case BeachLoungerTypeBeachLoungerWithUmbrellaAndService:
    return "With Umbrella and Service";
  default:
    return "Unknown";
  }
}

QString Lounger::getConditionName(short condition) {
  switch (condition) {
  case conditionNew:
    return "New";
  case conditionAsGoodAsNew:
    return "As Good As New";
  case conditionUsed:
    return "Used";
  case conditionWorn:
    return "Worn";
  case conditionDefective:
    return "Defective";
  case conditionDiscarded:
    return "Discarded";
  default:
    return "Unknown";
  }
}
