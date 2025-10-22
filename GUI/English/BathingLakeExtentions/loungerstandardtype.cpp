#include "loungerstandardtype.h"

LoungerStandardType::LoungerStandardType(unsigned long newInventoryNr)
    : inventoryNr(newInventoryNr), leaseTime(0) {}

QString LoungerStandardType::serialize() {
  QString retValue;
  retValue = "Liege, Typ Standard, Nr " + QString::number(inventoryNr) +
             ", Zustand neuwertig, gebucht für " + QString::number(leaseTime) +
             " Tage.";
  return retValue;
}

unsigned long LoungerStandardType::getInventoryNr() { return inventoryNr; }

unsigned short LoungerStandardType::getLeaseTime() { return leaseTime; }

void LoungerStandardType::setLeaseTime(unsigned short time) {
  leaseTime = time;
}
