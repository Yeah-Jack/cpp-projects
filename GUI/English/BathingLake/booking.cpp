#include "booking.h"

Booking::Booking(unsigned int pId, unsigned int lId)
    : personId(pId), loungerId(lId) {}

unsigned int Booking::getPersonId() const { return personId; }
unsigned int Booking::getLoungerId() const { return loungerId; }