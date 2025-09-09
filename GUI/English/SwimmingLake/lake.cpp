#include "lake.h"
#include <algorithm>

Lake::Lake() : currentWaterTemperature(20.0) {
  // Initialize with some sample loungers
  for (unsigned short i = 1; i <= 10; ++i) {
    lounger.push_back(new Lounger(i, 1)); // Type 1 loungers
  }
  waterTemperatureHistory.push_back(currentWaterTemperature);
  currentWaterQuality = {8, 7, 9}; // Sample quality values
}

Lake::~Lake() {
  for (auto p : people)
    delete p;
  for (auto l : lounger)
    delete l;
}

void Lake::addPerson(Person *person) { people.push_back(person); }

void Lake::removePerson(Person *person) {
  auto it = std::find(people.begin(), people.end(), person);
  if (it != people.end()) {
    people.erase(it);
    delete person;
  }
}

std::vector<Person *> Lake::getPeople() const { return people; }

Lounger *Lake::rentLounger() {
  for (auto l : lounger) {
    if (l->isAvailable()) {
      l->setCondition(l->getCondition() - 10); // Slight wear from use
      return l;
    }
  }
  return nullptr; // No available loungers
}

void Lake::returnLounger(Lounger *l) {
  // Lounger is returned, condition might improve slightly
  unsigned short cond = l->getCondition();
  if (cond < 100) {
    l->setCondition(cond + 5);
  }
}

double Lake::getCurrentWaterTemperature() const {
  return currentWaterTemperature;
}

void Lake::setCurrentWaterTemperature(double temp) {
  currentWaterTemperature = temp;
  waterTemperatureHistory.push_back(temp);
}

std::vector<double> Lake::getWaterTemperatureHistory() const {
  return waterTemperatureHistory;
}

std::vector<unsigned short> Lake::getCurrentWaterQuality() const {
  return currentWaterQuality;
}

void Lake::setCurrentWaterQuality(const std::vector<unsigned short> &quality) {
  currentWaterQuality = quality;
}

int Lake::getCurrentNumberOfVisitors() const { return people.size(); }
