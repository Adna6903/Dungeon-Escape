
#ifndef MERCHANT_H
#define MERCHANT_H

#include <iostream>
#include "Team.h"


using namespace std;

//Cost weapons
//club, spear, rapier
// Cost armor
// Cost food
// Cost cookware
//ceramic pot, frying pan, cauldron

//----------------------------------------merchant class declaration-------------------------------------------------------------------------

class Merchant
{
        private:
                
               
                //multiplied with initial cost and number of levels passed 
                double multiplier_ = 0.25;
                int weaponsCostClub_;
                int weaponsCostSpear_;
                int weaponsCostRapier_;
                int weaponsCostBattleAxe_;
                int weaponsCostLongsword_;
                int armorCost_;
                int foodCost_;
                int cookwareCostCeramicPot_;
                int cookwareCostFryingPan_;
                int cookwareCostCauldron_;
                
        
        
        public:

                Merchant();
                // number of levels cleared will be accessed from status class        
                void setMenuCost(int numLevelsCleared);
                int merchantMenu();
                int getClubCost();
                int getSpearCost();
                int getRapierCost();
                int getBattleAxeCost();
                int getLongswordCost();
                int getFoodCost();
                int getCeramicPotCost();
                int getFryingPanCost();
                int getCauldronCost();
                int getArmorCost();


};



#endif



