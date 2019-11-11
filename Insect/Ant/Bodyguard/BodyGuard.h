//
// Created by sarge on 11/6/2019.
//

#ifndef INC_361LAB5_BODYGUARD_H
#define INC_361LAB5_BODYGUARD_H

#include "../Ant.h"
class BodyGuard : public Ant{
public:
    BodyGuard();
    ~BodyGuard() override;

    bool isPlaceable(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard, int position) override;
    bool isProtectable() override;
    std::string toString() override;
};


#endif //INC_361LAB5_BODYGUARD_H
