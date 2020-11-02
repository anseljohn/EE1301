#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    srand(time(NULL));

    int roll;
    int sides = 0;
    string rollAgain = "y";

    cout << "Enter number of sides on die: ";
    cin >> sides;

    while (sides <= 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid number of sides." << endl << "Enter number of sides on the die: ";
        cin >> sides;
    }

    while (rollAgain == "y" || rollAgain == "yes") {
        roll = rand() % sides + 1;
        cout << "You rolled a " << roll << ". Do you want to roll again? (y/n) ";
        cin >> rollAgain;
        transform(rollAgain.begin(), rollAgain.end(), rollAgain.begin(), ::tolower);
        while (rollAgain != "n" && rollAgain != "y" && rollAgain != "yes" && rollAgain != "no") {
            cout << "Invalid response." << endl << "Do you want to roll again? (y/n) ";
            cin >> rollAgain;
            transform(rollAgain.begin(), rollAgain.end(), rollAgain.begin(), ::tolower);
        }
    }
    return 0;
    
}