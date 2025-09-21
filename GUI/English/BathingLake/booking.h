#ifndef BOOKING_H
#define BOOKING_H

class Booking {
public:
  Booking(unsigned int personId, unsigned int loungerId);
  unsigned int getPersonId() const;
  unsigned int getLoungerId() const;

private:
  unsigned int personId;
  unsigned int loungerId;
};

#endif // BOOKING_H