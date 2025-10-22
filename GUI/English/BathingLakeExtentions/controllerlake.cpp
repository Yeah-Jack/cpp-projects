#include "controllerlake.h"
#include "qcontainerfwd.h"

ControllerLake::ControllerLake() : inventarNrGlobal(1) {}

void ControllerLake::createLoungerStandardType() {
  LoungerStandardType *tempLounger = nullptr;

  tempLounger = new LoungerStandardType(inventarNrGlobal++);
  loungerStandardType.push_back(tempLounger);
}

QStringList ControllerLake::getListLoungers() {
  QStringList retValue;
  QString itemString;

  for (LoungerStandardType *i : loungerStandardType) {
    itemString = i->serialize();
    retValue.append(itemString);
  }
  return retValue;
}
