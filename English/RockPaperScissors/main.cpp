#include <Windows.h>
#include <ctime>
#include <iostream>

void showChoice(char choice);
void chooseWinner(char player, char computer);

int main() {
  SetConsoleOutputCP(CP_UTF8);

  char player;

  do {
    std::cout << "Rock-Paper-Scissors Game!" << std::endl
              << "Choose one of the following" << std::endl
              << "'r' for rock" << std::endl
              << "'p' for paper" << std::endl
              << "'s' for scissors" << std::endl;
    std::cin >> player;
  } while (player != 'r' && player != 'p' && player != 's');

  std::cout << "Your Choice: ";
  showChoice(player);

  srand(static_cast<unsigned int>(time(0)));

  int computer = rand() % 3 + 1;
  char computerChoice;

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
    std::cout << "Rock" << std::endl;
    break;
  case 'p':
    std::cout << "Paper" << std::endl;
    break;
  case 's':
    std::cout << "Scissors" << std::endl;
    break;
  default:
    std::cout << "Invalid choice" << std::endl;
    break;
  }
}

void chooseWinner(char player, char computer) {
  if (player == computer) {
    std::cout << "It's a tie!" << std::endl;
  } else if ((player == 'r' && computer == 's') ||
             (player == 'p' && computer == 'r') ||
             (player == 's' && computer == 'p')) {
    std::cout << "You win!" << std::endl;
  } else {
    std::cout << "You lose!" << std::endl;
  }
}