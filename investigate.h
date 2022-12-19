
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
#include "attack.h"
using namespace std;

/** Algorithm:
 * If the user chooses to explore this function will be called
 * Generate a random number
 * If the number is between 1-10 they found a key, add a key to the number of keys 
 * If the number is between 11-30 they bound a treasrue, add a treasure to the number of treasres(which treasure is deptendent on the number of rooms cleared)
 * If the number is between 31-80 each player looses a fulness point There is also a 50% chance a monster will be spawned
*/

Team investigate(Team x,Map map)
{

    if(map.isExplored(map.getPlayerRow(),map.getPlayerCol()))
    {
        cout<<"You have already explored this space"<<endl;
        return x;
    }

    else{
    srand(time(0));
    int randomNumber;
    randomNumber = rand() % 100 + 1;
    

    //Key found
    if(randomNumber > 0 && randomNumber <= 10)
    {
        cout << "You found a key!" << endl;
        int currentKeys = x.getKeys();
        int keysPlusOne = currentKeys + 1;
        x.setKeys(keysPlusOne);
    }
    
    //Treasure found
    if(randomNumber > 10 && randomNumber <= 30)
    {
        int roomsCleared = x.getNumRoomsCleared();
        if ( roomsCleared == 1)
        {
            cout << "You found a silver ring!" << endl;
            vector <string> currentTreassures = x.getTreasures();
            currentTreassures.push_back("Silver ring");
            x.setTreasures(currentTreassures);
        }
        else if (roomsCleared == 2)
        {
            cout << "You found a ruby necklace!" << endl;
          
            vector <string> currentTreassures = x.getTreasures();
            currentTreassures.push_back("Ruby necklace");
            x.setTreasures(currentTreassures);
            
        }
         else if (roomsCleared == 3)
        {
            cout << "You found a emerald bracelet!" << endl;
            
            vector <string> currentTreassures = x.getTreasures();
            currentTreassures.push_back("Emerald bracelet");
            x.setTreasures(currentTreassures);
        }
         else if (roomsCleared == 4)
        {
            cout << "You found a diamond circlet!" << endl;
            
            vector <string> currentTreassures = x.getTreasures();
            currentTreassures.push_back("Diamond circlet");
            x.setTreasures(currentTreassures);
        }
         else if (roomsCleared == 5)
        {
            cout << "You found a gem-encrusted goblet!" << endl;
     
            vector <string> currentTreassures = x.getTreasures();
            currentTreassures.push_back("Gem-encrusted goblet");
            x.setTreasures(currentTreassures);
        }

    }

        if(randomNumber>30&randomNumber<=80)
        {
            cout<<"Oh no! each player has lost a fullness point"<<endl;
            //50% chance each player looses a fulness point
        for (int i = 0; i < x.getPlayers().size(); i++)
        {
                x.setPlayerFullnessPointsAt(x.getPlayers().at(i).getFullnessPoints()-1,i);
        }

        }

    //       //Spawn a monster;
    if(randomNumber >= 30 && randomNumber <= 50)
    {
         Monster randomMonster;

           int numPlayers = x.getPlayers().size();
           x = attack(x,randomMonster,map);
           if(numPlayers == x.getPlayers().size())
           {
            x.setNumRoomsCleared(x.getNumRoomsCleared()-1);
           }
           
    }

        if(randomNumber>=35&&randomNumber<40)
        {
            cout<<"You have found a health potion!"<<endl;
            x.setPotions(x.getPotions()+ 1);
        }


     }

   
    
    

    return x;

}