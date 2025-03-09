#include <iostream>
#include <random>
#include <windows.h>

void addRandomProductVariables(int (&products)[5][4]);
void addCustomProductVariables(int (&products)[5][4]);
void printProducts(int (&products)[5][4]);
double calculateSalesAverage(int products[5][4]);
void updateInventory(int (&products)[5][4]);

int main() {
  SetConsoleOutputCP(CP_UTF8);

  // The first column stores product IDs, the second column stores their prices,
  // the third stores their inventory, and the fourth stores their sales.
  int products[5][4];

  short choice;
  std::cout << "What do you want to do?\n1) Generate random data\n2) Input "
               "custom data\n";
  std::cin >> choice;
  switch (choice) {
  case 1:
    addRandomProductVariables(products);
    break;
  case 2:
    addCustomProductVariables(products);
    break;
  }

  printProducts(products);

  double average = calculateSalesAverage(products);
  std::cout << "\nAverage Sales: " << average << '\n';

  updateInventory(products);

  return 0;
}

void addRandomProductVariables(int (&products)[5][4]) {
  std::random_device random;
  std::uniform_int_distribution<short> generator(1, 100);

  for (int i = 0; i < 5; i++) {
    products[i][0] = i + 1;
    products[i][1] = generator(random);
    products[i][2] = generator(random);
    products[i][3] = generator(random);
  }
}

void addCustomProductVariables(int (&products)[5][4]) {
  for (int i = 0; i < 5; i++) {
    products[i][0] = i + 1;
    std::cout << "Enter the price of product " << i + 1 << ": ";
    std::cin >> products[i][1];
    std::cout << "Enter the inventory of product " << i + 1 << ": ";
    std::cin >> products[i][2];
    std::cout << "Enter the sales of product " << i + 1 << ": ";
    std::cin >> products[i][3];
    std::cout << '\n';
  }
}

void printProducts(int (&products)[5][4]) {
  std::cout << "Product ID\tPrice\tInventory\tSales\n";
  for (int i = 0; i < 5; i++) {
    std::cout << products[i][0] << "\t\t$" << products[i][1] << '\t'
              << products[i][2] << "\t\t" << products[i][3] << '\n';
  }
}

double calculateSalesAverage(int products[5][4]) {
  double average = 0.0;
  for (int i = 0; i < 5; i++) {
    average += products[i][3];
  }

  return average / 2;
}

void updateInventory(int (&products)[5][4]) {
  std::cout << "Enter the product to update inventory: ";
  int productID;
  std::cin >> productID;

  std::cout << "Enter the new inventory for product " << productID << ": ";
  int newInventory;
  std::cin >> newInventory;
  products[productID - 1][2] = newInventory;

  printProducts(products);
}