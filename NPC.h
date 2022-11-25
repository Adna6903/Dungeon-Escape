#include <iostream>
#include <vector>
#include <fstream>
#include "Team.h"
#include "Weapons.h"
#include "Player.h"
#include "Merchant.h"
#include "attack.h"
#include "MerchantMenu.h"
using namespace std;



// Must somehow pass in number of rooms cleared
// How to only read the file once?
// Or how to use ofstream to modifiy the file so that each monster is deleted after it is called?
// If the riddle is corredt How to not span and npc?
void NPC(Team exTeam)
{
    srand(time(0));

    // Read "riddles.txt"
    fstream Riddles;
    Riddles.open("riddles.txt");
    if (Riddles.fail())
    {
        cout << "Failed to open Riddles.txt." << endl;
    }

    // Vectors used to store the riddle and correct response
    vector<string> listOfRiddles;
    vector<string> correctResponse;

    // Variables used to process the text file
    string theLine;
    string lineSegment_a[2];

    while (!Riddles.eof())
    {
        getline(Riddles, theLine);
        split(theLine, '~', lineSegment_a, 2);

        listOfRiddles.push_back(lineSegment_a[0]);
        correctResponse.push_back(lineSegment_a[1]);

        lineSegment_a[0] = "";
        lineSegment_a[1] = "";
    }

    int riddleIndex = rand() % 20;
  
   
    cout << "Here is my riddle " << listOfRiddles.at(riddleIndex) << endl;
    cout<<correctResponse.at(riddleIndex)<<endl;
    string response = "";
    cin >> response;
    cout<<"--------------"<<endl;
    string CorrectResponse = correctResponse.at(riddleIndex);

    cout<<response<<endl;
    string Response = response;
    if (Response == CorrectResponse.substr(0,Response.length()))
    {
       
        cout << "Correct!" << endl;
        // If the riddle is corrrect go to merchant menu
        int roomsCleared = exTeam.getNumRoomsCleared();
        merchantMenu(exTeam, roomsCleared);
        cout<<""<<endl;
        return;
    }
    else if(response!=correctResponse.at(riddleIndex))
    {
       int x = Response.compare(CorrectResponse);
       cout<<x<<endl;
  
       cout<<Response.length()<<endl;
       cout<<CorrectResponse.length()<<endl;
        Monster randomMonster = getRandomMonster(exTeam.getNumRoomsCleared(),exTeam);
        attack(exTeam, randomMonster);

      

        return;
    } // Else brace (wrong answer to riddle)
}