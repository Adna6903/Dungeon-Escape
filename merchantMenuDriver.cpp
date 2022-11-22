#include <iostream>
#include "MerchantMenu.h"
#include "Team.h"
#include "Player.h"
#include "Weapons.h"

using namespace std;



int main()
{
    vector <Player> Test1;
    Team y(Test1);
    merchantMenu(y,2);

    return 0;
}