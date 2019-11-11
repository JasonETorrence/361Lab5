//
// Created by sarge on 11/6/2019.
//

#include "Thrower.h"

Thrower::Thrower(){
    foodCost = 4;
    armor = 1;
}

Thrower::~Thrower() = default;

bool Thrower::doAction(TotallyNotAVector<TotallyNotAVector<Insect *>> *gameBoard, Player &player) {
    if(gameBoard->getReference(Xlocation)->length() > 1){
        for(int i = 0; i < gameBoard->getReference(Xlocation)->length(); i++){
            Insect* nextBug = gameBoard->getReference(Xlocation)->get(i);
            if(!nextBug->isFriendly()){
                nextBug->takeDmg(1);
                return true;
            }
        }
        return true;
    }else{
        return true;
    }
}

std::string Thrower::toString() {
    return "T";
}
