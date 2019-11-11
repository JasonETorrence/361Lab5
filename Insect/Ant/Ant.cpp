//
// Created by sarge on 11/6/2019.
//

#include "Ant.h"

Ant::Ant(){
    blockability = true;
    beeAttackable = true;
    friendly = true;
}

Ant::~Ant() = default;


Ant::Ant(const Ant &aAnt) noexcept {
    attack = aAnt.getAttack();
    armor = aAnt.getArmor();
    foodCost = aAnt.getfoodCost();
    Xlocation = aAnt.getXLocation();
    Ylocation = aAnt.getYLocation();
    blockability = aAnt.getBlockability();
    beeAttackable = aAnt.isBeeAttackable();
}

bool Ant::getBlockability() const {
    return blockability;
}

int Ant::getfoodCost() const {
    return foodCost;
}

bool Ant::isPlaceable(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard, int position){
    if(gameBoard->get(position).length() > 0){//if there is something at that position...
        return !gameBoard->get(position).get(0)->isFriendly();//return true if it's not friendly
    }
    return true;//if there is nothing on that position
}

bool Ant::isProtectable() {
    return true;
}

std::string Ant::toString() {
    return "A";
}
