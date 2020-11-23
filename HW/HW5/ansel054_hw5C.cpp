// EE 1301 
// HW 5B
// John Anselmo
// ansel054

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int N = 100;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "INPUT ERROR: program requires one text file input" << endl;
    } else {
        ifstream inputPixels;

        int readMatrix[N][N] = {0};
        int newMatrix[N][N] = {0};
        int rows = 0;
        int cols = 0;
        string line;

        inputPixels.open(argv[1]);
        if (inputPixels.is_open()) {
            while (getline(inputPixels, line)) {
                string temp = "";
                for (int charAt = 0; charAt < line.length(); charAt++) {
                    if (line.at(charAt) != ' ' || charAt == line.length() - 1) {
                        temp += line.at(charAt);
                    } else {
                        readMatrix[rows][cols] = stoi(temp);
                        // cout << readMatrix[rows][cols] << " ";
                        temp = "";
                        if (rows == 0) {
                            cols++;
                        }
                    }
                }
                // cout << endl;
                rows++;
                cout << rows << " " << cols << endl;

            }
        }
        inputPixels.close();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << readMatrix[rows][cols] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}