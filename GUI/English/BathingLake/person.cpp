#include "person.h"

unsigned int Person::nextnr = 1;

Person::Person() {}

QString Person::getFirstName() const { return firstName; }
QString Person::getLastName() const { return lastName; }
unsigned int Person::getId() const { return id; }
void Person::setFirstName(const QString first) { firstName = first; }
void Person::setLastName(const QString last) { lastName = last; }
void Person::setId(unsigned int newId) { id = newId; }
