#include <iostream>
#include "Maze.h"

using namespace std;

int main()
{
    Maze m(6, 4);
    m.openMaze("maze1.txt");
    cout << m << endl;
    m.findPath(0, 0);
    cout << m;
    return 0;
}
