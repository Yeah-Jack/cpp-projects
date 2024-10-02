#include <Windows.h>
#include <iostream>

struct Person {
  std::string name;
  int age;
  double height;
  double weight;
};

void printPerson(const Person &person);
void updatePerson(Person &person, int newAge, double newHeight,
                  double newWeight);

int main() {
  SetConsoleOutputCP(CP_UTF8);

  Person person1 = {"Spongebob Squarepants", 11, 1.22, 65.25};
  Person person2 = {"Patrick Star", 12, 1.33, 75.25};

  std::cout << "Initial information:" << std::endl;
  printPerson(person1);
  printPerson(person2);

  updatePerson(person1, 12, 1.25, 67.5);
  updatePerson(person2, 13, 1.35, 77.0);

  std::cout << "\nUpdated information:" << std::endl;
  printPerson(person1);
  printPerson(person2);

  return 0;
}

void printPerson(const Person &person) {
  std::cout << "Name: " << person.name << std::endl;
  std::cout << "Age: " << person.age << " years" << std::endl;
  std::cout << "Height: " << person.height << " m" << std::endl;
  std::cout << "Weight: " << person.weight << " kg" << std::endl;
  std::cout << std::endl;
}

void updatePerson(Person &person, int newAge, double newHeight,
                  double newWeight) {
  person.age = newAge;
  person.height = newHeight;
  person.weight = newWeight;
}