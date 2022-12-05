// CSCI 1300 Fall 2022
// Author: Adithya Narayanan & Benjamin E Apelman 
// Recitation: 106 –Chanheum Park (Adithya)
// Recitation: Section 105 – Raegan Rychecky (Benjamin)
// Project 3 

#include <iostream>
#include <fstream>
#include <vector>
#include "Team.h"

#include "Player.h"
#include "Merchant.h"

/** Algorithm:
 * Create four player objects
 * Prompt the user for a name for each player
 * Set each players name
 * Pass each player into a vector of players
 * Pass that vector into the Team constructor
 * Read the riddles.txt file and pass it as a vector into team as a datamember
 * read the monsters.txt file and pass it as a vector into team as a datamember
 * Return the team
 * 
*/


using namespace std;


Team startGame()
{
    //Variables:
    Player playerOne;
    string nameOne;
    Player playerTwo;
    string nameTwo;
    Player playerThree;
    string nameThree;
    Player playerFour;
    string nameFour;
    Player playerFive;
    string nameFive;

    //Get and Set player names:
    cout << "Player one, what is your name?" << endl;
    cin >> nameOne;
    playerOne.setPlayerName(nameOne);

    cout << "Player two, what is your name?" << endl;
    cin >> nameTwo;
    playerTwo.setPlayerName(nameTwo);

    cout << "Player three, what is your name?" << endl;
    cin >> nameThree;
    playerThree.setPlayerName(nameThree);

    cout << "Player four, what is your name?" << endl;
    cin >> nameFour;
  
    playerFour.setPlayerName(nameFour);
   

    cout << "Player five, what is your name?" << endl;
    cin >> nameFive;
    playerFive.setPlayerName(nameFive);

    //Create a vector of players
    vector<Player> thePlayers; 

    thePlayers.push_back(playerOne);
    thePlayers.push_back(playerTwo);
    thePlayers.push_back(playerThree);
    thePlayers.push_back(playerFour);
    thePlayers.push_back(playerFive);

   
    //Pass the vecotr of players into "theTeam" class object
    Team theTeam(thePlayers);


    //Add a vector of riddles to the team
    fstream riddles;
    riddles.open("riddles.txt");

    vector <string> riddlesList;

    while(!riddles.eof())
        {
            string line;
            getline(riddles, line);

            if(line != "")
            {
            riddlesList.push_back(line);
            }

            line = "";
        }

        theTeam.setRiddles(riddlesList);

    //Add a vector of monsters to the team

    fstream monsters;
    monsters.open("Monsters.txt");

    vector<string> monstersList; 

    while(!monsters.eof())
    {
        string line;
        getline(monsters,line);

        if(line != "")
        {
            monstersList.push_back(line);
        }
        line = "";
    }

    theTeam.setMonsters(monstersList);

    return theTeam;
}