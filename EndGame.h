

#include "Team.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



/** Algorithm:
 * Pass the current leaderboard into a vector
 * Prompt the user to enter their team name
 * Append the team name to the leaderboard and upon the team name apend the socrere anger level (how many moves it took to finish the game)
 * Use a bubble sort so organize the vector from lowest sorcerer anger level to highest(the least amount of moves to finish the game)
 * Within the bubble sort it is necesary to split the line into to segments: team name and score
 * Output the vector line by line back to the file so it is stored for next time
 * Once the vector has been sorted traverse the vecotor and find which place the user finished
 * Output which place they finished
 */ 

void endGame (Team exTeam)
{

    // Read the current top scores
    fstream topScores;

    topScores.open("LeaderBoard.txt");

    // Vector to store the high scores
    vector<string> highScores;

    // Pass the entire file into a vector of strings
    while (!topScores.eof())
    {
        string line;
        getline(topScores, line);
        if(line!="")
        {
        highScores.push_back(line);
        }
        line = "";
    }

    string teamName;
    cout << "Congratulations You finishined the game!" << endl;
    cout << "Enter a team name" << endl;
    cin >> teamName;
    teamName += ",";
    teamName += to_string(exTeam.getSorcererAngerLevel());
    highScores.push_back(teamName);

    // //Array to store left&right vector
    string leftVectorStorage[2];
    string rightVectorStorage[2];

    for(int j = 0; j<highScores.size()-1; j++)
    {
        for(int i = 0; i<highScores.size()-1; i++)
        {
            if(highScores[i]!= "" && highScores[i+1] != "")
            {
            split(highScores[i], ',', leftVectorStorage, 2);
                int leftScore = stoi(leftVectorStorage[1]);
                
            split(highScores[i+1], ',', rightVectorStorage, 2);
                int rightScore = stoi(rightVectorStorage[1]);
            

                
            if(leftScore > rightScore)
            {
                string temp = highScores[i];
                highScores[i] = highScores[i+1];
                highScores[i+1] = temp;
            }
            }
        //Clear
        leftVectorStorage[0] = "";
        leftVectorStorage[1] = "";
        rightVectorStorage[0]= "";
        rightVectorStorage[1]= "";
        
        }//Inner For
    }//Outer For



    //Output
    ofstream outHighScores;
    outHighScores.open("LeaderBoard.txt");


    for(int i = 0; i<highScores.size(); i++)
    {
        outHighScores << highScores[i] << endl;
    }


    //Find what place the player scored
    for(int i =0; i < highScores.size(); i ++)
    {
        string array[2];
        split(highScores[i],',', array, 2);

        string arrayB[2];
        split(teamName, ',', arrayB, 2);

        string justTheName = arrayB[0];
        
        if(array[0] == arrayB[0])
        {
            cout << "You finished in " << i+1 << "th place." << endl;
        }

        array[0] = "";
    }



    return;
}