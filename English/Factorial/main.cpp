#include <Windows.h>
#include <iostream>

long factorialIterative(long num);
//long factorialRecursive(long num);

int main() {
  SetConsoleOutputCP(CP_UTF8);

  long num;

  std::cout << "Enter a number: ";
  std::cin >> num;

   std::cout << "Factorial of your number is: " << factorialIterative(num) << 
   '\n';
  //std::cout << "Factorial of your number is: " << factorialRecursive(num) 
  //          << '\n';;

  return 0;
}

long factorialIterative(long num) {
  long result = 1;

  for (int i = 1; i <= num; i++) {
    result *= i;
  }

  return result;
}

/* long factorialRecursive(long num) {
  if (num > 1) {
    return num * factorialRecursive(num - 1);
  } else {
    return 1;
  }
} */