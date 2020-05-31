#include "Board.hpp"


Soldier*& WarGame::Board::operator[](std::pair<int,int> location){
    return board[location.first][location.second];
}

 Soldier* WarGame::Board::operator[](std::pair<int,int> location) const{
     return board[location.first][location.second];
 }

void checkLegal(uint player_number,std::pair<int,int> source, WarGame::Board::MoveDIR direction, std::vector<std::vector<Soldier*>>& board){

    if(board[source.first][source.second] == nullptr){throw std::invalid_argument("There is not soldier exsist");};
    if( board[source.first][source.second]->player_number != player_number ){throw std::invalid_argument("That not your'e soldier");}
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
    if(player_number == 1){
    switch (direction)
    {
    case WarGame::Board::Up:
        
        board[source.first+1][source.second]= board[source.first][source.second];
        board[source.first][source.second]= nullptr;  
        s->move(source.first+1,source.second,board);  
        break;
    case WarGame::Board::Down:
        board[source.first-1][source.second]= board[source.first][source.second];
        board[source.first][source.second]= nullptr;  
        s->move(source.first-1,source.second,board);
        break;
    case WarGame::Board::Right:
        board[source.first][source.second+1]= board[source.first][source.second];
        board[source.first][source.second]= nullptr;  
        s->move(source.first,source.second+1,board);
        break;
    case WarGame::Board::Left:
        board[source.first][source.second-1]= board[source.first][source.second];
        board[source.first][source.second]= nullptr;  
        s->move(source.first,source.second-1,board);
        break;        
    default:
        break;
    }
    }else{
       switch (direction)
    {
    case WarGame::Board::Up:
        
        board[source.first-1][source.second]= board[source.first][source.second];
        board[source.first][source.second]= nullptr;  
        s->move(source.first-1,source.second,board);  
        break;
    case WarGame::Board::Down:
        board[source.first+1][source.second]= board[source.first][source.second];
        board[source.first][source.second]= nullptr;  
        s->move(source.first+1,source.second,board);
        break;
    case WarGame::Board::Right:
        board[source.first][source.second-1]= board[source.first][source.second];
        board[source.first][source.second]= nullptr;  
        s->move(source.first,source.second-1,board);
        break;
    case WarGame::Board::Left:
        board[source.first][source.second+1]= board[source.first][source.second];
        board[source.first][source.second]= nullptr;  
        s->move(source.first,source.second+1,board);
        break;        
    default:
        break;
    }
    }

    


    
}

bool WarGame::Board::has_soldiers(uint player_number) const{

    for(int i =0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]->player_number == player_number)
                return true;
        }
    }
    return false;
}