#include "controller.h"

Controller::Controller() {}

void Controller::setBit(
    int bit) {
  lights = lights | (1 << bit);
  qDebug() << "Lights state after setting bit" << bit
           << QString::number(lights, 2).rightJustified(8, '0');
}

void Controller::clearBit(int bit) {
  lights = lights & ~(1 << bit);
  qDebug() << "Lights state after clearing bit" << bit
           << QString::number(lights, 2).rightJustified(8, '0');
}

bool Controller::checkBit(int bit) const {
  bool result = (lights & (1 << bit)) != 0;

  return result;
}

bool Controller::isLightOn(int room) const {
  bool roomOn = checkBit(room);
  bool central = checkBit(centralBit);
  bool result = roomOn && central;

  qDebug() << "Room" << room << "| Room Bit:" << roomOn
           << "| Central:" << central << "| Light on:" << result;

  return result;
}
