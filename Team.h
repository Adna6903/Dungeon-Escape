// CSCI 1300 Fall 2022
// Author: Adithya Narayanan
// Recitation: 106 –Chanheum Park
// Author: Benjamin E Apelman 
// Recitation: Section 105 – Raegan Rychecky
// Project 3 Code Skeleton

#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <vector>

#include "Player.h"
#include "Weapons.h"

using namespace std;

class Team

{

private:
    
    vector<Player> players_;

    int numRoomsCleared_;

    int sorcererAngerLevel_;

    vector<Weapons> weapons_; // Should we make a weapons class and make this an vector of objects?

    vector<string> treasures_;

    int keys_;

    int gold_;

    vector<string> cookware_; // Change this to a vecotr of class objects?

    int ingredients_;

    vector<int> armor_;

public:

    
    // parameterized Constructor:
    Team(vector <Player> players);

    // Getters:

    int getNumRoomsCleared();
    int getSorcererAngerLevel();
    vector<Weapons> getWeapons();
    vector<string> getTreasures();
    int getKeys();
    int getGold();
    vector<string> getCookware();
    int getIngredients();
    vector<int> getArmor();
    vector <Player> getPlayers();

    // Setters:
   
    void setNumRoomsCleared(int numRoomsCleared);
    void setSorcererAngerLevel(int sorcererAngerLevel);
    void removePlayer(int index);
    void setWeapons(vector<Weapons> weapons);
    void setTreasures(vector<string> treasures);
    void setKeys(int keys);
    void setGold(int gold);
    void setCookware(vector<string> cookware);
    void setIngredients(int ingredients);
    void setArmor(vector<int> armor);
    void removeTreasureAt(int index);
    void setPlayerFullnessPointsAt(int fullnessPoints,int index);
    void removeCookwareAt(int index);
    void removeWeaponsAt(int index);

    //Universal setter
   
};

#endif
