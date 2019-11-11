//
// Created by sarge on 11/6/2019.
//

#include <iostream>
#include "Bee.h"



Bee::Bee(){
    armor = 3;
    attack = 1;
    Xlocation = 0;
    beeAttackable = false;
    friendly = false;
}

Bee::~Bee() = default;

bool Bee::doAction(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard, Player &player) {
    bool canAttack = false;
    if(gameBoard->getReference(Xlocation)->length() == 1){
        moveLeft(gameBoard);
        return true;
    }else if(gameBoard->getReference(Xlocation)->length() > 0){
        for(int i = 0; i < gameBoard->getReference(Xlocation)->length(); i++){
            if(gameBoard->getReference(Xlocation)->get(i)->isBeeAttackable()){
                canAttack = true;
            }
        }
        if(canAttack){
            std::cout << "A bee on space " << std::to_string(Xlocation);
            gameBoard->getReference(Xlocation-1)->get(0)->takeDmg(attack);
        }else{
            moveLeft(gameBoard);
        }
        return true;
    }
    return false;
}

void Bee::moveLeft(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard){
    gameBoard->getReference(Xlocation - 1)->append
        (gameBoard->getReference(Xlocation)->remove(Ylocation));
}

std::string Bee::toString() {
    return "B";
}
