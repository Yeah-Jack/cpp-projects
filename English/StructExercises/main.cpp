#include <Windows.h>
#include <iostream>

struct Person {
  std::string name;
  int age;
  double height;
};

void printPerson(Person &person);

int main() {
  SetConsoleOutputCP(CP_UTF8);

  Person person1;
  person1.name = "Spongebob Squarepants";
  person1.age = 11;
  person1.height = 1.22;

  printPerson(person1);

  return 0;
}

void printPerson(Person &person) {
  std::cout << "Name: " << person.name << std::endl;
  std::cout << "Age: " << person.age << " years" << std::endl;
  std::cout << "Height: " << person.height << " meters" << std::endl;
}