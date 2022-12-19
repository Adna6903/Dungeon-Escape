

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