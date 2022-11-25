#include "Team.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



void endGame(Team exTeam)
{
    cout << "Congratulations You finishined the game!" << endl;

    // Read the current top scores
    fstream topScores;

    
    topScores.open("LeaderBoard.txt");
    

    // Vector to store the high scores
    vector<int> highScores;

    // String to store the entire line
    string nameAndScore[5];

    // Number of top scores if less than 5
    int count = 0;
   
    while (!topScores.eof())
    {
        
        string line;
        string arr[2];
        getline(topScores, line);
        if(line!="")
        {
        nameAndScore[count] = line;
        split(line, ',', arr, 2);
        highScores.push_back(stoi(arr[1]));
        arr[0] = "";
        arr[1] = "";
        count++;
        }
    }

    // Output
    fstream newHighscore;
    newHighscore.open("LeaderBoard.txt", ios::app);

    // index (aka place 1st - 5th)
    int place;
    // Team name
    string teamName;
  

    for (int i = 0; i < count; i++)
    {
        if (exTeam.getSorcererAngerLevel() < highScores[i])
        {

            place = i;
            cout << "New High Score! You finished in " << i+1 << " place." << endl;
            cout << "Enter a name for the leaderboard" << endl;
            cin >> teamName;
            newHighscore << teamName << "," << exTeam.getSorcererAngerLevel() << endl;
            break;
        }
    }
    newHighscore.close();

    // Sort the file
    ofstream sortLeaderboard;
    sortLeaderboard.open("LeaderBoard.txt");

    // While i is less than place just rewrite the line
    // When you come to the place the team scored write that team and their score onto that line
    // Decrement i so that the the next line will be the team the new team beat

    for (int i = 0; i < 5; i++)
    {
        if (i == place)
        {
            sortLeaderboard << teamName << "," << exTeam.getSorcererAngerLevel() << endl;
           
        }
        else
        {
            sortLeaderboard << nameAndScore[i] << endl;
        }
    }

    return;
}