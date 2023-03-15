#include <iostream>
#include "player.h"
using namespace std;
//Task One
Player:: Player(const char* const name, const int elo){
    this->name = new char[strlen(name + 1)];
    strcpy(this->name,name);
    this->elo = elo;
    this->score = 0;
    cout << this->name;
    cout << this->elo;
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

void PlayerList::addPlayer(Player* const player){ //Erro
    this->players[numPlayers++] = player;
}
void PlayerList::sort(){
    for(int i = 0 ; i < numPlayers; i++){
        for(int j = 0 ; j < numPlayers - i ; j++){
            if(players[i]->getScore() <= players[j+1]->getScore()){
                if(players[i]->getELO() <= players[j+1]->getELO())
            swap(players[i],players[j+1]);
            }
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