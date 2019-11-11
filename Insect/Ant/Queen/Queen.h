//
// Created by sarge on 11/6/2019.
//

#ifndef INC_361LAB5_QUEEN_H
#define INC_361LAB5_QUEEN_H

#include "../Ant.h"
class Queen : public Ant{
public:
    Queen();
    ~Queen();

    void die(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard) override;
    std::string toString() override;
};


#endif //INC_361LAB5_QUEEN_H
