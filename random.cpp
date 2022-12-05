#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Function to generate a random number between 1 and 10
int randomNumber()
{

    srand(time(0));

    int randomNumber = (rand() % 10) + 1;

    return randomNumber;
}

// Function that will return true if random number == 1
bool tenPercent()
{
    if (randomNumber() == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Funciton that will return true if random number is a 1 or 2 (20%)
bool twentyPercent()
{

    if (randomNumber() == 1 || randomNumber() == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function that will return true 50% of the time
bool fiftyPercent()
{
    if (randomNumber() >= 1 && randomNumber() <= 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function that will return true 60 % of the time
bool sixtyPercent()
{
    if (randomNumber() >= 1 && randomNumber() <= 6)
    {
        return true;
    }

    else
    {
        return false;
    }
}

int main()
{

    cout << randomNumber() << endl;
    cout << tenPercent() << endl;
    cout << twentyPercent() << endl;
    cout << fiftyPercent() << endl;
    cout << sixtyPercent() << endl;
}
