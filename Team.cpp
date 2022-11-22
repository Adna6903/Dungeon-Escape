// CSCI 1300 Fall 2022
// Author: Adithya Narayanan
// Recitation: 106 –Chanheum Park
// Author: Benjamin E Apelman 
// Recitation: Section 105 – Raegan Rychecky
// Project 3 Code Skeleton

#include <iostream>
#include <vector>
#include "Team.h"
#include "Player.h"

using namespace std;
vector <Player> Team::getPlayers()
{
    return players_;
}


Team::Team(vector <Player> players)
{
   for(int i = 0; i< players.size(); i++)
   {
    players_.push_back(players[i]);
   }
   numRoomsCleared_ = 0;

   sorcererAngerLevel_ = 0;

   Weapons weapons_; 

   treasures_ = {};

   keys_ = 0;

   gold_ = 100;

   cookware_ = {};

   ingredients_ = 0;

   armor_ = {0,0,0,0,0};


}

// Getters:

int Team::getNumRoomsCleared()
{

    return numRoomsCleared_;
}

int Team::getSorcererAngerLevel()
{

    return sorcererAngerLevel_;
}

vector<Weapons> Team::getWeapons()
{

    return weapons_;
}

vector<string> Team::getTreasures()
{
    return treasures_;
}

int Team::getKeys()
{
    return keys_;
}

int Team::getGold()
{
    return gold_;
}

vector<string> Team::getCookware()
{
    return cookware_;
}

int Team::getIngredients()
{
    return ingredients_;
}

vector<int> Team::getArmor()
{
    return armor_;
}

// Setters:

void Team::setSorcererAngerLevel(int sorcererAngerLevel)
{

    sorcererAngerLevel_ = sorcererAngerLevel;
}

void Team::setNumRoomsCleared(int numRoomsCleared)
{

    numRoomsCleared_ = numRoomsCleared;
}

void Team::removePlayer(int index)
{

    players_.erase(players_.begin()+index);
}

void Team::setWeapons(vector<Weapons> weapons)
{

    for (int i = 0; i < weapons.size(); i++)
    {
        weapons_.push_back(weapons[i]);
    }
}

void Team::setTreasures(vector<string> treasures)
{
     for (int i = 0; i < treasures.size(); i++)
    {
        treasures_.push_back(treasures[i]);
    }

}

void Team::setKeys(int keys)
{
    keys_ = keys;
}

void Team::setGold(int gold)
{
    gold_ = gold;
}

void Team::setCookware(vector<string> cookware)
{
    for (int i = 0; i < cookware.size(); i++)
    {
        cookware_.push_back(cookware[i]);
    }

}

void Team::setIngredients(int ingredients)
{
    ingredients_ = ingredients;
}

void Team::setArmor(vector<int> armor)
{
    for (int i = 0; i < armor.size(); i++)
    {
        armor_.push_back(armor[i]);
    }
}

void Team::removeTreasureAt(int index)
{

    treasures_.erase(treasures_.begin()+index);

}

void Team::setPlayerFullnessPointsAt(int fullnessPoints,int index)
{



    players_.at(index).setFullnessPoints(fullnessPoints);



}

void Team::removeCookwareAt(int index)
{

       cookware_.erase(cookware_.begin()+index);


}