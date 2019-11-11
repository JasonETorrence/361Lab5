//
// Created by sarge on 11/6/2019.
//

#ifndef INC_361LAB5_SHORTTHROWER_H
#define INC_361LAB5_SHORTTHROWER_H

#include "../Ant.h"
class ShortThrower : public Ant{
public:
    ShortThrower();
    ~ShortThrower() override;

    bool doAction(TotallyNotAVector<TotallyNotAVector<Insect *>>* gameBoard, Player &player) override;
    std::string toString() override;
};


#endif //INC_361LAB5_SHORTTHROWER_H
