#include <iostream>
#include "player.h"
using namespace std;
//Task One
Player:: Player(const char* const name, const int elo){
    this->name = new char[strlen(name + 1)];
    strcpy(this->name,name);
    this->elo = elo;
    this->score = 0;
}

Player::~Player(){
    delete []name;
}

PlayerList::PlayerList(){
    this->numPlayers = 0;
    this->players = nullptr;
}
PlayerList::PlayerList(const PlayerList& list){
    for(int i = 0 ; i < numPlayers ; i++)
        players[i] = list.getPlayer(i);
}
PlayerList::~PlayerList(){
    for(int i = 0 ; i < numPlayers; i++){
        delete players[i];
    }
    delete []players;
    this->players = nullptr;
}

void PlayerList::addPlayer(Player* const player){ //Error
    if(numPlayers == 0){
    players = new Player*[numPlayers + 1];
    players[numPlayers++] = player;
    }else{ // resize the dynamic array with copy data
        Player** temp = new Player*[numPlayers + 1];
        for(int i = 0 ; i < numPlayers ; i++){
            temp[i] = players[i];
        }
        delete []players;
        temp[numPlayers++] = player;
        players = temp;
    }
}
void PlayerList::sort(){
    for(int i = 0 ; i < numPlayers; i++){
        for(int j = 0 ; j < numPlayers - i - 1 ; j++){
            if(players[j]->getELO() < players[j+1]->getELO())
                swap(players[j],players[j+1]);
        }
    }
    for(int i = 0 ; i < numPlayers; i++){
        for(int j = 0 ; j < numPlayers - i - 1 ; j++){
            if(players[j]->getScore() < players[j+1]->getScore())
                swap(players[j],players[j+1]);
        }
    }
}
PlayerList* PlayerList:: splice(const int startIndex, const int endIndex) const{
    if(startIndex < 0 || endIndex > getNumPlayers() || startIndex >= endIndex){
        PlayerList* newList = new PlayerList(*this);
        return newList;
    }
    else{
        PlayerList* newList = new PlayerList;
        for(int i = startIndex; i <= endIndex ; i++){
            newList->addPlayer(this->players[i]);
        }
    }
}