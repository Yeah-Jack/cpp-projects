#include <array>
#include <iostream>
#include <string>
#include <windows.h>

const int maxFamilyMembers = 5;

struct Person {
  std::string name;
  int age;
  double height;
  double weight;
};

struct Family {
  std::array<Person, maxFamilyMembers> members;
  int familySize;
};

void printPerson(const Person &person);
void addFamilyMember(Family &family, const Person &newMember);
void printFamily(const Family &family);
void updateFamilyMember(Family &family, int index, int newAge, double newHeight,
                        double newWeight);

int main() {
  SetConsoleOutputCP(CP_UTF8);

  Family myFamily = {std::array<Person, maxFamilyMembers>{}, 0};

  Person person1 = {"John Doe", 40, 1.80, 80.0};
  Person person2 = {"Jane Doe", 38, 1.65, 60.0};
  Person person3 = {"Jimmy Doe", 10, 1.40, 35.0};

  addFamilyMember(myFamily, person1);
  addFamilyMember(myFamily, person2);
  addFamilyMember(myFamily, person3);

  std::cout << "\nInitial family information:\n";
  printFamily(myFamily);

  updateFamilyMember(myFamily, 2, 11, 1.45, 38.0);

  std::cout << "\nUpdated family information:\n";
  printFamily(myFamily);

  Person person4 = {"Jenny Doe", 8, 1.30, 30.0};
  Person person5 = {"Jack Doe", 5, 1.10, 20.0};
  Person person6 = {"Jill Doe", 3, 0.90, 15.0};

  addFamilyMember(myFamily, person4);
  addFamilyMember(myFamily, person5);
  addFamilyMember(myFamily, person6);

  std::cout << "\nFinal family information:\n";
  printFamily(myFamily);

  return 0;
}

void printPerson(const Person &person) {
  std::cout << "Name: " << person.name << "\nAge: " << person.age << " years\n"
            << "Height: " << person.height << " m\n"
            << "Weight: " << person.weight << " kg\n\n";
}

void addFamilyMember(Family &family, const Person &newMember) {
  if (family.familySize < maxFamilyMembers) {
    family.members[family.familySize] = newMember;
    family.familySize++;
    std::cout << "Added " << newMember.name << " to the family.\n";
  } else {
    std::cout << "Family is full. Cannot add more members.\n";
  }
}

void printFamily(const Family &family) {
  std::cout << "Family Members:\n";
  for (int i = 0; i < family.familySize; i++) {
    std::cout << "Member " << i + 1 << ":\n";
    printPerson(family.members[i]);
  }
}

void updateFamilyMember(Family &family, int index, int newAge, double newHeight,
                        double newWeight) {
  if (index >= 0 && index < family.familySize) {
    family.members[index].age = newAge;
    family.members[index].height = newHeight;
    family.members[index].weight = newWeight;
    std::cout << "Updated information for " << family.members[index].name
              << '\n';
  } else {
    std::cout << "Invalid family member index.\n";
  }
}
