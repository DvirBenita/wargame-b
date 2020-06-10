#pragma once

#include "Soldier.hpp"
#define paramedic_health 100

class Paramedic : public Soldier{

     public:
    Paramedic(int player_number):Soldier(player_number,paramedic_health){}
    void move(uint player_number,std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board);
  
};