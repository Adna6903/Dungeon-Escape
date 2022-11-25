#include <iostream>
#include "investigate.h"
#include "Map.h"
#include "Team.h"
#include "Player.h"
#include "NPC.h"
#include "cook.h"
#include "Dead.h"
#include "Random.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "status.h"
#include "misfortune.h"
#include<chrono>
#include<thread>
 

using namespace std::this_thread;     // sleep_for
using namespace std::chrono_literals;
using namespace std;
/*
ask for what the user wants to do
make switch cases for each option
call in map driver

BONUS: you already have one case and the outer while loops 
*/

    Team actionMenu(Team x,Map map)
    {

       
    
   

    char movement = ' ';
    cout << "Room #: " << map.getRoomCount() << endl;
    int numRooms = 0;
    
    while(!map.isRoomLocation(rand() % 12 +1,rand() % 12 +1,x)||numRooms!=5)
    {
        if( map.addRoom( rand() % 12 +1,rand() % 12 +1,x))
        {
            numRooms++;
        }
    }
    numRooms = 0;

    while(!map.isNPCLocation(rand() % 12 +1,rand() % 12 +1,x)||numRooms!=5)
    {
        if( map.addNPC( rand() % 12 +1,rand() % 12 +1,x))
        {
            numRooms++;
        }
    }

    
    
   
   

    
  
  
    
 

        int z = 1;

        while(z!=0)
        {
            

        int choiceActionMenu = 6;
        char movement = 'x';
        map.displayMap();

         while(choiceActionMenu != 5) 
         {

            

             if(map.isNPCLocation(map.getPlayerRow(),map.getPlayerCol(),x))
                {
                    char yesOrNo = 'x';
                     cout<<"You have encountered an NPC"<<endl;
            cout<<"Do you wish to interact with the NPC?(y/n)"<<endl;
            cin>>yesOrNo;
            while(yesOrNo!='y'&&yesOrNo!='n')
            {
                cout<<"Invalid Input"<<endl;
                cout<<"Do you wish to interact with the NPC?(y/n)"<<endl;
                cin>>yesOrNo;
            }
            if(yesOrNo=='y')
            {
                 NPC(x);
                
            }

                }

                if(map.isRoomLocation(map.getPlayerRow(),map.getPlayerCol(),x))
                {
                          cout<<"You have encountered a room"<<endl;
        if (x.getKeys()==0)
        {
            cout<<"You do not have any keys to enter the room"<<endl;
           
        }
        else{
       
        
        char yesOrNo = 'x';
      
      
        
        
        
            while(yesOrNo!='y'&&yesOrNo!='n')
            {
                
               cout<<"Do you want to use key to enter the room?(y/n)"<<endl;
                cin>>yesOrNo;

                if(yesOrNo!='y'&&yesOrNo!='n')
                {
                    cout<<"Invalid Input"<<endl;
                    cout<<yesOrNo;
                }
            }
            if(yesOrNo == 'y')
            {
               
                int a = x.getKeys();
                x.setKeys(a- 1);
               
               
             x = attack(x,  getRandomMonster(x.getNumRoomsCleared(),x));
            
                
                
            }
        }
                
              

                
                  
                }
                
                x = Dead(x);
              

         do{ 

        cout<<"Select one:"<<endl;
        cout<<"1. Move"<<endl;
        cout<<"2. Investigate"<<endl;
        cout<<"3. Pick a Fight"<<endl;
        cout<<"4. Cook and Eat"<<endl;
        cout<<"5. Give up"<<endl;
        cin>>choiceActionMenu;

        if(choiceActionMenu <1 ||choiceActionMenu >5)
        {
            cout<<"Invalid Input"<<endl;
        }

         }while(choiceActionMenu<1 || choiceActionMenu>5);

         switch(choiceActionMenu)
         {
              

            case 1:   
            {  
         if(x.getPlayers().size()>0)
                {
        if(x.getSorcererAngerLevel()<100)
            {
               
        cout<<"Where do you want to move?"<<endl;
        cin>>movement;

        if(movement!='w'&&movement!='s'&&movement!='a'&&movement!='d')
        {
            
            cout<<"Invalid Input"<<endl;

        }
        else
        {
            
            if(movement=='s')
            {
              
                map.move('s',x);
                x = misfortune(x,map);
                
            }
               
               
            

            if(movement=='w')
            {
              
                map.move('w',x);
          
                x = misfortune(x,map);
                
                
                
                 
            }

            if(movement=='a')
            {
                
                map.move('a',x);
              
               
              x = misfortune(x,map);
                  
                
                   

            }

            if(movement=='d')
            {
          
                map.move('d',x);
                
                x = misfortune(x,map);
                   
                
            }

            status(x);
             map.displayMap();

        }
        }

            else
            {
                map.setDungeonExit(map.getPlayerRow(), map.getPlayerCol(),x);
                
            }
            }

        if(x.getPlayers().size()<=0)
        {
                cout<<"ALL PLAYERS HAVE DIED"<<endl;
                return x;
        }

        if(map.isDungeonExit(map.getPlayerRow(),map.getPlayerCol(),x)&&x.getNumRoomsCleared()==5)
        {
            cout<<"congrats! you have finished the game!"<<endl;
          
        }

        else
        if(map.isDungeonExit(map.getPlayerRow(),map.getPlayerCol(),x)&&x.getNumRoomsCleared()!=5)
        {
                cout<<"Clear all rooms to exit the dungeon"<<endl;
        }

        if(x.getSorcererAngerLevel()>=100)
        {
            cout<<"Sorcerer has gotten very angry"<<endl;
              
                return x;

        }


         }
                break;
            case 2:
            {       
                        
                        x = investigate(x,map);
                        map.exploreSpace(map.getPlayerRow(),map.getPlayerCol(),x);
                         if(x.getPlayers().size()<=0)
        {
                cout<<"ALL PLAYERS HAVE DIED"<<endl;
                return x;
        }

        if(map.isDungeonExit(map.getPlayerRow(),map.getPlayerCol(),x)&&x.getNumRoomsCleared()==5)
        {
            cout<<"congrats! you have finished the game!"<<endl;
          
        }

        else
        if(map.isDungeonExit(map.getPlayerRow(),map.getPlayerCol(),x)&&x.getNumRoomsCleared()!=5)
        {
                cout<<"Clear all rooms to exit the dungeon"<<endl;
        }

        if(x.getSorcererAngerLevel()>=100)
        {
            cout<<"Sorcerer has gotten very angry"<<endl;
              
                return x;

        }
                        status(x);
                        map.displayMap();
            }            
                        break;
            case 3:
            {
                        srand(time(0));
                        Monster rand;
                        rand = getRandomMonster(x.getNumRoomsCleared(),x);
                       x =  attack(x,rand);
                        if(x.getPlayers().size()<=0)
        {
                cout<<"ALL PLAYERS HAVE DIED"<<endl;
                return x;
        }

        if(map.isDungeonExit(map.getPlayerRow(),map.getPlayerCol(),x)&&x.getNumRoomsCleared()==5)
        {
            cout<<"congrats! you have finished the game!"<<endl;
          
        }

        else
        if(map.isDungeonExit(map.getPlayerRow(),map.getPlayerCol(),x)&&x.getNumRoomsCleared()!=5)
        {
                cout<<"Clear all rooms to exit the dungeon"<<endl;
        }

        if(x.getSorcererAngerLevel()>=100)
        {
            cout<<"Sorcerer has gotten very angry"<<endl;
              
                return x;

        }
                       status(x);
                        map.displayMap();
            }           
                        break;

            case 4:

                        x = cooking(x);
                        status(x);
                        map.displayMap();

                        break;
            
            case 5:

                        cout<<"GAME OVER"<<endl;
                        z = 0;



                        break;





            default: 
                        cout<<"Invalid Input"<<endl;
         }




         }
        }


   

        return x;
    }

