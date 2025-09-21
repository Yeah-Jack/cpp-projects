#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person {
public:
  Person();
  QString getFirstName();
  QString getLastName();
  void setFirstName(const QString &first);
  void setLastName(const QString &last);

private:
  QString firstName;
  QString lastName;
};

#endif // PERSON_H
