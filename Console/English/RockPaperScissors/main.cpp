#include <iostream>
#include <random>
#include <windows.h>

void showChoice(char choice);
void chooseWinner(char player, char computer);

int main() {
  SetConsoleOutputCP(CP_UTF8);

  char player;
  char computerChoice;

  do {
    std::cout << "Rock-Paper-Scissors Game!\n"
              << "Choose one of the following\n"
              << "'r' for rock\n"
              << "'p' for paper\n"
              << "'s' for scissors\n";
    std::cin >> player;
  } while (player != 'r' && player != 'p' && player != 's');

  std::cout << "Your Choice: ";
  showChoice(player);

  std::random_device rd;
  std::uniform_int_distribution<int> dist(1, 3);

  int computer = dist(rd);

  switch (computer) {
  case 1:
    computerChoice = 'r';
    break;
  case 2:
    computerChoice = 'p';
    break;
  case 3:
    computerChoice = 's';
    break;
  }

  std::cout << "Computer's Choice: ";
  showChoice(computerChoice);

  chooseWinner(player, computerChoice);

  return 0;
}

void showChoice(char choice) {
  switch (choice) {
  case 'r':
    std::cout << "Rock\n";
    break;
  case 'p':
    std::cout << "Paper\n";
    break;
  case 's':
    std::cout << "Scissors\n";
    break;
  default:
    std::cout << "Invalid choice\n";
    break;
  }
}

void chooseWinner(char player, char computer) {
  if (player == computer) {
    std::cout << "It's a tie!\n";
  } else if ((player == 'r' && computer == 's') ||
             (player == 'p' && computer == 'r') ||
             (player == 's' && computer == 'p')) {
    std::cout << "You win!\n";
  } else {
    std::cout << "You lose!\n";
  }
}