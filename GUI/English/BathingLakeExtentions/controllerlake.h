#ifndef CONTROLLERLAKE_H
#define CONTROLLERLAKE_H

#include "loungerstandardtype.h"
#include <QStringList>
#include <vector>

using namespace std;

class ControllerLake {
public:
  ControllerLake();
  void createLoungerStandardType();
  QStringList getListLoungers();

private:
  vector<LoungerStandardType *> loungerStandardType;
  unsigned long inventarNrGlobal;
};

#endif // CONTROLLERLAKE_H
