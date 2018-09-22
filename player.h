#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
  Player(int ship);
  void initialBoard(int ship);
  void putShipOnRow(int r, int c, int size, bool& b);
  void putShipOnCol(int r, int c, int size, bool& b);
  void displayBoard();
  bool hit(char guessRow, int guessCol);
  bool invalidRow(char guessRow);
  bool invalidCol(int guessCol);
  char board[10][10];
  char display_board[10][10];
};

#endif
