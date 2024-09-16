#include <iostream>

using namespace std;

int main() {
  const double sales = 95000;
  const double state_tax = 0.04;
  const double county_tax = 0.02;

  double after_state_tax = sales * state_tax;
  double after_county_tax = sales * county_tax;
  double total_tax = after_state_tax + after_county_tax;

  cout << "Sales: $" << sales << endl
       << "After State Tax: $" << after_state_tax << endl
       << "After County Tax: $" << after_county_tax << endl
       << "Total Tax: $" << total_tax << endl;

  return 0;
}