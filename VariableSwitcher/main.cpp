#include <iostream>

using namespace std;

int main()
{
    int zahl1, zahl2, temp;

    std::cout << "Gebe Zahl 1 ein: " << endl;
    std::cin >> zahl1;
    std::cout << "Gebe Zahl 2 ein: " << endl;
    std::cin >> zahl2;

    temp = zahl1;
    zahl1 = zahl2;
    zahl2 = temp;

    cout << "Neue Zahl 1: " << zahl1 << endl;
    cout << "Neue Zahl 2: " << zahl2 << endl;

    return 0;
}
