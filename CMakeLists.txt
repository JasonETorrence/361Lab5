cmake_minimum_required(VERSION 3.15)
project(361Lab5)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        361Lab5
        main.cpp
        Driver.cpp Driver.h
        Utilities/TotallyNotAVector.h
        Utilities/Utilities.cpp Utilities/Utilities.h
        Insect/Ant/Ant.cpp Insect/Ant/Ant.h
        Insect/Insect.cpp Insect/Insect.h
        Insect/Ant/Bodyguard/BodyGuard.cpp Insect/Ant/Bodyguard/BodyGuard.h
        Insect/Ant/Fire/Fire.cpp Insect/Ant/Fire/Fire.h
        Insect/Ant/Harvester/Harverster.cpp Insect/Ant/Harvester/Harverster.h
        Insect/Ant/LongThrower/LongThrower.cpp Insect/Ant/LongThrower/LongThrower.h
        Insect/Ant/Ninja/Ninja.cpp Insect/Ant/Ninja/Ninja.h
        Insect/Ant/Queen/Queen.cpp Insect/Ant/Queen/Queen.h
        Insect/Ant/ShortThrower/ShortThrower.cpp Insect/Ant/ShortThrower/ShortThrower.h
        Insect/Ant/Thrower/Thrower.cpp Insect/Ant/Thrower/Thrower.h
        Insect/Ant/Wall/Wall.cpp Insect/Ant/Wall/Wall.h
        Insect/Bee/Bee.cpp Insect/Bee/Bee.h
        Player/Player.cpp Player/Player.h
        Utilities/Purchaser.h)
