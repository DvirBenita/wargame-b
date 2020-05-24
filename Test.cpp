#include "doctest.h"
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"



TEST_CASE("1"){
    WarGame::Board test(8,8);
    test[{0,0}] = new FootSoldier(1);
    test[{0,1}] = new FootCommander(2);

    for(int i=0;i<100;i++){
        CHECK(test.has_soldiers(1));
        CHECK(test.has_soldiers(2));
        CHECK_NOTHROW(test.move(1,{0,0},WarGame::Board::Right);)
    }


}