#pragma once

#include "Soldier.hpp"
#define footCom_health 150

class FootCommander : public Soldier {

    public:    
    FootCommander(uint player_number ):Soldier(player_number,footCom_health){}

    Soldier* minDis(int l,int r,std::vector<std::vector<Soldier*>> board);



    void move(int l,int r,std::vector<std::vector<Soldier*>>& board);


};