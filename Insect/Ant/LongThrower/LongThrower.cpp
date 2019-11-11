//
// Created by sarge on 11/6/2019.
//

#include "LongThrower.h"

LongThrower::LongThrower() {
    foodCost = 3;
    armor = 1;
}

LongThrower::~LongThrower() = default;

bool LongThrower::doAction(TotallyNotAVector<TotallyNotAVector<Insect *>> *gameBoard, Player &player) {
    for(int i = 0; i < 5 && (i + Xlocation) < gameBoard->length(); i++) {
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

std::string LongThrower::toString() {
    return "lT";
}
