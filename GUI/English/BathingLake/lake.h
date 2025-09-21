#ifndef LAKE_H
#define LAKE_H

#include "booking.h"
#include "lounger.h"
#include "person.h"
#include <random>
#include <vector>

/**
 * @brief Manages the lake's visitors (people), loungers, bookings, and
 * data like water temperature and quality.
 */
class Lake {
public:
  Lake();
  ~Lake();
  /**
   * @brief Retrieves the current water temperature, generated randomly.
   * @return The water temperature in degrees Celsius.
   */
  double getWaterTemperature();

  /**
   * @brief Retrieves the current water quality rating, generated randomly.
   * @return The water quality on a scale of 1 to 5.
   */
  unsigned short getWaterQuality();

  /**
   * @brief Retrieves a person by their index in the people list.
   * @param index The index of the person.
   * @return Pointer to the Person object.
   */
  Person *getPerson(int index);

  /**
   * @brief Retrieves the list of all people at the lake.
   * @return Vector of pointers to Person objects.
   */
  std::vector<Person *> getPeople();

  /**
   * @brief Retrieves the list of all loungers at the lake.
   * @return Vector of pointers to Lounger objects.
   */
  std::vector<Lounger *> getLoungers();

  /**
   * @brief Retrieves the list of all bookings at the lake.
   * @return Vector of pointers to Booking objects.
   */
  std::vector<Booking *> getBookings();

  /**
   * @brief Adds a new person to the lake's people list.
   * @param p Pointer to the Person to add.
   */
  void addPerson(Person *p);

  /**
   * @brief Removes a person from the lake's people list by index.
   * @param index The index of the person to remove.
   */
  void removePerson(int index);

  /**
   * @brief Adds a new lounger to the lake's loungers list.
   * @param l Pointer to the Lounger to add.
   */
  void addLounger(Lounger *l);

  /**
   * @brief Removes a lounger from the lake's loungers list by index.
   * @param index The index of the lounger to remove.
   */
  void removeLounger(int index);

  /**
   * @brief Adds a new booking to the lake's bookings list.
   * @param b Pointer to the Booking to add.
   */
  void addBooking(Booking *b);

  /**
   * @brief Gets the next available lounger ID.
   * @return The next lounger ID.
   */
  unsigned int getNextLoungerId();

  /**
   * @brief Gets the next available person ID.
   * @return The next person ID.
   */
  unsigned int getNextPersonId();

  /**
   * @brief Gets the current number of people at the lake.
   * @return The number of people.
   */
  unsigned int getPeopleCount();

  /**
   * @brief Gets the current number of loungers at the lake.
   * @return The number of loungers.
   */
  unsigned int getLoungerCount();

  /**
   * @brief Checks if a new lounger can be rented (limit of 200).
   * @return True if renting is possible, false otherwise.
   */
  bool canRentLounger();

private:
  std::vector<Person *> people;
  std::vector<Lounger *> lounger;
  std::vector<Booking *> bookings;
  std::vector<double> waterTemperatureHistory;
  double waterTemperature;
  unsigned short waterQuality;
  unsigned int nextPersonId;
  unsigned int nextLoungerId;

  std::random_device rd;
};

#endif // LAKE_H
