//
// Created by sarge on 11/6/2019.
//

#include "ShortThrower.h"

ShortThrower::ShortThrower() {
    foodCost = 3;
    armor = 1;
}

ShortThrower::~ShortThrower() = default;

bool ShortThrower::doAction(TotallyNotAVector<TotallyNotAVector<Insect *>> *gameBoard, Player &player) {
    for(int i = 0; i < 3 && (i + Xlocation) < gameBoard->length(); i++) {
        for (int j = 0; j < gameBoard->getReference(i)->length(); j++) {
            Insect *nextBug = gameBoard->getReference(i)->get(j);
            if (!nextBug->isFriendly()) {
                nextBug->takeDmg(1);
                return true;
            }
        }
    }
    return true;
}

std::string ShortThrower::toString() {
    return "sT";
}
