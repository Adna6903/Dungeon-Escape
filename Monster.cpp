

#include <iostream>
using namespace std;

#include "Monster.h"


//Getters

  string Monster::getName()
    {
        return name_;
    }

    int Monster::getDifficulty()
    {
        return difficulty_;
    }


//Setters:

    void Monster:: setName(string name){

        name_ = name;         

    }

    void Monster:: setDifficulty(int difficulty)
    {
        difficulty_ = difficulty; 
    }




