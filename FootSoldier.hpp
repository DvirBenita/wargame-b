#pragma once

#include "Soldier.hpp"
#include <cmath> 
#define footSoldier_health 100

class FootSoldier : public Soldier{
    public:    
    FootSoldier(uint player_number ):Soldier(player_number,footSoldier_health){}
    Soldier*& minDis(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board);
    void move(uint player_number,std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board);
    int fullLife();
};