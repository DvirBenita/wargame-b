
#include "SniperCommander.hpp"
#include "Sniper.hpp"
namespace WarGame {
    void SniperCommander::move(uint player_number,std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board){
        uint maxHealth = 0;
        Soldier* strongest = nullptr;
        int I,J;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if (board[i][j] != nullptr && board[i][j]->player_number != this->player_number && board[i][j]->health > maxHealth){
                    maxHealth = board[i][j]->health;
                    strongest = board[i][j];
                    I=i;J=j;
                }
            }
        }
        if(strongest != nullptr)
            strongest->health-= 50;
            if(strongest->health<0){
                delete board[I][J];
                board[I][J] = nullptr;
            }
        else{
            std::cerr << "Sniper::play can't find someone to shoot at" << std::endl;
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(Sniper* para = dynamic_cast<Sniper*>(board[i][j])){
                    std::pair<int,int> pair = {i,j};
                    para->move(this->player_number,pair,board);
                }
            }
        }    
        
    }
}