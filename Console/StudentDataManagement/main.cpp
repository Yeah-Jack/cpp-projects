#include <iostream>
#include <random>
#include <windows.h>

void PrintStudentData(int students[5][3]);
double AverageGrades(int students[5][3]);
int main() {
  SetConsoleOutputCP(CP_UTF8);

  std::random_device random;
  std::uniform_int_distribution<short> age(18, 29);
  std::uniform_int_distribution<short> grade(0, 100);

  // Declare a 2D array to store student data. The first column will store
  // student IDs, the second column will store their ages, and the third will
  // store their grades.
  int students[5][3];

  // Initialize the array with some sample data.
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

  PrintStudentData(students);

  double average = AverageGrades(students);
  std::cout << "Average grade: " << average << '\n';

  return 0;
}

void PrintStudentData(int students[5][3]) {
  std::cout << "Student ID\tAge\tGrade\n";
  for (int i = 0; i < 5; i++) {
    std::cout << students[i][0] << "\t\t" << students[i][1] << '\t'
              << students[i][2] << '\n';
  }
}

double AverageGrades(int students[5][3]) {
  double average = 0.0;
  for (int i = 0; i < 5; i++) {
    average += students[i][2];
  }
  average /= 5;

  return average;
}