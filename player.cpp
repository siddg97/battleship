#include "player.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Player::Player(int ship){
  initialBoard(ship);
}

void Player::initialBoard(int ship){
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      board[i][j] = 'O';
      display_board[i][j] = 'O';
    }
  }
  while(ship != 0){
    int row, col;
    bool flag = true;
    int shipSize = 3;
    row = rand() % 6;
    col = rand() % 6;

    if (rand() % 2 == 0)
      putShipOnRow(row, col, shipSize, flag);
    else
      putShipOnCol(row, col, shipSize, flag);

    if (flag == true)
      ship--;
  }
}

void Player::putShipOnRow(int r, int c, int size, bool& b) {
  int count = 0;
  for (int i = 0; i < size; i++)
    if (board[r + i][c] == 'O')
      count++;
  if (count == size)
    for (int i = 0; i < size; i++)
      board[r + i][c] = 'S';
  else
    b = false;
}

void Player::putShipOnCol(int r, int c, int size, bool& b) {
  int count = 0;
  for (int i = 0; i < size; i++)
    if (board[r][c + i] == 'O')
      count++;
  if (count == size)
    for (int i = 0; i < size; i++)
      board[r][c + i] = 'S';
  else
    b = false;
}

void Player::displayBoard(){
  cout << " | ";
  for (int i = 1; i <= 10; i++)
    cout << i << " ";
  cout << "|" << endl;
  for (int i = 0; i < 10; i++){
    char ch = 65 + i;
    cout << ch << "| ";
    for (int j = 0; j < 10; j++)
      cout << display_board[i][j] << " ";
    cout << " |" << endl;
  }
  cout << endl;
}

bool Player::hit(char guessRow, int guessCol){
  int col = guessCol;
  int row = static_cast<int>(guessRow);
  if (row >= 65 && row <= 74)
    row -= 65;
  else if (row >= 97 && row <= 106)
    row -= 97;

  if (board[row][col] == 'S'){
    cout << "Hit!" << endl;
    display_board[row][col] = 'X';
    return true;
  }
  else if (board[row][col] == 'O'){
    cout << "Missed" << endl;
    display_board[row][col] = '-';
    return false;
  }
  else{
    cout << "Already hit!" << endl;
    return false;
  }
}

bool Player::invalidRow(char guessRow){
  if (guessRow >= 'A' && guessRow <= 'J')
    return false;
  else if (guessRow >= 'a' && guessRow <= 'j')
    return false;
  else
    return true;
}

bool Player::invalidCol(int guessCol){
  if (guessCol >= 1 && guessCol <= 10)
    return false;
  else
    return true;
}
