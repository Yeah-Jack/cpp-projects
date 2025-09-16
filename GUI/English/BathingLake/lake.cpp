#include "lake.h"

Lake::Lake() {}

double Lake::getCurrentWaterTemperature() {
  currentWaterTemperature = 20;
  return currentWaterTemperature;
}

unsigned short Lake::getCurrentWaterQuality() {
  currentWaterQuality = 2;
  return currentWaterQuality;
}

