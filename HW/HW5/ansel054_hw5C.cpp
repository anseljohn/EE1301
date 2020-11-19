// EE 1301 
// HW 5B
// John Anselmo
// ansel054

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "INPUT ERROR: program requires one text file input" << endl;
    } else {
        ifstream inputPixels (argv[1]);

        // Will never be above 100 x 100
        const int N = 10;
        int readMatrix[N][N] = {0};
        int newMatrix[N][N] = {0};
        memset(readMatrix, 0, N*N*sizeof(int));
        memset(newMatrix, 0, N*N*sizeof(int));
        string line = "";

        if (inputPixels.is_open()) {
            int i = 0;
            int j = 0;
            while (getline(inputPixels, line)) {
                string temp = "";
                for (int charAt = 0; charAt < line.size(); charAt++) {
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

            // for (int i = 0; i < N; i++) {
            //     for (int j = 0; j < N; j++) {
            //         cout << readMatrix[i][j] << " ";
            //     }
            //     cout << endl;
            // }
        }

    }

    return 0;
}