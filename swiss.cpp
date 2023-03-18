#include <iostream>
#include "swiss.h"
#include "match.h"
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
void Swiss::print(){
    cout << "Here"<< endl;
}
void Swiss::play(){ //recursive function
    //Create array of list that contain all possible score
    PlayerList* list_AllScore = new PlayerList[(numRounds*2) -1 ];
    for(curRound = 1 ; curRound <= numRounds; curRound++){
        int possibleScore = 2* curRound - 1;
        cout << "curRound" << curRound << endl;
        if(possibleScore == 1){
            for(int i = 0 ; i < list.getNumPlayers(); i++)
                list_AllScore[0].addPlayer(list.getPlayer(i));
            int middleIndex = list_AllScore[0].getNumPlayers() / 2;
            for(int j = 0 ; j < middleIndex; j++){
                Player* p1 = list_AllScore[0].getPlayer(j);        
                Player* p2 = list_AllScore[0].getPlayer(middleIndex + j);
                Match m(p1,p2);
                m.play();
                }
            list.sort();
            printLeaderboard();
            continue;
            } else if (possibleScore > 1) {
               list.sort();
               int i = 0;
                int firstPlayerPos = 0;
               while (i < possibleScore) {
                   int score = list.getPlayer(firstPlayerPos)->getScore();
                int playerIndex = firstPlayerPos;
                   while (playerIndex + 1 < list.getNumPlayers()
                    && list.getPlayer(playerIndex)->getScore() == list.getPlayer(playerIndex + 1)->getScore()) {
                       playerIndex++;
                   }
                   if (playerIndex % 2 == 0) {//position
                    if(firstPlayerPos != 0)
                        firstPlayerPos--;
                       list_AllScore[score] = (*list.splice(firstPlayerPos, playerIndex));
                       firstPlayerPos = playerIndex + 1;
                       i++;
                       continue;
                   }\
                   list_AllScore[score] = (*list.splice(firstPlayerPos, playerIndex));
                   firstPlayerPos += playerIndex+1;
                   if (score == 0 && playerIndex % 2 != 0) {
                       // last element edge case
                       list.getPlayer(list.getNumPlayers() - 1)->addScore(2);
                   }
                   i++;
                }
            }
    for(int i = possibleScore - 1 ; i >= 0 ; i--){
        if(list_AllScore[i].getNumPlayers() == 0) //edge case player no exist in score elo
            continue;
        int middleIndex = list_AllScore[i].getNumPlayers() / 2;
    //    cout << "Line 75: " << possibleScore << endl;
    //    cout << "Line 76: " << i << endl;
        for(int j = 0 ; j < middleIndex; j++){
    //    list_AllScore[i].getPlayer(j)->print();
    //    cout << endl;
    //    list_AllScore[i].getPlayer(middleIndex + j)->print();
    //    cout << endl;
        Player* p1 = list_AllScore[i].getPlayer(j);        
        Player* p2 = list_AllScore[i].getPlayer(middleIndex + j);
        Match m(p1,p2);
        m.play();
        }
    }
    list.sort();
        printLeaderboard();
    //delete []list_AllScore;
}
}