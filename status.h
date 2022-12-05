// CSCI 1300 Fall 2022
// Author: Adithya Narayanan & Benjamin E Apelman 
// Recitation: 106 –Chanheum Park (Adithya)
// Recitation: Section 105 – Raegan Rychecky (Benjamin)
// Project 3 

#include <iostream>
#include "Team.h"
using namespace std;

/** Algorithm
 * Display Every member variable of team
 * This is done by using the preconstruced getter
 * display the treausers by traversing the vector of treasures
 * Return the team withouth mutating it 
*/

     Team status(Team x)
    {

        
        int armorQuantity = 0;
        int PCookwareQuantity = 0;
        int FCookwareQuantity = 0;
        int CCookwareQuantity = 0;
        int CWeaponQuantity = 0;
        int SWeaponQuantity = 0;
        int RWeaponQuantity = 0;
        int BWeaponQuantity = 0;
        int LWeaponQuantity = 0;
        int RTreasureQuantity = 0;
        int NTreasureQuantity = 0;
        int BTreasureQuantity = 0;
        int CTreasureQuantity = 0;
        int GTreasureQuantity = 0;
       

       for(int i = 0; i<x.getTreasures().size(); i++)
        {
            if(x.getTreasures()[i]=="Silver ring")
            {
                RTreasureQuantity++;

            }


        }

        for(int i = 0; i<x.getTreasures().size(); i++)
        {
            if(x.getTreasures()[i]=="Ruby necklace")
            {
                NTreasureQuantity++;

            }


        }

        for(int i = 0; i<x.getTreasures().size(); i++)
        {
            if(x.getTreasures()[i]=="Emerald bracelet")
            {
                BTreasureQuantity++;

            }


        }

        for(int i = 0; i<x.getTreasures().size(); i++)
        {
            if(x.getTreasures()[i]=="Diamond circlet")
            {
                CTreasureQuantity++;

            }


        }

        for(int i = 0; i<x.getTreasures().size(); i++)
        {
            if(x.getTreasures()[i]=="Gem-encrusted goblet")
            {
                GTreasureQuantity++;

            }


        }

    for(int i =0; i<x.getArmor().size(); i++)
        {
            if(x.getArmor()[i]==1)
            {

                    armorQuantity++;

            }

        }
          for(int i = 0; i<x.getCookware().size(); i++)
        {
            if(x.getCookware()[i]=="Ceramic Pot")
            {
                PCookwareQuantity++;

            }


        }

          for(int i = 0; i<x.getCookware().size(); i++)
        {
            if(x.getCookware()[i]=="Frying Pan")
            {
                FCookwareQuantity++;

            }


        }

          for(int i = 0; i<x.getCookware().size(); i++)
        {
            if(x.getCookware()[i]=="Cauldron")
            {
                CCookwareQuantity++;

            }


        }
           for(int i = 0; i<x.getWeapons().size(); i++)
        {
            if(x.getWeapons()[i].getName()=="Club")
            {
                CWeaponQuantity++;

            }

        }

         for(int i = 0; i<x.getWeapons().size(); i++)
        {
            if(x.getWeapons()[i].getName()=="Spear")
            {
                SWeaponQuantity++;

            }


        }

         for(int i = 0; i<x.getWeapons().size(); i++)
        {
            if(x.getWeapons()[i].getName()=="Rapier")
            {
                RWeaponQuantity++;

            }


        }

         for(int i = 0; i<x.getWeapons().size(); i++)
        {
            if(x.getWeapons()[i].getName()=="Battle Axe")
            {
                BWeaponQuantity++;

            }


        }

         for(int i = 0; i<x.getWeapons().size(); i++)
        {
            if(x.getWeapons()[i].getName()=="Longsword")
            {
                LWeaponQuantity++;

            }


        }
        cout<<"+-------------+" <<endl;
        cout<<"| STATUS      |" <<endl;
        cout<<"+-------------+" <<endl;
        cout<<"| Rooms Cleared: "<<x.getNumRoomsCleared() <<" | Keys: "<<x.getKeys() <<" | Anger Level: "<<x.getSorcererAngerLevel() <<endl;
        cout<<"+-------------+"<<endl;
        cout<<"| INVENTORY   |"<<endl;
        cout<<"+-------------+"<<endl;
        cout<<"| Gold        | "<< x.getGold() <<endl;
        cout<<"| Ingredients | "<< x.getIngredients() <<" kg"<<endl;
        cout<<"| Cookware    | P: "<< PCookwareQuantity <<" | F: "<< FCookwareQuantity<<" | C: "<<CCookwareQuantity<<endl;
        cout<<"| Weapons     | C: "<< CWeaponQuantity <<" | S: "<< SWeaponQuantity<<" | R: "<< RWeaponQuantity <<" | B: "<< BWeaponQuantity<<" | L: "<<LWeaponQuantity <<endl;
        cout<<"| Armor       | "<<armorQuantity<<endl;
        cout<<"| Treasures   | R: "<<RTreasureQuantity<<" | N: "<< NTreasureQuantity <<" | B: "<< BTreasureQuantity <<" | C: "<< CTreasureQuantity <<" | G: "<< GTreasureQuantity<<endl;
        cout<<"+-------------+" <<endl;
        cout<<"| PARTY       |" <<endl;
        cout<<"+-------------+" <<endl;
        for(int i = 0; i< x.getPlayers().size();i++)
        {
            cout<<"| "<<x.getPlayers()[i].getPlayerName()<<" | Fullness: "<<x.getPlayers()[i].getFullnessPoints() <<endl;
        }
        // cout<<"| Zach | Fullness: 40" <<endl;
        // cout<<"| Morgan | Fullness: 40" <<endl;
        // cout<<"| Christopher | Fullness: 45" <<endl;
        // cout<<"| Enora | Fullness: 41" <<endl;
        // cout<<"| Jot | Fullness: 43" <<endl;
        cout<<"+-------------+" <<endl;

  
    
   






        return x;
    }