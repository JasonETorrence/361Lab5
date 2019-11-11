//
// Created by sarge on 11/6/2019.
//

#ifndef INC_361LAB5_BEE_H
#define INC_361LAB5_BEE_H


#include "../Insect.h"

class Bee : public Insect{
protected:
    void moveLeft(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard);
public:
    Bee();
    ~Bee() override;
    bool doAction(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard, Player &player) override;
    std::string toString() override;
};


#endif //INC_361LAB5_BEE_H
