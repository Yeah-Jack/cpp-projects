#include <iostream>
#include <windows.h>

class BankAccount {
public:
  std::string bankName;

  void Deposit(double amount) { balance += amount; }

  void Withdraw(double amount) {
    if (amount <= balance) {
      balance -= amount;
    } else {
      std::cout << "Insufficient funds.\n";
    }
  }

  double GetBalance() { return balance; }

private:
  double balance = 1000.0;
};

int main() {
  SetConsoleOutputCP(CP_UTF8);

  BankAccount main;
  main.bankName = "Chase";

  std::cout << "Your main bank's name is " << main.bankName << " with $"
            << main.GetBalance() << ".\n\n";

  BankAccount second;
  std::string name;
  std::cout << "Give your second bank account a name: ";
  std::getline(std::cin, name);
  second.bankName = name;
  std::cout << "Your second bank's name is " << second.bankName << " with $"
            << second.GetBalance() << ".\n\n";

  short choice;
  bool repeat;
  do {
    std::cout
        << "What do you want to do?\n1) Deposit Money\n2) Withdraw Money\n";
    std::cin >> choice;

    double amount;

    switch (choice) {
    case 1:
      std::cout << "Enter an amount to deposit: ";
      std::cin >> amount;
      main.Deposit(amount);
      break;

    case 2:
      std::cout << "Enter an amount to withdraw: ";
      std::cin >> amount;
      main.Withdraw(amount);
      break;
    }

    std::cout << "You have $" << main.GetBalance()
              << " in your bank account.\n\nDo you want to do another "
                 "transaction?\n1) Yes\n0) No\n";
    std::cin >> repeat;
  } while (repeat);

  return 0;
}