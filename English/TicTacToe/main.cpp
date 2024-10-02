#include <array>
#include <iostream>
#include <random>

void drawBoard(const std::array<char, 9> &spaces);
void playerMove(std::array<char, 9> &spaces, char player);
void computerMove(std::array<char, 9> &spaces, char computer);
bool checkWinner(const std::array<char, 9> &spaces, char player, char computer);
bool checkTie(const std::array<char, 9> &spaces);

int main() {
  std::array<char, 9> spaces = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  char player = 'X';
  char computer = 'O';
  bool running = true;

  drawBoard(spaces);

  while (running) {
    playerMove(spaces, player);
    drawBoard(spaces);
    if (checkWinner(spaces, player, computer) || checkTie(spaces)) {
      running = false;
      break;
    }

    computerMove(spaces, computer);
    drawBoard(spaces);
    if (checkWinner(spaces, player, computer) || checkTie(spaces)) {
      running = false;
      break;
    }
  }
  std::cout << "Thanks for playing!" << std::endl;
  return 0;
}

void drawBoard(const std::array<char, 9> &spaces) {
  std::cout << std::endl;
  std::cout << "     |     |     " << std::endl;
  ;
  std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2]
            << "  " << std::endl;
  ;
  std::cout << "_____|_____|_____" << std::endl;
  ;
  std::cout << "     |     |     " << std::endl;
  ;
  std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5]
            << "  " << std::endl;
  ;
  std::cout << "_____|_____|_____" << std::endl;
  ;
  std::cout << "     |     |     " << std::endl;
  ;
  std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8]
            << "  " << std::endl;
  ;
  std::cout << "     |     |     " << std::endl;
  ;
  std::cout << std::endl;
}

void playerMove(std::array<char, 9> &spaces, char player) {
  int number;
  do {
    std::cout << "Enter a spot to place a marker (1-9): ";
    std::cin >> number;
    number--;
    if (number >= 0 && number < 9 && spaces[number] == ' ') {
      spaces[number] = player;
      break;
    }
  } while (true);
}

void computerMove(std::array<char, 9> &spaces, char computer) {
  int number;
  std::random_device rd;
  std::uniform_int_distribution<int> dist(0, 8);

  while (true) {
    number = dist(rd);
    if (spaces[number] == ' ') {
      spaces[number] = computer;
      break;
    }
  }
}

bool checkWinner(const std::array<char, 9> &spaces, char player,
                 char computer) {
  const std::array<std::array<int, 3>, 8> winningCombinations = {{
      {0, 1, 2},
      {3, 4, 5},
      {6, 7, 8}, // Rows
      {0, 3, 6},
      {1, 4, 7},
      {2, 5, 8}, // Columns
      {0, 4, 8},
      {2, 4, 6} // Diagonals
  }};

  for (const auto &combo : winningCombinations) {
    if (spaces[combo[0]] != ' ' && spaces[combo[0]] == spaces[combo[1]] &&
        spaces[combo[1]] == spaces[combo[2]]) {
      if (spaces[combo[0]] == player) {
        std::cout << "YOU WIN!" << std::endl;
      } else {
        std::cout << "YOU LOSE!" << std::endl;
      }
      return true;
    }
  }
  return false;
}

bool checkTie(const std::array<char, 9> &spaces) {
  for (char space : spaces) {
    if (space == ' ') {
      return false;
    }
  }
  std::cout << "IT'S A TIE!" << std::endl;
  return true;
}