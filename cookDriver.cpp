#include "iostream"
#include "cook.h"


using namespace std;



int main()
{
    Player P1;
    P1.setFullnessPoints(20);
    vector <Player> players;
    players.push_back(P1);
    Team x(players);
    vector <string> cookware;
    cookware.push_back("Cauldron");
    cookware.push_back("Frying Pan");
    x.setCookware(cookware);
    x.setIngredients(25);

    cooking(x);






}