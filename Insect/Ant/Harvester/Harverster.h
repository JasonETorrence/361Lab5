//
// Created by sarge on 11/6/2019.
//

#ifndef INC_361LAB5_HARVERSTER_H
#define INC_361LAB5_HARVERSTER_H

#include "../Ant.h"
class Harverster : public Ant{
public:
    Harverster();
    ~Harverster() override;

    bool doAction(TotallyNotAVector<TotallyNotAVector<Insect *>>* gameBoard, Player &player) override;
    std::string toString() override;
};


#endif //INC_361LAB5_HARVERSTER_H
