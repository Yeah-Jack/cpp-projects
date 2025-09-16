#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person {
public:
  Person();
  QString getFirstName();
  QString getLastName();
  //  QString setFirstName(QString &first);
  //  QString setLastName(QString &last);

private:
  QString firstName;
  QString lastName;
};

#endif // PERSON_H
