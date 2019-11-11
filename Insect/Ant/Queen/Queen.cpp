//
// Created by sarge on 11/6/2019.
//

#include <iostream>
#include "Queen.h"

Queen::Queen() {
    armor = 1;
}

Queen::~Queen() = default;



void Queen::die(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard){
    std::cout << "Your queen died! Your ant kingdom will now fall into utter nothingness! Ouch!" << std::endl;
    exit(0);
}

std::string Queen::toString() {
    return "Q: " + std::to_string(reinterpret_cast<int>(this));
}
