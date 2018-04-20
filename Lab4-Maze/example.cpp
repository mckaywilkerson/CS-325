#include <iostream>
using namespace std;

void numberFunction(int i) {
    //cout << "The number is " << i << endl;                    // if you put this up here, then it counts down from 10
    
    if (i < 0) {                                                // change to i==0 if you want to include 0 when it counts down
        return;
    }
  
    numberFunction(i-1);
    cout << "The number is " << i << endl;                      // if you put this down here, then it counts up from 0
}

int main() {

    int i = 0;
    numberFunction(10);

    return 0;
}

/*
int F(int N) {
    if (N == 0) {
        return 0;
    }
    else {
        return N + F(N - 1);
    }
}
*/

// for 
string Pathfinder::createMaze() {
    for (int row = 0; row < ROW_SIZE; row++) {
        for (int col = 0; col < COL_SIZE; col++) {
            
            //need a special library for random number
            if ((row ==0 && col == 0) || (row == 4 && col == 4)) {
                maze_grid[row][col] = 1;
            }
            else {
                int i = rand() % 2;
                maze_grid[row][col] = i;
            }
        }
    }
}