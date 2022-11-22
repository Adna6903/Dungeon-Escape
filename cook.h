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

using namespace std;

// If you have ingredients, you can choose to cook the ingredients into a meal. When cooking,
// prompt the player to select which cookware item they want to use,
// as well as how many kg of ingredients they want to cook in increments of 5 kg.
// There is a 5:1 ratio between kg of ingredients, and amount of fullness increased by a successfully cooked meal.
// See Cookware above to learn the chance of a successful cook.
// If the cookware breaks while trying to cook, then the meal is not created,
// the ingredients are lost, and the cookware is removed from the player inventory.
// A message should be shown to the player to let them know their cook failed.
// If the cook is successful, display a message to the user telling them so.
// After either a successful or unsuccessful cook, display the fullness levels of each party member,
// as well as the remaining number of kg of food.
// Note: The people in your party share meals, and the fullness level will increase by the same amount for each person.
// For example, if you cook a meal with 5 kg of food, then each person's fullness will increase by 1.

Team cooking(Team exTeam)
{
    srand(time(0));

    string response;
    if (exTeam.getCookware().size() >= 1 && exTeam.getIngredients() >= 5)
    {
        cout << "Would you like to you to cook to restore a players health? (y/n) " << endl;
        cin >> response;
    }

    int ingredientsUsed;

    if (response == "y")
    {
        // Amount of ingredients to use
        cout << "How much food would you like to cook? Enter a multiple of 5kg. " << endl;

        cin >> ingredientsUsed;

        while (ingredientsUsed % 5 != 0)
        {
            cout << "Please enter a multible of 5 Kg" << endl;
            cin >> ingredientsUsed;
        }

        int indexOfCookwareUsed = 0;

        // Which peice of cookware to use
        if (exTeam.getCookware().size() > 1)
        {
            cout << "What do you want to use to cook your food? ";
            for (int i = 0; i < exTeam.getCookware().size(); i++)
            {
                cout << i << ") " << exTeam.getCookware().at(i) << " ";
            }
            cin >> indexOfCookwareUsed;
        }
        else
        {
            cout << "You only have one piece of cookware the " << exTeam.getCookware().at(0) << " enter 0 to use" << endl;
            cin >> indexOfCookwareUsed;
        }
        while (indexOfCookwareUsed > exTeam.getCookware().size() || indexOfCookwareUsed < 0)
        {
            cout << "Invalid input. Try again." << endl;
            cin >> indexOfCookwareUsed;
        }

        string cookwareUsed = exTeam.getCookware().at(indexOfCookwareUsed);
        int randomNumber = rand() % 100 + 1;

        if (cookwareUsed == "Ceramic Pot")
        {
            if (randomNumber > 0 & randomNumber <= 25)
            {
                cout << "The Ceramic Pot is broken!" << endl;
                exTeam.removeCookwareAt(indexOfCookwareUsed);
                return exTeam;
            }
            else
            {
                cout << "Each players health has been increaed by " << ingredientsUsed / 5 << endl;
                for (int i = 0; i < exTeam.getPlayers().size(); i++)
                {
                    int currentFullness = exTeam.getPlayers().at(i).getFullnessPoints();
                    int fulnessAdded = ingredientsUsed / 5;
                    int newFullness = currentFullness + fulnessAdded;
                    exTeam.setPlayerFullnessPointsAt(newFullness,i);
                }
            }
        }
        else if (cookwareUsed == "Frying Pan")
        {
            if (randomNumber > 25 & randomNumber <= 35)
            {
                cout << "The Frying Pan is broken!" << endl;
                exTeam.removeCookwareAt(indexOfCookwareUsed);
                return exTeam;
            }
            else
            {
                cout << "Each players health has been increaed by " << ingredientsUsed / 5 << endl;
                for (int i = 0; i < exTeam.getPlayers().size(); i++)
                {
                    int currentFullness = exTeam.getPlayers().at(i).getFullnessPoints();
                    int fulnessAdded = ingredientsUsed / 5;
                    int newFullness = currentFullness + fulnessAdded;
                    exTeam.setPlayerFullnessPointsAt(newFullness,i);
                }
            }
        }
        else if (cookwareUsed == "Cauldron")
        {
            if (randomNumber > 35 & randomNumber <= 37)
            {
                cout << "The Cauldron is broken!" << endl;
                exTeam.removeCookwareAt(indexOfCookwareUsed);
                return exTeam;
            }
            else
            {
                cout << "Each players health has been increaed by " << ingredientsUsed / 5 << endl;
                for (int i = 0; i < exTeam.getPlayers().size(); i++)
                {
                    int currentFullness = exTeam.getPlayers().at(i).getFullnessPoints();
                    int fulnessAdded = ingredientsUsed / 5;
                    int newFullness = currentFullness + fulnessAdded;
                    exTeam.setPlayerFullnessPointsAt(newFullness,i);
                }
            }
        }

    } // If yes brace

    // Display Health for each player
    for (int i = 0; i < exTeam.getPlayers().size(); i++)
    {
        cout << "Player " << exTeam.getPlayers()[i].getPlayerName()<< " health: " << exTeam.getPlayers().at(i).getFullnessPoints() << endl;
    }
    //Return the new team
    return exTeam;
}