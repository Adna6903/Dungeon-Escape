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

#include "Map.h"
using namespace std;

Team misfortune(Team exTeam, Map exMap)
{
    srand(time(0));
    int aRandomNumber = rand() % 100 + 1;

    // 40 % chance of misfortune:
    if (aRandomNumber > 0 && aRandomNumber <= 40)
    {
        int aSecondRandomNumber = rand() % 100 + 1;

        // Robery
        if (aSecondRandomNumber > 0 && aSecondRandomNumber <= 30)
        {
            cout << "You have been robbed!"<<endl;
            int thirdRandomNumber = rand() % 3 + 1;

            // ingredients
            if (thirdRandomNumber == 1)
            {
                cout << "Misfortune: loose 10 kg ingredients." << endl;
                int currentIngredients = exTeam.getIngredients();

                if (currentIngredients <= 10)
                {
                    exTeam.setIngredients(0);
                }
                else
                {
                    int newIngredients = currentIngredients - 10;
                    exTeam.setIngredients(newIngredients);
                }
            }
            // Cookware
            if (thirdRandomNumber == 2)
            {
                cout << "Misfortune: loose 1 piece of cookware." << endl;
                int cookware = exTeam.getCookware().size();
                if (cookware >= 1)
                {
                    exTeam.getCookware().pop_back();
                }
            }

            // Armor
            if (thirdRandomNumber == 3)
            {
                cout << "Misfortune: loose 1 piece of armor." << endl;
                int armor = exTeam.getArmor().size();
                if (armor >= 1)
                {
                    exTeam.getArmor().pop_back();
                }
            }

        } // Robery brace

        // Something Breaks
        if (aSecondRandomNumber > 30 && aSecondRandomNumber <= 40)
        {
            cout << "A weapon has broken!" << endl;
            int weapons = exTeam.getWeapons().size();

            if (weapons >= 1)
            {
                exTeam.getWeapons().pop_back();
            }
        }

        // Food poisioning
        if (aSecondRandomNumber > 40 && aSecondRandomNumber <= 70)
        {
            cout << "Food poisioning! Loose 10 fullness points." << endl;

            int LastPlayer = exTeam.getPlayers().size()-1;
            int currentHelth = exTeam.getPlayers().at(LastPlayer).getFullnessPoints();
            int newHealth = currentHelth - 10;
            exTeam.getPlayers().at(LastPlayer).setFullnessPoints(newHealth);
        }

        //Player locked in previous room
        if(aSecondRandomNumber > 70 && aSecondRandomNumber <= 100 && exMap.isRoomLocation(exMap.getNumRows(), exMap.getNumCols(), exTeam) == true)
        {
            cout << "A player has been locked in the previous room" << endl;
            exTeam.getPlayers().pop_back();
        }


    }
    return exTeam;
}