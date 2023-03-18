#include <iostream>
#include "swiss.h"
#include "match.h"
using namespace std;

// Task 4
Swiss::Swiss(const int numRounds, const PlayerList &list)
{
    this->numRounds = numRounds;
    this->curRound = 0;
    this->list = list;
    this->list.sort();
}

Swiss::~Swiss()
{
}
void Swiss::print()
{
    cout << "Here" << endl;
}
void Swiss::play()
{ // recursive function
    // Create array of list that contain all possible score
    PlayerList *list_AllScore = new PlayerList[(numRounds * 2) - 1];
    for (curRound = 1; curRound <= numRounds; curRound++)
    {

        int playCount = 0;
        int possibleScore = 2 * curRound - 1;
        if (possibleScore == 1)
        {
            for (int i = 0; i < list.getNumPlayers(); i++)
                list_AllScore[0].addPlayer(list.getPlayer(i));
            int middleIndex = list_AllScore[0].getNumPlayers() / 2;
            for (int j = 0; j < middleIndex; j++)
            {
                Player *p1 = list_AllScore[0].getPlayer(j);
                Player *p2 = list_AllScore[0].getPlayer(middleIndex + j);
                Match m(p1, p2);
                m.play();
                playCount++;
            }
            if (list.getNumPlayers() % 2 != 0 && playCount == list.getNumPlayers() / 2)
            {
                list.sort();
                list.getPlayer(list.getNumPlayers() - 1)->addScore(2);
            }
            list.sort();
            printLeaderboard();
            continue;
        }
        else if (possibleScore > 1)
        {
            list.sort();
            for (int i = possibleScore; i >= 0; i--)
            {
                if (list_AllScore[i].getNumPlayers() > 0)
                    list_AllScore[i] = (*list_AllScore[i].splice(-1, 0));
            }
            for (int i = 0; i < list.getNumPlayers(); i++)
            {
                int score = list.getPlayer(i)->getScore();
                if (i + 1 < list.getNumPlayers() && list.getPlayer(i)->getScore() != list.getPlayer(i + 1)->getScore() && i % 2 == 0)
                {
                    list_AllScore[list.getPlayer(i + 1)->getScore()].addPlayer(list.getPlayer(i));
                    continue;
                }
                list_AllScore[score].addPlayer(list.getPlayer(i));
                continue;
            }
            for (int i = possibleScore - 1; i >= 0; i--)
            {
                if (list_AllScore[i].getNumPlayers() == 0) // edge case player no exist in score elo
                    continue;
                int middleIndex = list_AllScore[i].getNumPlayers() / 2;
                for (int j = 0; j < middleIndex; j++)
                {
                    Player *p1 = list_AllScore[i].getPlayer(j);
                    Player *p2 = list_AllScore[i].getPlayer(middleIndex + j);
                    Match m(p1, p2);
                    m.play();
                    playCount++;
                    cout << playCount << endl;
                }
            }
            if (list.getNumPlayers() % 2 != 0 && playCount == list.getNumPlayers() / 2)
            {
                list.sort();
                list.getPlayer(list.getNumPlayers() - 1)->addScore(2);
            }
            list.sort();
            printLeaderboard();
        }
    }
    delete[] list_AllScore;
}