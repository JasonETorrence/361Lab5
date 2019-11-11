//
// Created by sarge on 11/6/2019.
//

#include <iostream>
#include "Utilities/TotallyNotAVector.h"
#include "Utilities/Utilities.h"
#include "Insect/Insect.h"
#include "Insect/Ant/Ant.h"
#include "Insect/Ant/Queen/Queen.h"
#include "Insect/Ant/Harvester/Harverster.h"
#include "Insect/Ant/Thrower/Thrower.h"
#include "Insect/Ant/Fire/Fire.h"
#include "Insect/Ant/LongThrower/LongThrower.h"
#include "Insect/Ant/ShortThrower/ShortThrower.h"
#include "Insect/Ant/Wall/Wall.h"
#include "Insect/Ant/Ninja/Ninja.h"
#include "Insect/Ant/Bodyguard/BodyGuard.h"

#define UserQuits false
#define UserWaits true
#define boardSize 20

using namespace std;

// Prototyping!
void haveEverythingDoEverything(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard, Player &player);
TotallyNotAVector<TotallyNotAVector<Insect*>>* setUpBoard();
bool GetUserInput(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard, Player &player);
void givePlayerOptions(Player &player);
void buyAnAnt(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard, Player &player);
int checkIfValidPurchase(char userInput, Player &player);
Ant* purchaseAnAnt(char antType);
void attemptToPurchase(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard, Ant* ant, Player &player);
void printBuyOptions(Player &player);
void printWholeBoard(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard);

void Driver(){
    auto* gameBoard = setUpBoard();
    Player player;
    while(true){
        cout << "Driver started" << endl;
        if(GetUserInput(gameBoard, player) == UserQuits){
            cout << "Goodbye!" << endl;
            exit(0);
        }else{
            haveEverythingDoEverything(gameBoard, player);
            printWholeBoard(gameBoard);
        }
    }
}

void haveEverythingDoEverything(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard, Player &player){
    for(int i = 0; i < boardSize; i++){
        auto* nextSquare = gameBoard->getReference(i);
        for(int m = 0; m < nextSquare->length(); m++){
            auto* nextInsect = nextSquare->get(m);
            nextInsect->doAction(gameBoard, player);
        }
    }
}

TotallyNotAVector<TotallyNotAVector<Insect*>>* setUpBoard(){
    auto* gameBoard = new TotallyNotAVector<TotallyNotAVector<Insect*>>();
    for(int i = 0; i < boardSize; i++){
        gameBoard->append(*(new TotallyNotAVector<Insect*>()));
    }
    gameBoard->getReference(0)->append(new Queen());
    return gameBoard;
}

bool GetUserInput(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard, Player &player){
    string userInput;
    while(true){
        cout << "Before:" << endl;
        printWholeBoard(gameBoard);
        givePlayerOptions(player);
        getline(cin, userInput);
        if(userInput.substr(0,1) == "B" or userInput.substr(0,1) == "b"){
            buyAnAnt(gameBoard, player);
        }else if(userInput.substr(0,1) == "W" or userInput.substr(0,1) == "w"){
            return UserWaits;
        }else if(userInput.substr(0,1) == "Q" or userInput.substr(0,1) == "q"){
            return UserQuits;
        }else {
            cout << "invalid input, please enter:" << endl;
            givePlayerOptions(player);
        }
    }
}

void givePlayerOptions(Player &player){
    cout << "What do you want to do?" << endl;
    cout << "Options:" << endl;
    cout << "(B)uy an ant" << endl;
    cout << "(W)ait" << endl;
    cout << "(Q)uit" << endl;
    cout << "You have " << to_string(player.getAmountOfFood()) << " food." << endl;
}

void buyAnAnt(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard, Player &player){
    string userInput;
    while(true) {
        printBuyOptions(player);
        getline(cin, userInput);
        int isValid = checkIfValidPurchase(tolower(userInput[0]), player);
        if(isValid == 0){
            cout << "You don't have the food for that!" << endl;
        }else if(isValid == 1){
            attemptToPurchase(gameBoard, purchaseAnAnt(tolower(userInput[0])), player);
            return;
        }else if (isValid == 2) {
            return;
        }else{
            cout << "Please Enter one of the following:" << endl;
        }
    }
}

