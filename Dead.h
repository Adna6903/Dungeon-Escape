

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Team.h"
#include "Player.h"


using namespace std;


       
/**
 * 1) had to build a get playes function
 */

Team Dead(Team x)
{

 for(int i = 0; i<x.getPlayers().size(); i++)
        {

             int hpMain = x.getPlayers().at(0).getFullnessPoints();
             if (hpMain <= 0)
            {
            cout << "Player "<<x.getPlayers()[i].getPlayerName()<<" has died!" << endl;
                x.removePlayer(i);
                i--;
            }
            
        }

    return x;
    
}