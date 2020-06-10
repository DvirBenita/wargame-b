#pragma once
#include "Soldier.hpp"
#define footCom_health 150

class FootCommander : public Soldier {
    public:    
    FootCommander(uint player_number ):Soldier(player_number,footCom_health){}
    Soldier*& minDis(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board);
    void move(uint player_number,std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board);
    int fullLife();
    
};