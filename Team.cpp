// CSCI 1300 Fall 2022
// Author: Adithya Narayanan & Benjamin E Apelman 
// Recitation: 106 –Chanheum Park (Adithya)
// Recitation: Section 105 – Raegan Rychecky (Benjamin)
// Project 3 

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

   armor_ = {};

   hasPlayerGivenUp = false;

   mainPlayerName_ = players_.at(0).getPlayerName();

   spacesExplored_ = 0;

   numMonstersDefeated_ = 0;

   turnsElapsed_ = 0;


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

bool Team::getGiveUp()
{
    return hasPlayerGivenUp;
}

int Team::getPotions()
{
    return potions_;
}

vector<string> Team::getMonster()
{
    return listOfMonsters_;
}

vector<string> Team::getRiddle()
{
    return listOfRiddles_;
}

string Team::getMainPlayerName()
{
    return mainPlayerName_;
}

int Team::getSpacesExplored()
{
    return spacesExplored_;
}

int Team::getNumMonstersDefeated()
{
    return numMonstersDefeated_;
}

int Team::getNumTurnsElapsed()
{
    return turnsElapsed_;
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
    for(int i = 0; i<weapons.size();i++)
    {
        weapons_.push_back(weapons.at(i));
    }
    
    
    // for(int i = 0; i < weapons_.size()-1;)
    // {
    //     for(int i = 0; i<weapons_.size()-1; i++)
    //     {
    //         if(weapons_.at(i).getLevel() > weapons_.at(i+1).getLevel())
    //         {
    //             vector<Weapons> temp;
    //             temp.at(i) = weapons_.at(i);
    //             weapons_.at(i) = weapons_.at(i+1);
    //             weapons_.at(i+1) = temp.at(i);

    //         }
    //     }
    // }
       
    
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

void Team::removeWeaponsAt(int index)
{

    weapons_.erase(weapons_.begin()+index);

}

void Team::setGiveUp(bool isGiveUp)
{
    hasPlayerGivenUp = isGiveUp;
}

void Team::removeArmorAt(int index)
{
    armor_.erase(armor_.begin()+index);
}

void Team::setPotions(int potions)
{
    potions_ = potions;
}

void Team::setRiddles(vector<string> listOfRiddles)
{
    listOfRiddles_ = listOfRiddles;
}

void Team::setMonsters(vector<string> listOfMonsters)
{
    listOfMonsters_ = listOfMonsters;
}

void Team::eraseMonsterAt(int index)
{
    listOfMonsters_.erase(listOfMonsters_.begin()+index);
}

void Team::eraseRiddleAt(int index)
{
    listOfRiddles_.erase(listOfRiddles_.begin()+index);
}

void Team::clearPlayers()
{

int playerSize = players_.size();

    for(int i = 0; !players_.empty(); i++)
    {
        players_.pop_back();
    }
}

void Team::setSpacesExplored(int spaces)
{
    spacesExplored_ = spacesExplored_ + spaces;
}

void Team::setNumMonstersDefeated(int numMonsters)
{
    numMonstersDefeated_ = numMonstersDefeated_ + numMonsters;
}

void Team::setTurnsElapsed(int turns)
{
    turnsElapsed_ = turnsElapsed_ + turns;
}