#ifndef LAKE_H
#define LAKE_H

#include "lounger.h"
#include "person.h"
#include <random>
#include <vector>

class Lake {
public:
  Lake();
  ~Lake();
  double getWaterTemperature();
  unsigned short getWaterQuality();
  Person *getPerson(int index);
  std::vector<Person *> getPeople();
  std::vector<Lounger *> getLoungers();
  void addPerson(Person *p);
  void removePerson(int index);
  void addLounger(Lounger *l);
  void removeLounger(int index);
  unsigned int getNextLoungerId();
  unsigned int getPeopleCount();
  unsigned int getLoungerCount();
  bool canRentLounger();

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
