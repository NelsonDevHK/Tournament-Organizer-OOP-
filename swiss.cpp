#include <iostream>
#include "swiss.h"
using namespace std;

//Task 4
Swiss::Swiss(const int numRounds, const PlayerList& list){
    this->numRounds = numRounds;
    this->curRound = 0;
    this->list = list;
    this->list.sort();
}

Swiss::~Swiss(){
    
}

void Swiss::play(){
    for(int i = 0 ; i < numRounds; i++){
        
    }
    return ;
}