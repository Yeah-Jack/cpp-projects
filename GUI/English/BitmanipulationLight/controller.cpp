#include "controller.h"
#include <QDebug>

Controller::Controller() {}

void Controller::setBit(
    int bit) {
  lights = lights | (1 << bit);
  qDebug() << "Lights state after setting bit" << bit << ": "
           << QString::number(lights, 2).rightJustified(8, '0');
}

void Controller::deleteBit(
    int bit) {
  lights = lights & ~(1 << bit);
  qDebug() << "Lights state after deleting bit" << bit << ": "
           << QString::number(lights, 2).rightJustified(8, '0');
}

bool Controller::checkBit(
    int bit) {
  return false;
}