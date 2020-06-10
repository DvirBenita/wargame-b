#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

    class Soldier{
         public:
        
        uint health;
        uint player_number;
     
         Soldier(uint player_number,uint health):health(health),player_number(player_number){}
         virtual void move(uint player_number,std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board) = 0;
         virtual int fullLife()= 0;
    };