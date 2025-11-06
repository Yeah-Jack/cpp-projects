#include "liege.h"

LiegeStandard::LiegeStandard(
    int zustand)
    : zustand_(zustand), belegt(false) {}

bool LiegeStandard::istBelegt() const { return belegt; }

bool LiegeStandard::buchen() {
  if (belegt) {
    return false;
  }
  belegt = true;
  return true;
}

bool LiegeStandard::stornieren() {
  if (!belegt) {
    return false;
  }
  belegt = false;
  return true;
}

int LiegeStandard::zustand() const { return zustand_; }

LiegePremium::LiegePremium(
    int zustand,
    int anzKissen)
    : LiegeStandard(zustand),
      anzKissen_(anzKissen) {}

int LiegePremium::anzahlKissen() const { return anzKissen_; }
