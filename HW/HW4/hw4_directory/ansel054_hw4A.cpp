// EE 1301 
// HW 4A
// John Anselmo
// ansel054

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum lineValueTypes {NAME, GRADE};
double getGradeFromLine(string str);

int main() {
    string line;
    ifstream gradeSheet ("./grades.txt");
    ofstream gradeDistribution;

    int gradeCounts[5] = {0, 0, 0, 0, 0};
    char letters[5] = {'A', 'B', 'C', 'D', 'F'};

    gradeDistribution.open("./statistics.csv");
    gradeDistribution << "Grade,NumStudents\n";
    if (gradeSheet.is_open()) {
        int i = 0;
        string tempHolder [3];
        while (getline(gradeSheet, line)) {
            double grade = getGradeFromLine(line);

            // Creating distribution based off of grade
            if (grade >= 90.0) {
                gradeCounts[0]++;
            } else if (grade >= 80.0) {
                gradeCounts[1]++;
            } else if (grade >= 70.0) {
                gradeCounts[2]++;
            } else if (grade >= 60.0) {
                gradeCounts[3]++;
            } else {
                gradeCounts[4]++;
            }

            i++;
        }

        for (int j = 0; j < 4; j++) {
            cout << gradeCounts[j] << " " << letters[j] << endl;
            gradeDistribution << letters[j] << "," << gradeCounts[j] << "\n";
        }

        cout << gradeCounts[4] << " " << letters[4] << endl;
        gradeDistribution << letters[4] << "," << gradeCounts[4];

        gradeSheet.close();
        gradeDistribution.close();
    }

    return 0;
}


/**
 * Function gets the grade from the line input str
 * string str: input string to get the grade from
 * returns: the grade of the str
 **/
double getGradeFromLine(string str) {
    string grade = "";
    char delim = ' ';
    for (int i = 0; i < str.length(); i++) {
        // If you reach a space, reset the grade string, since it will first be filled with FirstName and LastName
        // Then finally the grade.
        if (str.at(i) == delim) {
            grade = "";
        } else {
            // Add on characters until reaching a space
            grade += str.at(i);
        }
    }
    return stod(grade); // The last thing placed into grade is the grade due to the file format, so return
}