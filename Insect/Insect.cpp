//
// Created by sarge on 11/6/2019.
//

#include "Insect.h"

Insect::Insect(){
    armor = 0;
    attack = 0;
    Xlocation = 0;
    Ylocation = 0;
    beeAttackable = true;
}

Insect::~Insect() = default;

int Insect::getArmor() const {
    return armor;
}

int Insect::getAttack() const {
    return attack;
}

int Insect::getXLocation() const {
    return Xlocation;
}

int Insect::getYLocation() const {
    return Ylocation;
}

void Insect::setXLocation(int index){
    Xlocation = index;
}

void Insect::setYLocation(int index) {
    Ylocation = index;
}


void Insect::takeDmg(int amount) {
    armor -= amount;
}

bool Insect::isBeeAttackable() const {
    return beeAttackable;
}

bool Insect::doAction(TotallyNotAVector<TotallyNotAVector<Insect *>> *gameBoard, Player &player) {
    return true;
}

bool Insect::isFriendly() const {
    return friendly;
}

void Insect::die(TotallyNotAVector<TotallyNotAVector<Insect *>> *gameBoard) {
    gameBoard->getReference(Xlocation)->remove(Ylocation);
}

std::string Insect::toString() {
    return "X";
}

