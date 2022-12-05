// CSCI 1300 Fall 2022
// Author: Adithya Narayanan & Benjamin E Apelman 
// Recitation: 106 –Chanheum Park (Adithya)
// Recitation: Section 105 – Raegan Rychecky (Benjamin)
// Project 3 

#include <iostream>
using namespace std;


class Monster
{
    private:
        string name_;
        int difficulty_; 




    public:
    //Getters:
    int getDifficulty();
    string getName();

    //Setters

    void setDifficulty(int difficulty_);
    void setName(string name);

};