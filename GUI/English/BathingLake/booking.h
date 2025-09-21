#ifndef BOOKING_H
#define BOOKING_H

/**
 * @brief Represents a booking linking a person to a lounger by their IDs.
 */
class Booking {
public:
  /**
   * @brief Constructs a Booking with the given person and lounger IDs.
   * @param personId The ID of the person.
   * @param loungerId The ID of the lounger.
   */
  Booking(unsigned int personId, unsigned int loungerId);
  unsigned int getPersonId() const;
  unsigned int getLoungerId() const;

private:
  unsigned int personId;
  unsigned int loungerId;
};

#endif // BOOKING_H