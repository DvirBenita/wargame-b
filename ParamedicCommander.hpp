#pragma once

#include "Soldier.hpp"
#define paramedicCom_health 200
class ParamedicCommander : public Soldier {
    public:
    ParamedicCommander(int player_number):Soldier(player_number,paramedicCom_health ){}
    Soldier*& minDis(int l,int r,std::vector<std::vector<Soldier*>>& board);
   void move(uint player_number,std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board);
};