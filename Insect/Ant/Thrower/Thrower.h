//
// Created by sarge on 11/6/2019.
//

#ifndef INC_361LAB5_THROWER_H
#define INC_361LAB5_THROWER_H

#include "../Ant.h"
class Thrower : public Ant{
public:
    Thrower();
    ~Thrower() override;

    bool doAction(TotallyNotAVector<TotallyNotAVector<Insect *>>* gameBoard, Player &player) override;
    std::string toString() override;
};


#endif //INC_361LAB5_THROWER_H
