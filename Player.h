
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;


class Player
{
    
private:
            string playerName_;
            int fullnessPoints_;

public:
            Player();
            int getFullnessPoints();
            void setFullnessPoints(int fullnessPoints);
            string getPlayerName();
            void setPlayerName(string playerName);

};


#endif