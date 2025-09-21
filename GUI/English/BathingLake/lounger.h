#ifndef LOUNGER_H
#define LOUNGER_H

#include <QString>

enum LoungerType {
  typeSimple,
  typeLuxury,
  typeWithUmbrella,
  typeWithService,
  typeWithUmbrellaAndService,
  typeUnknown = -1
};

enum Condition {
  conditionNew,
  conditionAsGoodAsNew,
  conditionUsed,
  conditionWorn,
  conditionDefective,
  conditionDiscarded,
  conditionUnknown = -1
};

class Lounger {
public:
  Lounger();
  unsigned int getId() const;
  short getType() const;
  short getCondition() const;
  void setType(const short newType);
  void setCondition(const short newCondition);
  void setId(const unsigned int newId);
  static QString getTypeName(short type);
  static QString getConditionName(short condition);

private:
  unsigned int id;
  short type;
  short condition;
};

#endif // LOUNGER_H
