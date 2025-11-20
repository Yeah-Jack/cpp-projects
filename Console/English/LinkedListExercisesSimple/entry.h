#ifndef ENTRY_H
#define ENTRY_H

class entry {
public:
  entry();

  int getAge() const;
  void setAge(int newAge);

  entry *getNext() const;
  void setNext(entry *newNext);

  entry *getPrevious() const;
  void setPrevious(entry *newPrevious);

private:
  int age;
  entry *next;
  entry *previous;
};

#endif // ENTRY_H
