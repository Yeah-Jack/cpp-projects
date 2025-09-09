#ifndef LAKE_H
#define LAKE_H

#include "lounger.h"
#include "person.h"
#include <vector>

class Lake {
public:
  Lake();
  ~Lake();

  void addPerson(Person *person);
  void removePerson(Person *person);
  std::vector<Person *> getPeople() const;

  Lounger *rentLounger();
  void returnLounger(Lounger *l);

  double getCurrentWaterTemperature() const;
  void setCurrentWaterTemperature(double temp);
  std::vector<double> getWaterTemperatureHistory() const;

  std::vector<unsigned short> getCurrentWaterQuality() const;
  void setCurrentWaterQuality(const std::vector<unsigned short> &quality);

  int getCurrentNumberOfVisitors() const;

private:
  std::vector<Person *> people;
  std::vector<Lounger *> lounger;
  double currentWaterTemperature;
  std::vector<double> waterTemperatureHistory;
  std::vector<unsigned short> currentWaterQuality;
};

#endif // LAKE_H
