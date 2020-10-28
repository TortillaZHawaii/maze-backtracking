#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Maze {
    // Size of A
    int xMax, yMax;
    /* A table
    * 0 - free space
    * 1 - wall
    * 'X' - our path
    */
    char** A;

    // Our goal
    int xGoal, yGoal;

    /* Available moves:
    * N E S W
    * noMoves - number of moves
    */
    static const int noMoves = 4;
    int xMoves[noMoves] = { 1, 0, -1, 0 };
    int yMoves[noMoves] = { 0, 1, 0, -1 };

    // Checks if we can go to x,y
    bool isValiable(int x, int y);

public:
    Maze(int xMax, int yMax);

    void openMaze(const char* filename);

    friend ostream& operator<<(ostream &out, const Maze& m);

    ~Maze();

    /* returns false if dead end
    *          true if success
    */
    bool findPath(int x0, int y0);
};
