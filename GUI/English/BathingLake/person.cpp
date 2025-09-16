#include "person.h"

Person::Person() {}

QString Person::getFirstName() {
  firstName = "Hans";
  return firstName;
}
QString Person::getLastName() {
  lastName = "Baumann";
  return lastName;
}
// QString Person::setFirstName(QString &first) { firstName = first; }
// QString Person::setLastName(QString &last) { lastName = last; }
