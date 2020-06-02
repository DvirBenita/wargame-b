

    #pragma once
     #include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

    class Soldier{
         public:
        
        uint health;
        uint player_number;
        
       
         Soldier(uint player_number,uint health):health(health),player_number(player_number){
         }

         virtual void move(int l, int r,std::vector<std::vector<Soldier*>>& board) =0;




    };




