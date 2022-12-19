
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