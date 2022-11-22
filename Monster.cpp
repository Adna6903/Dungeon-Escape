// CSCI 1300 Fall 2022
// Author: Adithya Narayanan
// Recitation: 106 –Chanheum Park
// Author: Benjamin E Apelman 
// Recitation: Section 105 – Raegan Rychecky
// Project 3 Code Skeleton

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




