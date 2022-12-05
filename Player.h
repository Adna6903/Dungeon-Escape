// CSCI 1300 Fall 2022
// Author: Adithya Narayanan & Benjamin E Apelman 
// Recitation: 106 –Chanheum Park (Adithya)
// Recitation: Section 105 – Raegan Rychecky (Benjamin)
// Project 3 

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