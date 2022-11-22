#include <iostream>
#include <vector>
#include "Team.h"
#include "Player.h"
void universalSetter(Team oldTeam,Team newTeam)
{
    
    for(int i = 0; i< newTeam.getPlayers().size(); i++)
   {
    players_.push_back(newTeam.getPlayers().size()[i]);
   }
   numRoomsCleared_ = newTeam.getNumRoomsCleared();

   sorcererAngerLevel_ = newTeam.getSorcererAngerLevel();

   Weapons weapons_ = newTeam.getWeapons(); 

   treasures_ = newTeam.getTreasures();

   keys_ = newTeam.getKeys();

   gold_ = newTeam.getGold();

   cookware_ = newTeam.getCookware();

   ingredients_ = newTeam.getIngredients();

   armor_ = newTeam.getArmor();
    

return;

}