#include "gui.h"
#include "lake.h"

GUI::GUI() : lake(new Lake()) {}

GUI::~GUI() { delete lake; }

bool GUI::rentLounger() {
  Lounger *l = lake->rentLounger();
  if (l) {
    // Successfully rented
    return true;
  }
  return false;
}

void GUI::parkBike() {
  // For now, just acknowledge
  // Could add bike parking logic later
}

double GUI::viewCurrentWaterTemperature() {
  return lake->getCurrentWaterTemperature();
}

unsigned short GUI::viewCurrentWaterQuality() {
  auto quality = lake->getCurrentWaterQuality();
  if (!quality.empty()) {
    // Return average quality
    unsigned short sum = 0;
    for (auto q : quality)
      sum += q;
    return sum / quality.size();
  }
  return 0;
}

int GUI::viewCurrentNumberOfVisitors() {
  return lake->getCurrentNumberOfVisitors();
}

Lake *GUI::getLake() const { return lake; }
