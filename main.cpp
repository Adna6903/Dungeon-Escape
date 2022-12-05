// CSCI 1300 Fall 2022
// Author: Adithya Narayanan & Benjamin E Apelman 
// Recitation: 106 –Chanheum Park (Adithya)
// Recitation: Section 105 – Raegan Rychecky (Benjamin)
// Project 3 

#include <iostream>
#include "Map.h"
#include "Merchant.h"
#include "actionMenu.h"
#include "Player.h"
#include "Team.h"
#include "Results.h"
#include "startGame.h"
#include "EndGame.h"
#include "BossBattle.h"


/** Algorithm
 * Run the start game funciton
 * Output the intro message
 * Generate a random map
 * Call the Action menu with the team (from start game) and the random map as parameters
 * Check to see if the game is over. This can happen because of: giving up, all players dieing, the sorcerer anger level reaching 100, lossing the boss battle
 * As long as the game is not over continute to call the action menu
 * 
*/




//g++ -std=c++17 main.cpp Map.cpp Merchant.cpp Monster.cpp Player.cpp Team.cpp Weapons.cpp
int main()
{
       Team mainTeam = startGame();
       cout<<"Welcome to dungeon escape oh brave warrior!"<<endl;
       cout<<"You and your team will have to clear all 5 rooms to escape the dungeon but BEWARE! "<<endl;
       cout<<"For a sorcerer dwells at the end of the dungeon"<<endl;
       cout<<"Finish clearing the rooms and destroy the sorcerer before time runs out or else it is the end of all your journeys today!"<<endl;
       cout<<"Having second thoughts already?! Well too late for there is no escape now"<<endl;

       cout<<"Here let me sell you some of my wares before you enter to meet your fate"<<endl;
       cout<<"Between the 5 of you, you have 100 gold pieces."<<endl; 
       cout<<"You will need to spend the some of your money on the following items:"<<endl;
       cout<<""<<endl;
       cout<<"- INGREDIENTS. To make food, you have to cook raw ingredients."<<endl;
       cout<<"- COOKWARE. If you want to cook, you have to have cookware first."<<endl;
       cout<<"- WEAPONS. You'll want at least one weapon per party member to fend off monsters."<<endl;
       cout<<"- ARMOR. Armor increases the chances of surviving a monster attack."<<endl;
       cout<<""<<endl;
       cout<<"You can spend all of your money here before you start your journey, or you can save some to spend on merchants along the way. But beware, some of the merchants in this dungeon are shady characters, and they won't always give you a fair price..."<<endl;


              mainTeam = merchantMenu(mainTeam,0);
      
       Map map1;
      
       mainTeam = actionMenu(mainTeam,map1);
       if(!mainTeam.getGiveUp())
       {
       if(mainTeam.getSorcererAngerLevel()<100&&mainTeam.getPlayers().size()>=2)
       {
          bool result = bossBattle();
        if(result)
        {
         endGame(mainTeam);
        }
        else
        {
          cout<<"GAME OVER"<<endl;
          results(mainTeam);
        }
       }

       else if(mainTeam.getSorcererAngerLevel()>=100)
       {
    
        cout<<"GAME OVER"<<endl;
        results(mainTeam);
        return 0;

       }
       else if(mainTeam.getPlayers().size()<2)
       {
       
        cout<<"GAME OVER"<<endl;
        results(mainTeam);

        return 0;
       }
       }
      
         return 0;

 }