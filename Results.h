#include "Team.h"
#include <iostream>
#include <fstream>
using namespace std;


void results(Team x)
{
    cout<< "Main player name: " <<x.getMainPlayerName()<<endl;
    cout << "Sorcerrer Anger level: " <<x.getSorcererAngerLevel() << endl;
    cout <<"Gold: " <<x.getGold() << endl;
    cout<<"Treasures: ";
    for(int i = 0; i<x.getTreasures().size(); i++)
    {
        cout<<x.getTreasures().at(i)<<"  ";
    }
    cout<<""<<endl;
    cout<<"Spaces Explored: "<<x.getSpacesExplored()<<endl;
    cout<<"Monsters Defeated: "<<x.getNumMonstersDefeated()<<endl;
    cout<<"Number of turns: "<<x.getNumTurnsElapsed()<<endl;
    

    ofstream teamResults;
    teamResults.open("gameResults.txt", ios::app);

    teamResults<< "Main player name: " <<x.getMainPlayerName()<<endl;
    teamResults << "Sorcerrer Anger level: " <<x.getSorcererAngerLevel() << endl;
    teamResults <<"Gold: " <<x.getGold() << endl;
    teamResults<<"Treasures: ";
    for(int i = 0; i<x.getTreasures().size(); i++)
    {
        teamResults<<x.getTreasures().at(i)<<"  ";
    }
    teamResults<<""<<endl;
    teamResults<<"Spaces Explored: "<<x.getSpacesExplored()<<endl;
    teamResults<<"Monsters Defeated: "<<x.getNumMonstersDefeated()<<endl;
    teamResults<<"Number of turns: "<<x.getNumTurnsElapsed()<<endl;
    teamResults<< ""<< endl;
    teamResults.close();


}