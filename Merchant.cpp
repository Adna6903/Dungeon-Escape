


#include "Merchant.h"

#include <iostream>

using namespace std;

/** Algorithm:
 * Calculate the cost of each item based on the number of rooms cleared
*/

//constructer

    Merchant::Merchant()
    {
        
        weaponsCostClub_ = 2;
        weaponsCostSpear_ = 2;
        weaponsCostRapier_ = 5;
        weaponsCostBattleAxe_ = 15;
        weaponsCostLongsword_ = 50;
        armorCost_ = 5;
        foodCost_ = 1;
        cookwareCostCeramicPot_ = 5; 
        cookwareCostFryingPan_ = 10;
        cookwareCostCauldron_ = 20;

    }

    void Merchant::setMenuCost(int numLevelsCleared)
    {

        weaponsCostClub_ = weaponsCostClub_ + weaponsCostClub_*numLevelsCleared*multiplier_;
        weaponsCostBattleAxe_ = weaponsCostBattleAxe_ + weaponsCostBattleAxe_*numLevelsCleared*multiplier_;
        weaponsCostLongsword_ = weaponsCostLongsword_ + weaponsCostLongsword_*numLevelsCleared*multiplier_;
        weaponsCostRapier_ = weaponsCostRapier_ + weaponsCostRapier_*numLevelsCleared*multiplier_;
        weaponsCostSpear_ = weaponsCostSpear_ + weaponsCostSpear_*numLevelsCleared*multiplier_;
        armorCost_ = armorCost_ + armorCost_*numLevelsCleared*multiplier_;
        foodCost_ = foodCost_ + foodCost_*numLevelsCleared*multiplier_;
        cookwareCostCauldron_ = cookwareCostCauldron_ + cookwareCostCauldron_*numLevelsCleared*multiplier_;
        cookwareCostCeramicPot_ = cookwareCostCeramicPot_ + cookwareCostCeramicPot_*numLevelsCleared*multiplier_;
        cookwareCostFryingPan_ = cookwareCostFryingPan_ + cookwareCostFryingPan_*numLevelsCleared*multiplier_;


    }

    int Merchant::getArmorCost()
    {
        return armorCost_;
    }

    int Merchant::getClubCost()
    {
        return weaponsCostClub_;
    }

    int Merchant::getBattleAxeCost()
    {
        return weaponsCostBattleAxe_;
    }

    int Merchant::getLongswordCost()
    {
        return weaponsCostLongsword_;
    }

    int Merchant::getRapierCost()
    {
        return weaponsCostRapier_;
    }

    int Merchant::getSpearCost()
    {
        return weaponsCostSpear_;
    }

    int Merchant::getFoodCost()
    {
        return foodCost_;
    }

    int Merchant::getCauldronCost()
    {
        return cookwareCostCauldron_;
    }

    int Merchant::getFryingPanCost()
    {
        return cookwareCostFryingPan_;
    }

    int Merchant::getCeramicPotCost()
    {
        return cookwareCostCeramicPot_;
    }

 

   

   

    