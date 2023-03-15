#include <iostream>
#include "swiss.h"
using namespace std;

//Task 4
Swiss::Swiss(const int numRounds, const PlayerList& list){
    this->numRounds = numRounds;
    this->curRound = 0;
    this->list = list;
    this->list.sort();
    printLeaderboard();
}

Swiss::~Swiss(){
    
}

void Swiss::play(){
    return ;
}