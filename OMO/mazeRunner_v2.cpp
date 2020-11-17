#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char BLANK = '-';
const char ROBOT = 'X';
const char GOAL = 'O';
const char WALL = 'W';

// For coordinate system
const int X = 0;
const int Y = 1;

const int screen_num_lines = 25;
const int lengthX = 10;       // for now we only support square boards
const int lengthY = 10;       // it "should" work with non-square, YMMV

int xPos = 0, yPos = 0;
char board[lengthX][lengthY] = {0};

// Board is described by the following coordinate system:
// 0 --> +X
// |
// |
// V
// +Y

void initBoard(char board[lengthX][lengthY], int &xPos, int &yPos);
bool coordsConnected(int c1[2], int c2[2])
bool rowsConnected(int rowOne, int rowTwo[lengthX]);
bool rowsConnected(int rowOne, bool up);
void clearScreen();
void showGrid(char board[lengthX][lengthY]);

bool hasChar(char board[lengthX][lengthY], char findMe);
void updateGrid(char board[lengthX][lengthY], int &xPos, int &yPos, char action);

int main()
{
    srand(time(NULL));

    initBoard(board, xPos, yPos);


    while(hasChar(board, GOAL))
    {
        char action;
        clearScreen();
        showGrid(board);
        cout << "Where would you like to go? (l, r, u, d) " << endl;

        cin >> action;

        updateGrid(board, xPos, yPos, action);

    }

    clearScreen();
    showGrid(board);
    cout << "You found the cookie!  Congratulations!\n";

    return 0;
}






// ==========================================================================
//                          CONSTRUCTION ZONE BEGINNING
// ==========================================================================


/*
Description: Initializes game board. Sets all characters in board as blanks,
then sets position of goal, and then sets position of robot.
Inputs:
    char board[][] - 2D array used to represent game board
    int xPos - saved x position of robot
    int yPos - saved y position of robot
Outputs: NA
*/
void initBoard(char board[lengthX][lengthY], int &xPos, int &yPos) {
    int goalPosX = rand() % lengthX;
    int goalPosY = rand() % lengthY;
    xPos = goalPosX;
    yPos = goalPosY;

    while (goalPosX == xPos || goalPosY == yPos) {
        if (goalPosX == xPos) {
            goalPosX = rand() % lengthX;
        } else if (goalPosY == yPos) {
            goalPosY = rand() % lengthY;
        }
    }

    for(int curRow=0; curRow < lengthY; curRow++) {
        for(int curCol=0; curCol < lengthX; curCol++) {
            board[curCol][curRow] = BLANK;
        }
    }

    board[goalPosX][goalPosY] = GOAL;
    board[xPos][yPos] = ROBOT;
}


/**
 * Check whether the coordinate is one the player is able to move to
 * int coord[2]: the coordinate to check
 * returns: if they can move there/already have
 */
bool canMoveTo(int coord[2]) {
    return board[coord[Y]][coord[X]] == BLANK || board[coord[Y]][coord[X]] == ROBOT;
}

/**
 * Checks whether you can reach one coordinate from another or not
 * int c1[2]: starting position
 * int c2[2]: position to move to
 * returns: if you can get from c1 to c2
 */
