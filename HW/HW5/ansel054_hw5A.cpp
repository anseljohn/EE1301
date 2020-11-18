#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char BLANK = '-';
const char ROBOT = 'X';
const char GOAL = 'O';
const char WALL = 'W';
const int screen_num_lines = 25;
const int lengthX = 10;       // for now we only support square boards
const int lengthY = 10;       // it "should" work with non-square, YMMV
// Board is described by the following coordinate system:
// 0 --> +X
// |
// |
// V
// +Y

void initBoard(char board[lengthX][lengthY], int &xPos, int &yPos);
void clearScreen();
void showGrid(char board[lengthX][lengthY]);

bool hasChar(char board[lengthX][lengthY], char findMe);
void updateGrid(char board[lengthX][lengthY], int &xPos, int &yPos, char action);

int main()
{
    char board[lengthX][lengthY] = {0};
    int xPos = 0, yPos = 0;

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
        for(int curRow=0; curRow < lengthY; curRow++) {
            for(int curCol=0; curCol < lengthX; curCol++) {

                // Adding walls to default board!
                if (curRow == 0 && curCol > 2) {
                    board[curCol][curRow] = WALL;
                } else {
                    board[curCol][curRow] = BLANK;
                }

                if (curRow == 1 && curCol <= 1) {
                    board[curCol][curRow] = WALL;
                }

            }
        }

        int firstRow[lengthX] = {'a','b','c','d','e','f','g','h','i','j'};
        for (int i = 0; i < lengthX; i++) {
            board[i][0] = firstRow[i];
        }

        board[0][0] = GOAL;
        xPos = lengthX - 2;
        yPos = lengthY - 2;

        board[xPos][yPos] = ROBOT;

}

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
    if (action == 'l' && xPos > 0) {
        if (board[xPos - 1][yPos] != WALL) {
            xPos--;
        }
    } else if(action == 'r' && xPos < lengthX - 1) {
        if (board[xPos + 1][yPos] != WALL) {
            xPos--;
        }
    } else if(action == 'u' && yPos > 0) {
        if (board[xPos][yPos - 1] != WALL) {
            yPos--;
        }
    } else if(action == 'd' && yPos < lengthY - 1) {
        if (board[xPos][yPos + 1] != WALL) {
            yPos++;
        }
    }
    board[xPos][yPos] = ROBOT;
}
