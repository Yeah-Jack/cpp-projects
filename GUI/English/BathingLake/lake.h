#ifndef LAKE_H
#define LAKE_H

#include "lounger.h"
#include "person.h"
#include <random>
#include <vector>

class Lake {
public:
  Lake();
  double getCurrentWaterTemperature();
  unsigned short getCurrentWaterQuality();

private:
  std::vector<Person *> people;
  std::vector<Lounger *> lounger;
  std::vector<double> waterTemperatureHistory;
  double currentWaterTemperature;
  unsigned short currentWaterQuality;

  std::random_device rd;
  std::uniform_int_distribution<short> dist();
};

#endif // LAKE_H
