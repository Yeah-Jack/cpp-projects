#ifndef LOUNGER_H
#define LOUNGER_H

#include <QString>

/**
 * @brief Enumeration for different types of loungers available at the lake.
 */
enum LoungerType {
  typeSimple,
  typeLuxury,
  typeWithUmbrella,
  typeWithService,
  typeWithUmbrellaAndService,
  typeUnknown = -1
};

/**
 * @brief Enumeration for the condition states of loungers.
 */
enum Condition {
  conditionNew,
  conditionAsGoodAsNew,
  conditionUsed,
  conditionWorn,
  conditionDefective,
  conditionDiscarded,
  conditionUnknown = -1
};

/**
 * @brief Represents a lounger with an ID, type, and condition.
 */
class Lounger {
public:
  Lounger();
  unsigned int getId() const;
  short getType() const;
  short getCondition() const;
  void setType(const short newType);
  void setCondition(const short newCondition);
  void setId(const unsigned int newId);
  /**
   * @brief Returns the string name corresponding to the given lounger type.
   * @param type The lounger type value.
   * @return The name as a QString.
   */
  static QString getTypeName(short type);

  /**
   * @brief Returns the string name corresponding to the given condition.
   * @param condition The condition value.
   * @return The name as a QString.
   */
  static QString getConditionName(short condition);

private:
  unsigned int id;
  short type;
  short condition;
};

#endif // LOUNGER_H
