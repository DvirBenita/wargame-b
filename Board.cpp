#include "Board.hpp"


Soldier*& WarGame::Board::operator[](std::pair<int,int> location){
    return board[location.first][location.second];
}

 Soldier* WarGame::Board::operator[](std::pair<int,int> location) const{
     return board[location.first][location.second];
 }


void WarGame::Board:: move(uint player_number, std::pair<int,int> source, MoveDIR direction){
    
}

bool WarGame::Board::has_soldiers(uint player_number) const{
  
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != nullptr) {
                if (board[i][j]->player_number == player_number) {
                    return true;
                }
            }
        }
    }
    return false;

}