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
    PlayerList* list_AllScore = new PlayerList[1];
    for(curRound ; curRound <= numRounds; curRound++){
        int possibleScore = 2* curRound - 1;
        if(possibleScore == -1){
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
        }else{// dynamic resize the array of possible score as curround increase
            PlayerList* tempList = new PlayerList[possibleScore];
                for(int i = 0 ; i < (possibleScore-1)/2 ; i++)
                    tempList[i] = list_AllScore[i];
            print();
                delete []list_AllScore;
                list_AllScore = tempList;
        }


    for(int i = possibleScore ; i >= 0 ; i--){
        if(list_AllScore[i].getNumPlayers() == 0) //edge case player no exist in score elo
            continue;
        int middleIndex = list_AllScore[i].getNumPlayers() / 2;
        if(middleIndex % 2 != 0){// odd number case reorder list first
            list.sort();
            int playerCount = 0;
            while (list_AllScore[i].getPlayer(playerCount)->getScore() != list_AllScore[i].getPlayer(playerCount + 1)->getScore())
                playerCount++;
            list_AllScore[i+1] = (*list_AllScore[i].splice(i,playerCount));
        }
        for(int j = 0 ; j < middleIndex; j++){
        Player* p1 = list_AllScore[i].getPlayer(j);        
        Player* p2 = list_AllScore[i].getPlayer(middleIndex + j);
        Match m(p1,p2);
        m.play();
        }
    }

}
}