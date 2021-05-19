#include <iostream>
using namespace std;

void displayBoard(char board[3][3]){
   using namespace std;
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         cout << board[i][j];
         if (j < 2) cout << ' ';
      }
      cout << endl;
   }
}

bool didWin(char board[3][3], char player){
   bool vWin, hWin, d1Win, d2Win;
   d1Win = true;
   d2Win = true;
   for (int i = 0; i < 3; ++i) {
      vWin = true;
      hWin = true; 

      for (int j = 0; j < 3; ++j) {
         if (board[i][j] != player) vWin = false;
         if (board[j][i] != player) hWin = false;
         
         if(!(hWin || vWin)) break;
      }
      
      if (vWin || hWin) return true;

      
      if(board[i][i] != player) d1Win = false;
      if(board[i][2-i] != player) d2Win = false;
   }
   
   if (d1Win || d2Win) return true;

   return false;
}


int main()
{
   char board[3][3] = {
      {'1','2','3'},
      {'4','5','6'},
      {'7','8','9'}
   };

   char players[2] = {'X','O'};
   int player = 0;
   int turn = 0;

   while(true){
      turn++;
      displayBoard(board);

      if(turn > 5 && didWin(board, players[player])){
         cout << endl << "Congratulations " << players[player] << " you have one the game!\n";
         break;
      }

      if(turn == 10){
         cout << endl << "No one wins.\n";
      }

      player = (player + 1) % 2;

      int move;
      cout <<  players[player] << ", please enter your move: ";
      cin >> move;
      move -= 1;

      while(1){
         char * cell = &board[move/3][move%3];
         if(move > 8 || move < 0){
            cout << "Your move must be between 1 and 9: ";
         }else if(*cell == players[0] || *cell == players[1] ){
            cout << "That move is taken, please choose another: ";
         }else{
            *cell = players[player];
            break;
         }
         cin >> move;
         move -= 1;
      }
   }
}