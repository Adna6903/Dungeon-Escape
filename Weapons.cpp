// CSCI 1300 Fall 2022
// Author: Adithya Narayanan
// Recitation: 106 –Chanheum Park
// Author: Benjamin E Apelman 
// Recitation: Section 105 – Raegan Rychecky
// Project 3 Code Skeleton

#include <vector>
#include <iostream>
#include "Weapons.h"


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

