// EE 1301 
// HW 5B
// John Anselmo
// ansel054

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <fstream>


using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "ERROR: Incorrect number of arguments.\nProgram requires 3\n";
        return 1;
    } else {
        srand(time(NULL));

        ofstream outputFile;
        outputFile.open("./randArray.txt");

        // Order of inputs: run_command row_count column_count max_random_number
        // Throw out first input
        const int rows = stoi((string) argv[1]);
        const int columns = stoi((string) argv[2]);
        const int max = stoi((string) argv[3]);

        for (int rowNum = 0; rowNum < rows; rowNum++) {
            for (int colNum = 0; colNum < columns; colNum++) {
                outputFile << (rand() % ((2 * max) + 1)) - max;
                if (colNum != columns - 1) { 
                    outputFile << " ";
                }
            }
            if (rowNum != rows - 1) {
                outputFile << endl;
            }
        }
    }

    return 0;
}