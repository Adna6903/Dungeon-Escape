#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Function to generate a random number between 1 and 10
int randomNumber()
{

    srand(time(0));

    
    int randomNumber = rand();
        if(randomNumber%12!=0)
        {
    return randomNumber;
        }
        else
        {
            return randomNumber+1;
        }
}

// Function that will return true if random number == 1


