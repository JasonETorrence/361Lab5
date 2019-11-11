//
// Created by sarge on 11/6/2019.
//

#ifndef INC_361LAB5_LONGTHROWER_H
#define INC_361LAB5_LONGTHROWER_H

#include "../Ant.h"
class LongThrower : public Ant{
public:
    LongThrower();
    ~LongThrower() override;

    bool doAction(TotallyNotAVector<TotallyNotAVector<Insect *>>* gameBoard, Player &player) override;
    std::string toString() override;
};


#endif //INC_361LAB5_LONGTHROWER_H
