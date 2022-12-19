
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Team.h"

#include "Player.h"
#include "Merchant.h"
#include "Monster.h"
#include "split.h"

using namespace std;


/** Algorithm:
 * Generate two random numbers
 * Find a monster with a difficulty coresponding to the number of rooms cleared
 * Warn the user of the monster
 * Calculate the combat score based on two random numbers, the number of weapons/ armor, and the diffuculty of the monster
 * If the user wins erase the monster and there is a chance that they find something
 * If the monster wins erase one of the players
 */


// How to make it so the monster never appears aggain?
// Else brace (wrong answer to riddle)


    
Team attack(Team theTeam, Monster theMonster,Map map)
{
    // Seed random numbers with time
    srand(time(0));

   
    
        // Generate random monster
        string name;
        int challangeRating = 999;
        int random;
        int numberOfRoomsCleared = theTeam.getNumRoomsCleared();

            
       
        while(challangeRating>=numberOfRoomsCleared+2)
        {
             challangeRating = 0; 
             name = "";
             
             random = rand() % theTeam.getMonster().size();


            string array[2];
            string monsterAndRating = theTeam.getMonster().at(random);
            split(monsterAndRating, ',', array, 2);

            challangeRating = stoi(array[1]);

            name = array[0];
          

        }

      

        theMonster.setDifficulty(challangeRating);
        theMonster.setName(name);

    // Anounce the monster
    cout << theMonster.getName() << " ahead! They look hostile!" << endl;

    if (theTeam.getWeapons().size() >=  1&&theTeam.getArmor().size()>0)
    {
        cout << "Would you like to fight the monster? (y/n)" << endl;
        string response;
        cin >> response;

        if(response == "y")
        {
            
    // Count the number of toal weapons
    int toatalWeapons = theTeam.getWeapons().size();

    // Calculate the level of each weapon
    int levelOneWeapons = 0;
    int levelTwoWeapons = 0;
    int levelThreeWeapons = 0;

    for (int i = 0; i < toatalWeapons; i++)
    {

        int weaponLevel = theTeam.getWeapons().at(i).getLevel();

        if (weaponLevel == 1)
        {
            levelOneWeapons++;
        }

        if (weaponLevel == 2)
        {
            levelTwoWeapons++;
        }

        if (weaponLevel == 3)
        {
            levelThreeWeapons++;
        }
    }
    
    // Calculate  "w"
    int weaponsScore = toatalWeapons + levelOneWeapons + (2 * levelTwoWeapons) + (3 * levelThreeWeapons);

    // calculate "d" (if all players weapons are different)

    string weaponOneName = "a";
    string weaponTwoName = "b";
    string weaponThreeName = "c";
    string weaponFourName = "d";

    // This is to avoid a seg fault--if a player has died they have been removed from the vector
    if (toatalWeapons >= 1)
    {
        weaponOneName = theTeam.getWeapons().at(0).getName();
    }
    if (toatalWeapons >= 2)
    {
        weaponTwoName = theTeam.getWeapons().at(1).getName();
    }
    if (toatalWeapons >= 3)
    {
        weaponThreeName = theTeam.getWeapons().at(2).getName();
    }
    if (toatalWeapons >= 4)
    {
        weaponFourName = theTeam.getWeapons().at(3).getName();
    }

    int diffrentWeapons;

    if ((weaponOneName != weaponTwoName && weaponOneName != weaponTwoName && weaponOneName != weaponThreeName && weaponOneName != weaponFourName &&
        weaponTwoName != weaponThreeName && weaponTwoName != weaponFourName &&
        weaponThreeName != weaponFourName)&&theTeam.getWeapons().size()==4)
    {
        diffrentWeapons = 4;
    }
    else
    {
        diffrentWeapons = 0;
    }
   

    int challangeRating = theMonster.getDifficulty();

    // Calcualte "a" (# of sets of armour)
    int setsOfArmor = 0;
    for(int i = 0; i<theTeam.getArmor().size(); i++)
    {
        if(theTeam.getArmor()[i]==1)
        {
            setsOfArmor++;
        }

    }

    // Two random numbers

    int randomNumber1 = (rand() % 6) + 1;
    int randomNumber2 = (rand() % 6) + 1;
    

    // Calcuate the outcome of battle

    // In addition, there is a 10% chance the monster will drop a key. Finally,
    // once a monster is defeated, it will never appear again. Make sure to keep track of what monsters the party has defeated!

    // There is a glitch here where if sets of armor is zero you will be dividing by zero!!!

    double combat = (randomNumber1 * weaponsScore + diffrentWeapons) - ((randomNumber2 * challangeRating) / setsOfArmor);
    

    if (combat > 0)
    {
        cout<<"VICTORY"<<endl;
        // Gold gained (10 * challange rating)
        int currentGold = theTeam.getGold();
        int goldWon = (10 * theMonster.getDifficulty());
        int newGold = currentGold + goldWon;
        theTeam.setGold(newGold);

        // Ingredients gained (5 * challange rating)
        int currentIngredinets = theTeam.getIngredients();
        int ingredientsWon = (5 * theMonster.getDifficulty());
        int newIngredients = currentIngredinets + ingredientsWon;
        theTeam.setIngredients(newIngredients);

        // 10% chance to get a key
        int randomNumber = (rand() % 10) + 1;
        if (randomNumber == 1)
        {
            cout << "You found a key!" << endl;
            int currentKeys = theTeam.getKeys();
            int newKeys = currentKeys + 1;
            theTeam.setKeys(newKeys);
       
       }
       map.removeRoom(map.getPlayerRow(),map.getPlayerCol());
       theTeam.setNumRoomsCleared(theTeam.getNumRoomsCleared()+1);
       
       theTeam.eraseMonsterAt(random);

       theTeam.setNumMonstersDefeated(1);
    }
    
    // If they lose the battle, the party loses a quarter of their gold reserves
    // (rounded down to the nearest integer), up to 30 kg of ingredients, and each party member,
    // excluding the player, independently has an 10% chance of being slain by a monster, but if they are wearing armor,
    // then they only have a 5% chance of being slain. If any party member is slain in the process,
    // the party loses that member.  You should print a message announcing this party member's death.

    else if (combat <= 0)
    {
        cout<<"DEFEAT"<<endl;
        // Party looses 1/4 of their gold
        int goldBeforeDefeat = theTeam.getGold();
        int goldLost = (goldBeforeDefeat * .75);
        int goldRemaining = goldBeforeDefeat - goldLost;
        theTeam.setGold(goldRemaining);

        // Party looses up to 30 kg of ingredients
        int indgredients = theTeam.getIngredients();
        if (indgredients >= 30)
        {
            int indgredientsAfterLoss = indgredients - 30;
            theTeam.setIngredients(indgredientsAfterLoss);
        }
        else if (indgredients < 30)
        {
            theTeam.setIngredients(0);
        }

        // Each player has a 10% chance of death (5% if they are wearing armor)
        int randomNumber = (rand() % (theTeam.getPlayers().size()-1)) + 1;
        theTeam.removePlayer(randomNumber);
       

    } // Defeat brace

        }
    }
    else
    {
        if(theTeam.getWeapons().size()<=0)
        {
        cout << "You don't have any weapons, a player has been captured." << endl;
        }
        else
        {
            cout<<"You don't have any armor, a player has been captured. "<<endl;
        }
        int index = theTeam.getPlayers().size()-1;
        theTeam.removePlayer(index);
        

        // 50% chance of loosing one fullness point
        int minusOneHP = rand() % 2 + 1;
        if (minusOneHP == 1)
        {
            cout << "Each player has lost one fulness point" << endl;
            for(int i = 0; i<theTeam.getPlayers().size(); i++)
            {
                theTeam.setPlayerFullnessPointsAt(theTeam.getPlayers().at(i).getFullnessPoints()- 1,i);
            }
        }
       
    }
   
    return theTeam;
}