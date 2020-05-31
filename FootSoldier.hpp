#pragma once

#include "Soldier.hpp"
#include <cmath> 
#define footSoldier_health 100

class FootSoldier : public Soldier{

    public:    
    FootSoldier(uint player_number ):Soldier(player_number,footSoldier_health){}

    Soldier* minDis(int l,int r,std::vector<std::vector<Soldier*>> board);

    void move(int l,int r,std::vector<std::vector<Soldier*>> board);


};