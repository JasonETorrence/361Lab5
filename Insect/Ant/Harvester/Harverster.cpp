//
// Created by sarge on 11/6/2019.
//

#include "Harverster.h"

Harverster::Harverster() {
    armor = 1;
    foodCost = 2;
}

Harverster::~Harverster() = default;

bool Harverster::doAction(TotallyNotAVector<TotallyNotAVector<Insect *>> *gameBoard, Player &player) {
    player.recieveFood(1);
    return true;
}

std::string Harverster::toString() {
    return "H: " + std::to_string(reinterpret_cast<int>(this));
}
