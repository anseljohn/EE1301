// EE 1301 
// HW 4B
// John Anselmo
// ansel054

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int getGradeAmountFromLine(string str);

int main() {
    string line;
    ofstream histogram;
    ifstream gradeDistribution ("./statistics.csv");
    
    int amounts[5];
    int maxAmount = 0; //The biggest amount, to create '=' spacing at the bottom

    histogram.open("./histogram.txt");

    // Reading in all amounts per letter grade
    if (gradeDistribution.is_open()) {
        int i = 0;
        getline(gradeDistribution, line);
        while (getline(gradeDistribution, line)) {\
            amounts[i] = getGradeAmountFromLine(line);
            i++;
        }
        gradeDistribution.close();
    }

    for (int j = 'A'; j <= 'F'; j++) {
        if (j == 'E') {
            continue;
        } else {
            histogram << (char) j;

            // For loop using char Ascii is faulty in that there is no E grade, but there is an [E % 65]th index
            // Had to make the for loop limiter equal to E % 65 instead of F % 65 since that would be an out of bounds index.
            int forLoopLimiter = amounts[j % 65];
            if (j == 'F') {
                forLoopLimiter = amounts[(j - 1) % 65];
            }
            for (int k = 0; k < forLoopLimiter; k++) {
                if (forLoopLimiter > maxAmount) {
                    maxAmount = forLoopLimiter;
                }
                histogram << " X";
            }
            histogram << endl;
        }
    }

    histogram << setfill('=') << setw(maxAmount * 2 + 2) << "" << endl << "  "; // Filling equal signes to separate output sections

    // Creating amount labeling underneath = spacing
    for (int i = 1; i <= maxAmount; i++) {
        histogram << i << " ";
    }
    histogram.close();

    return 0;
}

/**
 * Gets the amount of a certain grade from the csv inputted lines
 * string str: the line input from the csv file
 * Output: n, the amount of the grade at that line
**/
int getGradeAmountFromLine(string str) {
    string strs[2];
    string temp = "";
    char delim = ',';
    for (int i = 0; i < str.length(); i++) {
        if (str.at(i) == delim) {
            strs[0] = temp;
            temp = "";
        } else {
            temp += str.at(i);
            if (i == str.length() - 1) {
                strs[1] = temp;
            }
        }
    }
    return stoi(strs[1]);
}