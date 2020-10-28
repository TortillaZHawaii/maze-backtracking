#include "Maze.h"

bool Maze::isValiable(int x, int y) {
    return x < xMax and x >= 0 and
        y < yMax and y >= 0 and
        !A[x][y];
}

Maze::Maze(int xMax, int yMax) : xMax(xMax), yMax(yMax) {
    xGoal = xMax - 1;
    yGoal = yMax - 1;
    try {
        A = new char* [xMax];
    }
    catch (bad_alloc e) {
        fprintf(stderr, e.what());
    }
    for (int i = 0; i < xMax; ++i) {
        try {
            A[i] = new char[yMax];
        }
        catch (bad_alloc e) {
            for (int j = i - 1; j >= 0; --j) {
                delete[] A[j];
            }
            delete[] A;
            fprintf(stderr, e.what());
        }
    }
}

void Maze::openMaze(const char* filename)
{
    ifstream in(filename);
    string line;

    int j = 0;
    while (in >> line) {
        for (int i = 0; i < xMax; ++i) {
            A[i][j] = line[i] - '0'; // quick fix
        }
        j++;
    }
    
    in.close();
}

Maze::~Maze() {
    if (A) {
        for (int i = 0; i < xMax; ++i)
            if(A[i])
                delete[] A[i];
        delete[] A;
    }
}

bool Maze::findPath(int x0, int y0) {
    A[x0][y0] = 'X';

    if (x0 == xGoal and y0 == yGoal)
        return true;

    for (int i = 0; i < noMoves; ++i) {
        int x = x0 + xMoves[i];
        int y = y0 + yMoves[i];

        if (isValiable(x, y)) {
            if (findPath(x, y) == 1)
                return true;
            else {// cleaning after backtrack
                A[x][y] == 0;
                return false;
            }
        }
    }

    return false; // failed to find a path
}

ostream& operator<<(ostream& out, const Maze& m)
{
    for (int j = 0; j < m.yMax; ++j) {
        for (int i = 0; i < m.xMax; ++i) {
            out << m.A[i][j];
        }
        out << endl;
    }
    return out;
}
