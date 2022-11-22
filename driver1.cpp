#include <iostream>
#include "Player.h"
#include <vector>
#include "Team.h"
using namespace std;

int main()
{

    Player test;
    test.setFullnessPoints(0);
    Player test1;
    cout<<test.getFullnessPoints()<<endl;
    cout<<test1.getFullnessPoints()<<endl;
    vector<Player> players;
    Player one;
    Player two;
    players.push_back(one);
    players.push_back(two);
    Team testTeam(players);
    testTeam.setPlayerFullnessPointsAt(0,0);
    cout<<testTeam.getPlayers().at(0).getFullnessPoints();

    
    return 0;



}
