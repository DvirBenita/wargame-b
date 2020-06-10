#pragma once


#include "Soldier.hpp"

#define sniper_health 100

class Sniper : public Soldier{

    public:
    Sniper(int player_number):Soldier(player_number,sniper_health){}
    void move(uint player_number,std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board);
    int fullLife();
};