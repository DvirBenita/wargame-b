#pragma once


#include "Soldier.hpp"
#define sniperCom_health 120

class SniperCommander : public Soldier{

    public:
    SniperCommander(int player_number):Soldier(player_number,sniperCom_health){}
    Soldier*& minDis(int l,int r,std::vector<std::vector<Soldier*>>& board);
    void  move(uint player_number,std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board);
    int fullLife();
    
};