bool coordsConnected(int c1[2], int c2[2]) {

    // Four for loops is absolutely painful to look at, but I originally had a function below that
    // adds or subtracts from the current x and y values depending on the direction of travel
    // but that required checking direction every single cycle of each loop which is just inefficient.

    /**
     * Depending on whether we move up/down left/right, add or subtract from coordinate 
     * int &operand: the value to do the operation on
     * bool leftOrUp: whether we move up/down or left/right
     */
    // auto opChangeByDirection = [](int &operand, bool leftOrUp) {
    //     if (leftOrUp) {
    //         operand--;
    //     } else {
    //         operand++;
    //     }
    // };

    bool up = c2[Y] < c1[Y];
    bool left = c1[X] < c1[X];
    if (up) {
        if (left) {
            for (int currX = c1[X]; currX != c2[X]; currX--) {
                for (int currY = c1[Y]; currY != c2[Y]; currY--) {
                    int coord[2] = {currX, currY};
                    if (!canMoveTo(coord)) {
                        return false;
                    }
                }
            }
        } else {
            for (int currX = c1[X]; currX != c2[X]; currX++) {
                for (int currY = c1[Y]; currY != c2[Y]; currY--) {
                    int coord[2] = {currX, currY};
                    if (!canMoveTo(coord)) {
                        return false;
                    }
                }
            }
        }
    } else {
        if (left) {
            for (int currX = c1[X]; currX != c2[X]; currX--) {
                for (int currY = c1[Y]; currY != c2[Y]; currY--) {
                    int coord[2] = {currX, currY};
                    if (!canMoveTo(coord)) {
                        return false;
                    }
                }
            }
        } else {
            for (int currX = c1[X]; currX != c2[X]; currX++) {
                for (int currY = c1[Y]; currY != c2[Y]; currY--) {
                    int coord[2] = {currX, currY};
                    if (!canMoveTo(coord)) {
                        return false;
                    }
                }
            }
        }
    }
    

    // The single for loop that SEEMS more efficient, but isn't when considering the fact that
    // although there are four for loops, only one runs, and you only have to check direction once.

    // for (int currX = c1[X]; currX != c2[X]; opChangeByDirection(currX, left)) {
    //     for (int currY = c1[Y]; currY != c2[Y]; opChangeByDirection(currX, up)) {
    //         int coord[2] = {currX, currY};
    //         if (!canMoveTo(coord)) {
    //             return false;
    //         }
    //     }
    // }
    return true;
}

bool 


// ==========================================================================
//                          CONSTRUCTION ZONE END
// ==========================================================================





/*
Description: Loops through given game board to determine if it contains given char findMe.
Inputs:
    char board[][] - 2D array used to represent game board
    char findMe - character to look for in game board
Outputs:
    bool - returns true if board contains findMe, else returns false 
*/
bool hasChar(char board[lengthX][lengthY], char findMe) {
    for(int curRow=0; curRow < lengthY; curRow++) {
        for(int curCol=0; curCol < lengthX; curCol++) {
            if(board[curCol][curRow] == findMe) {
                return true;
            }
        } //end curCol loop
    } // end curRow loop

    return false;
}

/*
Description: Prints out screen_num_lines amount of end lines to terminal so 
that old board is no longer visible.
Inputs: NA
Outputs: NA
*/
void clearScreen() {
    for(int i = 0;i<screen_num_lines;i++) {
        cout << endl;
    }
}

/*
Description: Prints out input game board to the terminal.
Inputs: 
    char board[][] - 2D array used to represent game board
Outputs: NA
*/
void showGrid(char board[lengthX][lengthY]) {
    for(int curRow=0; curRow < lengthY; curRow++) {
        for(int curCol=0; curCol < lengthX; curCol++) {
            cout << board[curCol][curRow];
        } // end curCol loop
        cout << endl;
    } // end curRow loop
}

/*
Description: Updates saved grid position of robot based on input action.
Inputs:
    char board[][] - 2D array used to represent game board
    int xPos - saved x position of robot
    int yPos - saved y position of robot
    char action - desired direction for robot to move, i.e. 'l', 'r', 'u', or 'd'
Outputs: NA
*/
void updateGrid(char board[lengthX][lengthY],int & xPos, int & yPos,char action) {
    board[xPos][yPos] = BLANK;
    if       (action == 'l' && xPos > 0) {
            xPos--;
    } else if(action == 'r' && xPos < lengthX - 1) {
            xPos++;
    } else if(action == 'u' && yPos > 0) {
            yPos--;
    } else if(action == 'd' && yPos < lengthY - 1) {
            yPos++;
    }
    board[xPos][yPos] = ROBOT;
}
