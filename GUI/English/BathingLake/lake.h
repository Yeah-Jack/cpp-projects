#ifndef LAKE_H
#define LAKE_H

#include "lounger.h"
#include "person.h"
#include <random>
#include <vector>

class Lake {
public:
  Lake();
  double getWaterTemperature();
  unsigned short getWaterQuality();

private:
  std::vector<Person *> people;
  std::vector<Lounger *> lounger;
  std::vector<double> waterTemperatureHistory;
  double waterTemperature;
  unsigned short waterQuality;

  std::random_device rd;
  std::uniform_int_distribution<short> dist();
};

#endif // LAKE_H
