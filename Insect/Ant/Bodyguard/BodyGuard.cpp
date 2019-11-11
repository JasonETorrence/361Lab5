#include "BodyGuard.h"

//
// Created by sarge on 11/6/2019.
//

BodyGuard::BodyGuard() {
    armor = 2;
    attack = 0;
    blockability = false;
    foodCost = 4;
}

bool BodyGuard::isPlaceable(TotallyNotAVector<TotallyNotAVector<Insect *>> *gameBoard, int position) {
    if(gameBoard->get(position).length() > 0){//if that position on the board has something on it....
        if(gameBoard->get(position).get(0)->isFriendly()){//if the first place on that position is friendly...
            bool protectable = ((Ant*)gameBoard->get(position).get(0))->isProtectable();
            if(gameBoard->get(position).length() > 1){ //if there is more than one thing at this position...
                return !gameBoard->get(position).get(1)->isFriendly(); //return true if it's not friendly
            }else if(protectable){//if there is only one thing and it's protectable...
                return true;
            }
        }else{//if that position on the board has nothing friendly....
            return false;
        }
    }
    return false;//if that position on the board has nothing on it....
}

bool BodyGuard::isProtectable() {
    return false;
}

std::string BodyGuard::toString() {
    return "b";
}

BodyGuard::~BodyGuard() = default;

