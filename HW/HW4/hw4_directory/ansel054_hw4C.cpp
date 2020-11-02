// EE 1301 
// HW 4C
// John Anselmo
// ansel054

// NOTE: I kept the directory 'output_files' due to ofstream not having directory creation

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string line;
    ifstream file ("./input_files/blahblah.txt");
    ofstream outputFile; // the file to write the vote counts to

    // Counts for    a  e  i  o  u
    int counts[5] = {0, 0, 0, 0, 0};
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    if (file.is_open()) {
        while (getline(file, line)) {\
            // Go through each character in the line
            for (int i = 0; i < line.size(); i++) {
                // Go through each vowel and check if equal
                for (int j = 0; j < sizeof(vowels)/sizeof(vowels[0]); j++) {
                    // Up that vowel's count if found!
                    if (tolower(line.at(i)) == vowels[j]) {
                        counts[j]++;
                    }
                }
            }
        }
        file.close();
    }


    // Printing election findings
    int winnerIndex = 0;
    cout << "The results are in!\n";
    for (int i = 0; i < sizeof(vowels)/sizeof(vowels[0]); i++) {
        if (counts[i] > counts[winnerIndex]) {
            winnerIndex = i;
        }
        cout << (char) toupper(vowels[i]) << "/" << vowels[i] << " received " << counts[i] << " votes\n";
    }
    cout << "The winner is the letter \"" << (char) toupper(vowels[winnerIndex]) << "\"!\n";

    // Outputting election findings to election_results.txt
    outputFile.open("./output_files/election_results.txt");
    for (int i = 0; i < 4; i++) {
        outputFile << (char) toupper(vowels[i]) << "," << counts[i] << endl;
    }
    outputFile << "U," << counts[4];
    outputFile.close();

    return 0;
}