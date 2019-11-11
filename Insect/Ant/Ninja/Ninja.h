//
// Created by sarge on 11/6/2019.
//

#ifndef INC_361LAB5_NINJA_H
#define INC_361LAB5_NINJA_H

#include "../Ant.h"
class Ninja : public Ant{

public:
    Ninja();
    ~Ninja() override;

    bool doAction(TotallyNotAVector<TotallyNotAVector<Insect *>>* gameBoard, Player &player) override;
    std::string toString() override;
    bool isProtectable() override;
};


#endif //INC_361LAB5_NINJA_H
