#ifndef PERSON_H
#define PERSON_H

#include <QString>

/**
 * @brief Represents a person with a first name, last name, and unique ID.
 */
class Person {
public:
  Person();
  QString getFirstName() const;
  QString getLastName() const;
  unsigned int getId() const;
  void setFirstName(const QString first);
  void setLastName(const QString last);
  void setId(unsigned int newId);

private:
  QString firstName;
  QString lastName;
  unsigned int id;
};

#endif // PERSON_H
