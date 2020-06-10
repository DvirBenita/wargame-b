#pragma once
#include "Board.hpp"


Soldier*& WarGame::Board::operator[](std::pair<int,int> location){
    return board[location.first][location.second];
}

 Soldier* WarGame::Board::operator[](std::pair<int,int> location) const{
     return board[location.first][location.second];
 }

void checkLegal(uint player_number,std::pair<int,int> source, WarGame::Board::MoveDIR direction, std::vector<std::vector<Soldier*>>& board){

    if(board[source.first][source.second] == nullptr){throw std::invalid_argument("There is not soldier exsist");};
    if(board[source.first][source.second]->player_number != player_number ){throw std::invalid_argument("That not your'e soldier");}
    switch (direction)
    {
    case WarGame::Board::Up:
        if( board[source.first+1][source.second] != nullptr){
            throw std::invalid_argument("There is soldier in this target postion");
        }
        break;
    case WarGame::Board::Down:
        if( board[source.first][source.second-1] != nullptr){
            throw std::invalid_argument("There is soldier in this target postion");
        }
        break;
    case WarGame::Board::Right:
        if( board[source.first][source.second+1] != nullptr){
            throw std::invalid_argument("There is soldier in this target postion");
        }
        break;
    case WarGame::Board::Left:
        if( board[source.first-1][source.second] != nullptr){
            throw std::invalid_argument("There is soldier in this target postion");
        }
        break;        
    default:
        break;
    }
}
void WarGame::Board:: move(uint player_number, std::pair<int,int> source, MoveDIR direction){
     checkLegal(player_number,source,direction,board);
     Soldier* s = board[source.first][source.second]; 
    switch (direction)
    {
    case WarGame::Board::Up:
        if(source.first+1 < board.size() && board[source.first+1][source.second] == nullptr){
         board[source.first+1][source.second]= board[source.first][source.second];
         board[source.first][source.second]= nullptr;  
         s->move(player_number,source,board);  
        }else{
            throw std::invalid_argument("cannot move up");
        }
        break;
    case WarGame::Board::Down:
        if(source.first-1>=0){
        board[source.first-1][source.second]= board[source.first][source.second];
        board[source.first][source.second]= nullptr;  
        s->move(player_number,source,board);
        }else{
            throw std::invalid_argument("cannot move down");
        }
        break;
    case WarGame::Board::Right:
        if(source.second+1 < board[source.first].size()){
        board[source.first][source.second+1]= board[source.first][source.second];
        board[source.first][source.second]= nullptr;  
        s->move(player_number,source,board);
        }
        else{
            throw std::invalid_argument("cannot move right");
        }
        break;
    case WarGame::Board::Left:
        if(source.second-1 >= 0){
        board[source.first][source.second-1]= board[source.first][source.second];
        board[source.first][source.second]= nullptr;  
        s->move(player_number,source,board);
        }else{
            throw std::invalid_argument("cannot move left");
        }
        break;        
    default:
        break;
    }    
}
static int count =0;
 bool WarGame::Board::has_soldiers(uint player_number) const{

        for (const auto & i : board) {
            for (auto j : i) {
                if(j != nullptr && j->player_number == player_number)
                    return true;
            }
        }
 };