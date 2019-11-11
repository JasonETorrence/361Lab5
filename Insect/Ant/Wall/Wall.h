//
// Created by sarge on 11/6/2019.
//

#ifndef INC_361LAB5_WALL_H
#define INC_361LAB5_WALL_H

#include "../Ant.h"
class Wall : public Ant {
public:
    Wall();
    ~Wall() override;

    std::string toString() override;

};


#endif //INC_361LAB5_WALL_H
