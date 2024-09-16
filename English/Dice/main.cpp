#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  const short minValue = 1;
  const short maxValue = 6;

  srand(time(0));
  short first = (rand() % (maxValue - minValue + 1)) + minValue;
  short second = (rand() % (maxValue - minValue + 1)) + minValue;

  std::cout << "First dice: " << first << std::endl
            << "Second dice: " << second << std::endl;

  return 0;
}
