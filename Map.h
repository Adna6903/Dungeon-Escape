#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "Team.h"
#include "Player.h"

using namespace std;

class Map
{
private:
    const char UNEXPLORED = '-'; // marker for unexplored spaces
    const char EXPLORED = ' ';   // marker for explored spaces
    const char ROOM = 'R';       // marker for room locations
    const char NPC = 'N';        // marker for NPC locations
    const char PARTY = 'X';      // marker for party position
    const char EXIT = 'E';       // marker for dungeon exit

    static const int num_rows_ = 12; // number of rows in map
    static const int num_cols_ = 12; // number of columns in map
    static const int max_npcs_ = 5;  // max non-player characters
    static const int max_rooms_ = 5; // max number of rooms

    int player_position_[2];              // player position (row,col)
    int dungeon_exit_[2];                 // exit location of the dungeon
    int npc_positions_[max_npcs_][3];     // stores the (row,col) positions of NPCs present on map and if they have been found
    int room_positions_[max_rooms_][2];   // stores the (row,col) positions of rooms present on map
    char map_data_[num_rows_][num_cols_]; // stores the character that will be shown at a given (row,col)

    int npc_count_;  // stores number of misfortunes currently on map
    int room_count_; // stores number of sites currently on map

    

 
public:
    Map();

    void resetMap();

    // getters
    int getPlayerRow();
    int getPlayerCol();
    int getDungeonExitRow();
    int getDungeonExitCol();
    int getRoomCount();
    int getNPCCount();
    int getNumRows();
    int getNumCols();
    bool isOnMap(int row, int col,Team exTeam);
    bool isNPCLocation(int row, int col,Team exTeam);
    bool isRoomLocation(int row, int col, Team exTeam);
    bool isExplored(int row, int col,Team exTeam);
    bool isFreeSpace(int row, int col,Team exTeam);
    bool isDungeonExit(int row, int col, Team exTeam);
    
    
    // setters
    void setPlayerPosition(int row, int col,Team exTeam);
    void setDungeonExit(int row, int col,Team exTeam);
    

    // other
    void displayMap();
    bool move(char,Team exTeam);
    bool addNPC(int row, int col,Team exTeam);
    bool addRoom(int row, int col,Team exTeam);
    bool removeNPC(int row, int col);
    bool removeRoom(int row, int col);
    void exploreSpace(int row, int col,Team exTeam);
};

#endif