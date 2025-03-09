#include <iostream>
#include <random>
#include <windows.h>

void printStudentData(int students[5][3]);
double averageGrades(int students[5][3]);
int increaseAge(int (&students)[5][3], int &studentSelection, bool &success);
void filterGrades(int (&students)[5][3]);

int main() {
  SetConsoleOutputCP(CP_UTF8);

  std::random_device random;
  std::uniform_int_distribution<short> age(18, 29);
  std::uniform_int_distribution<short> grade(0, 100);

  // The first column stores student IDs, the second column stores their ages,
  // and the third stores their grades.
  int students[5][3];

  students[0][0] = 1;
  students[0][1] = age(random);
  students[0][2] = grade(random);

  students[1][0] = 2;
  students[1][1] = age(random);
  students[1][2] = grade(random);

  students[2][0] = 3;
  students[2][1] = age(random);
  students[2][2] = grade(random);

  students[3][0] = 4;
  students[3][1] = age(random);
  students[3][2] = grade(random);

  students[4][0] = 5;
  students[4][1] = age(random);
  students[4][2] = grade(random);

  printStudentData(students);

  double average = averageGrades(students);
  std::cout << "\nAverage grade: " << average << '\n';

  int studentSelection;
  bool success;

  std::cout << "Of which student do you want to increase the age? (1 - 5): ";
  std::cin >> studentSelection;

  success = (increaseAge(students, studentSelection, success) != 0);
  if (success && studentSelection >= 1 && studentSelection <= 5) {
    std::cout << "The age of student " << studentSelection
              << " has been increased to " << students[studentSelection - 1][1]
              << ".\n\n";
  } else {
    std::cout << "Invalid student selection.\n\n";
  }

  filterGrades(students);

  return 0;
}

void printStudentData(int students[5][3]) {
  std::cout << "Student ID\tAge\tGrade\n";
  for (int i = 0; i < 5; i++) {
    std::cout << students[i][0] << "\t\t" << students[i][1] << '\t'
              << students[i][2] << '\n';
  }
}

double averageGrades(int students[5][3]) {
  double average = 0.0;
  for (int i = 0; i < 5; i++) {
    average += students[i][2];
  }
  average /= 5;

  return average;
}

int increaseAge(int (&students)[5][3], int &studentSelection, bool &success) {
  if (studentSelection >= 1 && studentSelection <= 5) {
    students[studentSelection - 1][1]++;
    success = true;
  }

  return students[studentSelection - 1][1];
}

void filterGrades(int (&students)[5][3]) {
  int matchCount = 0;
  for (int i = 0; i < 5; i++) {
    if (students[i][2] >= 70) {
      matchCount++;
    }
  }

  if (matchCount != 0) {
    std::cout
        << "Students with grades better than 70:\nStudent ID\tAge\tGrade\n";
    for (int i = 0; i < 5; i++) {
      if (students[i][2] >= 70) {
        std::cout << students[i][0] << "\t\t" << students[i][1] << '\t'
                  << students[i][2] << '\n';
      }
    }
  } else {
    std::cout << "No students have a better or equal grade to 70.\n";
  }
}
