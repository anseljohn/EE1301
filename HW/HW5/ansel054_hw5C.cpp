// EE 1301 
// HW 5B
// John Anselmo
// ansel054

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputPixels ("./maze.txt");

    // Will never be above 100 x 100
    int rowCount = 100;
    int colCount = 100;
    int readMatrix[rowCount][colCount] = {0};

    string line = "";
    if (inputPixels.is_open()) {
        int i = 0;
        int j = 0;
        while (getline(inputPixels, line)) {
            string temp = "";
            for (int charAt = 0; charAt < line.length(); charAt++) {
                if (line.at(charAt) != ' ') {
                    temp += line.at(charAt);
                } else {
                    readMatrix[i][j] = stoi(temp);
                    temp = "";
                    j++;
                }
            }
            i++;
        }
    }


    return 0;
}