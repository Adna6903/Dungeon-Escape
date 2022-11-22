#include <iostream>
#include "Map.h"
#include "Merchant.h"
#include "actionMenu.h"
#include "Player.h"
#include "Team.h"
#include "Weapons.h"
#include "startGame.h"
#include "EndGame.h"



//g++ -std=c++17 main.cpp Map.cpp Merchant.cpp Monster.cpp Player.cpp Team.cpp Weapons.cpp
int main()
{
       Team mainTeam = startGame();
       mainTeam = merchantMenu(mainTeam,0);
      
       Map map1;
      
       mainTeam = actionMenu(mainTeam,map1);
       
        
         endGame(mainTeam);

         return 0;

 }