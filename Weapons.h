// CSCI 1300 Fall 2022
// Author: Adithya Narayanan
// Recitation: 106 –Chanheum Park
// Author: Benjamin E Apelman 
// Recitation: Section 105 – Raegan Rychecky
// Project 3 Code Skeleton

#ifndef WEAPONS_H
#define WEAPONS_H
#include <iostream>
#include <vector>
#include <string>
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