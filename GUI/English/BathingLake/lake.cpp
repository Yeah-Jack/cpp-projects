#include "lake.h"

Lake::Lake() {}

double Lake::getCurrentWaterTemperature() {
  std::random_device rd;
  std::uniform_int_distribution<short> dist(-10, 30);

  currentWaterTemperature = dist(rd);
  return currentWaterTemperature;
}

unsigned short Lake::getCurrentWaterQuality() {
  std::random_device rd;
  std::uniform_int_distribution<short> dist(1, 5);

  currentWaterQuality = dist(rd);
  return currentWaterQuality;
}
