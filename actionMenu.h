
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
#include "Misfortune.h"
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

    bool roomPuzzle(Team x)
    {   
        bool result = false;
        srand(time(0));
        int chances = 0;
        
        while(chances!=3)
        {

            int choice = 0;
        int randomChoice = (rand()%3) +1;
        while((choice<=0||choice>=4)) {
        cout<<"Choose one of the following Boulder/Parchment/Shears and I will choose on as well."<<endl;
        cout<<"If you manage to beat me then I will let one of you pass or else I shall destroy one of you"<<endl;
        cout<<"1. Boulder"<<endl;
        cout<<"2. Parchment"<<endl;
        cout<<"3. Shears"<<endl;
        string temp;
        cin>>temp;
        
       
        if(temp=="1"||temp =="2"||temp=="3")
        {
            choice = stoi(temp);

        }
        else
        {
                choice = 4;
        }
        if(choice<1 || choice>3 )
        {
            cout<<"Invalid Input."<<endl;
        }
        };

         switch(randomChoice)
         {
            case 1:
                        if(choice ==1)
                        {
                            cout<<"Tie"<<endl;
                            chances++;

                        }
                        if(choice==2)
                        {
                          cout<<"Victory"<<endl;
                          chances = 3;
                          result = true;   
                        }
                        if(choice==3)
                        {
                            cout<<"Defeat"<<endl;
                            chances++;
                            result = false;
                        }

                        break;
            
        case 2:
                        if(choice ==1)
                        {
                            cout<<"Defeat"<<endl;
                            chances++;
                            result = false;

                        }
                        if(choice==2)
                        {
                          cout<<"Tie"<<endl;
                          chances++;
                            
                        }
                        if(choice==3)
                        {
                            cout<<"Victory"<<endl;
                            chances = 3;
                            result = true;
                        }

                        break;
        
        case 3:
                        if(choice ==1)
                        {
                            cout<<"Victory"<<endl;
                            chances = 3;
                            result = true;

                        }
                        if(choice==2)
                        {
                          cout<<"Defeat"<<endl;
                          chances++;
                          result = false;   
                        }
                        if(choice==3)
                        {
                            cout<<"Tie"<<endl;
                            chances++;
                           
                        }

                        break;

        
            




         }


        }
        return result;

    }



    Team actionMenu(Team x,Map map)
    {

      

        system("clear");
       srand(time(0));
    
   
   
    char movement = ' ';
    
    int numRooms = 0;
    
    while(!map.isRoomLocation(rand() % 12 +1,rand() % 12 +1)||numRooms!=5)
    {
        if( map.addRoom( rand() % 12 +1,rand() % 12 +1))
        {
            numRooms++;
        }
    }
    numRooms = 0;

    while(!map.isNPCLocation(rand() % 12 +1,rand() % 12 +1)||numRooms!=5)
    {
        if( map.addNPC( rand() % 12 +1,rand() % 12 +1))
        {
            numRooms++;
        }
    }

    
    
   
   

    
  
  
    
 

        int z = 1;

        while(z!=0)
        {
            

        int choiceActionMenu = 6;
        char movement = 'x';
        status(x);
        map.displayMap();

         while(choiceActionMenu != 5) 
         {

            

             if(map.isNPCLocation(map.getPlayerRow(),map.getPlayerCol()))
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
                int numPlayers = x.getPlayers().size();
               x =  NPC(x,map);
               if(x.getPlayers().size()==numPlayers)
             {
                map.removeNPC(map.getPlayerRow(),map.getPlayerCol());
             }
                
            }

                }

                if(map.isRoomLocation(map.getPlayerRow(),map.getPlayerCol()))
                {
                          cout<<"You have encountered a room"<<endl;
        if (x.getKeys()==0)
        {
            cout<<"You do not have any keys to enter the room"<<endl;
            cout<<"You have now been trapped in the room till you complete this puzzle"<<endl;
            bool result = roomPuzzle(x);
            if(result == true)
            {
                cout<<"Congratulations! you have cleared the puzzle! You may now enter the room"<<endl;
                
               
               int numPlayers = x.getPlayers().size();
                Monster randomMonster;
             x = attack(x, randomMonster,map);
             if(x.getPlayers().size()==numPlayers)
             {
                map.removeRoom(map.getPlayerRow(),map.getPlayerCol());
             }

            }
            else
            {
                cout<<"You have failed to clear the puzzle. A team member has been removed!"<<endl;
                x.removePlayer(x.getPlayers().size()-1);
            }
           
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
               
               int numPlayers = x.getPlayers().size();
                Monster randomMonster;
             x = attack(x, randomMonster,map);
             if(x.getPlayers().size()==numPlayers)
             {
                map.removeRoom(map.getPlayerRow(),map.getPlayerCol());
             }

            
                
                
            }
        }
                
              

                
                  
                }
               string check =  x.getPlayers().at(0).getPlayerName();
                x = Dead(x);
                if(x.getPlayers().empty())
                {
                    choiceActionMenu = 5;
                    z = 0;
                    break;
                    return x;

                }
              
                cin.clear();
        //  do{ 
          
        cout<<"Select one:"<<endl;
        cout<<"1. Move"<<endl;
        cout<<"2. Investigate"<<endl;
        cout<<"3. Pick a Fight"<<endl;
        cout<<"4. Cook and Eat"<<endl;
        cout<<"5. Give up"<<endl;
        string temp;
        cin >> temp;
        //cin>>choiceActionMenu;
        if (temp == "1"||temp=="2"||temp=="3"||temp=="4"||temp == "5")
        {
            choiceActionMenu = stoi(temp);
        }

        else
        {
            choiceActionMenu = 6;
        }
        



       
        //  }while(/*(choiceActionMenu<1 || choiceActionMenu>5)&&cin>>choiceActionMenu*/);

        if(choiceActionMenu<1 || choiceActionMenu>5){
              system("clear");
            cout << "Invalid Input" << endl;
            status(x);
            map.displayMap();

           


        } else{

        

         switch(choiceActionMenu)
         {
              

            case 1:   
            {  
                x.setTurnsElapsed(1);
         if(x.getPlayers().size()>0)
                {
        if(x.getSorcererAngerLevel()<100)
            {
               
        cout<<"Where do you want to move?"<<endl;
        cin>>movement;
        system("clear");

        if(movement!='w'&&movement!='s'&&movement!='a'&&movement!='d')
        {
            
            cout<<"Invalid Input"<<endl;

        }
        else
        {
            
            if(movement=='s')
            {
              
                map.move('s');
                x = misfortune(x,map);
                x.setSorcererAngerLevel(x.getSorcererAngerLevel()+1);
                
            }
               
               
            

            if(movement=='w')
            {
              
                map.move('w');
          
                x = misfortune(x,map);
                
                  x.setSorcererAngerLevel(x.getSorcererAngerLevel()+1);
                
                 
            }

            if(movement=='a')
            {
                
                map.move('a');
              
               
              x = misfortune(x,map);
                  
                  x.setSorcererAngerLevel(x.getSorcererAngerLevel()+1);
                   

            }

            if(movement=='d')
            {
          
                map.move('d');
                
                x = misfortune(x,map);
                   
                  x.setSorcererAngerLevel(x.getSorcererAngerLevel()+1);
            }

            x = status(x);
             map.displayMap();

        }
        }

            else
            {
                map.setDungeonExit(map.getPlayerRow(), map.getPlayerCol());
                
            }
            }

        if(x.getPlayers().size()<=1)
        {
                cout<<"ONLY ONE PLAYER REMAINING"<<endl;
                return x;
        }

        if(map.isDungeonExit(map.getPlayerRow(),map.getPlayerCol())&&x.getNumRoomsCleared()==5)
        {
               cout<<"congrats! you cleared the dungeon!"<<endl;
              z = 0;
            choiceActionMenu = 5;
        }

        else
        if(map.isDungeonExit(map.getPlayerRow(),map.getPlayerCol())&&x.getNumRoomsCleared()!=5)
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
                system("clear");
                        x.setTurnsElapsed(1);
                        x = investigate(x,map);
                       
                        
                        map.exploreSpace(map.getPlayerRow(),map.getPlayerCol());
                        x.setSpacesExplored(1);
                         if(x.getPlayers().size()<=1)
        {
                cout<<"ONLY ONE PLAYER REMAINING"<<endl;
                return x;
        }

        if(map.isDungeonExit(map.getPlayerRow(),map.getPlayerCol())&&x.getNumRoomsCleared()==5)
        {
               cout<<"congrats! you cleared the dungeon!"<<endl;
              z = 0;
            choiceActionMenu = 5;
          
        }

        else
        if(map.isDungeonExit(map.getPlayerRow(),map.getPlayerCol())&&x.getNumRoomsCleared()!=5)
        {
                cout<<"Clear all rooms to exit the dungeon"<<endl;
        }

        if(x.getSorcererAngerLevel()>=100)
        {
            cout<<"Sorcerer has gotten very angry"<<endl;
              
                return x;

        }
                       x =  status(x);
                        map.displayMap();
            }            
                        break;
            case 3:
            {
                x.setTurnsElapsed(1);
                        system("clear");
                        srand(time(0));
                        Monster rand;
                       
                        int numPlayers = x.getPlayers().size();
                       x =  attack(x,rand,map);
                       
                       
                       if(x.getPlayers().size()==numPlayers)
             {
                x.setNumRoomsCleared(x.getNumRoomsCleared()-1);
                map.removeRoom(map.getPlayerRow(),map.getPlayerCol());
             }
                        if(x.getPlayers().size()<=1)
        {
                cout<<"ONLY ONE PLAYER REMAINING"<<endl;
                return x;
        }

        if(map.isDungeonExit(map.getPlayerRow(),map.getPlayerCol())&&x.getNumRoomsCleared()==5)
        {
            cout<<"congrats! you cleared the dungeon!"<<endl;
            z = 0;
            choiceActionMenu = 5;
            break;
          
        }

        else
        if(map.isDungeonExit(map.getPlayerRow(),map.getPlayerCol())&&x.getNumRoomsCleared()!=5)
        {
                cout<<"Clear all rooms to exit the dungeon"<<endl;
        }

        if(x.getSorcererAngerLevel()>=100)
        {
            cout<<"Sorcerer has gotten very angry"<<endl;
              
                return x;

        }
                     x =  status(x);
                        map.displayMap();
            }           
                        break;

            case 4:
                        x.setTurnsElapsed(1);
                        system("clear");
                        x = cooking(x);
                      x =  status(x);
                        map.displayMap();

                        break;
            
            case 5:

                        cout<<"GAME OVER"<<endl;
                        z = 0;

                        x.setGiveUp(true);

                        break;





            default: 
                        cout<<"Invalid Input"<<endl;
                        break;
         }
         }




         }
        }


   

        return x;
    }

