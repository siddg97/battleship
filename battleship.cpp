#include <iostream>
#include <cstdlib>
#include "player.h"
using namespace std;

int turn = 1;
int numShip = 7;
int p1numShip = 7;
int p2numShip = 7;

void solo_mode(){
  srand(time(NULL));
  Player player1(numShip);
  while(turn != 20 && numShip != 0){
    char guess_row;
    int guess_col;

    cout << "Turn: " << turn << endl;
    cout << "Guess row: ";
    cin >> guess_row;
    while(player1.invalidRow(guess_row)){
      cout << "Invalid Input. Guess row: ";
      cin >> guess_row;
    }

    cout << "Guess col: ";
    cin >> guess_col;
    while(player1.invalidCol(guess_col)){
      cout << "Invalid Input. Guess col: ";
      cin >> guess_col;
    }

    if(player1.hit(guess_row, guess_col-1))
      numShip--;
    player1.displayBoard();
    turn++;
  }
  if (numShip == 0)
    cout << "YOU WIN!" << endl;
  else
    cout << "GAME OVER!" << endl;
}

void versus_mode(){
  srand(time(NULL));
  Player player1(p1numShip);
  int match = 1;
  Player player2(p2numShip);
  while(p1numShip != 0 && p2numShip != 0){
    char guess_row;
    int guess_col;
    if(match % 2 == 1){
      cout << "Player one, Guess row: ";
      cin >> guess_row;
      while(player1.invalidRow(guess_row)){
        cout << "Invalid Input. Guess row: ";
        cin >> guess_row;
      }

      cout << "Guess col: ";
      cin >> guess_col;
      while(player1.invalidCol(guess_col)){
        cout << "Invalid Input. Guess col: ";
        cin >> guess_col;
      }

      if(player2.hit(guess_row, guess_col-1))
        numShip--;
      player2.displayBoard();
    }
    else{
      cout << "Player two, Guess row: ";
      cin >> guess_row;
      while(player1.invalidRow(guess_row)){
        cout << "Invalid Input. Guess row: ";
        cin >> guess_row;
      }

      cout << "Guess col: ";
      cin >> guess_col;
      while(player1.invalidCol(guess_col)){
        cout << "Invalid Input. Guess col: ";
        cin >> guess_col;
      }

      if(player1.hit(guess_row, guess_col-1))
        numShip--;
      player1.displayBoard();
    }
    match++;
  }
  if (p1numShip == 0)
    cout << "PLAYER TWO WINS!" << endl;
  else
    cout << "PLAYER ONE WINS!" << endl;
}

void versus_bot_mode(){
  srand(time(NULL));
  Player player1(p1numShip);
  int match = 1;
  Player bot(p2numShip);
  while(p1numShip != 0 && p2numShip != 0){
    char guess_row;
    int guess_col;
    if(match % 2 == 1){
      cout << "Player, Guess row: ";
      cin >> guess_row;
      while(player1.invalidRow(guess_row)){
        cout << "Invalid Input. Guess row: ";
        cin >> guess_row;
      }

      cout << "Guess col: ";
      cin >> guess_col;
      while(player1.invalidCol(guess_col)){
        cout << "Invalid Input. Guess col: ";
        cin >> guess_col;
      }

      if(bot.hit(guess_row, guess_col-1))
        numShip--;
      bot.displayBoard();
    }
    else{
      cout << "Bot chooses row: ";
      guess_row = rand() % 10 + 65;
      cout << guess_row << endl;
      cout << "Bot chooses col: ";
      guess_col = rand() % 10 + 1;
      cout << guess_col << endl;

      if(player1.hit(guess_row, guess_col-1))
        numShip--;
      player1.displayBoard();
    }
    match++;
  }
  if (p1numShip == 0)
    cout << "BOT WINS!" << endl;
  else
    cout << "YOU WINS!" << endl;
}

void home(){
  while(true){
  cout << "==========================================================" << endl;
  cout << "1. Single Play mode" << endl;
  cout << "2. 2 Players mode" << endl;
  cout << "3. Versus Bot mode" << endl;
  cout << "==========================================================" << endl;
  cout << "Enter number to select play mode: ";

  int choice;
  cin >> choice;

  if (choice == 1){
    cout << endl;
    solo_mode();
  }
  else if (choice == 2){
    cout << endl;
    versus_mode();
  }
  else if (choice == 3){
    cout << endl;
    versus_bot_mode();
  }
  else if (choice == 0){
    cout << "Bye!" << endl;
    break;
  }
  else{
    cout << "Invalid input" << endl;
  }
 }
}

int main(){
  home();
  return 0;
}
