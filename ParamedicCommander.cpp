#pragma once 
#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"
#define footCom_health 150



    void ParamedicCommander::move(uint player_number,std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board){
       

          for (int i = source.first-1; i < source.first+2 && i < board.size(); ++i) {
                 if(i<0)
                    i=0;
             for (int j = source.second-1; j < source.second+2 && j < board[i].size(); ++j) {
                   if(j<0)
                       j=0;
                   if(i == source.first && j == source.second) 
                         continue;
                   if(board[i][j] != nullptr && board[i][j]->player_number == player_number)
                       board[i][j]->fullLife();
             }
         }  
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(Paramedic* para = dynamic_cast<Paramedic*>(board[i][j])){
                    std::pair<int,int> pair = {i,j};
                    para->move(this->player_number,pair,board);
                }
            }
        }
    }    


    int  ParamedicCommander::fullLife(){
        return footCom_health;
    }