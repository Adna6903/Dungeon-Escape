// CSCI 1300 Fall 2022
// Author: Adithya Narayanan & Benjamin E Apelman 
// Recitation: 106 –Chanheum Park (Adithya)
// Recitation: Section 105 – Raegan Rychecky (Benjamin)
// Project 3 

#include <iostream>
#include "Player.h"


using namespace std;

        Player::Player()
        {
            
            
            fullnessPoints_ = 50;
            playerName_ = "";


        }


        void Player::setFullnessPoints(int fullnessPoints)
        {

            fullnessPoints_ = fullnessPoints;


        }


        int Player::getFullnessPoints()
        {

                return fullnessPoints_;

        }

        void Player::setPlayerName(string playerName)
        {

            playerName_ = playerName;

        }

        string Player::getPlayerName()
        {

            return playerName_;

        }