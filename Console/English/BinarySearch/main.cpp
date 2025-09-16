#include <iostream>
#include <windows.h>

/**
 * @brief Performs a binary search on a sorted array to find the index of a
 * target value.
 * @param myArray The sorted array to search
 * in.
 * @param size The number of elements in the array.
 * @param target The value to search for.
 * @return The index of the target value if found, otherwise -1.
 */
int binarySearch(const int myArray[], int size, int target) {
  int left = 0;
  int right = size - 1;
  int mid = 0;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (myArray[mid] == target) {
      return mid;
    } else if (myArray[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int main() {
  SetConsoleOutputCP(CP_UTF8);

  const int myArray[9] = {1, 3, 5, 7, 8, 9, 11, 13, 15};
  int size = sizeof(myArray) / sizeof(myArray[0]);
  int target = 0;
  int result = 0;

  std::cout << "Enter a number to search for: ";
  std::cin >> target;

  result = binarySearch(myArray, size, target);

  if (result != -1) {
    std::cout << "Element found at index: " << result << '\n';
  } else {
    std::cout << "Element not found" << '\n';
  }

  return 0;
}