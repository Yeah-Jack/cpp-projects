#include "lake.h"

Lake::Lake() {}

Lake::~Lake() {
  for (auto p : people)
    delete p;
  for (auto l : lounger)
    delete l;
}

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

Person *Lake::getPerson(int index) { return people[index]; }

void Lake::addLounger(Lounger *l) { lounger.push_back(l); }

unsigned int Lake::getNextLoungerId() { return lounger.size() + 1; }

unsigned int Lake::getNextPersonId() { return people.size() + 1; }

unsigned int Lake::getPeopleCount() { return people.size(); }

unsigned int Lake::getLoungerCount() { return lounger.size(); }

std::vector<Person *> Lake::getPeople() { return people; }

std::vector<Lounger *> Lake::getLoungers() { return lounger; }

void Lake::addPerson(Person *p) { people.push_back(p); }

bool Lake::canRentLounger() { return lounger.size() < 200; }

void Lake::removePerson(int index) {
  if (index >= 0 && static_cast<size_t>(index) < people.size()) {
    delete people[index];
    people.erase(people.begin() + index);
  }
}

void Lake::removeLounger(int index) {
  if (index >= 0 && static_cast<size_t>(index) < lounger.size()) {
    delete lounger[index];
    lounger.erase(lounger.begin() + index);
  }
}
