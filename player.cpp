#include <iostream>
#include <cstring>
#include "player.h"
using namespace std;
//Task One
Player:: Player(const char* const name, const int elo){
    this->name = new char[strlen(name) + 1];
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
    numPlayers = list.getNumPlayers();
    players = new Player*[numPlayers];
    for(int i = 0 ; i < numPlayers ; i++)
        players[i] = list.players[i];
}

PlayerList::~PlayerList(){
    delete []players;
}


void PlayerList::addPlayer(Player* const player){
    Player **temp = new Player *[numPlayers + 1];

    int x = 0;
    while(x < numPlayers)
    {
        temp[x] = this->players[x];
        x++;
    }

    temp[numPlayers] = player;

    numPlayers += 1;

    delete[] players;
    players = temp;
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

PlayerList* PlayerList::splice(const int startIndex, const int endIndex) const {
    if (startIndex < 0 || endIndex > numPlayers || startIndex >= endIndex) {
        PlayerList* defaultList = new PlayerList();
        return defaultList;
    }

    PlayerList* temp = new PlayerList();
    temp->numPlayers = endIndex - startIndex + 1;
    temp->players = new Player*[temp->numPlayers];

    for (int i = 0 ; i <= temp->numPlayers ; i++) {
        temp->players[i] = this->players[i + startIndex];
    }

    return temp;
}
