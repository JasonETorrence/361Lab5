//
// Created by sarge on 11/6/2019.
//

#include "Fire.h"

Fire::Fire(){
    armor = 1;
    foodCost = 4;
}

Fire::~Fire() = default;

void Fire::die(TotallyNotAVector<TotallyNotAVector<Insect *>> *gameBoard) {
    for(int i = 0; i < gameBoard->getReference(Xlocation)->length(); i++){
        Insect* nextBug = gameBoard->getReference(Xlocation)->get(i);
        if(!nextBug->isFriendly()){
            nextBug->die(gameBoard);
        }
    }
    gameBoard->getReference(Xlocation)->remove(Ylocation);
}

std::string Fire::toString() {
    return "F";
}
