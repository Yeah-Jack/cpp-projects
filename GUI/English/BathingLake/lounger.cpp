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

/**
 * @brief Lounger::getTypeName
 * @param type
 * @return
 */
QString Lounger::getTypeName(short type) {
  switch (type) {
  case typeSimple:
    return "Simple";
  case typeLuxury:
    return "Luxury";
  case typeWithUmbrella:
    return "With Umbrella";
  case typeWithService:
    return "With Service";
  case typeWithUmbrellaAndService:
    return "With Umbrella and Service";
  default:
    return "Unknown";
  }
}

/**
 * @brief Lounger::getConditionName
 * @param condition
 * @return
 */
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
