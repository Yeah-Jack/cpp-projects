#include "loungerluxury.h"

LoungerLuxury::LoungerLuxury(unsigned long newInventoryNr, int pillows,
                             QString coverColor, QString frameColor)
    : LoungerStandardType(newInventoryNr), numPillows(pillows),
      coverColor(coverColor), frameColor(frameColor) {}

int LoungerLuxury::getNumPillows() const { return numPillows; }

QString LoungerLuxury::getCoverColor() const { return coverColor; }

QString LoungerLuxury::getFrameColor() const { return frameColor; }

void LoungerLuxury::setNumPillows(int pillows) { numPillows = pillows; }

void LoungerLuxury::setCoverColor(const QString &color) { coverColor = color; }

void LoungerLuxury::setFrameColor(const QString &color) { frameColor = color; }

QString LoungerLuxury::serialize() {
  QString retValue;
  retValue = "Liege, Typ Luxuriös, Nr " + QString::number(getInventoryNr()) +
             ", Zustand neuwertig, Farbe " + frameColor + ", Polster " +
             coverColor + ", " + QString::number(numPillows) +
             " Kissen, gebucht für " + QString::number(getLeaseTime()) +
             " Stunden.";
  return retValue;
}
