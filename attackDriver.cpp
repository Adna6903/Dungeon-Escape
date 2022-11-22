#include <iostream>
#include "attack.h"
#include "Team.h"


using namespace std;

int main()
{
    srand(time(0));
    vector<Player> test;
    Player Adi;
    Player Ben;
    test.push_back(Ben);
    test.push_back(Adi);
    Team random(test);
    
    attack(random,getRandomMonster(2,random) );

}