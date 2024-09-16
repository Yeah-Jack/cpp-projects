#include <iostream>
using namespace std;

int main() {
  cout << "Test 1: " << (2 + 3 == 5 ? "Bestanden" : "Fehlgeschlagen") << endl;
  cout << "Test 2: " << (6 + 4 == 10 ? "Bestanden" : "Fehlgeschlagen") << endl;
  cout << "Test 3: " << (10 + 20 == 30 ? "Bestanden" : "Fehlgeschlagen")
       << endl;
  cout << "Test 4: " << (5 + 3 == 7 ? "Bestanden" : "Fehlgeschlagen") << endl;
  cout << "Test 5: " << (100 + 200 == 250 ? "Bestanden" : "Fehlgeschlagen")
       << endl;

  return 0;
}
