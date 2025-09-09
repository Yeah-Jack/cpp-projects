#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person {
public:
  Person();
  Person(const QString &first, const QString &last);

  QString getFirstName() const;
  QString getLastName() const;
  void setFirstName(const QString &first);
  void setLastName(const QString &last);

private:
  QString firstName;
  QString lastName;
};

#endif // PERSON_H
