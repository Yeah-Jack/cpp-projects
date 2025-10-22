#include "loungerstandardtype.h"

LoungerStandardType::LoungerStandardType(unsigned long newInventoryNr)
    : inventoryNr(newInventoryNr) {}

QString LoungerStandardType::serialize() {
  QString retValue;
  retValue = "Liege Typ standard, Nr: " + QString::number(inventoryNr);
  retValue.append(" Zustand: neuwertig, gebucht: ") +
      QString::number(leaseTime);

  return retValue;
}

unsigned long LoungerStandardType::getInventoryNr() { return inventoryNr; }
