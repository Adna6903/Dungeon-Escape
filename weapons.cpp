#include <vector>
#include "weapons.h"
using namespace std;

//Getters


    string Weapons::getName()
    {
        return name_; 
    }

    int Weapons::getLevel()
    {
        return level_;
    }

    //Setters:
   

    void Weapons::setName(string name)
    {
        name_ = name;
    }


    void Weapons::setLevel(int level)
    {
        level_ = level;
    }

