//
// Created by sarge on 11/8/2019.
//

#ifndef INC_361LAB5_PLAYER_H
#define INC_361LAB5_PLAYER_H


class Player {
protected:
    int amountOfFood;
public:
    Player();
    ~Player();

    int getAmountOfFood();
    void spendFood(int amount);
    void recieveFood(int amount);
};


#endif //INC_361LAB5_PLAYER_H
