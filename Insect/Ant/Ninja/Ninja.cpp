//
// Created by sarge on 11/6/2019.
//

#include "Ninja.h"
#include "../../Bee/Bee.h"

Ninja::Ninja(){
    armor = 1;
    attack = 1;
    foodCost = 6;
    blockability = true;
    beeAttackable = false;
}

Ninja::~Ninja() = default;

bool Ninja::doAction(TotallyNotAVector<TotallyNotAVector<Insect *>>* gameBoard, Player &player) {
    int numThingsOnSquare = gameBoard->getReference(Xlocation)->length();
    if(numThingsOnSquare > 1){
        for(int i = 1; i < numThingsOnSquare; i++){
            gameBoard->getReference(Xlocation)->get(i)->takeDmg(1);
        }
        return true;
    }else{
        return false;
    }

}

std::string Ninja::toString() {
    return "N";
}

bool Ninja::isProtectable() {
    return false;
}

#include "Ninja.h"
