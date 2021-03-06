// EE 1301 
// HW 5A
// John Anselmo
// ansel054
// Changed it to arr[row #][col #] instead of arr[x pos][y pos]


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
    char board[lengthY][lengthX] = {0};
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
Description: Initializes default or custom board depending on whether a custom one
exists or not.
Inputs:
    char board[][] - 2D array used to repre
    sent game board
    int xPos - saved x position of robot
    int yPos - saved y position of robot
Outputs: NA
*/
void initBoard(char board[lengthY][lengthX], int &xPos, int &yPos) {
    ifstream customBoard ("./maze.txt");
    string line = "";
    if (customBoard.is_open()) {
        int i = 0;
        while (getline(customBoard, line)) {
            for (int j = 0; j < lengthX; j++) {
                char charAtIJ = line.at(j);
                if (charAtIJ == ROBOT) {
                    xPos = j;
                    yPos = i;
                }
                board[i][j] = charAtIJ;
            }
            i++;
        }
    } else {
        
        // Creating the default board
        char defaultBoard[lengthY][lengthX] = {
            {BLANK , BLANK , GOAL  , WALL  , WALL  , WALL  , WALL  , WALL  , WALL  , WALL  },
            {BLANK , BLANK , BLANK , BLANK , BLANK , BLANK , WALL  , WALL  , WALL  , WALL  },
            {WALL  , BLANK , WALL  , WALL  , WALL  , BLANK , BLANK , WALL  , WALL  , WALL  },
            {WALL  , WALL  , BLANK , BLANK , BLANK , BLANK , WALL  , WALL  , WALL  , WALL  },
            {WALL  , WALL  , BLANK , BLANK , BLANK , WALL  , WALL  , WALL  , WALL  , WALL  },
            {BLANK , BLANK , BLANK , WALL  , WALL  , BLANK , BLANK , WALL  , WALL  , WALL  },
            {BLANK , BLANK , BLANK , WALL  , WALL  , WALL  , WALL  , WALL  , WALL  , WALL  },
            {WALL  , WALL  , BLANK , BLANK , BLANK , WALL  , WALL  , WALL  , WALL  , WALL  },     
            {BLANK , BLANK , BLANK , BLANK , BLANK , BLANK , BLANK , WALL  , WALL  , WALL  },
            {BLANK , BLANK , BLANK , WALL  , WALL  , BLANK , BLANK , BLANK , BLANK , ROBOT }
        };

        // Couldn't apply the above board directly so enter it through nested for
        for(int curRow=0; curRow < lengthY; curRow++) {
            for(int curCol=0; curCol < lengthX; curCol++) {
                board[curRow][curCol] = defaultBoard[curRow][curCol];
            }
        }

        xPos = lengthX - 1;
        yPos = lengthY - 1;
    }
}

/*
Description: Loops through given game board to determine if it contains given char findMe.
Inputs:
    char board[][] - 2D array used to represent game board
    char findMe - character to look for in game board
Outputs:
    bool - returns true if board contains findMe, else returns false 
*/
bool hasChar(char board[lengthY][lengthX], char findMe) {
    for(int curRow=0; curRow < lengthY; curRow++) {
        for(int curCol=0; curCol < lengthX; curCol++) {
            if(board[curRow][curCol] == findMe) {
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
            cout << board[curRow][curCol];
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
void updateGrid(char board[lengthX][lengthY],int & xPos, int & yPos, char action) {
    action = tolower(action);
    board[yPos][xPos] = BLANK;
    if (action == 'l' && xPos > 0) {
        if (board[yPos][xPos - 1] != WALL) {
            xPos--;
        }
    } else if(action == 'r' && xPos < lengthX - 1) {
        if (board[yPos][xPos + 1] != WALL) {
            xPos++;
        }
    } else if(action == 'u' && yPos > 0) {
        if (board[yPos - 1][xPos] != WALL) {
            yPos--;
        }
    } else if(action == 'd' && yPos < lengthY - 1) {
        if (board[yPos + 1][xPos] != WALL) {
            yPos++;
        }
    }
    board[yPos][xPos] = ROBOT;
}
