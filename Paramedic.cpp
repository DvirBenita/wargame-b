#pragma once 
#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"

    void Paramedic::move(uint player_number,std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board){
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
    }
       