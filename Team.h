

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

    string mainPlayerName_;

    int numRoomsCleared_;

    int sorcererAngerLevel_;

    vector<Weapons> weapons_; // Should we make a weapons class and make this an vector of objects?

    vector<string> treasures_;

    int keys_;

    int gold_;

    vector<string> cookware_; // Change this to a vecotr of class objects?

    int ingredients_;

    vector<int> armor_;

    bool hasPlayerGivenUp;

    int potions_;

     vector<string> listOfRiddles_;

    vector<string> listOfMonsters_;

    int spacesExplored_;

    int numMonstersDefeated_;

    int turnsElapsed_;



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
    bool getGiveUp();
    int getPotions();
     vector<string>getMonster();
    vector<string>getRiddle();
    string getMainPlayerName();
    int getSpacesExplored();
    int getNumMonstersDefeated();
    int getNumTurnsElapsed();
    

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
    void setGiveUp(bool isGiveUp);
    void removeArmorAt(int index);
    void setPotions(int potions);
    void setRiddles(vector<string> listOfRiddles);
    void setMonsters(vector<string> listOfMonsters);
    void eraseRiddleAt(int index );
    void eraseMonsterAt(int index);
    void clearPlayers();
    void setSpacesExplored(int spaces);
    void setNumMonstersDefeated(int numMonsters);
    void setTurnsElapsed(int turns);


    //Universal setter
   
};

#endif
