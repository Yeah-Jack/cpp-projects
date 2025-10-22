#ifndef CONTROLLERLAKE_H
#define CONTROLLERLAKE_H

#include "loungerluxury.h"
#include "loungerstandardtype.h"
#include <QStringList>
#include <vector>

using namespace std;

class ControllerLake {
public:
  ControllerLake();
  void createLoungerStandardType(unsigned short days);
  void createLoungerLuxury(unsigned short hours, int pillows,
                           QString coverColor, QString frameColor);
  QStringList getListLoungers();

private:
  vector<LoungerStandardType *> loungers;
  unsigned long inventarNrGlobal;
};

#endif // CONTROLLERLAKE_H
