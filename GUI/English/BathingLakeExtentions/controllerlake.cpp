#include "controllerlake.h"
#include "loungerluxury.h"
#include "qcontainerfwd.h"

ControllerLake::ControllerLake() : inventarNrGlobal(1) {}

void ControllerLake::createLoungerStandardType(unsigned short days) {
  LoungerStandardType *tempLounger =
      new LoungerStandardType(inventarNrGlobal++);
  tempLounger->setLeaseTime(days);
  loungers.push_back(tempLounger);
}

void ControllerLake::createLoungerLuxury(unsigned short hours, int pillows,
                                         QString coverColor,
                                         QString frameColor) {
  LoungerLuxury *tempLounger =
      new LoungerLuxury(inventarNrGlobal++, pillows, coverColor, frameColor);
  tempLounger->setLeaseTime(hours);
  loungers.push_back(tempLounger);
}

QStringList ControllerLake::getListLoungers() {
  QStringList retValue;
  QString itemString;

  for (LoungerStandardType *i : loungers) {
    itemString = i->serialize();
    retValue.append(itemString);
  }
  return retValue;
}
