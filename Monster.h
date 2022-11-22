// CSCI 1300 Fall 2022
// Author: Adithya Narayanan
// Recitation: 106 –Chanheum Park
// Author: Benjamin E Apelman 
// Recitation: Section 105 – Raegan Rychecky
// Project 3 Code Skeleton

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