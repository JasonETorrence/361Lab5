//
// Created by sarge on 11/6/2019.
//

#ifndef INC_361LAB5_FIRE_H
#define INC_361LAB5_FIRE_H

#include "../Ant.h"
class Fire : public Ant{
public:
    Fire();
    ~Fire() override;

    void die(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard) override;
    std::string toString() override;
};


#endif //INC_361LAB5_FIRE_H
