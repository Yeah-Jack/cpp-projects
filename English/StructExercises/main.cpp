#include <array>
#include <iostream>
#include <string>

const int MAX_FAMILY_MEMBERS = 5;

struct Person {
  std::string name;
  int age;
  double height;
  double weight;
};

struct Family {
  std::array<Person, MAX_FAMILY_MEMBERS> members;
  int familySize;
};

void printPerson(const Person &person);
void addFamilyMember(Family &family, const Person &newMember);
void printFamily(const Family &family);
void updateFamilyMember(Family &family, int index, int newAge, double newHeight,
                        double newWeight);

int main() {
  Family myFamily = {std::array<Person, MAX_FAMILY_MEMBERS>{}, 0};

  Person person1 = {"John Doe", 40, 1.80, 80.0};
  Person person2 = {"Jane Doe", 38, 1.65, 60.0};
  Person person3 = {"Jimmy Doe", 10, 1.40, 35.0};

  addFamilyMember(myFamily, person1);
  addFamilyMember(myFamily, person2);
  addFamilyMember(myFamily, person3);

  std::cout << std::endl << "Initial family information:" << std::endl;
  printFamily(myFamily);

  updateFamilyMember(myFamily, 2, 11, 1.45, 38.0);

  std::cout << std::endl << "Updated family information:" << std::endl;
  printFamily(myFamily);

  Person person4 = {"Jenny Doe", 8, 1.30, 30.0};
  Person person5 = {"Jack Doe", 5, 1.10, 20.0};
  Person person6 = {"Jill Doe", 3, 0.90, 15.0};

  addFamilyMember(myFamily, person4);
  addFamilyMember(myFamily, person5);
  addFamilyMember(myFamily, person6);

  std::cout << std::endl << "Final family information:" << std::endl;
  printFamily(myFamily);

  return 0;
}

void printPerson(const Person &person) {
  std::cout << "Name: " << person.name << std::endl;
  std::cout << "Age: " << person.age << " years" << std::endl;
  std::cout << "Height: " << person.height << " m" << std::endl;
  std::cout << "Weight: " << person.weight << " kg" << std::endl;
  std::cout << std::endl;
}

void addFamilyMember(Family &family, const Person &newMember) {
  if (family.familySize < MAX_FAMILY_MEMBERS) {
    family.members[family.familySize] = newMember;
    family.familySize++;
    std::cout << "Added " << newMember.name << " to the family." << std::endl;
  } else {
    std::cout << "Family is full. Cannot add more members." << std::endl;
  }
}

void printFamily(const Family &family) {
  std::cout << "Family Members:" << std::endl;
  for (int i = 0; i < family.familySize; i++) {
    std::cout << "Member " << i + 1 << ":" << std::endl;
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
              << std::endl;
  } else {
    std::cout << "Invalid family member index." << std::endl;
  }
}
