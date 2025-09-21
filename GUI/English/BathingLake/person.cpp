#include "person.h"

Person::Person() {}

QString Person::getFirstName() { return firstName; }
QString Person::getLastName() { return lastName; }
void Person::setFirstName(const QString &first) { firstName = first; }
void Person::setLastName(const QString &last) { lastName = last; }
