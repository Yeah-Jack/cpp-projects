#ifndef LOUNGER_H
#define LOUNGER_H

class Lounger {
public:
  Lounger();
  unsigned short getId() const;
  unsigned short getType() const;
  unsigned short getCondition() const;
  void setType(const unsigned short newType);
  void setCondition(const unsigned short newCondition);
  void setId(const unsigned short newId);

private:
  unsigned short id;
  unsigned short type;
  unsigned short condition;
};

#endif // LOUNGER_H
