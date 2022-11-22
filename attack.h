#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Team.h"
#include "Weapons.h"
#include "Player.h"
#include "Merchant.h"
#include "Monster.h"
#include "split.h"

using namespace std;





// How to make it so the monster never appears aggain?
// How to adjust the playesr fulness points mid function?
Monster getRandomMonster(int numLevelsCleared,Team exTeam)
{
       ifstream monstersText;

        monstersText.open("Monsters.txt");
        if (monstersText.fail())
        {
            cout << "Failed to open Monsters.txt." << endl;
        }

        // Vectors to store the name and difficulty
        vector<string> monsterName;
        vector<int> monsterRating;

        // Variables used to process the text file
        string line = "";
        string lineSegment[2];
        


        // Read the file and pass it into the vectors
        while (getline(monstersText, line))
        {
            
            split(line, ',', lineSegment, 2);

            monsterName.push_back(lineSegment[0]);
            monsterRating.push_back(stoi(lineSegment[1]));

            lineSegment[0] = "";
            lineSegment[1] = "";
        }

        // Generate random monster
        string name;
        int challangeRating = 999;
        int random;
        int numberOfRoomsCleared = exTeam.getNumRoomsCleared();

       
        while(challangeRating>=numLevelsCleared+2)
        {
             challangeRating = 0; 
             name = "";
             
             random = rand() % 21;

            challangeRating = monsterRating.at(random);
            name = monsterName.at(random);
          

        }
        // while (challangeRating >= numberOfRoomsCleared)
        // {
        //     random = rand() % 21;

        //     challangeRating = monsterRating.at(random);
        //     name = monsterName.at(random);
        // }

        Monster randomMonster;

        randomMonster.setDifficulty(challangeRating);
        randomMonster.setName(name);

        return randomMonster;
    } // Else brace (wrong answer to riddle)


    
Team attack(Team theTeam, Monster theMonster)
{
    // Seed random numbers with time
    srand(time(0));

    // Anounce the monster
    cout << theMonster.getName() << " ahead! They look hostile!" << endl;

    if (theTeam.getWeapons().size() >=  1)
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
        int randomNumber = (rand() % 100) + 1;
        double peicesOfArmor = theTeam.getArmor().size();

        if (peicesOfArmor == 0)
        {

            if (randomNumber1 > 10 && randomNumber1 <= 20)
            {
                cout << "Player one has died!" << endl;
                theTeam.removePlayer(0);
            }
            if (randomNumber1 > 20 && randomNumber1 <= 30)
            {
                cout << "Player two has died!" << endl;
                theTeam.removePlayer(1);
            }
            if (randomNumber1 > 30 && randomNumber1 <= 40)
            {
                cout << "Player three has died!" << endl;
                theTeam.removePlayer(2);
            }
            if (randomNumber1 > 40 && randomNumber1 <= 50)
            {
                cout << "Player four has died!" << endl;
                theTeam.removePlayer(3);
            }
        }
        else if (peicesOfArmor == 1)
        {

            if (randomNumber1 > 10 && randomNumber1 <= 20)
            {
                cout << "Player one has died!" << endl;
                theTeam.removePlayer(0);
            }
            if (randomNumber1 > 20 && randomNumber1 <= 30)
            {
                cout << "Player two has died!" << endl;
                theTeam.removePlayer(1);
            }
            if (randomNumber1 > 30 && randomNumber1 <= 40)
            {
                cout << "Player three has died!" << endl;
                theTeam.removePlayer(2);
            }
            if (randomNumber1 > 40 && randomNumber1 <= 50)
            {
                cout << "Player four has died!" << endl;
                theTeam.removePlayer(3);
            }
        }
        else if (peicesOfArmor == 2)
        {

            if (randomNumber1 > 10 && randomNumber1 <= 15)
            {
                cout << "Player one has died!" << endl;
                theTeam.removePlayer(0);
            }
            if (randomNumber1 > 20 && randomNumber1 <= 30)
            {
                cout << "Player two has died!" << endl;
                theTeam.removePlayer(1);
            }
            if (randomNumber1 > 30 && randomNumber1 <= 40)
            {
                cout << "Player three has died!" << endl;
                theTeam.removePlayer(2);
            }
            if (randomNumber1 > 40 && randomNumber1 <= 50)
            {
                cout << "Player four has died!" << endl;
                theTeam.removePlayer(3);
            }
        }
        else if (peicesOfArmor == 3)
        {

            if (randomNumber1 > 10 && randomNumber1 <= 15)
            {
                cout << "Player one has died!" << endl;
                theTeam.removePlayer(0);
            }
            if (randomNumber1 > 20 && randomNumber1 <= 25)
            {
                cout << "Player two has died!" << endl;
                theTeam.removePlayer(1);
            }
            if (randomNumber1 > 30 && randomNumber1 <= 40)
            {
                cout << "Player three has died!" << endl;
                theTeam.removePlayer(2);
            }
            if (randomNumber1 > 40 && randomNumber1 <= 50)
            {
                cout << "Player four has died!" << endl;
                theTeam.removePlayer(3);
            }
        }
        else if (peicesOfArmor == 4)
        {

            if (randomNumber1 > 10 && randomNumber1 <= 15)
            {
                cout << "Player one has died!" << endl;
                theTeam.removePlayer(0);
            }
            if (randomNumber1 > 20 && randomNumber1 <= 25)
            {
                cout << "Player two has died!" << endl;
                theTeam.removePlayer(1);
            }
            if (randomNumber1 > 30 && randomNumber1 <= 35)
            {
                cout << "Player three has died!" << endl;
                theTeam.removePlayer(2);
            }
            if (randomNumber1 > 40 && randomNumber1 <= 50)
            {
                cout << "Player four has died!" << endl;
                theTeam.removePlayer(3);
            }
        }
        else if (peicesOfArmor == 5)
        {

            if (randomNumber1 > 10 && randomNumber1 <= 15)
            {
                cout << "Player one has died!" << endl;
                theTeam.removePlayer(0);
            }
            if (randomNumber1 > 20 && randomNumber1 <= 25)
            {
                cout << "Player two has died!" << endl;
                theTeam.removePlayer(1);
            }
            if (randomNumber1 > 30 && randomNumber1 <= 35)
            {
                cout << "Player three has died!" << endl;
                theTeam.removePlayer(2);
            }
            if (randomNumber1 > 40 && randomNumber1 <= 45)
            {
                cout << "Player four has died!" << endl;
                theTeam.removePlayer(3);
            }
        }

    } // Defeat brace

        }
    }
    else
    {
        cout << "You don't have any weapons, a player has been captured." << endl;
        int index = theTeam.getPlayers().size();
        theTeam.removePlayer(index);
        

        // 50% chance of loosing one fullness point
        int minusOneHP = rand() % 2 + 1;
        if (minusOneHP == 1)
        {
            // Need a function in team to adjuest the fullnes point of a player
        }
        else if (minusOneHP == 2)
        {

        }
    }
   
    return theTeam;
}