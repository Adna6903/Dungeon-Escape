// CSCI 1300 Fall 2022
// Author: Adithya Narayanan
// Recitation: 106 –Chanheum Park
// Author: Benjamin E Apelman 
// Recitation: Section 105 – Raegan Rychecky
// Project 3 Code Skeleton

#include <iostream>
#include "Player.h"


using namespace std;

        Player::Player()
        {
            
            
            fullnessPoints_ = 100;
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