//
// Created by sarge on 11/6/2019.
//

#ifndef INC_361LAB5_ANT_H
#define INC_361LAB5_ANT_H

#include "../Insect.h"

class Ant : public Insect{
protected:
    bool protectAvility;
    bool blockability;
    int foodCost;
public:
    Ant();
    ~Ant() override;
    Ant(const Ant &aAnt) noexcept;

    virtual bool isProtectable();
    virtual bool isPlaceable(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard, int position);
    int getfoodCost() const ;
    bool getBlockability() const ;

    std::string toString() override;

};


#endif //INC_361LAB5_ANT_H
