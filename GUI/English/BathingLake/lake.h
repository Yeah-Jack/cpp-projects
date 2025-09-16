#ifndef LAKE_H
#define LAKE_H

#include "lounger.h"
#include "person.h"
#include <vector>

class Lake {
public:
  Lake();
  double getCurrentWaterTemperature();
  unsigned short getCurrentWaterQuality();

private:
  std::vector<Person *> people;
  std::vector<Lounger *> lounger;
  double currentWaterTemperature;
  std::vector<double> waterTemperatureHistory;
  unsigned short currentWaterQuality;
};

#endif // LAKE_H
