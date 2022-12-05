// CSCI 1300 Fall 2022
// Author: Adithya Narayanan & Benjamin E Apelman 
// Recitation: 106 –Chanheum Park (Adithya)
// Recitation: Section 105 – Raegan Rychecky (Benjamin)
// Project 3 

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Team.h"
#include "Player.h"

using namespace std;


/** Algorithm:
 *  Traverse the array of players
 *  Get the fulness points of each player
 *  If the fulness points of any player is at or bellow zero erase that player and tell the user that a player has died
 *  If the player has a potion give them the opportunity to use that potion to revive a player
 *  If they say yes then remove one potion
 */


Team Dead(Team x)
{

    for (int i = 0; i < x.getPlayers().size(); i++)
    {

        int hpMain = x.getPlayers().at(i).getFullnessPoints();
        if (hpMain <= 0)
        {

           

              
                    x.setPlayerFullnessPointsAt(50, x.getPlayers().size()-1);
                    cout << x.getPlayers()[i].getPlayerName() << " now has " << x.getPlayers()[i].getFullnessPoints() << " fulness points." << endl;
                  
                    return x;
                



            if(x.getPlayers().at(0).getFullnessPoints() <= 0)
            {
                cout << "Main player has died, you loose!" << endl;
                
                x.clearPlayers();

                return x;
                break;
            }

            cout << "Player " << x.getPlayers()[i].getPlayerName() << " has died!" << endl;
            x.removePlayer(i);
            i--;
        }
    }

    

    return x;
}