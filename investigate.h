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


Team investigate(Team x,Map map)
{

    if(map.isExplored(map.getPlayerRow(),map.getPlayerCol(),x))
    {
        cout<<"You have already explored this space"<<endl;
        return x;
    }

    else{
    srand(time(0));
    int randomNumber;
    randomNumber = rand() % 100 + 1;

    //Key found
    if(randomNumber > 0 & randomNumber <= 10)
    {
        cout << "You found a key!" << endl;
        int currentKeys = x.getKeys();
        int keysPlusOne = currentKeys + 1;
        x.setKeys(keysPlusOne);
    }
    
    //Treasure found
    if(randomNumber > 10 & randomNumber <= 30)
    {
        int roomsCleared = x.getNumRoomsCleared();
        if ( roomsCleared == 1)
        {
            cout << "You found a silver ring!" << endl;
            vector <string> currentTreassures = x.getTreasures();
            currentTreassures.push_back("silver ring");
            x.setTreasures(currentTreassures);
        }
        else if (roomsCleared == 2)
        {
            cout << "You found a ruby necklace!" << endl;
            cout << "You found a ruby necklace!" << endl;
            vector <string> currentTreassures = x.getTreasures();
            currentTreassures.push_back("ruby necklace");
            x.setTreasures(currentTreassures);
            
        }
         else if (roomsCleared == 3)
        {
            cout << "You found a emerald bracelet!" << endl;
            cout << "You found a emerald bracelet!" << endl;
            vector <string> currentTreassures = x.getTreasures();
            currentTreassures.push_back("emerald bracelet");
            x.setTreasures(currentTreassures);
        }
         else if (roomsCleared == 4)
        {
            cout << "You found a diamond circlet!" << endl;
            cout << "You found a diamond circlet!" << endl;
            vector <string> currentTreassures = x.getTreasures();
            currentTreassures.push_back("diamond circlet");
            x.setTreasures(currentTreassures);
        }
         else if (roomsCleared == 5)
        {
            cout << "You found a gem-encrusted goblet!" << endl;
            cout << "You found a gem-encrusted goblet!" << endl;
            vector <string> currentTreassures = x.getTreasures();
            currentTreassures.push_back("gem-encrusted goblet");
            x.setTreasures(currentTreassures);
        }

    }
    }

    //Spawn a monster;
    // if(randomNumber >= 30 && randomNumber <= 50)
    // {

    // }
    
    // //50% chance each player looses a fulness point
    // for (int i = 0; i < x.getPlayers().size(); i++)
    // {
        
    // }

    return x;

}