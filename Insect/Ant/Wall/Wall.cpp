//
// Created by sarge on 11/6/2019.
//

#include "Wall.h"

Wall::Wall(){
    armor = 4;
    attack = 0;
    foodCost = 4;
}

std::string Wall::toString() {
    return "W";
}

Wall::~Wall() = default;
