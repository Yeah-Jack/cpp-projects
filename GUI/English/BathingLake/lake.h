#ifndef LAKE_H
#define LAKE_H

#include "booking.h"
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
  std::vector<Booking *> getBookings();
  void addPerson(Person *p);
  void removePerson(int index);
  void addLounger(Lounger *l);
  void removeLounger(int index);
  void addBooking(Booking *b);
  unsigned int getNextLoungerId();
  unsigned int getNextPersonId();
  unsigned int getPeopleCount();
  unsigned int getLoungerCount();
  bool canRentLounger();

private:
  std::vector<Person *> people;
  std::vector<Lounger *> lounger;
  std::vector<Booking *> bookings;
  std::vector<double> waterTemperatureHistory;
  double waterTemperature;
  unsigned short waterQuality;

  std::random_device rd;
  std::uniform_int_distribution<short> dist;
};

#endif // LAKE_H
