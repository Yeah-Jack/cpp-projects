#include <iostream>
#include <windows.h>

class Person {
public:
  void print_info() {
    std::cout << "Name: " << name << "\nAge: " << age << '\n';
  }
  void setName(std::string newName) { name = newName; }
  void setAge(int newAge) { age = newAge; }

protected:
  std::string name = "";
  int age = 0;
};

class Student : public Person {
public:
  void print_info() {
    std::cout << "Name: " << name << "\nAge: " << age
              << "\nUniversity: " << university << '\n';
  }
  void setUniversity(std::string newUniversity) { university = newUniversity; }

protected:
  std::string university = "";
};

int main() {
  SetConsoleOutputCP(CP_UTF8);

  Person person1;
  Student student1;

  person1.setName("Tom");
  person1.setAge(20);
  person1.print_info();

  student1.setName("Jerry");
  student1.setAge(18);
  student1.setUniversity("Harvard");
  student1.print_info();

  return 0;
}