#include "messwertmodel.h"

MesswertModel::MesswertModel() {}

const std::vector<int> &MesswertModel::getMesswerte() const {
  return messwerte;
}

void MesswertModel::addMesswerte() {
  messwerte = {18, 19, 21, 21, 21, 22, 22, 26, 23, 27, 27, 24, 25, 25, 27,
               27, 30, 31, 27, 31, 29, 32, 31, 29, 31, 32, 30, 28, 29, 31,
               30, 29, 28, 28, 28, 26, 26, 28, 25, 26, 26, 27, 25, 22, 25,
               25, 20, 23, 19, 23, 20, 21, 19, 20, 17, 15, 14, 15, 15, 13,
               13, 12, 14, 13, 13, 12, 11, 11, 11, 10, 10, 8,  12, 9,  12,
               9,  9,  11, 11, 10, 12, 10, 11, 9,  11, 10, 12, 14, 13, 12,
               13, 17, 15, 15, 17, 18, 19, 17, 19, 18};
}
