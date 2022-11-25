#include <iostream>
#include <vector>
#include "Team.h"
#include "Weapons.h"
#include "Player.h"
#include "Merchant.h"



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


    return theTeam;
}
