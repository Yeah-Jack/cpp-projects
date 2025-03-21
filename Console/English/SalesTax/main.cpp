#include <iostream>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  const double sales = 95000;
  const double state_tax = 0.04;
  const double county_tax = 0.02;

  double after_state_tax = sales * state_tax;
  double after_county_tax = sales * county_tax;
  double total_tax = after_state_tax + after_county_tax;

  std::cout << "Sales: $" << sales << '\n'
            << "After State Tax: $" << after_state_tax << '\n'
            << "After County Tax: $" << after_county_tax << '\n'
            << "Total Tax: $" << total_tax << '\n';

  return 0;
}