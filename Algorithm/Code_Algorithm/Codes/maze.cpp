#include <iostream>

using namespace std;

#define PATHWAY 0
#define WALL 1
#define BLOCKED 2
#define PATH 3

int N = 8;

int maze[8][8] ={
    {0,0,0,0,0,0,0,1},
    {0,1,1,0,1,1,0,1},
    {0,0,0,1,0,0,0,1},
    {0,1,0,0,1,1,0,0},
    {0,1,1,1,0,0,1,1},
    {0,1,0,0,0,1,0,1},
    {0,0,0,1,0,0,0,1},
    {0,1,1,1,0,1,0,0}
};

void printMaze(){
    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < N ; j++){
            cout << maze[i][j] << ",";
        }
        cout << endl;
    }
}

bool findPath(int x, int y){
    // out of grid case
    if (x < 0 || x > N-1 || y < 0 || y > N-1)
        return false;
    // WALL or VISITED(BLOCKED or PATH) case
    else if (maze[x][y] == WALL || maze[x][y] != PATHWAY)
        return false;
    // Success case
    else if (x == N-1 && y == N-1){
        maze[x][y] = PATH;
        return true;
    }
    // Recursive case
    else{
        maze[x][y] = PATH;
        if (findPath(x-1,y) || findPath(x+1,y) || findPath(x,y-1) || findPath(x,y+1))
            return true;
        else{
            maze[x][y] = BLOCKED;
            return false;
        }
    
    }
}

int main (){
    printMaze();
    findPath(0,0);
    cout << "---------------------" << endl;
    printMaze();
    return 0;
}