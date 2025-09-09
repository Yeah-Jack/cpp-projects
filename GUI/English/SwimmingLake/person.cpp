#include "person.h"

Person::Person() {}

Person::Person(const QString &first, const QString &last)
    : firstName(first), lastName(last) {}

QString Person::getFirstName() const { return firstName; }

QString Person::getLastName() const { return lastName; }

void Person::setFirstName(const QString &first) { firstName = first; }

void Person::setLastName(const QString &last) { lastName = last; }
