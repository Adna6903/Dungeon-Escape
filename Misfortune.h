

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Team.h"

#include "Player.h"
#include "Merchant.h"
#include "Map.h"
using namespace std;



/** Algorithm:
 * Generate a random number
 * If the number is between 0-40 a misfortune has occured
 * Generate a second random number
 * If that number is between 0 - 30 a robbery has occured
 * If that number is between 31-40 a Weapon has broken
 * If that number is between 41-70 food poinsing and the last player looses 10 fulness points
 * if that number is between is between 70-100 and the team is passing through a room a player has been locked in the last room
*/

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
               
                int currentIngredients = exTeam.getIngredients();

                if (currentIngredients <= 10)
                {
                
                    cout << "Misfortune...all ingredients lost" << endl;
                    exTeam.setIngredients(0);
                }
                else
                {
                     cout << "Misfortune....10 kg ingredients lost" << endl;
                    int newIngredients = currentIngredients - 10;
                    exTeam.setIngredients(newIngredients);
                }
            }
            // Cookware
            if (thirdRandomNumber == 2)
            {
               
                int cookware = exTeam.getCookware().size();
                if (cookware >= 1)
                {
                     cout << "Misfortune...one piece of cookware lost" << endl;
                    exTeam.removeCookwareAt(exTeam.getCookware().size()-1);
                }
            }

            // Armor
            if (thirdRandomNumber == 3)
            {
                
                int armor = exTeam.getArmor().size();
                if (armor >= 1)
                {
                    cout << "Misfortune.....1 piece of armor lost." << endl;
                  exTeam.removeArmorAt(armor - 1);
                }
            }

        } // Robery brace

        // Something Breaks
        if (aSecondRandomNumber > 30 && aSecondRandomNumber <= 40)
        {
           
            int weapons = exTeam.getWeapons().size();

            if (weapons >= 1)
            {
                cout << "A weapon has broken accidentally....." << endl;
                exTeam.removeWeaponsAt(exTeam.getWeapons().size()-1);
            }
        }

        // Food poisioning
        if (aSecondRandomNumber > 40 && aSecondRandomNumber <= 70)
        {
            cout << "Food poisoning.....last player has lost 10 fullness points." << endl;

            int LastPlayer = exTeam.getPlayers().size()-1;
            int currentHelth = exTeam.getPlayers().at(LastPlayer).getFullnessPoints();
            int newHealth = currentHelth - 10;
            exTeam.setPlayerFullnessPointsAt(newHealth,exTeam.getPlayers().size()-1);
        }

        


    }
    
    
    return exTeam;
}