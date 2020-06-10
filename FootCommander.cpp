#pragma once 
#include "FootCommander.hpp"
#include "FootSoldier.hpp"


Soldier*& FootCommander::minDis(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board){
        Soldier* s= nullptr;
        int L=0,R=0, l = source.first,r=source.second;
        double dis=0;
        for(int i = 0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++){
                if (board[i][j] != nullptr && board[i][j]->player_number != Soldier::player_number)
                {
                    if(s != nullptr ){
                        if(sqrt((l-L)*(l-L) + (r-R)*(r-R))<dis)
                        s=board[L][R];
                        L=l;
                        r=R;
                        dis=sqrt((l-L)*(l-L) + (r-R)*(r-R));
                    }
                    else{
                        s=board[L][R];
                        L=l;
                        R=r;
                        dis=sqrt((l-L)*(l-L) + (r-R)*(r-R));
                    }
                }
            }
        }
        if(s!= nullptr && board[L][R]->health-20 <= 0){
            delete board[L][R];
            board[L][R] = nullptr;
            s = nullptr;
        }
        return s;
    } 

    void FootCommander::move(uint player_number,std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board){
       
        Soldier* s = minDis(source,board);
        if(s != nullptr ){
            s->health -= 20;
        }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(FootSoldier* footSol = dynamic_cast<FootSoldier*>(board[i][j])){
                    footSol->move(player_number,source,board);
                }
            }
        }
    }    


    int FootCommander:: fullLife(){
        return footCom_health;
    }