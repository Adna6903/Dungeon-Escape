
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;
#include "Team.h"
#include "Weapons.h"
#include "Player.h"
#include "Merchant.h"
#include "Monster.h"


int main(){

//Test Default Constructor For Player
Player playerOne;
assert(playerOne.getFullnessPoints()==100);
assert(playerOne.getPlayerName() == "");

//Test Setters For Player
Player playerTwo;
playerTwo.setFullnessPoints(50);
assert(playerTwo.getFullnessPoints()==50);

playerTwo.setPlayerName("Nick");
assert(playerTwo.getPlayerName()=="Nick");

//Test Setters and Getter for Monster
Monster Goblin;

Goblin.setDifficulty(3);
assert(Goblin.getDifficulty()==3);

Goblin.setName("Goblin");
assert(Goblin.getName()=="Goblin");

Weapons Sword;
Sword.setName("Sword");
assert(Sword.getName()=="Sword");
Sword.setLevel(3);
assert(Sword.getLevel() == 3);



Merchant merchant;


merchant.setMenuCost(2);
assert(merchant.getArmorCost()==7);




    
  
return 0; 
}