

#ifndef WEAPONS_H
#define WEAPONS_H

#include <iostream>
#include <vector>
using namespace std;

class Weapons
{
private:

    string name_;
    int level_;

public:
    // Gettters:
    string getName();
    int getLevel();

    //Setters:
    void setName(string name);
    void setLevel(int level);



    
};
#endif