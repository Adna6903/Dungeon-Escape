
#include <iostream>
#include <vector>
#include <fstream>
#include "Team.h"
#include "Player.h"
#include "Merchant.h"

#include "MerchantMenu.h"
using namespace std;


/** Algorithm:
 * Generate a radom number
 * Use that number to pick a random riddle from the vector of riddles stored in team as a datamember
 * split the riddle into the question and the correct response
 * output the riddle
 * If the respose is correct call the merchant function
 * If the response is incorrect generate a monster and call the attack function
 * 
*/



Team NPC(Team exTeam,Map map)
{
    srand(time(0));
    int randomNumber = rand() % exTeam.getRiddle().size();

    

    string riddleAndResponse = exTeam.getRiddle().at(randomNumber);
    exTeam.getRiddle().at(randomNumber).erase();

   

    string array[2];

    split(riddleAndResponse, '~', array, 2);
  
   
    cout << "Here is my riddle " << array[0] << endl;

    exTeam.eraseRiddleAt(randomNumber);
    
    string response = "";
    cin >> response;
   
    string CorrectResponse = array[1];

   
    string Response = response;
    if (Response == CorrectResponse.substr(0,Response.length()))
    {
       
        cout << "Correct!" << endl;
        // If the riddle is corrrect go to merchant menu
        int roomsCleared = exTeam.getNumRoomsCleared();
           map.removeNPC(map.getPlayerRow(),map.getPlayerCol());
       exTeam =  merchantMenu(exTeam, roomsCleared);
        cout<<""<<endl;
        return exTeam;
    }
    else if(response!=array[1])
    {
       
      
  
      
        Monster randomMonster;
        attack(exTeam, randomMonster,map);
        map.removeNPC(map.getPlayerRow(),map.getPlayerCol());
      
      


        return exTeam;
    } // Else brace (wrong answer to riddle)

    
    

    return exTeam;
}