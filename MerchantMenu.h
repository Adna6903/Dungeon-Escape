// CSCI 1300 Fall 2022
// Author: Adithya Narayanan & Benjamin E Apelman 
// Recitation: 106 –Chanheum Park (Adithya)
// Recitation: Section 105 – Raegan Rychecky (Benjamin)
// Project 3 

#include <iostream>
#include <limits>
#include <ios>
#include "Team.h"
#include "Player.h"

#include "Merchant.h"
#include <stdlib.h>
using namespace std;


/** Algorithm:
 * Prompt the user to get supplies
 * Display the menu
 * If the user chooses to buy something, ask what quanitity they want
 * Check that the input is valid
 * Check that there is enough gold for the purchase
 * If they sucsessfully purchase something add that to the coresponding team member variable
 * Loop this untill the user chooses to exit
*/

Team merchantMenu(Team x, int numLevelsCleared)
    {

    Merchant merchant;

    merchant.setMenuCost(numLevelsCleared);
        

        int option =7;
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
        int quantity = -1;
        char yesOrNo = 'X';

       cout<<"If you're looking to get supplies, you've come to the right place."<<endl;
       cout<<"I would be happy to part with some of my wares...for the proper price!"<<endl;

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
        


        while(option != 6) {

          

        
        

    do {
        option = 0;
        cout<<"+-------------+"<<endl;
        cout<<"| INVENTORY   |"<<endl;
        cout<<"+-------------+"<<endl;
        cout<<"| Gold        | "<< x.getGold() <<endl;
        cout<<"| Ingredients | "<< x.getIngredients() <<" kg"<<endl;
        cout<<"| Cookware    | P: "<< PCookwareQuantity <<" | F: "<< FCookwareQuantity<<" | C: "<<CCookwareQuantity<<endl;
        cout<<"| Weapons     | C: "<< CWeaponQuantity <<" | S: "<< SWeaponQuantity<<" | R: "<< RWeaponQuantity <<" | B: "<< BWeaponQuantity<<" | L: "<<LWeaponQuantity <<endl;
        cout<<"| Armor       | "<<armorQuantity<<endl;
        cout<<"| Treasures   | R: "<<RTreasureQuantity<<" | N: "<< NTreasureQuantity <<" | B: "<< BTreasureQuantity <<" | C: "<< CTreasureQuantity <<" | G: "<< GTreasureQuantity<<endl;
        cout<<""<<endl;
        cout<<"Choose one of the following: "<<endl;
        cout<<"1. Ingredients: To make food, you have to cook raw ingredients."<<endl;
        cout<<"2. Cookware: You will need something to cook those ingredients."<<endl;
        cout<<"3. Weapons: It's dangerous to go alone, take this!"<<endl;
        cout<<"4. Armor: If you want to survive monster attacks, you will need some armor."<<endl;
        cout<<"5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands."<<endl;
        cout<<"6. Leave: Make sure you get everything you need, I'm leaving after this sale!"<<endl;

        string temp;

        cin >> temp;
           if (temp == "1"||temp=="2"||temp=="3"||temp=="4"||temp == "5"||temp=="6")
        {
            option = stoi(temp);
        }

        else
        {
            option = 7;
        }
        
        
    if (option < 1 || option > 6) {
        cout << "Invalid Input." << endl;
    }
    }
    while(option < 1 || option > 6);
        
        switch (option)
        {
            case 1:
                    quantity = -1;
                    while(quantity%5!=0)
                    {
                    cout<<"How many kg of ingredients do you need ["<<merchant.getFoodCost()<<" Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel)"<<endl;
                    cin>>quantity;
                    cin.clear();
                        if(cin.ignore(numeric_limits<streamsize>::max(), '\n'))
                        {
                            system("clear");
                            cout<<"Invalid Input"<<endl;
                        }
                    yesOrNo = 'x';

                    if(quantity%5!=0)
                    {
                        
                        cout<<"Invalid Input"<<endl;

                    }

                    }

                    if(quantity==0)
                    {
                            break;

                    }

                    
                   while(yesOrNo!='y'&& yesOrNo!='n')
                                    {
                                    cout<<"You want to buy "<<quantity<<" ingredients for "<<quantity*merchant.getFoodCost()<<" Gold? (y/n)"<<endl;
                                    cin>>yesOrNo;
                                    if(yesOrNo == 'n')
                                    {
                                        
                                        break;
                                    }
                                    else if(yesOrNo == 'y')
                                    {
                                        if (x.getGold()>=quantity*merchant.getFoodCost())
                                        {
                                           
                                           x.setIngredients(x.getIngredients()+quantity);
                                           x.setGold(x.getGold()-quantity*merchant.getFoodCost());
                                         
                                            
                                        }
                                        else
                                        {
                                            cout<<"Insufficient funds"<<endl;
                                            
                                            break;

                                        }
                                        
                                        
                                    }

                                    else
                                    {
                                            cout<<"Invalid Input."<<endl;

                                    }
                                    }

                    break;

            case 2:
            {

                    int choice2 = 5;
                    
                    cout<<"I have a several types of cookware, which one would you like?"<<endl;
                    cout<<"Each type has a different probability of breaking when used, marked with (XX%)."<<endl;
                    cout<<""<<endl;

                while(choice2 != 4) {
                do {
                    quantity = -1;
                    cout<< "Choose one of the following:"<<endl;
                    cout<< "1. (25%) Ceramic Pot ["<<merchant.getCeramicPotCost()<<" Gold]"<<endl;
                    cout<< "2. (10%) Frying Pan ["<<merchant.getFryingPanCost()<<" Gold]"<<endl;
                    cout<< "3. ( 2%) Cauldron ["<<merchant.getCauldronCost()<<" Gold]"<<endl;
                    cout<< "4. Cancel"<<endl;

                    string temp;

        cin >> temp;
           if (temp == "1"||temp=="2"||temp=="3"||temp=="4"||temp == "5"||temp=="6")
        {
        choice2 = stoi(temp);
        }

        else
        {
            choice2 = 7;
        }
             
                    
                    if (option < 1 || option > 4) {
                    cout << "Invalid Input." << endl;
                                                  }
                      }
                      while(option < 1 || option > 4);
                                    
                    
                    switch(choice2)
                    {   
                        case 1:
                                while(quantity<0)
                                {
                                cout<<"How many would you like? (Enter a positive integer, or 0 to cancel)"<<endl;
                                cin>>quantity;
                                cin.clear();
                        if(cin.ignore(numeric_limits<streamsize>::max(), '\n'))
                        {
                            system("clear");
                            cout<<"Invalid Input"<<endl;
                        }
                                yesOrNo = 'x';
                                if(quantity ==0)
                                {
                                    choice2 = 4;
                                    break;
                                    
                                }
                                else if(quantity>0)
                                {
                                    while(yesOrNo!='y'&& yesOrNo!='n')
                                    {
                                    cout<<"You want to buy "<<quantity<<" Ceramic Pot(s) for "<<quantity*merchant.getCeramicPotCost()<<" Gold? (y/n)"<<endl;
                                    cin>>yesOrNo;
                                    if(yesOrNo == 'n')
                                    {
                                        choice2 = 4;
                                        break;
                                    }
                                    else if(yesOrNo == 'y')
                                    {
                                        if (x.getGold()>=quantity*merchant.getCeramicPotCost())
                                        {
                                            vector<string> AddCeramicPot = {"Ceramic Pot"};
                                            for(int i = 0; i<quantity; i++)
                                            {
                                            x.setCookware(AddCeramicPot);
                                            x.setGold(x.getGold()-merchant.getCeramicPotCost());
                                            PCookwareQuantity++;
                                            }
                                            cout<<"Thank you for your patronage! What else can I get for you?"<<endl;
                                            choice2 = 4;
                                            break;
                                            
                                        }
                                        else
                                        {
                                            cout<<"Insufficient funds"<<endl;
                                            choice2 = 4;
                                            break;

                                        }
                                        
                                        
                                    }

                                    else
                                    {
                                            cout<<"Invalid Input."<<endl;

                                    }
                                    }
                                }

                                else
                                {

                                        cout<<"Invalid Input."<<endl;

                                }
                                
                                }
                    
                                break;
                            
                        case 2:

                                while(quantity<0)
                                {
                                cout<<"How many would you like? (Enter a positive integer, or 0 to cancel)"<<endl;
                                cin>>quantity;
                                cin.clear();
                    if(cin.ignore(numeric_limits<streamsize>::max(), '\n'))
                        {
                            system("clear");
                            cout<<"Invalid Input"<<endl;
                        }
                                yesOrNo = 'x';
                                if(quantity ==0)
                                {
                                    choice2 = 4;
                                    break;
                                    
                                }
                                else if(quantity>0)
                                {
                                    while(yesOrNo!='y'&& yesOrNo!='n')
                                    {
                                    cout<<"You want to buy "<<quantity<<" Frying Pan(s) for "<<quantity*merchant.getFryingPanCost()<<" Gold? (y/n)"<<endl;
                                    cin>>yesOrNo;
                                    if(yesOrNo == 'n')
                                    {
                                        choice2 = 4;
                                        break;
                                    }
                                    else if(yesOrNo == 'y')
                                    {
                                        if (x.getGold()>=quantity*merchant.getFryingPanCost())
                                        {
                                            vector<string> AddFryingPan = {"Frying Pan"};
                                            for(int i = 0; i<quantity; i++)
                                            {
                                            x.setCookware(AddFryingPan);
                                            x.setGold(x.getGold()-merchant.getFryingPanCost());
                                            
                                            FCookwareQuantity++;
                                            }
                                            cout<<"Thank you for your patronage! What else can I get for you?"<<endl;
                                            choice2 = 4;
                                            break;
                                            
                                        }
                                        else
                                        {
                                            cout<<"Insufficient funds"<<endl;
                                            choice2 = 4;
                                            break;

                                        }
                                        
                                        
                                    }

                                    else
                                    {
                                            cout<<"Invalid Input."<<endl;

                                    }
                                    }
                                }

                                else
                                {

                                        cout<<"Invalid Input."<<endl;

                                }
                                
                                }

                            
                                break;

                        case 3:
                                    while(quantity<0)
                                {
                                cout<<"How many would you like? (Enter a positive integer, or 0 to cancel)"<<endl;
                               
                                
                                cin>>quantity;
                                cin.clear();
                        if(cin.ignore(numeric_limits<streamsize>::max(), '\n'))
                        {
                            system("clear");
                            cout<<"Invalid Input"<<endl;
                        }
                                
                                yesOrNo = 'x';
                                if(quantity ==0)
                                {
                                    
                                    choice2 = 4;
                                    break;
                                    
                                }
                                else if(quantity>0)
                                {
                                    
                                    
                                    while(yesOrNo!='y'&& yesOrNo!='n')
                                    {
                                    cout<<"You want to buy "<<quantity<<" Cauldron(s) for "<<quantity*merchant.getCauldronCost()<<" Gold? (y/n)"<<endl;
                                    cin>>yesOrNo;
                                    if(yesOrNo == 'n')
                                    {
                                        choice2 = 4;
                                        break;
                                    }
                                    else if(yesOrNo == 'y')
                                    {
                                        if (x.getGold()>=quantity*merchant.getCauldronCost())
                                        {
                                            vector<string> AddCauldron = {"Cauldron"};
                                            for(int i = 0;i<quantity ; i++)
                                            {
                                            x.setCookware(AddCauldron);
                                            x.setGold(x.getGold()-merchant.getCauldronCost());
                                            CCookwareQuantity++;
                                            }
                                            cout<<"Thank you for your patronage! What else can I get for you?"<<endl;
                                            choice2 = 4;
                                            break;
                                            
                                        }
                                        else
                                        {
                                            cout<<"Insufficient funds"<<endl;
                                            choice2 = 4;
                                            break;

                                        }
                                        
                                        
                                    }

                                    else
                                    {
                                            cout<<"Invalid Input."<<endl;

                                    }
                                    }
                                }

                                else
                                {

                                        cout<<"Invalid Input."<<endl;

                                }
                                
                                }

                                break;
                        
                       

                       
                    }
                }
            }
                    
                    break;
            
            case 3:
            {
                        int choice3 = 0;

                      
                    
                  

                    if(x.getWeapons().size()==5)
                    {
                        cout<<"You already have 5 weapons, would you like to remove one?(y/n)"<<endl;
                        char yesOrNo = 'x';
                        while(yesOrNo!='y'&&yesOrNo!='n')
                        {
                            cin>>yesOrNo;
                            if(yesOrNo!='y'&&yesOrNo!='n')
                            {
                            cout<<"Invalid Input"<<endl;
                            cin>>yesOrNo;
                            }
                        }
                        if(yesOrNo=='y')
                        {       
                                int weaponRemoveIndex = 6;
                                while(weaponRemoveIndex>5||weaponRemoveIndex<1)
                                {
                                cout<<"Which weapon do you want to remove?"<<endl;
                                cout<<"1) "<<x.getWeapons().at(0).getName()<<" 2) "<<x.getWeapons().at(1).getName()<<" 3) "<<x.getWeapons().at(2).getName()<<" 4) "<<x.getWeapons().at(3).getName()<<" 5) "<<x.getWeapons().at(4).getName()<<endl;
                                string temp;

        cin >> temp;
           if (temp == "1"||temp=="2"||temp=="3"||temp=="4"||temp == "5"||temp=="6")
        {
            weaponRemoveIndex = stoi(temp);
        }

        else
        {
            weaponRemoveIndex = 7;
        }
        
        
   
                             

                                    if(weaponRemoveIndex>5||weaponRemoveIndex<1)
                                    {
                                        cout<<"invalid Input."<<endl;
                                    }

                                }

                               switch(weaponRemoveIndex)
                               {
                                    case 1: 
                                            if(x.getWeapons().at(0).getName()=="Club")
                                            {
                                                CWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(0).getName()=="Battle Axe")
                                            {
                                                BWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(0).getName()=="Spear")
                                            {
                                                SWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(0).getName()=="Rapier")
                                            {
                                                RWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(0).getName()=="Longsword")
                                            {
                                                LWeaponQuantity--;
                                            }
                                               x.removeWeaponsAt(0);
                                               
                                               

                                                break;

                                    case 2: 

                                                if(x.getWeapons().at(1).getName()=="Club")
                                            {
                                                CWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(1).getName()=="Battle Axe")
                                            {
                                                BWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(1).getName()=="Spear")
                                            {
                                                SWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(1).getName()=="Rapier")
                                            {
                                                RWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(1).getName()=="Longsword")
                                            {
                                                LWeaponQuantity--;
                                            }
                                                 x.removeWeaponsAt(1);

                                                break;
                                    
                                    case 3: 

                                                if(x.getWeapons().at(2).getName()=="Club")
                                            {
                                                CWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(2).getName()=="Battle Axe")
                                            {
                                                BWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(2).getName()=="Spear")
                                            {
                                                SWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(2).getName()=="Rapier")
                                            {
                                                RWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(2).getName()=="Longsword")
                                            {
                                                LWeaponQuantity--;
                                            }
                                                x.removeWeaponsAt(2);

                                                break;

                                    case 4: 

                                                if(x.getWeapons().at(3).getName()=="Club")
                                            {
                                                CWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(3).getName()=="Battle Axe")
                                            {
                                                BWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(3).getName()=="Spear")
                                            {
                                                SWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(3).getName()=="Rapier")
                                            {
                                                RWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(3).getName()=="Longsword")
                                            {
                                                LWeaponQuantity--;
                                            }
                                                x.removeWeaponsAt(3);

                                                break;

                                    case 5: 

                                                if(x.getWeapons().at(4).getName()=="Club")
                                            {
                                                CWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(4).getName()=="Battle Axe")
                                            {
                                                BWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(4).getName()=="Spear")
                                            {
                                                SWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(4).getName()=="Rapier")
                                            {
                                                RWeaponQuantity--;
                                            }
                                            if(x.getWeapons().at(4).getName()=="Longsword")
                                            {
                                                LWeaponQuantity--;
                                            }
                                                x.removeWeaponsAt(4);

                                                break;

                                                
                                     }

                        }
                        if(yesOrNo=='n')
                        {
                            choice3 = 6;
                            break;
                        
                        }

                    }

                      int weaponInventory = x.getWeapons().size(); 
                        cout<<""<<endl;
                      cout<<"I have a plentiful collection of weapons to choose from, what would you like?"<<endl;
                    cout<<"Note that some of them provide you a special bonus in combat, marked by a (+X)."<<endl;
                    cout<<""<<endl;

                while(choice3 != 6) {
                do {
                    quantity = -1;
                    cout<< "Choose one of the following:"<<endl;
                    cout<< "1. Stone Club ["<<merchant.getClubCost()<<" Gold]"<<endl;
                    cout<< "2. Iron Spear ["<<merchant.getSpearCost()<<" Gold]"<<endl;
                    cout<< "3. (+1) Mythril Rapier ["<<merchant.getRapierCost()<<" Gold]"<<endl;
                    cout<< "4. (+2) Flaming Battle-Axe ["<<merchant.getBattleAxeCost()<<" Gold]"<<endl;
                    cout<< "5. (+3) Vorpal Longsword ["<<merchant.getLongswordCost()<<" Gold]"<<endl;
                    cout<< "6. Cancel"<<endl;
                    cout<<""<<endl;
                    string temp;

        cin >> temp;
           if (temp == "1"||temp=="2"||temp=="3"||temp=="4"||temp == "5"||temp=="6")
        {
            choice3 = stoi(temp);
        }

        else
        {
            choice3 = 7;
        }
        
        
    
                    
                    
                    if (choice3 < 1 || choice3 > 6) {
                    cout << "Invalid Input." << endl;
                                                  }
                      }
                      while(choice3 < 1 || choice3 > 6);
                                    
                    
                    switch(choice3)
                    {   
                        case 1:
                                while(quantity<0||quantity+weaponInventory>5)
                                {
                                cout<<"How many would you like? (Enter a positive integer, or 0 to cancel)"<<endl;
                                yesOrNo = 'x';
                                cin>>quantity;
                                cin.clear();
                       if(cin.ignore(numeric_limits<streamsize>::max(), '\n'))
                        {
                            system("clear");
                            cout<<"Invalid Input"<<endl;
                        }
                                if(quantity ==0)
                                {
                                    choice3 = 6;
                                    break;
                                    
                                }
                                else if(quantity>0&&quantity+weaponInventory<=5)
                                {
                                    while(yesOrNo!='y'&& yesOrNo!='n')
                                    {
                                    cout<<"You want to buy "<<quantity<<" Stone Club(s) for "<<quantity*merchant.getClubCost()<<" Gold? (y/n)"<<endl;
                                    cin>>yesOrNo;
                                    if(yesOrNo == 'n')
                                    {
                                        choice3 = 6;
                                        break;
                                    }
                                    else if(yesOrNo == 'y')
                                    {
                                        if (x.getGold()>=quantity*merchant.getClubCost())
                                        {
                                            Weapons Club;
                                            Club.setName("Club");
                                            Club.setLevel(0);
                                            vector <Weapons> AddClub = {Club};
                                            for(int i = 0; i<quantity; i++)
                                            {
                                            x.setWeapons(AddClub);
                                            x.setGold(x.getGold()-merchant.getClubCost());
                                            CWeaponQuantity++;
                                            }
                                            cout<<"Thank you for your patronage! What else can I get for you?"<<endl;
                                            choice3 = 6;
                                            break;
                                            
                                        }
                                        else
                                        {
                                            cout<<"Insufficient funds"<<endl;
                                            choice3 = 6;
                                            break;

                                        }
                                        
                                        
                                    }

                                    else
                                    {
                                            cout<<"Invalid Input."<<endl;

                                    }
                                    }
                                }
                                else if(quantity+weaponInventory>5)
                                {
                                    cout<<"You can only have a maximum of 5 weapons!"<<endl;
                                }

                                else
                                {

                                        cout<<"Invalid Input."<<endl;

                                }
                                }
                                break;

                            case 2:
                                     while(quantity<0||quantity+weaponInventory>5)
                                {
                                cout<<"How many would you like? (Enter a positive integer, or 0 to cancel)"<<endl;
                                yesOrNo = 'x';
                                cin>>quantity;
                                cin.clear();
                        if(cin.ignore(numeric_limits<streamsize>::max(), '\n'))
                        {
                            system("clear");
                            cout<<"Invalid Input"<<endl;
                        }
                                if(quantity ==0)
                                {
                                    choice3 = 6;
                                    break;
                                    
                                }
                                else if(quantity>0&&quantity+weaponInventory<=5)
                                {
                                    while(yesOrNo!='y'&& yesOrNo!='n')
                                    {
                                    cout<<"You want to buy "<<quantity<<" Iron Spear(s) for "<<quantity*merchant.getSpearCost()<<" Gold? (y/n)"<<endl;
                                    cin>>yesOrNo;
                                    if(yesOrNo == 'n')
                                    {
                                        choice3 = 6;
                                        break;
                                    }
                                    else if(yesOrNo == 'y')
                                    {
                                        if (x.getGold()>=quantity*merchant.getSpearCost())
                                        {
                                            Weapons Spear;
                                            Spear.setName("Spear");
                                            Spear.setLevel(0);
                                            vector <Weapons> AddSpear = {Spear};
                                            for(int i = 0; i<quantity; i++)
                                            {
                                            x.setWeapons(AddSpear);
                                            x.setGold(x.getGold()-merchant.getSpearCost());
                                            SWeaponQuantity++;
                                            }
                                            cout<<"Thank you for your patronage! What else can I get for you?"<<endl;
                                            choice3 = 6;
                                            break;
                                            
                                        }
                                        else
                                        {
                                            cout<<"Insufficient funds"<<endl;
                                            choice3 = 6;
                                            break;

                                        }
                                        
                                        
                                    }

                                    else
                                    {
                                            cout<<"Invalid Input."<<endl;

                                    }
                                    }
                                }

                                else if(quantity+weaponInventory>5)
                                {
                                    cout<<"You can only have a maximum of 5 weapons!"<<endl;
                                }

                                else
                                {

                                        cout<<"Invalid Input."<<endl;

                                }
                                }

                                    break;

                            case 3:
                                     while(quantity<0||quantity+weaponInventory>5)
                                {
                                cout<<"How many would you like? (Enter a positive integer, or 0 to cancel)"<<endl;
                                yesOrNo = 'x';
                                cin>>quantity;
                                cin.clear();
                        if(cin.ignore(numeric_limits<streamsize>::max(), '\n'))
                        {
                            system("clear");
                            cout<<"Invalid Input"<<endl;
                        }
                                if(quantity ==0)
                                {
                                    choice3 = 6;
                                    break;
                                    
                                }
                                else if(quantity>0&&quantity+weaponInventory<=5)
                                {
                                    while(yesOrNo!='y'&& yesOrNo!='n')
                                    {
                                    cout<<"You want to buy "<<quantity<<" Mythril Rapier(s) for "<<quantity*merchant.getRapierCost()<<" Gold? (y/n)"<<endl;
                                    cin>>yesOrNo;
                                    if(yesOrNo == 'n')
                                    {
                                        choice3 = 6;
                                        break;
                                    }
                                    else if(yesOrNo == 'y')
                                    {
                                        if (x.getGold()>=quantity*merchant.getRapierCost())
                                        {
                                            Weapons Rapier;
                                            Rapier.setName("Rapier");
                                            Rapier.setLevel(1);
                                            vector <Weapons> AddRapier = {Rapier};
                                            for(int i = 0; i<quantity; i++)
                                            {
                                            x.setWeapons(AddRapier);
                                            x.setGold(x.getGold()-merchant.getRapierCost());
                                            RWeaponQuantity++;
                                            }
                                            cout<<"Thank you for your patronage! What else can I get for you?"<<endl;
                                            choice3 = 6;
                                            break;
                                            
                                        }
                                        else
                                        {
                                            cout<<"Insufficient funds"<<endl;
                                            choice3 = 6;
                                            break;

                                        }
                                        
                                        
                                    }

                                    else
                                    {
                                            cout<<"Invalid Input."<<endl;

                                    }
                                    }
                                }

                                else if(quantity+weaponInventory>5)
                                {
                                    cout<<"You can only have a maximum of 5 weapons!"<<endl;
                                }

                                else
                                {

                                        cout<<"Invalid Input."<<endl;

                                }
                                }

                                    break;

                            case 4:
                                     while(quantity<0||quantity+weaponInventory>5)
                                {
                                cout<<"How many would you like? (Enter a positive integer, or 0 to cancel)"<<endl;
                                yesOrNo = 'x';
                                cin>>quantity;
                                cin.clear();
                        if(cin.ignore(numeric_limits<streamsize>::max(), '\n'))
                        {
                            system("clear");
                            cout<<"Invalid Input"<<endl;
                        }
                                if(quantity ==0)
                                {
                                    choice3 = 6;
                                    break;
                                    
                                }
                                else if(quantity>0&&quantity+weaponInventory<=5)
                                {
                                    while(yesOrNo!='y'&& yesOrNo!='n')
                                    {
                                    cout<<"You want to buy "<<quantity<<" Flaming Battle-Axe(s) for "<<quantity*merchant.getBattleAxeCost()<<" Gold? (y/n)"<<endl;
                                    cin>>yesOrNo;
                                    if(yesOrNo == 'n')
                                    {
                                        choice3 = 6;
                                        break;
                                    }
                                    else if(yesOrNo == 'y')
                                    {
                                        if (x.getGold()>=quantity*merchant.getBattleAxeCost())
                                        {
                                            Weapons BattleAxe;
                                            BattleAxe.setName("Battle Axe");
                                            BattleAxe.setLevel(2);
                                            vector <Weapons> AddBattleAxe = {BattleAxe};
                                            for(int i = 0; i<quantity; i++)
                                            {
                                            x.setWeapons(AddBattleAxe);
                                            x.setGold(x.getGold()-merchant.getBattleAxeCost());
                                            BWeaponQuantity++;
                                            }
                                            cout<<"Thank you for your patronage! What else can I get for you?"<<endl;
                                            choice3 = 6;
                                            break;
                                            
                                        }
                                        else
                                        {
                                            cout<<"Insufficient funds"<<endl;
                                            choice3 = 6;
                                            break;

                                        }
                                        
                                        
                                    }

                                    else
                                    {
                                            cout<<"Invalid Input."<<endl;

                                    }
                                    }
                                }

                                else if(quantity+weaponInventory>5)
                                {
                                    cout<<"You can only have a maximum of 5 weapons!"<<endl;
                                }

                                else
                                {

                                        cout<<"Invalid Input."<<endl;

                                }
                                }

                                    break;

                            case 5:
                                     while(quantity<0||quantity+weaponInventory>5)
                                {
                                cout<<"How many would you like? (Enter a positive integer, or 0 to cancel)"<<endl;
                                yesOrNo = 'x';
                                cin>>quantity;
                                cin.clear();
                        if(cin.ignore(numeric_limits<streamsize>::max(), '\n'))
                        {
                            system("clear");
                            cout<<"Invalid Input"<<endl;
                        }
                                if(quantity ==0)
                                {
                                    choice3 = 6;
                                    break;
                                    
                                }
                                else if(quantity>0&&quantity+weaponInventory<=5)
                                {
                                    while(yesOrNo!='y'&& yesOrNo!='n')
                                    {
                                    cout<<"You want to buy "<<quantity<<" Vorpal Longsword(s) for "<<quantity*merchant.getLongswordCost()<<" Gold? (y/n)"<<endl;
                                    cin>>yesOrNo;
                                    if(yesOrNo == 'n')
                                    {
                                        choice3 = 6;
                                        break;
                                    }
                                    else if(yesOrNo == 'y')
                                    {
                                        if (x.getGold()>=quantity*merchant.getLongswordCost())
                                        {
                                            Weapons Longsword;
                                            Longsword.setName("Longsword");
                                            Longsword.setLevel(3);
                                            vector <Weapons> AddLongsword = {Longsword};
                                            for(int i = 0; i<quantity; i++)
                                            {
                                            x.setWeapons(AddLongsword);
                                            x.setGold(x.getGold()-merchant.getLongswordCost());
                                            LWeaponQuantity++;
                                            }
                                            cout<<"Thank you for your patronage! What else can I get for you?"<<endl;
                                            choice3 = 6;
                                            break;
                                            
                                        }
                                        else
                                        {
                                            cout<<"Insufficient funds"<<endl;
                                            choice3 = 6;
                                            break;

                                        }
                                        
                                        
                                    }

                                    else
                                    {
                                            cout<<"Invalid Input."<<endl;

                                    }
                                    }
                                }

                                else if(quantity+weaponInventory>5)
                                {
                                    cout<<"You can only have a maximum of 5 weapons!"<<endl;
                                }

                                else
                                {

                                        cout<<"Invalid Input."<<endl;

                                }
                                }

                                    break;

                        
                                       
                                
                    }
                }

            }         

                    break;
            
            case 4:
                        quantity = -1;
                    while(quantity<0)
                    {
                    cout<<"How many suits of armor can I get you? (Enter a positive integer, or 0 to cancel)"<<endl;
                    cin>>quantity;
                    cin.clear();
                       if(cin.ignore(numeric_limits<streamsize>::max(), '\n'))
                        {
                            system("clear");
                            cout<<"Invalid Input"<<endl;
                        }
                    yesOrNo = 'x';

                    if(quantity<0)
                    {
                        
                        cout<<"Invalid Input"<<endl;

                    }

                    }
                     
                     if(quantity==0)
                    {
                            break;

                    }

                   while(yesOrNo!='y'&& yesOrNo!='n')
                                    {
                                    cout<<"You want to buy "<<quantity<<" suit(s) for "<<quantity*merchant.getArmorCost()<<" Gold? (y/n)"<<endl;
                                    cin>>yesOrNo;
                                    if(yesOrNo == 'n')
                                    {
                                        
                                        break;
                                    }
                                    else if(yesOrNo == 'y')
                                    {
                                        if (x.getGold()>=quantity*merchant.getArmorCost())
                                        {
                                            int armor = 1;

                                            vector<int> AddArmor;
                                            for(int i = 0; i< quantity; i++)
                                            {

                                                AddArmor.push_back(armor);
                                                armorQuantity++;

                                            }
                                           
                                           x.setArmor(AddArmor);
                                           AddArmor.clear();
                                           x.setGold(x.getGold()-quantity*merchant.getArmorCost());
                                            
                                        }
                                        else
                                        {
                                            cout<<"Insufficient funds"<<endl;
                                            
                                            break;

                                        }
                                        
                                        
                                    }

                                    else
                                    {
                                            cout<<"Invalid Input."<<endl;

                                    }
                                    }

                    break;
            
            case 5:

                     int choice5;
                     choice5 = 7;
                //     quantity = -1;
                //     cout<<"Here is a list of how much I'll pay you for you treasures"<<endl;
                //     cout<<"Which treasure(s) would you like to sell?"<<endl;
                //     while(choice5 != 6) {
                // do {
                    // quantity = -1;
                    // cout<< "Choose one of the following:"<<endl;
                    // cout<< "1.  Silver ring (R) - 10 gold pieces each"<<endl;
                    // cout<< "2. Ruby necklace (N) - 20 gold pieces each"<<endl;
                    // cout<< "3. Emerald bracelet (B) - 30 gold pieces each"<<endl;
                    // cout<< "4. Diamond circlet (C) - 40 gold pieces each"<<endl;
                    // cout<< "5. Gem-encrusted goblet (G) - 50 gold pieces each"<<endl;
                    // cout<< "6. Cancel"<<endl;
                    // cout<<""<<endl;
                //     cin>>choice5;
                    
                //     if (choice5 < 1 || choice5 > 6) {
                //     cout << "Invalid Input." << endl;
                //                                   }
                //       }
                //       while(choice5 < 1 || choice5 > 6);

                //       switch (choice5)
                //       {
                //         case 1:
                //                 if(RTreasureQuantity<=0)
                //                 {
                //                     cout<<"You do not have this treasure"<<endl;
                //                     choice5 = 6;
                //                     break;
                //                 }
                //                 while(quantity<0)
                //     {
                //     cout<<"How many do you want to sell? (Enter a positive integer, or 0 to cancel)"<<endl;
                //     cin>>quantity;
                //     yesOrNo = 'x';

                //     if(quantity<0)
                //     {
                        
                //         cout<<"Invalid Input"<<endl;

                //     }

                //     }
                     
                //      if(quantity==0)
                //     {
                //             break;

                //     }

                //     if(RTreasureQuantity<quantity)
                //     {
                //         cout<<"You do not have enough of the treasure"<<endl;
                //         break;
                //     }

                //    while(yesOrNo!='y'&& yesOrNo!='n')
                //                     {
                //                     cout<<"You want to sell "<<quantity<<" treasure(s) for "<<10<<" Gold? (y/n)"<<endl;
                //                     cin>>yesOrNo;
                //                     if(yesOrNo == 'n')
                //                     {
                                        
                //                         break;
                //                     }
                //                     else if(yesOrNo == 'y')
                //                     {
                //                          x.setGold(x.getGold()+quantity*10);
                //                     for(int i = 0;i<x.getTreasures().size(); i++ )
                //                     {
                                        
                //                             if(x.getTreasures()[i]=="Silver ring")
                //                             {

                //                                     x.getTreasures()[i].erase(i);
                //                                     i--;
                //                                     quantity--;

                //                             }

                                        


                //                     }

                                        
                //                     }

                //                     else
                //                     {
                //                             cout<<"Invalid Input."<<endl;

                //                     }
                //                     }
                            

                //                 break;

                //         case 2:
                //                 if(NTreasureQuantity<=0)
                //                 {
                //                     cout<<"You do not have this treasure"<<endl;
                //                     choice5 = 6;
                //                     break;
                //                 }

                //                 cout<<"How many do you want to sell?"<<endl;
                //                 cin>>quantity;
                //                 yesOrNo == 'x';

                //                 if(NTreasureQuantity<quantity)
                //                 {

                //                         cout<<"You do not have the specified amount"<<endl;
                //                         choice5 = 6;
                //                         break;

                //                 }

                //                 else
                //                 {

                //                     x.setGold(x.getGold()+quantity*20);
                //                     for(int i = 0;i<x.getTreasures().size(); i++ )
                //                     {
                //                         if(quantity>0)
                //                         {
                //                             if(x.getTreasures()[i]=="Ruby necklace")
                //                             {

                //                                     x.getTreasures()[i].erase(i);
                //                                     i--;

                //                             }

                //                         }


                //                     }

                //                 }


                //                 break;

                //         case 3:
                //                 if(BTreasureQuantity<=0)
                //                 {
                //                     cout<<"You do not have this treasure"<<endl;
                //                     choice5 = 6;
                //                     break;
                //                 }

                //                 cout<<"How many do you want to sell?"<<endl;
                //                 cin>>quantity;
                //                 yesOrNo == 'x';

                //                 if(BTreasureQuantity<quantity)
                //                 {

                //                         cout<<"You do not have the specified amount"<<endl;
                //                         choice5 = 6;
                //                         break;

                //                 }

                //                 else
                //                 {

                //                     x.setGold(x.getGold()+quantity*30);
                //                     for(int i = 0;i<x.getTreasures().size(); i++ )
                //                     {
                //                         if(quantity>0)
                //                         {
                //                             if(x.getTreasures()[i]=="Emerald Bracelet")
                //                             {

                //                                     x.getTreasures()[i].erase(i);
                //                                     i--;

                //                             }

                //                         }


                //                     }

                //                 }


                //                 break;

                //         case 4:
                //                 if(CTreasureQuantity<=0)
                //                 {
                //                     cout<<"You do not have this treasure"<<endl;
                //                     choice5 = 6;
                //                     break;
                //                 }

                //                 cout<<"How many do you want to sell?"<<endl;
                //                 cin>>quantity;
                //                 yesOrNo == 'x';

                //                 if(CTreasureQuantity<quantity)
                //                 {

                //                         cout<<"You do not have the specified amount"<<endl;
                //                         choice5 = 6;
                //                         break;

                //                 }

                //                 else
                //                 {

                //                     x.setGold(x.getGold()+quantity*40);
                //                     for(int i = 0;i<x.getTreasures().size(); i++ )
                //                     {
                //                         if(quantity>0)
                //                         {
                //                             if(x.getTreasures()[i]=="Diamond circlet")
                //                             {

                //                                     x.getTreasures()[i].erase(i);
                //                                     i--;

                //                             }

                //                         }


                //                     }

                //                 }


                //                 break;
                        
                //         case 5:
                //                 if(GTreasureQuantity<=0)
                //                 {
                //                     cout<<"You do not have this treasure"<<endl;
                //                     choice5 = 6;
                //                     break;
                //                 }
                //                 yesOrNo == 'x';

                //                 cout<<"How many do you want to sell?"<<endl;
                //                 cin>>quantity;
                               
                //                 cout<<"x";

                //                 if(GTreasureQuantity<quantity)
                //                 {

                //                         cout<<"You do not have the specified amount"<<endl;
                //                         choice5 = 6;
                //                         break;

                //                 }

                //                 else
                //                 {

                //                     x.setGold(x.getGold()+quantity*50);
                //                     for(int i = 0;i<x.getTreasures().size(); i++ )
                //                     {
                //                         if(quantity>0)
                //                         {
                //                             if(x.getTreasures()[i]=="Gem-encrusted goblet")
                //                             {

                //                                     x.getTreasures()[i].erase(i);
                //                                     i--;

                //                             }

                //                         }


                //                     }

                //                 }


                //                 break;
                      
                       
                      
                //       default:
                //                 cout<<"Invalid Input"<<endl;

                        
                //       }
                //     }

                 while(choice5 != 6) {
                do {
                    quantity = -1;
                    cout<< "Choose one of the following:"<<endl;
                    cout<< "Choose one of the following:"<<endl;
                    cout<< "1.  Silver ring (R) - 10 gold pieces each"<<endl;
                    cout<< "2. Ruby necklace (N) - 20 gold pieces each"<<endl;
                    cout<< "3. Emerald bracelet (B) - 30 gold pieces each"<<endl;
                    cout<< "4. Diamond circlet (C) - 40 gold pieces each"<<endl;
                    cout<< "5. Gem-encrusted goblet (G) - 50 gold pieces each"<<endl;
                    cout<< "6. Cancel"<<endl;
                    cout<<""<<endl;
                    
                    string temp;

        cin >> temp;
           if (temp == "1"||temp=="2"||temp=="3"||temp=="4"||temp == "5"||temp=="6")
        {
            choice5 = stoi(temp);
        }

        else
        {
            choice5 = 7;
        }
        
        
   
                    
                    if (choice5 < 1 || choice5 > 6) {
                    cout << "Invalid Input." << endl;
                                                  }
                      }
                      while(choice5 < 1 || choice5 > 6);
                                    
                    
                    switch(choice5)
                    {   
                        case 1:
                                while(quantity<0)
                                {
                                cout<<"How many would you like to sell? (Enter a positive integer, or 0 to cancel)"<<endl;
                                yesOrNo = 'x';
                                cin>>quantity;
                                cin.clear();
                        if(cin.ignore(numeric_limits<streamsize>::max(), '\n'))
                        {
                            system("clear");
                            cout<<"Invalid Input"<<endl;
                        }
                                if(quantity ==0)
                                {
                                    choice5 = 6;
                                    break;
                                    
                                }
                                else if(quantity>0)
                                {
                                    while(yesOrNo!='y'&& yesOrNo!='n')
                                    {
                                    cout<<"You want to sell "<<quantity<<" Treasure(s) for "<<10<<" Gold? (y/n)"<<endl;
                                    cin>>yesOrNo;
                                    if(yesOrNo == 'n')
                                    {
                                        choice5 = 6;
                                        break;
                                    }
                                    else if(yesOrNo == 'y')
                                    {
                                        if (quantity<=RTreasureQuantity)
                                        {
                                           x.setGold(x.getGold()+quantity*10);
                                           RTreasureQuantity = RTreasureQuantity - quantity;
                                           
                                                for(int i = 0; i<x.getTreasures().size(); i++)
                                                {
                                                        if(quantity>0)
                                                        {
                                                        if(x.getTreasures()[i]=="Silver ring")
                                                        {
                                                            x.removeTreasureAt(i);
                                                            i--;
                                                            quantity--;

                                                        }
                                                        }


                                                }


                                           

                                           quantity = 1;
                                          

                                         
                                           choice5 = 6;
                                            break;
                                            
                                        }
                                        else
                                        {
                                            cout<<"Insufficient treasures"<<endl;
                                            choice5 = 6;
                                            break;

                                        }
                                        
                                        
                                    }

                                    else
                                    {
                                            cout<<"Invalid Input."<<endl;

                                    }
                                    }
                                }

                                else
                                {

                                        cout<<"Invalid Input."<<endl;

                                }
                                }
                                break;

                            case 2:
                                  while(quantity<0)
                                {
                                cout<<"How many would you like to sell? (Enter a positive integer, or 0 to cancel)"<<endl;
                                yesOrNo = 'x';
                                cin>>quantity;
                                cin.clear();
                        if(cin.ignore(numeric_limits<streamsize>::max(), '\n'))
                        {
                            system("clear");
                            cout<<"Invalid Input"<<endl;
                        }
                                if(quantity ==0)
                                {
                                    choice5 = 6;
                                    break;
                                    
                                }
                                else if(quantity>0)
                                {
                                    while(yesOrNo!='y'&& yesOrNo!='n')
                                    {
                                    cout<<"You want to sell "<<quantity<<" Treasure(s) for "<<2<<" Gold? (y/n)"<<endl;
                                    cin>>yesOrNo;
                                    if(yesOrNo == 'n')
                                    {
                                        choice5 = 6;
                                        break;
                                    }
                                    else if(yesOrNo == 'y')
                                    {
                                        if (quantity<=NTreasureQuantity)
                                        {
                                           x.setGold(x.getGold()+quantity*20);
                                           NTreasureQuantity = NTreasureQuantity - quantity;
                                           
                                                for(int i = 0; i<x.getTreasures().size(); i++)
                                                {
                                                        if(quantity>0)
                                                        {
                                                        if(x.getTreasures()[i]=="Ruby necklace")
                                                        {
                                                            x.removeTreasureAt(i);
                                                            i--;
                                                            quantity--;

                                                        }
                                                        }


                                                }


                                           

                                           quantity = 1;
                                          

                                         
                                           choice5 = 6;
                                            break;
                                            
                                        }
                                        else
                                        {
                                            cout<<"Insufficient treasures"<<endl;
                                            choice5 = 6;
                                            break;

                                        }
                                        
                                        
                                    }

                                    else
                                    {
                                            cout<<"Invalid Input."<<endl;

                                    }
                                    }
                                }

                                else
                                {

                                        cout<<"Invalid Input."<<endl;

                                }
                                }

                                    break;

                            case 3:
                                    while(quantity<0)
                                {
                                cout<<"How many would you like to sell? (Enter a positive integer, or 0 to cancel)"<<endl;
                                yesOrNo = 'x';
                                cin>>quantity;
                                cin.clear();
                        if(cin.ignore(numeric_limits<streamsize>::max(), '\n'))
                        {
                            system("clear");
                            cout<<"Invalid Input"<<endl;
                        }
                                if(quantity ==0)
                                {
                                    choice5 = 6;
                                    break;
                                    
                                }
                                else if(quantity>0)
                                {
                                    while(yesOrNo!='y'&& yesOrNo!='n')
                                    {
                                    cout<<"You want to sell "<<quantity<<" Treasure(s) for "<<30<<" Gold? (y/n)"<<endl;
                                    cin>>yesOrNo;
                                    if(yesOrNo == 'n')
                                    {
                                        choice5 = 6;
                                        break;
                                    }
                                    else if(yesOrNo == 'y')
                                    {
                                        if (quantity<=BTreasureQuantity)
                                        {
                                           x.setGold(x.getGold()+quantity*30);
                                           BTreasureQuantity = BTreasureQuantity - quantity;
                                           
                                                for(int i = 0; i<x.getTreasures().size(); i++)
                                                {
                                                        if(quantity>0)
                                                        {
                                                        if(x.getTreasures()[i]=="Emerald Bracelet")
                                                        {
                                                            x.removeTreasureAt(i);
                                                            i--;
                                                            quantity--;

                                                        }
                                                        }


                                                }


                                           

                                           quantity = 1;
                                          

                                         
                                           choice5 = 6;
                                            break;
                                            
                                        }
                                        else
                                        {
                                            cout<<"Insufficient treasures"<<endl;
                                            choice5 = 6;
                                            break;

                                        }
                                        
                                        
                                    }

                                    else
                                    {
                                            cout<<"Invalid Input."<<endl;

                                    }
                                    }
                                }

                                else
                                {

                                        cout<<"Invalid Input."<<endl;

                                }
                                }

                                    break;

                            case 4:
                                   while(quantity<0)
                                {
                                cout<<"How many would you like to sell? (Enter a positive integer, or 0 to cancel)"<<endl;
                                yesOrNo = 'x';
                                cin>>quantity;
                                cin.clear();
                        if(cin.ignore(numeric_limits<streamsize>::max(), '\n'))
                        {
                            system("clear");
                            cout<<"Invalid Input"<<endl;
                        }
                                if(quantity ==0)
                                {
                                    choice5 = 6;
                                    break;
                                    
                                }
                                else if(quantity>0)
                                {
                                    while(yesOrNo!='y'&& yesOrNo!='n')
                                    {
                                    cout<<"You want to sell "<<quantity<<" Treasure(s) for "<<10<<" Gold? (y/n)"<<endl;
                                    cin>>yesOrNo;
                                    if(yesOrNo == 'n')
                                    {
                                        choice5 = 6;
                                        break;
                                    }
                                    else if(yesOrNo == 'y')
                                    {
                                        if (quantity<=CTreasureQuantity)
                                        {
                                           x.setGold(x.getGold()+quantity*40);
                                           CTreasureQuantity = CTreasureQuantity - quantity;
                                           
                                                for(int i = 0; i<x.getTreasures().size(); i++)
                                                {
                                                        if(quantity>0)
                                                        {
                                                        if(x.getTreasures()[i]=="Diamond circlet")
                                                        {
                                                            x.removeTreasureAt(i);
                                                            i--;
                                                            quantity--;

                                                        }
                                                        }


                                                }


                                           

                                           quantity = 1;
                                          

                                         
                                           choice5 = 6;
                                            break;
                                            
                                        }
                                        else
                                        {
                                            cout<<"Insufficient treasures"<<endl;
                                            choice5 = 6;
                                            break;

                                        }
                                        
                                        
                                    }

                                    else
                                    {
                                            cout<<"Invalid Input."<<endl;

                                    }
                                    }
                                }

                                else
                                {

                                        cout<<"Invalid Input."<<endl;

                                }
                                }

                                    break;

                            case 5:
                                    while(quantity<0)
                                {
                                cout<<"How many would you like to sell? (Enter a positive integer, or 0 to cancel)"<<endl;
                                yesOrNo = 'x';
                                cin>>quantity;
                                cin.clear();
                        if(cin.ignore(numeric_limits<streamsize>::max(), '\n'))
                        {
                            system("clear");
                            cout<<"Invalid Input"<<endl;
                        }
                                if(quantity ==0)
                                {
                                    choice5 = 6;
                                    break;
                                    
                                }
                                else if(quantity>0)
                                {
                                    while(yesOrNo!='y'&& yesOrNo!='n')
                                    {
                                    cout<<"You want to sell "<<quantity<<" Treasure(s) for "<<50<<" Gold? (y/n)"<<endl;
                                    cin>>yesOrNo;
                                    if(yesOrNo == 'n')
                                    {
                                        choice5 = 6;
                                        break;
                                    }
                                    else if(yesOrNo == 'y')
                                    {
                                        if (quantity<=GTreasureQuantity)
                                        {
                                           x.setGold(x.getGold()+quantity*50);
                                           GTreasureQuantity = GTreasureQuantity - quantity;
                                           
                                                for(int i = 0; i<x.getTreasures().size(); i++)
                                                {
                                                        if(quantity>0)
                                                        {
                                                        if(x.getTreasures()[i]=="Gem-encrusted goblet")
                                                        {
                                                            x.removeTreasureAt(i);
                                                            i--;
                                                            quantity--;

                                                        }
                                                        }


                                                }


                                           

                                           quantity = 1;
                                          

                                         
                                           choice5 = 6;
                                            break;
                                            
                                        }
                                        else
                                        {
                                            cout<<"Insufficient treasures"<<endl;
                                            choice5 = 6;
                                            break;

                                        }
                                        
                                        
                                    }

                                    else
                                    {
                                            cout<<"Invalid Input."<<endl;

                                    }
                                    }
                                }

                                else
                                {

                                        cout<<"Invalid Input."<<endl;

                                }
                                }

                                    break;

                            
                                
                    }
                }

                               


                    break;

            case 6:
                    yesOrNo = 'x';
                    while(yesOrNo!='y'&&yesOrNo!='n')
                    {
                    cout<<"Are you sure you're finished? You won't be able to buy anything else from me! (y/n)"<<endl;
  

                    cin>>yesOrNo;
                    if(yesOrNo!='y'&&yesOrNo!='n')
                    {
                        cout<<"Invalid Input."<<endl;
                    }
                    }
                    if(yesOrNo == 'y')
                    {
                        cout<<"Stay safe out there! Goodbye!"<<endl;
                    }

                    else
                    {
                        option = 7;
                    }

                    break;
               
           
        }

    }
    system("clear");

    return x;
    }