int checkIfValidPurchase(char userInput, Player &player){
    cout << "Checking valid purchase, character sent: " << userInput << endl;
    switch(userInput){
        case('h'):
            return player.getAmountOfFood() >= 2;
        case('t'):
            return player.getAmountOfFood() >= 4;
        case('f'):
            return player.getAmountOfFood() >= 4;
        case('l'):
            return player.getAmountOfFood() >= 3;
        case('s'):
            return player.getAmountOfFood() >= 3;
        case('w'):
            return player.getAmountOfFood() >= 4;
        case('n'):
            return player.getAmountOfFood() >= 6;
        case('b'):
            return player.getAmountOfFood() >= 4;
        case('r'):
            return 2;
        default:
            return 3;
    }
}

Ant* purchaseAnAnt(char antType){
    switch(antType){
        case('h'):
            return new Harverster();
        case('t'):
            return new Thrower();
        case('f'):
            return new Fire();
        case('l'):
            return new LongThrower();
        case('s'):
            return new ShortThrower();
        case('w'):
            return new Wall();
        case('n'):
            return new Ninja();
        case('b'):
            return new BodyGuard();
        case('q'):
            return nullptr;
        default:
            return nullptr;
    }
}

void attemptToPurchase(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard, Ant* ant, Player &player){
    while(true){
        printWholeBoard(gameBoard);
        cout << "Where do you want to place it?" << endl;
        cout << "Enter '0' to return" << endl;
        int placement = getUserInputAsInt(boardSize,0);
        if(placement == 0){
            return;
        }
        if(ant->isPlaceable(gameBoard, placement)){
            ant->setXLocation(placement);
            gameBoard->getReference(placement)->append(ant);
            player.spendFood(ant->getfoodCost());
            cout << "after purchase: " << endl;
            printWholeBoard(gameBoard);
            return;
        }else{
            cout << "You can't place that there!" << endl;
        }
    }
}

void printBuyOptions(Player &player){
    cout << "Which ant do you want to buy?" << endl;
    cout << "Options:" << endl;
    cout << "(H)arvester: A food collector." << endl << "   Armor: 1" << endl << "  Cost: 2 Food." << endl;
    cout << "(T)hrower: Attacks bees on the same square." << endl << "   Armor: 1" << endl << "  Cost: 4 Food." << endl;
    cout << "(F)ire: explodes on death." << endl << "   Armor: 1" << endl << "  Cost: 4 Food." << endl;
    cout << "(L)ong Thrower: Attacks bees up to 4 squares away." << endl << "   Armor: 1" << endl << "  Cost: 3 Food."
        << endl;
    cout << "(S)hort Thrower: Attacks bees up to 2 squares away." << endl << "   Armor: 1" << endl << "  Cost: 3 Food."
        << endl;
    cout << "(W)all: A bee blocking device." << endl << "   Armor: 4" << endl << "  Cost: 4 Food." << endl;
    cout << "(N)inja: Attacks bees from the shadows." << endl << "   Armor: ??" << endl << "  Cost: 6 Food." << endl;
    cout << "(B)odyguard: Protects ants on the same square." << endl << "   Armor: 2" << endl << "  Cost: 4 Food."
        << endl;
    cout << "(R)eturn.";
    cout << "You have " << to_string(player.getAmountOfFood()) << " food." << endl;
}

void printWholeBoard(TotallyNotAVector<TotallyNotAVector<Insect*>>* gameBoard){
    cout << "Board Type: " << gameBoard->getType() << endl;
    for(int i = 0; i < gameBoard->length(); i++){
        auto* nextSquare = gameBoard->getReference(i);
        cout << "(" << to_string(i) << "): " << gameBoard->getType() << endl;
        std::cout << std::to_string(reinterpret_cast<int>(nextSquare)) <<"| ";
        for(int m = 0; m < nextSquare->length(); m++){
            if(m < nextSquare->length() - 1) {
                std::cout << nextSquare->get(m)->toString() << ", ";
            }else{
                std::cout << nextSquare->get(m)->toString();
            }
        }
        std::cout << " |" << endl;
    }
    std::cout << endl;

}