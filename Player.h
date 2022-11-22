// CSCI 1300 Fall 2022
// Author: Adithya Narayanan
// Recitation: 106 –Chanheum Park
// Author: Benjamin E Apelman 
// Recitation: Section 105 – Raegan Rychecky
// Project 3 Code Skeleton

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;


class Player
{
    
private:
            string playerName_;
            int fullnessPoints_;

public:
            Player();
            int getFullnessPoints();
            void setFullnessPoints(int fullnessPoints);
            string getPlayerName();
            void setPlayerName(string playerName);

};


#endif