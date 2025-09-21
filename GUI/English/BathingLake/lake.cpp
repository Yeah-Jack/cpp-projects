#include "lake.h"

Lake::Lake() : nextPersonId(1), nextLoungerId(1) {}

Lake::~Lake() {
  for (auto p : people)
    delete p;
  for (auto l : lounger)
    delete l;
  for (auto b : bookings)
    delete b;
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

void Lake::addLounger(Lounger *l) {
  lounger.push_back(l);
  nextLoungerId++;
}

unsigned int Lake::getNextLoungerId() { return nextLoungerId; }

unsigned int Lake::getNextPersonId() { return nextPersonId; }

unsigned int Lake::getPeopleCount() { return people.size(); }

unsigned int Lake::getLoungerCount() { return lounger.size(); }

std::vector<Person *> Lake::getPeople() { return people; }

std::vector<Lounger *> Lake::getLoungers() { return lounger; }

std::vector<Booking *> Lake::getBookings() { return bookings; }

void Lake::addPerson(Person *p) {
  people.push_back(p);
  nextPersonId++;
}

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

void Lake::addBooking(Booking *b) { bookings.push_back(b); }
