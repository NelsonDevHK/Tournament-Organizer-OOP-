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
        }else if(possibleScore > 1){//add element the array of possible score as curround increase
            delete []list_AllScore;
            list.sort();

        cout << "PScore :"<< possibleScore << endl;
            for(int i = 0 ; i < list.getNumPlayers(); i++){
                int playerCount = 0;
                int score = list.getPlayer(i)->getScore();
                //////////////////// BUuuUUUUUUUUUUUUUUUUUUUUUUUUUUUUG  /////////////
            cout << "FUCK :"<< list_AllScore[i].getNumPlayers() << endl;
            cout << "FUCK :"<< score << endl;
            list_AllScore[i].getPlayer(playerCount)->getScore();
                while (list_AllScore[i].getPlayer(playerCount)->getScore() == list_AllScore[i].getPlayer(playerCount + 1)->getScore())
                    playerCount++;
                if(playerCount % 2 != 0)
                    playerCount++;
                list_AllScore[score] = (*list.splice(i,playerCount));
            }
        }

// for(int i = 0 ; i < possibleScore; i++){
//     int middleIndex = list_AllScore[i].getNumPlayers()/2 ;
//         int playerCount = 0;
//         print();
//         while (list_AllScore[i].getPlayer(playerCount)->getScore() == list_AllScore[i].getPlayer(playerCount + 1)->getScore()){
//             playerCount++;
//         print();
//         }
//         playerCount++;
//         list_AllScore[i+1] = (*list_AllScore[i].splice(i,playerCount));
// }

    for(int i = possibleScore - 1 ; i >= 0 ; i--){
        if(list_AllScore[i].getNumPlayers() == 0) //edge case player no exist in score elo
            continue;
        int middleIndex = list_AllScore[i].getNumPlayers() / 2;
        cout << "PScore :"<< possibleScore << endl;
        cout << "Any :"<< middleIndex << endl;
        cout << "FUCK :"<< list_AllScore[i].getNumPlayers() << endl;

        for(int j = 0 ; j < middleIndex; j++){
                print();
        Player* p1 = list_AllScore[i].getPlayer(j);        
        Player* p2 = list_AllScore[i].getPlayer(middleIndex + j);
        Match m(p1,p2);
        m.play();
        }
    }

}
}