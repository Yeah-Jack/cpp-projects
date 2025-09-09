#ifndef LOUNGER_H
#define LOUNGER_H

class Lounger {
public:
  Lounger();
  Lounger(unsigned short id, unsigned short type);

  unsigned short getId() const;
  unsigned short getType() const;
  unsigned short getCondition() const;
  void setCondition(unsigned short cond);
  bool isAvailable() const;

private:
  unsigned short id;
  unsigned short type;
  unsigned short condition;
};

#endif // LOUNGER_H
