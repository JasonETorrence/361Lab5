//
// Created by sarge on 11/8/2019.
//

#include "Player.h"

Player::Player(){
    amountOfFood = 999999;
}

Player::~Player() = default;

int Player::getAmountOfFood() {
    return amountOfFood;
}

void Player::spendFood(int amount) {
    amountOfFood -= amount;
}

void Player::recieveFood(int amount) {
    amountOfFood += amount;
}

