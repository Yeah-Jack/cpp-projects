#include "lake.h"

Lake::Lake() {}

double Lake::getWaterTemperature() {
  std::random_device rd;
  std::uniform_int_distribution<short> dist(-10, 30);

  waterTemperature = dist(rd);
  return waterTemperature;
}

unsigned short Lake::getWaterQuality() {
  std::random_device rd;
  std::uniform_int_distribution<short> dist(1, 5);

  waterQuality = dist(rd);
  return waterQuality;
}
