//
// Created by sarge on 11/6/2019.
//

#ifndef INC_361LAB5_INSECT_H
#define INC_361LAB5_INSECT_H


#include <string>
#include "../Utilities/TotallyNotAVector.h"
#include "../Player/Player.h"

class Insect {
protected:
    int armor;
    int attack;
    int Xlocation;
    int Ylocation;
    bool beeAttackable;
    bool friendly;
public:
    Insect();
    virtual ~Insect();

    int getArmor() const;
    int getAttack() const;
    int getXLocation() const;
    int getYLocation() const;
    bool isBeeAttackable() const;
    bool isFriendly() const;
    void setXLocation(int index);
    void setYLocation(int index);
    void takeDmg(int amount);
    virtual std::string toString();

    virtual void die(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard);
    virtual bool doAction(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard, Player &player);
};


#endif //INC_361LAB5_INSECT_H
