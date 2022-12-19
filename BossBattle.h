 
#include <iostream>
#include"Player.h"
#include "Team.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/** Algorithm:
 * Generate a random number
 * If the guess is below the random number say aim hihger
 * If the guess is above the random number say aim lower
 * If the user guess the number they win
 * If the user cannon guess the number after three tries they loose
 */


using namespace std;


bool hotOrCold(int guessNumber,int targetNumber)
{

    bool result = false;

    if(guessNumber>targetNumber)
    {
        cout<<"Aim lower"<<endl;
        result = false;
    }
    
    if(guessNumber<targetNumber)
    {
        cout<<"Aim higher"<<endl;
        result = false;
    }

    if(guessNumber==targetNumber)
    {
        cout<<"Your aim is right!"<<endl;
       
        result = true;

    }

    return result;
}



bool bossBattle()
{
    srand(time(0));
    int sorcererHead = rand()%10 + 1;
    cout<<sorcererHead<<endl;
    int guessHead;
    bool Result = false;
    cout<<"You now face the Sorcerer"<<endl;
    cout<<"The sorcerer has 10 heads numbered 1 - 10 out of which one head is his vulnerable point"<<endl;
    cout<<"You have 3 arrows to hit the correct head or else your entire team will be devoured by the sorcerer"<<endl;
    cout<<"Enter first head you would like to hit"<<endl;
    cout<<sorcererHead<<endl;
    cin>>guessHead;
    Result = hotOrCold(guessHead,sorcererHead);
    if(!Result)
    {
        cout<<"Try again"<<endl;
        cout<<"Enter second head you would like to hit"<<endl;
        cin>>guessHead;
        Result = hotOrCold(guessHead,sorcererHead);
    }
     if(Result)
    {
        cout<<"You have managed to hit the sorcerer"<<endl;
        cout<<"The sorcrer has been defeated"<<endl;
        return true;
    }

    if(!Result)
    {
        cout<<"Try again"<<endl;
        cout<<"Enter third head you would like to hit"<<endl;
        cin>>guessHead;
        Result =hotOrCold(guessHead,sorcererHead);
    }
     if(Result)
    {
        cout<<"You have managed to hit the sorcerer"<<endl;
        cout<<"The sorcrer has been defeated"<<endl;
        return true;
    }

    if(!Result)
    {
        cout<<"You have failed to defeat the sorcerer"<<endl;
        cout<<"All team members have died"<<endl;
        return false;
    }
    else if(Result)
    {
        cout<<"You have managed to hit the sorcerer"<<endl;
        cout<<"The sorcrer has been defeated"<<endl;
        return true;
    }


        return false;


}