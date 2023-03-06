#include <iostream>
#include "player.h"
using namespace std;

Player:: Player(const char* const name, const int elo){
    this->name = new char[strlen(name +1)];
    strcpy(this->name,name);
    this->elo = elo;
    this->score = 0;
}

Player::~Player(){

}